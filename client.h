#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#ifndef _CLIENT_H
#define _CLIENT_H

#define LENGTH 2048

// Global variables
volatile sig_atomic_t flag = 0;
int sockfd = 0;
char name[32];

void str_overwrite_stdout();

void str_trim_lf (char* arr, int length);

void catch_ctrl_c_and_exit(int sig);

void send_msg_handler();

void recv_msg_handler();

#endif