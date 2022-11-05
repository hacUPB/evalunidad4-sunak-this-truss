#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <winsock.h>
#include <pthread.h>
#include "server.h"

void chatInit (int socketFd)
{

}

void bind (struct sockaddr_in *serverAddr, int socketFd, long port)
{

}

void removeClient (server * s, int clientSocket)
{

}

queue *queue_ctor(void)
{

}

void queue_dtor (queue * q)
{

}

void queue_push (queue * q,char * msg)
{

}

char* queue_pop (queue * q)
{

}

void* adminInit (void * data)
{

}

void* admin_SetUp (void * chv)
{

}

void* admin_message (void * data)
{
    
}
