
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
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 2000
#define IP_ADDR "46.62.213.203"
int main(int argc, char **argv)
{
    int socketFD=socket(AF_INET, SOCK_STREAM, NULL);
    
    struct sockaddr_in address;
    address.sin_family=AF_INET;
    address.sin_port=PORT;
    address.sin_addr.s_addr=
    connect(socketFD, &address, sizeof(address));
    return EXIT_SUCCESS;
}