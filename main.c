
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenti.h"

        int main() {
        Studente* studenti[MAX_STUDENTI];
        int numStudenti;

        leggiStudentiDaFile("registro.txt", studenti, &numStudenti);

        // Modifica i dati di uno degli studenti
        strcpy(studenti[0]->nome, "Gigi");
        strcpy(studenti[0]->cognome, "Riva");

        scriviStudentiSuFile("registro_modificato.txt", studenti, numStudenti);

        float mediaPrimoStudente = calcolaMediaStudente(studenti[0]);
        float mediaGenerale = calcolaMediaGenerale(studenti, numStudenti);
        printf("Media del primo studente: %.2f\n", mediaPrimoStudente);
        printf("Media generale: %.2f\n", mediaGenerale);

        // Pulizia della memoria
        for (int i = 0; i < numStudenti; i++)
            free(studenti[i]);

        return 0;
    }
