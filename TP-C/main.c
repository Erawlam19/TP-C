#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char id[150];
    char nomPrenom[150];
    char dateNaissance[20];
    char sexe;
    int nbEnfants;
    char enfants[];

}Personne;

Personne * ChargerPersonnes();
int countLineInFile(char * filename);
int charcount(char * filename);

int main()
{
    Personne * lesPersonnes = malloc(countLineInFile("personnes.csv") * sizeof(Personne));
    lesPersonnes = ChargerPersonnes();
    return 0;
}

Personne * ChargerPersonnes()
{
    char * line = malloc(charcount("personnes.csv") * sizeof(char));
    char * pch;
    int i,j = 0;
    Personne unePersonne;
    Personne * lesPersonnes = malloc(countLineInFile("personnes.csv") * sizeof(Personne));

    FILE* fichier = fopen("personnes.csv", "r");
    if(fichier != NULL)
    {
        while (fgets(line, charcount("personnes.csv") * sizeof(char), fichier))
        {
            printf("ok1");
            char* tmp = strdup(line);
            pch = strtok (tmp,";"); //premiere fois pour trouver le delimiter

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        strcpy(unePersonne.id,pch);
                    case 1:
                        strcpy(unePersonne.nomPrenom,pch);
                    case 2:
                        strcpy(unePersonne.dateNaissance,pch);
                    case 3:
                        unePersonne.nbEnfants = atoi(pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }

            lesPersonnes[i] = unePersonne;

            free(tmp);
            i++;
            j=0;
        }
    }

    fclose(fichier);
    return lesPersonnes;
}

int countLineInFile(char * filename)
{
    int count = 0;
    char line[1024];
    FILE* fichier = fopen(filename, "r");
    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            count++;
        }
    }
    return count;
}

int charcount(char * filename)
{
    FILE *fin;
    fin = fopen(filename, "r" );
    int c, count;

    count = 0;
    for( ;; )
    {
        c = fgetc( fin );
        if( c == EOF || c == '\n' )
            break;
        ++count;
    }
    fclose(fin);
    return count;
}
