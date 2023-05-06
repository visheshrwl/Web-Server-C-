// Vishesh Rawal
//
// TIET'26
//
// Project for PCR Tech

#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    //Define Address Structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    //Establish Socket
    sock = socket(domain, service , protocol);
    test_connection(sock);
    //Establish Network Connection
    connection = connect_to_network(sock, address);
    test_connection(connection);
}

void HDE::SimpleSocket::test_connection(int item_to_test)
{
    if(item_to_test < 0){
        perror('Failed to connect');
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in HDE::SimpleSocket::get_address(){
    return address;
}

int HDE::SimpleSocket::get_sock()
{
    return sock;
}

int HDE::SimpleSocket::get_connection()
{
    return connection;
}