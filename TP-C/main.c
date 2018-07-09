#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[150];
    char nomPrenom[150];
    char dateNaissance[20];
    char sexe;
    int nbEnfants;
    char enfants[260*4]; //record d'enfants pour un humain

}Personne;

Personne * ChargerPersonnes();
int countLineInFile(char * filename);
int charcount(char * filename);

int main()
{
    Personne *lesPersonnes;
    lesPersonnes = ChargerPersonnes;

    printf("%s\n", lesPersonnes[0].id);
    return 0;
}

Personne * ChargerPersonnes()
{
    char * line = malloc(charcount("personnes.csv") * sizeof(Personne));
    char * pch;
    int i,j = 0;
    i=0;
    Personne unePersonne;
    Personne lesPersonnes[countLineInFile("personnes.csv")];

    FILE* fichier = fopen("personnes.csv", "r");
    if(fichier != NULL)
    {
        while (fgets(line, charcount("personnes.csv") * sizeof(char), fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";"); //premiere fois pour trouver le delimiter

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        strcpy(unePersonne.id,pch);
                        //printf("id: %s\n", unePersonne.id);
                    case 1:
                        strcpy(unePersonne.nomPrenom,pch);
                    case 2:
                        strcpy(unePersonne.dateNaissance,pch);
                    case 3:
                        unePersonne.nbEnfants = atoi(pch);
                    case 4:
                        strcpy(unePersonne.enfants,pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }
            lesPersonnes[i] = unePersonne;
            i++;
            j=0;
        }
    }

    fclose(fichier);
    printf("over");
    return lesPersonnes;
}

int countLineInFile(char * filename) //retourne le nb de ligne d'un fichier
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

int charcount(char * filename) //retourne le nb de caractere de la plus grande ligne d'un fichier
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
