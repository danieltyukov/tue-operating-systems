#ifndef MESSAGES_H
#define MESSAGES_H

// define the data structures for your messages here

typedef struct {
    int request_id;
    int service_id;
    int data;
}req_queue_T21;

typedef struct {
    int request_id;
    int data;
}S1_queue_T21;

typedef struct{
    int request_id;
    int data;
}S2_queue_T21;

typedef struct{
    int request_id;
    int result;
}Rsp_queue_T21;

#endif
