#include "head.h"

#define tailleMax 256
#define tailleLettre 26

int menu(){
    int choix;

    printf("1. Remplire le fichier\n");
    printf("2. Lire le contenu du fichier\n");
    printf("3. Effacer le contenu du fichier\n");
    printf("4. Analyse du texte\n");
    printf("5. Occurence des lettres\n");
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
    int nbreMot = 0;

    // Precaution de lecture de fichier, signale l'erreur en cas d'echec
    fichier = fopen("fichier.txt", "r");
    if(fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    while(fgets(ligne, tailleMax, fichier) != NULL){
        // nombre de ligne
        nbreligne += 1;

        int i = 0;
        while(ligne[i] != '\0'){
            // nombre de mot
            if(ligne[i] != ' ' && ligne[i+1] == ' ' || ligne[i] != ' ' && ligne[i+1] == '\0') nbreMot += 1;

            //nombre de caractere
            if(ligne[i] != ' ' && ligne[i] != '\n') nbreCaracter ++;
            i++;
        }
    }
    //fermeture du fichier
    fclose(fichier);

    printf("nombre de mot: %d\n", nbreMot);
    printf("nombre de ligne: %d\n", nbreligne);

    return nbreCaracter;
}

int countLettre(FILE *fichier){
    int caractere;
    int occurrences[tailleLettre] = {0};
    int i = 0;

    fichier = fopen("fichier.txt", "r");

    // Vérifier si l'ouverture du fichier a réussi
    if(fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return (-1);
    }

    while((caractere = fgetc(fichier)) != EOF){

        caractere = tolower(caractere);

        if (isalpha(caractere)) {
            // Calculer l'indice correspondant dans le tableau (0 pour 'a', 1 pour 'b', etc.)
            int index = caractere - 'a';
            // Incrémenter le compteur pour cette lettre
            occurrences[index]++;
        }

    }

    fclose(fichier);

    printf("\nOccurrences de chaque lettre (insensible a la casse) :\n");
    for (i; i < tailleLettre; i++) {
        if(occurrences[i] > 0){
            // Convertir l'indice en lettre correspondante
            char lettre = 'a' + i;
            printf("'%c' : %d\n", lettre, occurrences[i]);
        }
    }

    return (0);
}