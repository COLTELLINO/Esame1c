// studenti.c

#include <stdio.h>
#include <stdlib.h>
#include "studenti.h"

float calcolaMediaStudente(Studente* studente) {
    float somma = 0;
    for (int i = 0; i < MAX_ESAMI; i++)
        somma += studente->voti[i];
    return somma / MAX_ESAMI;
}

float calcolaMediaGenerale(Studente** studenti, int numStudenti) {
    float somma = 0;
    for (int i = 0; i < numStudenti; i++)
        somma += calcolaMediaStudente(studenti[i]);
    return somma / numStudenti;
}

void leggiStudentiDaFile(char* nomeFile, Studente** studenti, int* numStudenti) {
    FILE* file = fopen(nomeFile, "r");
    if (file == NULL)
        return;
    *numStudenti = 0;
    while (!feof(file) && *numStudenti < MAX_STUDENTI) {
        Studente* studente = (Studente*)malloc(sizeof(Studente));
        fscanf(file, "%s %s %d", studente->nome, studente->cognome, &studente->matricola);
        for (int i = 0; i < MAX_ESAMI; i++)
            fscanf(file, "%d", &studente->voti[i]);
        studenti[(*numStudenti)++] = studente;
    }
    fclose(file);
}


void scriviStudentiSuFile(char* nomeFile, Studente** studenti, int numStudenti) {
    FILE* file = fopen(nomeFile, "w");
    if (file == NULL)
        return;
    for (int i = 0; i < numStudenti; i++) {
        fprintf(file, "%s %s %d", studenti[i]->nome, studenti[i]->cognome, studenti[i]->matricola);
        for (int j = 0; j < MAX_ESAMI; j++)
            fprintf(file, " %d", studenti[i]->voti[j]);
        fprintf(file, "\n");
    }
    fclose(file);
}
