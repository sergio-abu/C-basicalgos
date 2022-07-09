#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


enum {INPUT_SIZE = 30};
long vertices = 0, first, second;
float cost;
float *costs = NULL;
void dijkstra_algo(long vertices, long first, long second, float *costs);
void print_menu(void);
void build_graph(void);
void print_graph(void);
void run_calculator(void);


int main(int argc, char **argv) {
    printf("  Hello, Dijkstra!\n");
    char *ptr;
    long option;
    char str[INPUT_SIZE];
    do {
        print_menu();
        fgets(str, INPUT_SIZE, stdin);
        option = strtol(str, &ptr, 10);

        switch (option) {
            case 1:
                printf("| [1]                |\n");
                build_graph();
                break;
            case 2:
                printf("| [2]                |\n");
                print_graph();
                break;
            case 3:
                printf("| [3]                |\n");
                run_calculator();
                break;
        }
    } while (option !=4);
    return 0;
}

void print_menu(void){
    printf("|========MENU========|\n");
    printf("| [1] Build Graph    |\n");
    printf("| [2] Print Graph    |\n");
    printf("| [3] Run Calculator |\n");
    printf("| [4] Quit           |\n");
    printf("|====================|\n");
    printf(">> ");
}

void build_graph(void){
    char *ptr;
    char str[INPUT_SIZE];

    do{
        printf("| Type the number of |\n");
        printf("| vertices:          |\n");
        printf(">> ");
        fgets(str, INPUT_SIZE, stdin);
        vertices = strtol(str, &ptr, 10);
    } while(vertices < 3);

    if(!costs) {
        free(costs);
    }

    costs = (float*) malloc(sizeof(float)*vertices*vertices);
    if(costs == NULL){
        printf("| Memory Error       |\n");
        exit(-1);
    }
    for(int i = 0; i <= vertices * vertices; i++){
        costs[i]=-1;
    }

    do {
        printf("| Type the edges:    |\n");

        do {
            printf("| Type the first     |\n");
            printf("| node for the edge: |\n");
            printf("| (1 to %ld, [0] Exit) |\n", vertices);
            printf(">> ");
            fgets(str, INPUT_SIZE, stdin);
            first = strtol(str, &ptr, 10);
        } while (first < 0 || first > vertices);

        if (first) {
            do {
                printf("| Type the second    |\n");
                printf("| node for the edge: |\n");
                printf("| (1 to %ld)           |\n", vertices);
                printf("| (First node: %ld )   |\n", first);
                printf(">> ");
                fgets(str, INPUT_SIZE, stdin);
                second = strtol(str, &ptr, 10);
            } while (second < 1 || second > vertices || second == first);
            do {
                printf("| Type the cost of   |\n");
                printf("| this edge:         |\n");
                printf("| (Edge %ld to %ld)      |\n", first, second);
                printf(">> ");
                fgets(str, INPUT_SIZE, stdin);
                cost = strtof(str, &ptr);
            } while (cost < 0);
            costs[(first - 1) * vertices + second - 1] = cost;
        }
    } while (first);
}

void print_graph(void){
    printf("| %ld Nodes / Vertices |\n", vertices);
    printf("| (1 to %ld)           |\n", vertices);
}

void run_calculator(void){
    printf("| Shortest Paths:    |\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            dijkstra_algo(vertices, i, j, costs);
        }
    }
}

void dijkstra_algo(long vertices, long first, long second, float *costs){
    double range[vertices];
    long *ant, *temp;
    long *z;
    double min;
    long v, i, counter=0;

    ant = (long *) calloc(vertices, sizeof (long *));
    if (ant == NULL) {
        printf("| Memory Error       |\n");
        exit(-1);
    }
    temp = (long *) calloc(vertices, sizeof (long *));
    if (temp == NULL) {
        printf("| Memory Error       |\n");
        exit(-1);
    }
    z = (long *) calloc(vertices, sizeof (long *));
    if (z == NULL) {
        printf("| Memory Error       |\n");
        exit(-1);
    }

    for(i = 0; i < vertices; i++){
        if((costs[(first-1) * vertices + i]) != -1) {
            ant[i] = first - 1;
            range[i] = costs[(first - 1) * vertices + i];
        }
        else{
            ant[i] = -1;
            range[i] = HUGE_VAL;
        }
        z[i] = 0;
    }

    z[first -1] = 1;
    range[first -1] = 0;

    do {
        min = HUGE_VAL;
        for (i=0; i<vertices; i++){
            if(!z[i]) {
                if(range[i] >= 0 && range[i] < min) {
                    min = range[i]; v=i;
                }
            }
        }
        if(min != HUGE_VAL && v != second -1) {
            z[v] = 1;
            for(i = 0; i < vertices; i++){
                if(!z[i]) {
                    if(costs[v*vertices+i] != -1 && range[v] + costs[v*vertices+i] < range[i]){
                        range[i] = range[v] + costs[v*vertices+i];
                        ant[i] = v;
                    }
                }
            }
        }
    }while(v != second -1 && min != HUGE_VAL);

    printf("| Path: %ld to %ld       |\n", first, second);
    if (min == HUGE_VAL) {
        printf("| NAN                |\n");
    }
    else {
        i = second;
        i = ant[i-1];
        while (i != -1){
            temp[counter] = i + 1;
            counter++;
            i= ant[i];
        }
        for (i= counter; i>0; i--){
            printf("%ld >> ", temp[i-1]);
        }
        printf("%ld ", second);
        printf("Cost: %.4lf \n", range[second-1]);
    }

}
