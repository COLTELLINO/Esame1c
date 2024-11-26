// studenti.h

#define MAX_NOME 50
#define MAX_COGNOME 50
#define MAX_ESAMI 5
#define MAX_STUDENTI 100

typedef struct {
    char nome[MAX_NOME];
    char cognome[MAX_COGNOME];
    int matricola;
    int voti[MAX_ESAMI];
} Studente;

float calcolaMediaStudente(Studente* studente);
float calcolaMediaGenerale(Studente** studenti, int numStudenti);
void leggiStudentiDaFile(char* nomeFile, Studente** studenti, int* numStudenti);
void scriviStudentiSuFile(char* nomeFile, Studente** studenti, int numStudenti);
