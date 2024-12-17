#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

#include "arrivals.h"
#include "intersection_time.h"
#include "input.h"

/* 
 * curr_arrivals[][][]
 *
 * A 3D array that stores the arrivals that have occurred
 * The first two indices determine the entry lane: first index is Side, second index is Direction
 * curr_arrivals[s][d] returns an array of all arrivals for the entry lane on side s for direction d,
 *   ordered in the same order as they arrived
 */
static Arrival curr_arrivals[4][4][20];

/*
 * semaphores[][]
 *
 * A 2D array that defines a semaphore for each entry lane,
 *   which are used to signal the corresponding traffic light that a car has arrived
 * The two indices determine the entry lane: first index is Side, second index is Direction
 */
static sem_t semaphores[4][4];

// for manage light threads -> holds argumentss
typedef struct {
    Side side;
    Direction direction;
    pthread_mutex_t* intersection_mutex;
} LightArgs;

/*
 * supply_arrivals()
 *
 * A function for supplying arrivals to the intersection
 * This should be executed by a separate thread
 */
static void* supply_arrivals()
{
  int t = 0;
  int num_curr_arrivals[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  // for every arrival in the list
  for (int i = 0; i < sizeof(input_arrivals)/sizeof(Arrival); i++)
  {
    // get the next arrival in the list
    Arrival arrival = input_arrivals[i];
    // wait until this arrival is supposed to arrive
    sleep(arrival.time - t);
    t = arrival.time;
    // store the new arrival in curr_arrivals
    curr_arrivals[arrival.side][arrival.direction][num_curr_arrivals[arrival.side][arrival.direction]] = arrival;
    num_curr_arrivals[arrival.side][arrival.direction] += 1;
    // increment the semaphore for the traffic light that the arrival is for
    sem_post(&semaphores[arrival.side][arrival.direction]);
  }

  return(0);
}


/*
 * manage_light(void* arg)
 *
 * A function that implements the behaviour of a traffic light
 */
static void* manage_light(void* arg)
{
    LightArgs* args = (LightArgs*)arg;
    Side side = args->side;
    Direction direction = args->direction;
    pthread_mutex_t* intersection_mutex = args->intersection_mutex;
    int car_index = 0;

    while (get_time_passed() < END_TIME)
    {
        // Wait for a car arrival
        sem_wait(&semaphores[side][direction]);

        // Lock the intersection mutex
        pthread_mutex_lock(intersection_mutex);

        // Get the arrival information
        Arrival arrival = curr_arrivals[side][direction][car_index];
        car_index++;

        // Turn the traffic light green
        printf("traffic light %d %d turns green at time %d for car %d\n", side, direction, get_time_passed(), arrival.id);

        // Sleep for CROSS_TIME seconds
        sleep(CROSS_TIME);

        // Turn the traffic light red
        printf("traffic light %d %d turns red at time %d\n", side, direction, get_time_passed());

        // Unlock the intersection mutex
        pthread_mutex_unlock(intersection_mutex);
    }

    // frees memory
    free(args);
    return NULL;
	
  // TODO:
  // while not all arrivals have been handled, repeatedly:
  //  - wait for an arrival using the semaphore for this traffic light
  //  - lock the right mutex(es)
  //  - make the traffic light turn green
  //  - sleep for CROSS_TIME seconds
  //  - make the traffic light turn red
  //  - unlock the right mutex(es)
}


int main(int argc, char * argv[])
{
	//BASIC SOLUTION USES ONLY 1 MUTEX
	pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
	
	
	// create semaphores to wait/signal for arrivals
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			sem_init(&semaphores[i][j], 0, 0);
		}
	}

	// start the timer
	start_time();
  
  
	//Creates 16 threads, for now. INVESTIGATE HOW MANHY SHOULD BE MADE
  // Create threads for each traffic light
  pthread_t light_threads[4][4];
  for (int side = 0; side < 4; side++)
  {
      for (int direction = 0; direction < 4; direction++)
      {
          // Allocate memory for arguments
          LightArgs* args = malloc(sizeof(LightArgs));
          if (args == NULL) {
              perror("Failed to allocate memory for thread arguments");
              exit(EXIT_FAILURE);
          }
          args->side = side;
          args->direction = direction;
          args->intersection_mutex = &m;

          pthread_create(&light_threads[side][direction], NULL, manage_light, (void*)args);
      }
  }

  // Create the supply arrivals thread
  pthread_t supplier_thread;
  pthread_create(&supplier_thread, NULL, supply_arrivals, NULL);

	pthread_join(supplier_thread, NULL);

	// Wait until END_TIME
  while (get_time_passed() < END_TIME)
  {
      sleep(1);
  }


  // Nitin used: i: side && j: direction
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
      pthread_cancel(light_threads[i][j]);
			pthread_join(light_threads[i][j], NULL);
			}
	}

  // destroy semaphores
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      sem_destroy(&semaphores[i][j]);
    }
  }

  return 0;
}
