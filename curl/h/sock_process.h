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
short preparation(char* url_text);

// Pars url and return array with hostname and path.
char** extract_hostname(char* url);

// Formatting request to send.
char* request_formatting(char** host_path);

// Sending and recevie data process.
void send_receive_data(int fd, char* request);

// Fill struct with information.
short fill_socket(char* host, sock_info* information);

// Process to connect IPv4.
in_addr_t get_ipv4(char* host, sock_info* information);

#endif