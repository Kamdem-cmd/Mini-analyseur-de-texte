#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define tailleMax 256

int main()
{
    FILE *fichier;
    char ligne[tailleMax];

    fichier = fopen("fichier.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    printf("\nContenu du fichier:\n");
    while (fgets(ligne, tailleMax, fichier) != NULL){
        printf("%s", ligne);
    }
    printf("\n...Mini-analyseur de texte ...\n");

    fclose(fichier);
    return (0);
}