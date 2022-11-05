#ifndef _SERVER_H
#define _SERVER_H
#include <pthread.h>
#include <winsock.h>


#define MAX 1024
/*
Queue struct declaration
*/
typedef struct 
{
    char *buffer [MAX];
    int head, tail;
    int full, empty;
    pthread_mutex_t *mutex;
    pthread_cond_t *notFull, *notEmpty;
} queue;

typedef struct 
{
    fd_set serverFd;
    int sockectFd;
    int clientSokecket [MAX];
    int clientNum;
    pthread_mutex_t *clientMutex;
    queue *queue;
} server;

typedef struct 
{
    server *server;
    int clientFd;
} admin;

struct sockaddr_in serverAddr;

//Queue methods
queue *queue_ctor(void);
void queue_dtor (queue *);
void queue_push (queue *,char *);
char* queue_pop (queue *);

//Server methods
void chatInit (int);
void bind (struct sockaddr_in *serverAddr, int, long);
void removeClient (server *, int);

//Admin methods
void* adminInit (void *);
void* admin_SetUp (void *);
void* admin_message (void *);

#endif