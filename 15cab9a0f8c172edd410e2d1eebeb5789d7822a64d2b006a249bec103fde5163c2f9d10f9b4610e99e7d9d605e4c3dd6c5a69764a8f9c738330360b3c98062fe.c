#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numeros, num_cartelas, cartela[10], i, j, k, l, flag;
    flag = 0;

    printf("Digite quantas cartelas vc deseja: ");
    scanf("%i", &num_cartelas);
    fflush(stdin);
    srand( time(NULL));

    for(i = 0; i < num_cartelas; i++){

        for(j = 0; j < 10; j++){

            numeros = (rand() % 99);

            for(k = 0; k <= j - 1; k++){

               if(numeros == cartela[k]){

                flag = 1;
                break;

               }
            }
               if(flag == 1){
                    flag = 0;
                    j = j - 1;


               }else{
                   cartela[j] = numeros;
               }
        }
        for(l = 0; l < 10; l++){
        printf("%d ", cartela[l]);
     }
     printf("\n");
    }


}
