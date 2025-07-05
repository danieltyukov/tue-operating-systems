#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

// declare a mutex and a condition variable, and they are initialized as well
static pthread_mutex_t      mutex          = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t       condition      = PTHREAD_COND_INITIALIZER;

/*-------------------------------------------------------------------------*/

static void *
my_condition_thread (void * arg)
{
    pthread_mutex_lock (&mutex);
    printf ("                    thread: enter CS\n");
    sleep (4);
       
    printf ("                    thread: wait...\n");
    pthread_cond_wait (&condition, &mutex);
    printf ("                    thread: signalled\n");
    
    sleep (2);
    printf ("                    thread: leave CS\n");
    pthread_mutex_unlock (&mutex);
    return (arg);
}

static void
condition_test (void)
{
    /* note: this test case is only to validate that condition variables really work
     * it doesn't give the proper usage of condition variables for the assignments
     * (for proper usage: see lecture slides and the prodcons.c template file)
     */
    pthread_t   my_thread;

    pthread_create (&my_thread, NULL, my_condition_thread, NULL);
    sleep (2);
    
    printf ("willing to enter...\n");
    pthread_mutex_lock (&mutex);
    printf ("enter CS\n");
    sleep (2);
       
    printf ("signal\n");
    pthread_cond_signal (&condition);
    
    sleep (2);
    pthread_mutex_unlock (&mutex);
    printf ("leave CS\n");
    
    pthread_join (my_thread, NULL);
}


/*-------------------------------------------------------------------------*/

int main (void)
{
    condition_test();
    
    return (0);
}

