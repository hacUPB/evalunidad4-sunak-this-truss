
#include <netinet/in.h>
#include <arpa/inet.h> //socket libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>

#ifndef _SERVER_H
#define _SERVER_H

#define MAX_CLIENTS 100
#define BUFFER_SZ 2048

static _Atomic unsigned int cli_count = 0;
static int uid = 10;

/* Client structure */
typedef struct{
	struct sockaddr_in address;
	int sockfd;
	int uid;
	char name[32];
} client_t;

client_t *clients[MAX_CLIENTS];

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void str_overwrite_stdout(); //libera el buffer del stream

void str_trim_lf (char* arr, int length); //determina el final de cada mensaje

void print_client_addr(struct sockaddr_in addr);

/* Add clients to queue */
void queue_add(client_t *cl);

/* Remove clients to queue */
void queue_remove(int uid);

/* Send message to all clients except sender */
void send_message(char *s, int uid);

/* Handle all communication with the client */
void *handle_client(void *arg);

#endif