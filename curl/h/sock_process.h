#ifndef CURL_H_SOCK_PROCESS_H_
#define CURL_H_SOCK_PROCESS_H_

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "./structures.h"
#include "./my_string.h"

// Binding and connectiong process.
short socket_preparation(char* url_address);

// Pars url and return array with hostname and path.
char** extract_hostname_path(char* url);

// Formatting request to send.
char* request_format(char** host_path);

// Sending and recevie data process.
void sending_receive_info(short fd, char* request);

// Fill struct with information.
short filling_sock(char* host, sock_info* information);

// Process to connect IPv4.
in_addr_t geting_ipv4(char* host, sock_info* information);

//clean host name

void clear_host_path(char** host);

#endif