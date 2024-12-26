/*
    Ecrire un programme client/serveur de compteur distribué avec trois fichiers 
    serveur.c qui implémente le serveur qui initialise le compteur à 0
    client.c qui implémente le coté client 
    common.h qui contient les différents fichiers


    Le fonctionnement est le suivant
    1. Le serveur initialise le compteur à 0 et l'envoie au client
    2. Le client reçoit le compteur, l'incrémente, attends 1seconde et le renvoie au serveur
    3. Le serveur le reçoit, l'incrémente, attend une seconde et l'envoie au serveur 
    4. Retourner à l'étape 2
*/

#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

#endif