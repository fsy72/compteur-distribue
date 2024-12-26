#include "common.h"

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    int counter;
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 address from text to binary
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    while(1) {
        // Receive counter
        read(sock, &counter, sizeof(counter));
        printf("Client received: %d\n", counter);
        
        // Increment counter
        counter++;
        sleep(1);
        
        // Send updated counter
        send(sock, &counter, sizeof(counter), 0);
        printf("Client sent: %d\n", counter);
    }
    
    return 0;
}