#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {Cryptage, Decryptage} t_sens;

int majuscule(char c) {
    return c > 65 && c < 90;
}

int minuscule(char c) {
    return c > 97 && c < 112;
}

char lettreDebut(char c) {
    if(minuscule(c) == 1){
        return 'a';
    }else{
        return 'A';

    }
}


int main(int argc, char *argv[]) {
    char   *msg   = NULL,
    *resul = NULL;
    int    cle;
    size_t lgMsg = 0;
    t_sens sens;
    
    printf("Entrez un message : ");
    getline(&msg, &lgMsg, stdin);
    
    printf("Entrez la clé (numérique) : ");
    scanf("%d", &cle);
    
    msg[strlen(msg) - 1] = '\0';

    resul = (char *) malloc(strlen(msg) + 1);
    resul[strlen(msg)] = '\0';
    if (strlen(msg)>0){
        int positionLettre;
        int valeurCle = cle % 26+26;
        
        for (int i = 0; i < strlen(msg); ++i) {
            if(majuscule(msg[i]) || minuscule(msg[i])){
                positionLettre = msg[i] - lettreDebut(msg[i]);
                resul[i] =(positionLettre + valeurCle)%26 + lettreDebut(msg[i]);
            }

            else{
                resul[i] = msg[i]; 
            } }

        }

        printf("\nRésultat : %s\n", resul);
        
        free(resul);

        return 0;

    }


    
