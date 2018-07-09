#include <stdio.h>
#include <stdlib.h>
void ChargerPersonnes();

typedef struct
{
    char id[150]
    char nomPrenom[150]
    char sexe;
    char enfants[];

}Personne;

int main()
{

    return 0;
}

void ChargerPersonnes()
{
    char line[1024];
    char * pch;
    int i,j = 0;
    Client unClient;

    FILE* fichier = fopen("personnes.csv", "r");
    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";"); //premiere fois pour trouver le delimiter

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        unClient.id = atoi(pch);
                    case 1:
                        strcpy(unClient.nom,pch);
                    case 2:
                        strcpy(unClient.prenom,pch);
                    case 3:
                        strcpy(unClient.profession,pch);
                    case 4:
                        strcpy(unClient.telephone,pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }

            if(unClient.id == id)
            {
                fclose(fichier);
                return unClient;
            }

            free(tmp);
            i++;
            j=0;
        }
    }

    fclose(fichier);

    //Si aucun client n'esst trouvé, on met toutes les valeurs de client à 0, pour ne pas retourner le dernier de la liste
    unClient.id = 0;
    strcpy(unClient.nom, "0");
    strcpy(unClient.prenom, "0");
    strcpy(unClient.profession, "0");
    strcpy(unClient.telephone, "0");
    return unClient;
}
