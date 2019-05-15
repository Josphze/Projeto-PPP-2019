#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "locais.h"
#define cem 100
#define cinq 50
#define tele 9

nodeptr login(nodeptr first,Local placesptr){

    char *nome= malloc(cinq*sizeof(char));
    nodeptr aux;


    while (1){
        aux = first;

        printf("\n...................... Login .....................\n.......... Escreva quit para regressar ...........\n\n");
        printf("Nome de Utilizador: ");
        fgets(nome,cinq,stdin);
        fflush(stdin);
        nome=strtok(nome,"\n");

        if (strcmp(nome,"quit")==0)
            return NULL;

        while(aux->next != NULL){
            printf("/%s/%s/",nome,aux->name);
            if (strcmp(nome,aux->name)==0){
                preferedfile("users.txt",first,placesptr);
                return aux;

            }
            aux=aux->next;
        }

        printf("\nNome de Utilizador Nao Encontrado...\n");
    }
}

nodeptr regist(nodeptr first){

    char *name= malloc(cinq*sizeof(char));
    char *adress= malloc(cem*sizeof(char));
    char *date= malloc(cinq*sizeof(char));
    char *phone= malloc(tele*sizeof(char));
    nodeptr aux;
    int num = 0;



    while (num == 0){
        aux=first;
        num = 1;
        printf("\n.......... Inscricao de Novo utilizador ..........\n.......... Escreva quit para regressar ...........\n\n");

        printf("Nome de Utilizador: ");
        fgets(name,cinq,stdin);
        fflush(stdin);
        name=strtok(name,"\n");

        if (strcmp(name,"quit")==0)
            return NULL;

        while(aux->next != NULL){
            if (strcmp(name,aux->name)==0){                               /* Ve se o nome de utilizador ja existe*/
                printf("a");
                system("cls");
                printf("\n\t  ###### Utilizador em uso ######\n\n");
                num = 0;
            }
            aux=aux->next;
        }
    }

    printf("Morada: ");
    fgets(adress,cem,stdin);
    fflush(stdin);
    adress=strtok(adress,"\n");

    if (strcmp(adress,"quit")==0)
            return NULL;

    printf("Data de Nascimento: ");
    fgets(date,cinq,stdin);
    fflush(stdin);
    date=strtok(date,"\n");

    if (strcmp(date,"quit")==0)
            return NULL;

    printf("Telefone: ");
    fgets(phone,tele,stdin);
    fflush(stdin);
    phone=strtok(phone,"\n");

    if (strcmp(phone,"quit")==0)
            return NULL;

    while(aux->next != NULL){
            aux=aux->next;
    }

    insere(aux,name,adress,date,phone);

    return aux;
}

nodeptr menulogin(nodeptr first, Local placesptr){

    int num=0;
    nodeptr userptr;

    while (num == 0){
        printf("\n.......................");
        printf("\n\t -Menu-");
        printf("\n1 - Login");
        printf("\n2 - Register");
        printf("\n.......................\n");
        printf("\nEscolha: ");

        if (scanf("%d",&num) == 0 || (num < 1 || num > 2)) {   /* Caso o Utilizador nao Escolha uma das 2 opcoes */
            fflush(stdin);
            system("cls");
            num = 0;
        }
    }

    fflush(stdin);
    system("cls");

    switch (num){

            case 1:
                userptr=login(first,placesptr);break;
            case 2:
                userptr=regist(first);break;
    }

    return userptr;
}

int printadados(nodeptr userptr){
    printf("\n*************************\n");
    printf("Nome de Utilizador: %s\n",userptr->name);
    printf("Morada: %s\n",userptr->adress);
    printf("Data de Nascimento: %s\n",userptr->date);
    printf("Telefone: %s\n",userptr->phone);
    printf("*************************\n");
    return 2;
}

