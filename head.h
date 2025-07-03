#ifndef __HEAD_H__
#define __HEAD_H__

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include "function.c"

#define tailleMax 256

int remplirFichier(char *ligne, FILE *fichier);
int lireFichier(char *ligne, FILE *fichier);
int viderFichier(FILE *fichier);
int nombreCaractere(char *ligne, FILE *fichier);
int menu();

#endif