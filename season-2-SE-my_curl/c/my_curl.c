#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
// #include <openssl/ssl.h>
// #include <openssl/err.h>
// #include <openssl/x509.h>

#include "../h/my_string.h"

typedef struct
{
    struct sockaddr_in inform;
    struct addrinfo *data;
} sock_info;

#define MAX_BUFFER_SIZE 512

char **checking_url(char *str)
{
    int len = my_strlen(str);
    char **arr = calloc(sizeof(char *), 3);
    arr[0] = calloc(sizeof(char), len);
    arr[1] = calloc(sizeof(char), len);
    if (my_strncmp(str, "http://", 7) == 0)
    {
        int slash = my_strchr(&str[7], '/');
        if (slash == -1)
        {
            my_strcpy(arr[0], &str[7]);
            slash = my_strlen(arr[0]);
            arr[0][slash] = '/';
            return arr;
        }
        arr[0] = my_strncpy(arr[0], &str[7], slash);
        my_strcpy(arr[1], &str[slash + 7]);
        return arr;
    }
    errorMessage("Invalid URL format: missing 'http://'.\n");
    return arr;
}

in_addr_t address_ipv4(char *host_name, sock_info *info)
{
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((getaddrinfo(host_name, NULL, &hints, &(info->data))) != 0)
    {
        errorMessage("Could not resolve host: ");
        errorMessage(host_name);
        errorMessage("\n");
        return 0;
    }

    if (info->data == NULL)
    {
        errorMessage("No address\n");
        return 0;
    }
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)(info->data->ai_addr);
    info->inform.sin_addr = ipv4->sin_addr;
    return info->inform.sin_addr.s_addr;
}

void upload_sock_info(char *host_name, sock_info *info)
{
    if (address_ipv4(host_name, info) == 0)
    {
        errorMessage("ipv4 faulte\n");
        exit(EXIT_FAILURE);
    }
    char arr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(info->inform.sin_addr), arr, INET_ADDRSTRLEN);
    info->inform.sin_port = htons(80);
    info->inform.sin_family = AF_INET;
}

void request_and_response(int fd, char *request)
{
    if (write(fd, request, my_strlen(request)) < 0)
    {
        perror("Error writing to socket");
        return;
    }

    int len;
    char buffer[MAX_BUFFER_SIZE + 1];
    memset(buffer, 0, sizeof(buffer));

    while ((len = read(fd, buffer, MAX_BUFFER_SIZE)) > 0)
    {
        char *temp = strstr(buffer, "\r\n\r\n");

        if (temp)
        {
            printf("%s", temp + 4);
            break;
        }

        printf("%s", buffer);

        memset(buffer, 0, sizeof(buffer));
    }

    if (len < 0)
    {
        perror("Error reading from socket");
    }
}

int connect_to_socket(char **arr)
{
    int fd = 0;
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        errorMessage("error creating socket\n");
    }
    sock_info info;
    upload_sock_info(arr[0], &info);
    char *request = calloc(sizeof(char), MAX_BUFFER_SIZE);
    snprintf(request, MAX_BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n",
             arr[1], arr[0]);

    if (connect(fd, (struct sockaddr *)&info, sizeof(info)) == -1)
    {
        perror("Error connecting to server");
    }
    freeaddrinfo(info.data);
    request_and_response(fd, request);
    close(fd);
    free(request);
    // printf("Hello\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        errorMessage("Usage: ./my_curl <url>\n");
        return 1;
    }
    char **arr = checking_url(argv[1]);
    // printf("%s\n", arr[0]);
    connect_to_socket(arr);
    free(arr[0]);
    free(arr[1]);
    free(arr);
    return 0;
}