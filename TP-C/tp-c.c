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


}Personne;

int main()
{
    Personne * Tableau[30];
    Personne Pers;
    strcpy(Pers.id ,"P001");
    strcpy(Pers.nomPrenom ,"Jean Jacques");
    Pers.sexe = 'H';
    Pers.nbEnfants = 6;

    Tableau[0] = Pers.id;

    print("%d", Tableau[0].id);

    return 0;
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
        if(UnePersonne[i].enfants == 0)
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