void logout(nodeptr first){
    nodeptr aux=first;
    int counter=1;
    FILE *f=fopen("users.txt","w");
    while (aux->next!=NULL){
        if (counter==1){
            fprintf(f,"\n");
            fprintf(f,"%s\n",aux->name);
            fprintf(f,"%s\n",aux->adress);
            fprintf(f,"%s\n",aux->date);
            fprintf(f,"%s",aux->phone);
        }
        else{
            fprintf(f,"\n\n");
            fprintf(f,"%s\n",aux->name);
            fprintf(f,"%s\n",aux->adress);
            fprintf(f,"%s\n",aux->date);
            fprintf(f,"%s",aux->phone);
        }
        counter=0;
        aux=aux->next;
    }
    fclose(f);
    printf("\n     -Logged out com sucesso-\n");
}

int menualtera(nodeptr userptr,nodeptr first){

    int num=0;

    printf("\n.........................");
    printf("\n     -Alterar Dados-\n");
    printf("\n1 - Utilizador");
    printf("\n2 - Morada");
    printf("\n3 - Data de Nascimento");
    printf("\n4 - Telefone");
    printf("\n5 - Back");
    printf("\n.........................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 5)){  /* Caso o Utilizador nao Escolha uma das opcoes */
        fflush(stdin);
        system("cls");
        return 5;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 6; /*Altera user*/
            case 2:
                return 7; /*Altera morada*/
            case 3:
                return 8; /*Altera data*/
            case 4:
                return 9; /*Altera phone*/
            case 5:
                return 2; /* Vai para o perfil */

    }
    return 100;
}

int perfil(nodeptr userptr, nodeptr first){

    int num=0;

    printf("\n.........................");
    printf("\n\t -Perfil-\n");
    printf("\n1 - Mostrar dados");
    printf("\n2 - Alterar dados");
    printf("\n3 - Gravar e Logout");
    printf("\n4 - Back");
    printf("\n.........................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 4)){   /* Caso o Utilizador nao Escolha uma das 4 opcoes */
        fflush(stdin);
        system("cls");
        return 2;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 10; /* Mostrar os dados */
            case 2:
                return 5; /*logout*/
            case 3:
                return 0; /*alterar dados*/
            case 4:
                return 1; /*Back to main menu*/
    }
    return 100;
}

int escolhalocais(nodeptr userptr, Local placesptr){
    int num=0,i=1,count=1,prefcount=0;
    Local localaux=placesptr;
    printf("\n..................................");
    printf("\n\t -Locais Preferidos-");
    printf("\n..................................");
    printf("\n Escolha os seus Locais favoritos");
    printf("\n..................................");

    while(localaux->abcnext!=NULL){
        if (localaux->prefered==0)
            printf("\n%d - %s",i++,localaux->local);
        else if (localaux->prefered==1)
            printf("\n%d - %s *Choosen*",i++,localaux->local);
        localaux=localaux->abcnext;
    }
    printf("\n%d - Back",i++);
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > i)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        return 31;
    }

    if (num==i-1){              /* BACK OPTION */

        fflush(stdin);
        system("cls");
        return 3;
    }

    localaux=placesptr;
    while(localaux->abcnext!=NULL){
        if (localaux->prefered==1)
            prefcount++;
        localaux=localaux->abcnext;
    }

    localaux=placesptr;
    while(count!=num){              /* DISCOVER WHAT LOCAL IT IS */
        count++;
        localaux=localaux->abcnext;
    }


    if (localaux->prefered==1){         /* WAS IT ALREADY SELECTED? */
        fflush(stdin);
        system("cls");
        printf("Esse Local ja foi escolhido...");
        return 31;
    }

    if (prefcount==3){                   /* LIMIT OF 3 LOCALS PER PERSON */
        printf("Maximo de Locais Escolhidos (3) !");
    }

    localaux->prefered=1;
    localaux->pop++;

    prefcount++;

    fflush(stdin);
    system("cls");
    printf("Local Escolhido Numero %d: %s",prefcount,localaux->local);
    return 31;

}

