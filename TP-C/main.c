#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[150];
    char nomPrenom[150];
    char dateNaissance[150];
    char sexe;
    int nbEnfants;
    char enfants[260*4]; //record d'enfants pour un humain

}Personne;

Personne * ChargerPersonnes();
int countLineInFile(char * filename);
int charcount(char * filename);

int main()
{
    Personne lesPersonnes[10];

    Personne Personne1;
    strcpy(Personne1.id , "P001");
    strcpy(Personne1.dateNaissance , "21/06/1996");
    Personne1.nbEnfants = 3;
    Personne1.sexe = 'M';
    lesPersonnes[0] = Personne1;

    Personne Personne2;
    strcpy(Personne2.dateNaissance , "P003");
    strcpy(Personne2.dateNaissance , "21/06/1996");
    Personne2.nbEnfants = 3;
    Personne2.sexe = 'F';
    lesPersonnes[1] = Personne1;

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

void Menu()
{
    int choix;
    printf("\n*****************************************************************************\n");
    printf("Que souhaitez vous faire ?\n\n");
    printf(" - Ajouter une personne : tapez 1 \n");
    printf(" - Afficher larbre complet dune personne : tapez 2\n");
    printf(" - Obtenir des statistiques : tapez 3\n");
    printf(" - Rechercher des parents : tapez 4\n");
    printf("Cest a vous : ");
    scanf("%d", &choix);

    switch (choix)
    {
        case 1:
            AjoutPersonne();
            break;
        case 2:
            AfficherArbre();
            break;
        case 3:
            nbrPersSansEnfants();
            nbrMoyeEnf();
            nbrHetF();
            PersJeune();
            break;
        case 4:
            RechercheParents();
            break;
        default:
            printf("!! Votre saisie est incorrecte, veuillez reessayer !!");
            Menu();
          break;
    }
}



void nbrPersSansEnfants(Personne * tableau)
{
    tableau[i].enfants
    int i, compteur, taille;
    taille = sizeof(Personne);

    for(i = 0; i < taille; i++){
        if(UnePersonne[i]. == 0)
        {
            compteur =+ 1;
            printf("Il y a %d personnes, sans enfants", compteur);
        }
    }
}

void nbrMoyeEnf()
{
    int i, compteur, nbrdenfants, moyenne;
    taille = sizeof(Personne);


    for(i = 0; i < taille; i++){
        if(UnePersonne[i].enfants != 0)
        {
            compteur =+ 1;
            nbrdenfants = nbrdenfants + personne[i].enfants;
            moyenne = nbrdenfants/compteur;

            printf("Il y a %d personnes, sans enfants", compteur);
        }
        //printf("%d.%s\n", i, sp[i].name);
    }
}


void nbrHetF()
{
    int i, compteurH, compteurF, taille;
    taille = sizeof(Personne);


    for(i = 0; i < taille; i++){
        if(UnePersonne[i].sexe == 'H')
        {
            compteurH =+ 1;
        }
        if(personne[i].sexe == 'F')
        {
            compteurF =+ 1;
        }

        printf("Il y a %d homme(s) au total", compteurH);
        printf("Il y a %d femme(s) au total", compteurF);

    }
}

void PersJeune()
{
    int i, compteur;
    taille = sizeof(Personne);


    for(i = 0; i < taille; i++){
        char str[] = UnePersonne[i].dateNaissance;
        char *token = strtok(str, "/");

        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, "/");
        }

        if()
    }
}

/*
Nombre de personnes sans enfants - OK
 Nombre moyen d’enfants par personne - OK
 Quel est le nom et prénom de la personne la plus jeune ?
 Quel est le nom et prénom de la personne la plus agée ?
 Nombre d’hommes et de femmes - OK
*/
