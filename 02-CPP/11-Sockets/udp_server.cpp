
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


// 3. UDP Server
void udp_server() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;
    
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);
    
    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    socklen_t len = sizeof(cliaddr);
    int n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, 
                     (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    std::cout << "Client : " << buffer << std::endl;
    const char *hello = "Hello from server";
    sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM,
           (const struct sockaddr *)&cliaddr, len);
    std::cout << "Hello message sent." << std::endl;
}

// 4. UDP Client
void udp_client() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;
    
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    const char *hello = "Hello from client";
    sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM,
           (const struct sockaddr *)&servaddr, sizeof(servaddr));
    std::cout << "Hello message sent." << std::endl;
    
    socklen_t len = sizeof(servaddr);
    int n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL,
                     (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    std::cout << "Server : " << buffer << std::endl;
    
    close(sockfd);
}