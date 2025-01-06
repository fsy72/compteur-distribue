#include "common.h"

int main() {
    
    struct sockaddr_in addrserveur, addrclient;
    int socketserveur = socket(AF_INET, SOCK_STREAM, 0);

    memset(&addrserveur, 0, sizeof(struct sockaddr_in));
    addrserveur.sin_family = AF_INET;
    addrserveur.sin_port = htons(PORT);
    addrserveur.sin_addr.s_addr = INADDR_ANY;

    int resultat = bind(socketserveur, (struct sockaddr *)&addrserveur, sizeof(addrserveur));
    if(resultat == -1){
        perror("failed");
        exit(-1);
    }
    if(listen(socketserveur, 1) == -1){
        perror("failed");
        exit(-1);
    }

    printf("Server lit sur le port %d...\n", PORT);

    int taille = sizeof(addrserveur);
    int acceptClient = accept(socketserveur, (struct sockaddr *)&addrserveur, &taille);
    if(acceptClient == -1){
        perror("failed");
        exit(-1);
    }

    int compteur = 0;
    while(1) {
        send(acceptClient, &compteur, sizeof(compteur), 0);
        // printf("Serveur envoie %d\n", compteur);
        recv(acceptClient, &compteur, sizeof(compteur), 0);
        printf("Serveur reçoit %d\n", compteur);
        compteur++;
        sleep(1);
    }

    return 0;
}