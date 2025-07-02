#include "head.h"

#define tailleMax 256

int menu(){
    int choix;

    printf("1. Remplire le fichier\n");
    printf("2. Lire le contenu du fichier\n");
    printf("3. Effacer le contenu du fichier\n");
    printf("4. Nombre total de caractere\n");
    printf("99. Quitter\n");

    printf("votre choix: ");
    scanf("%d", &choix);

    return (choix);
}

int remplirFichier(char *ligne, FILE *fichier){
    char saisie[tailleMax -2];

    printf("Entrer une nouvelle ligne: ");
    scanf("%c", &saisie);
    fgets(saisie, sizeof(saisie), stdin);

    //Ecriture
    fichier = fopen("fichier.txt", "a");
    if(fichier == NULL){
        fputs("erreur lors de l'ouverture du fichier\n", stderr);
        return EXIT_FAILURE;
    }

    if (fputs(saisie, fichier) == EOF){
    fputs("Erreur lors de l'ecriture dans le fichier", stderr);
    return EXIT_FAILURE;
    }
    fclose(fichier);

    return (0);
}

int lireFichier(char *ligne, FILE *fichier){

    //Lecture
    fichier = fopen("fichier.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    printf("Contenu du fichier:\n");
    while (fgets(ligne, tailleMax, fichier) != NULL){
        printf("%s", ligne);
    }

    fclose(fichier);
}

int viderFichier(FILE *fichier){
    //Effacer
    fichier = fopen("fichier.txt", "w");
    printf("fichier desormais vide.\n");

    fclose(fichier);
    return (0);
}

int nombreCaractere(char *ligne, FILE *fichier){
    int nbreCaracter = 0;
    int nbreligne = 0;

    fichier = fopen("fichier.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    while (fgets(ligne, tailleMax, fichier) != NULL){
        nbreligne += 1;
        nbreCaracter += strlen(ligne);
        if(nbreCaracter > 0) nbreCaracter--;
    }
    printf("nombre de ligne: %d\n", nbreligne);

    fclose(fichier);
    return nbreCaracter;
}