int escolhapdis(nodeptr userptr, Local placesptr){
    int num=0,i=1,count=1,prefcount=0;
    Local localaux=placesptr;
    Pdi pdiaux;
    printf("\n..................................");
    printf("\n\t -PDI's Preferidos-");
    printf("\n..................................");
    printf("\n  Escolha os seus PDI favoritos");
    printf("\n..................................");

    while(localaux->abcnext!=NULL){
        pdiaux=localaux->pontos;
        while(pdiaux->abcnext!=NULL){
            if (pdiaux->prefered==0)
                printf("\n%2d - %s, %s",i++,pdiaux->nome,localaux->local);
            else if (pdiaux->prefered==1)
                printf("\n%2d - %s, %s  *Choosen*",i++,pdiaux->nome,localaux->local);
            pdiaux=pdiaux->abcnext;
        }
        localaux=localaux->abcnext;
    }
    return 100;
}

int preferencias(nodeptr user, Local place){
    int num=0;

    printf("\n..................................");
    printf("\n\t -Preferencias-\n");
    printf("\n1 - Locais");
    printf("\n2 - Pontos de Interesse");
    printf("\n3 - Back");
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        printf("%d",num);
        return 3;
    }
    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 31;            /*Vai para o Locais */
            case 2:
                return 32;              /*vai para PDIs */
            case 3:
                return 1;              /* vai para a Back */
    }
    return 100;
}

int mainmenu(nodeptr user, nodeptr first){

    int num=0;

    printf("\n..................................");
    printf("\n\t -Menu Principal-\n");
    printf("\n1 - Perfil");
    printf("\n2 - Preferencias");
    printf("\n3 - Gerar Viagem");
    printf("\n..................................\n");
    printf("\nEscolha: ");

    if (scanf("%d",&num) == 0 || (num < 1 || num > 3)){   /* Caso o Utilizador nao Escolha uma das opcoes */

        fflush(stdin);
        system("cls");
        printf("%d",num);
        return 1;
    }

    fflush(stdin);
    system("cls");

    switch (num){
            case 1:
                return 2;            /*Vai para o perfil*/
            case 2:
                return 3;              /*vai para as preferencias*/
            case 3:
                return 4;              /* vai para a viagem */
    }
    return 100;
}

int main(){
    int n=0;
    int num = 1;

    Local placesptr=openlocal("locais.txt");

    nodeptr first=cria_user();
    nodeptr userptr;
    openfile("users.txt",first);
    do{
        userptr = menulogin(first,placesptr);
        system("cls");
    }while (userptr == NULL);

    printf("\n      -Logged in com sucesso-\n");

    while (num!=0){
        switch (num){
            case 1:
                num = mainmenu(userptr,first);break;
                case 2:
                    num = perfil(userptr,first);break;
                    case 5:
                        num = menualtera(userptr,first);break;
                        case 6:
                            num = alterauser(userptr,first);break;
                        case 7:
                            num = alteramorada(userptr,first);break;
                        case 8:
                            num = alteradata(userptr,first);break;
                        case 9:
                            num = alteraphone(userptr,first);break;
                    case 10:
                        num=printadados(userptr);break;


                case 3:
                    num=preferencias(userptr,placesptr);break;
                    case 31:
                        num=escolhalocais(userptr,placesptr);break;
                    case 32:
                        num=escolhapdis(userptr,placesptr);break;
                case 4:
                    num = 0;break;
                case 100:
                    printf("\nerro -  a funcao chegou ao fim!\n");num=0;n=1;break;


        }
    }
    if (n==0)
        logout(first);

    return 0;
     /*
    Local ptr=cria_local();
    Pdi smth;
    openlocal("locais.txt",ptr);
    smth=ptr->pontos;
    smth=smth->abcnext;
    printf("\n%s\n%s\n%s\n%s\n%d\n",ptr->local,smth->nome,smth->descricao,smth->horario,smth->pop);
    return 0;
    */
}
