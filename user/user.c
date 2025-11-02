
/*
SIALPI_SERVER
Copyright (C) 2025 Alexinom91

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//SOCKET
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 80

int createTCPIpv4Socket();
struct sockaddr_in *createIPv4Address(char *ip, unsigned int port);
int main()
{
    
    int socketFD=createTCPIpv4Socket();
    
    char *ip="142.251.140.110";
    struct sockaddr_in *address=createIPv4Address(ip, PORT);
    
    //printf("alert1\n");
    int result=connect(socketFD,  (struct sockaddr*)address, sizeof(*address));
    //printf("alert2\n");
    if(result==0)
    {
        printf("The connection was successful\n");
    }
    else
    {
        printf("It wasnt sucessful %d, %d\n", errno, strerror(errno));
        //topperia missile
        close(socketFD);
        return 1;
    }


    char *message;
    message="GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socketFD, message, strlen(message), 0);
    char buff[1024];

    recv(socketFD, buff, 1024, 0);


    printf("Response was %s\n",buff);
    return 0;
}

int createTCPIpv4Socket()
{
    return socket(AF_INET, SOCK_STREAM, 0);
}

struct sockaddr_in* createIPv4Address(char *ip, unsigned int port)
{
    struct sockaddr_in* address=malloc(sizeof(struct sockaddr_in));
    //char *ip="142.251.140.110";
    address->sin_family=AF_INET;
    address->sin_port=htons(port);
    inet_pton(AF_INET, ip, &address->sin_addr.s_addr);

    return address;
}