#include "head.h"


int main()
{
    FILE *fichier;
    char ligne[tailleMax];
    int choix;

    printf("\n...Mini-analyseur de texte ...\n");
    while(choix != 99){
        choix = menu();
    
        switch (choix)
        {
        case 1:
            remplirFichier(ligne, fichier);
            break;
        case 2:
            lireFichier(ligne, fichier);
            break;
        case 3:
            viderFichier(fichier);
            break;
        default:
            break;
        }
    }

   return (0);
}
