#include <stdio.h>

#include <stdlib.h>

#include <locale.h>

int menu,cv1,cv2,cv3,cv4,cp1,cp2,cp3,vtv,vtp;

int main(){

setlocale(LC_ALL, "Portuguese");



cv1,cv2,cv3,cv4,cp1,cp2,cp3=0;



do{

printf ("Execute");

printf ("\n 1 - Votar \n 2 - Apurar \n 3 - Sair\n");

scanf ("%d",&menu);



switch(menu){

   case 1:

    printf ("\nVotar para qual vereador?");

  printf ("\n 111-João_do_Frete\n 222-Maria_da_Pamonha\n 333-Ze_da_Farmacia\n 444-Nulo\n");

     scanf ("%d",&vtv);







switch (vtv){

     case 111:

      printf ("\nVoto concluido");

    cv1=cv1+1;

    break;

    case 222:

     printf ("\nVoto concluido");

    cv2+cv2+1;

    break;

    case 333:

     printf ("\nVoto concluido");

    cv3=cv3+1;

    break;

    case 444:

     printf ("\nVoto concluido");

    cv4=cv4+1;

    break;

    default:

    printf ("Opçao invalida");



}



  printf ("\nVotar para qual prefeito?");

  printf ("\n 11-Dr_Zureta\n 22-Sr_Gomes\n 44-nulo\n");

     scanf ("%d",&vtp);



switch(vtp){



 while (vtp!=11,22,44);{

    case 11:

     printf ("Voto concluido\n");

    cp1=cp1+1;

    break;

    case 22:

     printf("Voto concluido\n");

    cp2=cp2+1;

    break;

    case 44:

     printf("Voto concluido\n");

    cp3=cp3+1;

    break;

    default:

    printf("Opçao invalida");

  }

   }



   case 2:



    printf ("\nVotaçao vereador");

    printf ("\nvoto para joao:%d", cv1);

    printf ("\nvoto para maria: %d" , cv2);

    printf ("\nvoto para ze: %d", cv3);

    printf ("\nvoto nulo: %d\n", cv4);

    printf ("\nVotaçao prefeito");

    printf ("\nvoto para zureta:%d", cp1);

    printf ("\nvoto para gomes: %d" , cp2);

    printf ("\nvoto nulo: %d", cp3);

    printf ("\n");

    break;

  }

 } while (menu!=3);

  return 0;

 }
