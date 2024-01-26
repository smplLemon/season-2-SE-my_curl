Task
The task of the provided code is to implement a simplified version of the curl command-line tool in C. It allows users to send HTTP GET requests to a specified URL and display the server's response.

The challenges involved in this task include:

Parsing the provided URL to extract the hostname and resource path.
Establishing a TCP socket connection to the server.
Generating an HTTP GET request with appropriate headers.
Handling the server's response and displaying it to the user.
Implementing error handling to manage potential issues during the process.

Description
The provided code solves the problem by:

Defining custom string manipulation functions in my_string.h.
Parsing the provided URL and extracting the hostname and resource path in checking_url() function.
Resolving the IPv4 address of the hostname and setting up socket information in address_ipv4() and upload_sock_info() functions.
Generating an HTTP GET request with appropriate headers in connect_to_socket() function.
Establishing a TCP socket connection to the server and handling the server's response in connect_to_socket() and request_and_response() functions.
Implementing basic error handling to manage potential issues during the process.

Installation
To install and compile the project:

Navigate to the directory containing the source files.
Use the provided Makefile by running the command:

➜  season-2-SE-my_curl git:(main) ✗ make
➜  season-2-SE-my_curl git:(main) ✗

Usage
To use the program: 

Compile the project using the provided Makefile.
Run the compiled binary my_curl followed by the URL you want to request:

➜  season-2-SE-my_curl git:(main) ✗ ./my_curl http://example.com