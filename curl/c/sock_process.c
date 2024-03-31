#include "../h/sock_process.h"
#include <stdio.h>
#include <stdlib.h>

char** extract_hostname(char* url_text) {
    short url_length = my_strlen(url_text);
    short flag = 0;
    short host_length = 0;
    char** host_path = (char**)malloc(sizeof(char*) * 2);
    host_path[0] = calloc((url_length + 1), sizeof(char));
    for(short i = 0; i < url_length; i++) {
        if(url_text[i] == '/' && url_text[i - 1] == '/') flag = 1;
        else if(flag == 1) {
            host_path[0][host_length++] = url_text[i];
            if(url_text[i + 1] == '/') flag = 2;
        }
        else if (flag == 2) {
            host_path[1] = my_strdup(&url_text[i]);
            break;
        }
    }
    if(host_path[0][0] == '\0') my_strcpy(host_path[0], url_text);
    if(host_path[1] == NULL) host_path[1] = my_strdup("/");
    return host_path;
}

in_addr_t get_ipv4(char* host, sock_info* information) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    short status = getaddrinfo(host, "http", &hints, &(information->data));
    if(status != 0) error("nodename nor servname provided, or not known\n");
    if(information->data == NULL) error("No address found for the given hostname.\n");
    struct sockaddr_in* ipv4 = (struct sockaddr_in*)(information->data->ai_addr);
    information->inform.sin_addr = ipv4->sin_addr;
    return information->inform.sin_addr.s_addr;
}

short fill_socket(char* host, sock_info* information) {
    in_addr_t addr = get_ipv4(host, information);
    if(addr == 0) error("Failed to retrieve the IPv4 address.\n");
    char ip_address[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(information->inform.sin_addr), ip_address, INET_ADDRSTRLEN);
    information->inform.sin_port = htons(80);
    information->inform.sin_family = AF_INET;
    return 0;
}

char* request_formatting(char** host_path) {
    char* request_form[3] = {"GET ", " HTTP/1.1\r\nHost: ", "\r\n\r\n"};
    short length = my_strlen(host_path[1]) + my_strlen(host_path[0]);
    length += my_strlen(request_form[0]) + my_strlen(request_form[1]) + my_strlen(request_form[2]);
    char* request = calloc(length + 1 , sizeof(char));
    my_strcpy(request, request_form[0]);
    my_strcpy(request, host_path[1]);
    my_strcpy(request, request_form[1]);
    my_strcpy(request, host_path[0]);
    my_strcpy(request, request_form[2]);
    return request;
}

void send_get_data(int fd, char* request) {
    write(fd, request, my_strlen(request));
    char data[4097] = {0};
    char* head = NULL;
    short flag = 0;
    short quantity = 0;
    short length = 0;
    while(1) {
        fill_null(data, 4096);
        quantity = read(fd, data, 4096);
        if(flag == 0) {
            if((head = strstr(data, "\r\n\r\n"))) {
                head += 4;
                write(1, head, my_strlen(head));
                flag = 1;
            }
        }
        else {
            length++;
            write(1, data, quantity);
        }
        if(quantity < 4096) break;
    }
    if(length > 0) write(1, data, my_strlen(data));
    free(request);
    close(fd);
}

void free_host(char** host) {
    for(short i = 0; i < 2; i++) free(host[i]);
    free(host);
}

short preparation(char* url_text) {
    char** host_path = extract_hostname(url_text);
    short fd = 0;
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) error("Socket fault\n");
    sock_info information;
    fill_socket(host_path[0], &information);
    char* request = request_formatting(host_path);
    if((connect(fd, (struct sockaddr*)&(information.inform), sizeof(information.inform))) < 0) error("Connection failture\n");
    freeaddrinfo(information.data);
    free_host(host_path);
    send_get_data(fd, request);
    return 0;
}