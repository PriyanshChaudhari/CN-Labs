#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

void getHostInfo(char* hostname) {
    struct hostent *host = gethostbyname(hostname);
    if (host != NULL) {
        printf("Host name: %s\n", host->h_name);
        printf("IP Address: %s\n", inet_ntoa(*((struct in_addr*) host->h_addr_list[0])));
    } else {
        printf("Host not found.\n");
    }
}

void getProtocolInfo(char* protocolname) {
    struct protoent *proto = getprotobyname(protocolname);
    if (proto != NULL) {
        printf("Protocol name: %s\n", proto->p_name);
        printf("Protocol number: %d\n", proto->p_proto);
    } else {
        printf("Protocol not found.\n");
    }
}

void getServiceInfo(char* servicename, char* protocol) {
    struct servent *serv = getservbyname(servicename, protocol);
    if (serv != NULL) {
        printf("Service name: %s\n", serv->s_name);
        printf("Port number: %d\n", ntohs(serv->s_port));
    } else {
        printf("Service not found.\n");
    }
}

int main() {
    getHostInfo("msubaroda.ac.in");
    getProtocolInfo("tcp");
    getServiceInfo("https", "tcp");
    return 0;
}