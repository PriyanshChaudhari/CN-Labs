#include <stdio.h>
#include <netdb.h>

int main() {
    struct protoent *proto;
    
    proto = getprotobyname("tcp");
    
    if (proto != NULL) {
        printf("Protocol name: %s\n", proto->p_name);
        printf("Protocol number: %d\n", proto->p_proto);
    } else {
        printf("Protocol not found.\n");
    }
    
    return 0;
}
