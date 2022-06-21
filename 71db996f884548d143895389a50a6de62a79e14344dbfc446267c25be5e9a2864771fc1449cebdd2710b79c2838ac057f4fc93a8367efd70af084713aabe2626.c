#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <errno.h>

int main()
{
    int whilecod, cpf, idade, pontos;
    char nome[150], sexo, errorString[512], sim;

    setlocale(LC_ALL, "Portuguese");
    errno = 0;

    FILE *arquivo = fopen("arqpaciente.txt", "a"); //não consegui criar o arquivo e resolver esse problema tentei vários modos de abertura
    if (arquivo == NULL);
    {
        printf("errno %d \n", errno);
        perror(errorString);
        printf("%s \n", errorString);
    }


    printf("Digite 1 cadastrar um novo paciente e qualquer outro numero para sair: \n");
    scanf("%d", &whilecod);
    fflush(stdin);

    while (whilecod == 1){

        printf("Digite o CPF do paciente: \n");
        scanf("%i", &cpf);
        fflush(stdin);

        printf("Digite o nome completo do paciente: \n");
        gets(nome);
        fflush(stdin);

        printf("Digite o sexo do paciente (M/F): \n");
        scanf("%c", &sexo);
        fflush(stdin);

        printf("Digite a idade do paciente: \n");
        scanf("%i", &idade);
        fflush(stdin);

        system("cls");
//-------------------------------------------------------------------------------------------------------------------------
        pontos = 0;

        printf("Digite (S/N) para os sintomas: \n");

        printf("Tem febre? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 5;
            sim = 0;
        }
        fflush(stdin);
        printf("Tem dor de cabeça? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 1;
            sim = 0;
        }
        fflush(stdin);
        printf("Tem secreção nasal ou espirros? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 1;
            sim = 0;
        }
        fflush(stdin);
        printf("Tem dor/irritação na garganta? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 1;
            sim = 0;
        }
        fflush(stdin);
        printf("Tem tosse seca? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 3;
            sim = 0;
        }
        fflush(stdin);
        printf("Tem dificuldade respiratória? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 10;
            sim = 0;
        }
        fflush(stdin);
        printf("Tem dores no corpo? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 1;
            sim = 0;
        }
        fflush(stdin);
        printf("Tem diarréia? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 1;
            sim = 0;
        }
        fflush(stdin);
        printf("Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 10;
            sim = 0;
        }
        fflush(stdin);
        printf("Esteve em locais com grande aglomeração (S/N)\n");
        scanf("%c", &sim);
        if((sim=='s') || (sim=='S')){
            pontos = pontos + 3;
            sim = 0;
        }
        fflush(stdin);
        system("cls");
//----------------------------------------------------------------------------------------------------------------------------------------------

        //printf("%i \n", pontos);

        if((pontos>=0) && (pontos<=9)){
            printf("Se encaminhe para a ala de Risco Baixo\n");
        }
        if((pontos>=10) && (pontos<=19)){
            printf("Se encaminhe para a ala de Risco Médio\n");
        }
        if(pontos>20){
            printf("Se encaminhe para a ala de Risco Alto\n\n");
        }

        system("pause");
        system("cls");

        printf(arquivo, "cpf: %i \n nome: %s \n sexo: %c \n idade: %i \n pontos: %i", cpf, nome, sexo, idade, pontos);
        fclose(arquivo);

        printf("Digite 1 cadastrar um novo paciente e qualquer outro numero para sair: \n");
        scanf("%d", &whilecod);
        fflush(stdin);
    }



    return (0);



}
