
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


#include <stdio.h>
#include <errno.h>
#include <string.h>
//#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080

int main()
{
    
    int socketFD=socket(AF_INET, SOCK_STREAM, 0);
    char *ip=" 	192.178.218.26";
    
    struct sockaddr_in address;
    address.sin_family=AF_INET;
    address.sin_port=htons(PORT);
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);
    printf("alert1\n");
    int result=connect(socketFD,  (struct sockaddr*)&address, sizeof address);
    printf("alert2\n");
    if(result==0)
    {
        printf("The connection was successful\n");
    }
    else
    {
        printf("It wasnt sucessful %d, %d\n", errno, strerror(errno));
    }
    return 0;
}