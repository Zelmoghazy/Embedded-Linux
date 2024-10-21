#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>



/*
    // (IPv4 only--see struct sockaddr_in6 for IPv6)
    // in -> Internet
    struct sockaddr_in {
        short sin_family;           // AF_INET 
        unsigned short sin_port;    // port number e.g. htons(3490) must be in Network Byte Order 
        struct in_addr sin_addr;    // destination address
        char sin_zero[8];           // should be memset to zeroes
    }

    struct in_addr {
        unsigned long s_addr;       // load with inet_pton() (presentation to network) converts an IP address in numbers-and-dots notation into struct in_addr
    };

    ----------------------------------------------------------------------------

    // (IPv6 only--see struct sockaddr_in and struct in_addr for IPv4)

    struct sockaddr_in6 {
        u_int16_t       sin6_family;   // address family, AF_INET6
        u_int16_t       sin6_port;     // port number, Network Byte Order
        u_int32_t       sin6_flowinfo; // IPv6 flow information
        struct in6_addr sin6_addr;     // IPv6 address
        u_int32_t       sin6_scope_id; // Scope ID
    };

    struct in6_addr {
        unsigned char   s6_addr[16];   // IPv6 address
    };

 */

// 9. HTTP Server
void http_server() 
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[30000] = {0};
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        ssize_t valread = read(new_socket, buffer, 30000);
        if (valread < 0) {
            perror("read");
            close(new_socket);
            continue;
        }
        
        char *http_response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
        
        send(new_socket, http_response, strlen(http_response), 0);
        printf("HTTP response sent\n");
        
        close(new_socket);
    }
}