#include "common.h"

int main() {
    
    struct sockaddr_in addrserveur;
    int socketclient = socket(AF_INET, SOCK_STREAM, 0);

    memset(&addrserveur, 0, sizeof(struct sockaddr_in));
    addrserveur.sin_family = AF_INET;
    addrserveur.sin_port = htons(PORT);
    addrserveur.sin_addr.s_addr = inet_addr("172.18.99.149");

    int connecter = connect(socketclient, (struct sockaddr *)&addrserveur, sizeof(addrserveur));
    if(connecter == -1){
        perror("failed");
        exit(-1);
    }

    int compteur;
    while(1) {
        recv(socketclient, &compteur, sizeof(compteur), 0);
        printf("Client reçoit %d\n", compteur);
        compteur++;
        sleep(1);
        send(socketclient, &compteur, sizeof(compteur), 0);
        // printf("Client envoie %d\n", compteur);
    }

    return 0;
}