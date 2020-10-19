#include "arvore.c"
#include <stdio.h>
#include <time.h>

int main(){
    int vector[MAX],aux[MAX];

    //Principais declaracoes de variaveis e inicianilacoes
    int n = 100,k=0,elem,posi;
    clock_t tempo;
    double vec_in[4],vec_re[4],vec_bus[4];

    printf("Crescente\n");
    while(n < 1000000){
        int vector[n];
    	tempo = clock();
        for(int i=0;i<n;i++){
            elem = i;
            posi = i-1;
            insercao(elem,posi,vector,n);
        }
        vec_in[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=0;i<(n/2);i++){
            elem = i;
            remocao(elem,vector,n);
        }
        for(int i=(n/2);i<n;i++){
            elem = i+n;
            remocao(elem,vector,n);
        }
        vec_re[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=(n/2);i<n;i++){
            elem = i;
            busca_bin(n,vector,elem);
        }
        for(int i=(n/2);i<n;i++){
            elem = i+n;
            busca_bin(n,vector,elem);
        }
        vec_bus[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        k++;
        n = n *10;
    }
    n = 100;
    for(int i=0;i<4;i++){
        printf("%d\n",n);
        printf("inser %lf\n",vec_in[i]);
        printf("Remo  %lf\n",vec_re[i]);
        printf("Busca %lf\n",vec_bus[i]);
        printf("\n\n");
        n=n*10;
    }
     printf("Aleatorio\n");
    while(n < 1000000){
        int vector[n];
    	tempo = clock();
        for(int i=0;i<n;i++){
            aux[i] = (rand()%1000000);
            elem = aux[i];
            posi = i-1;
            insercao(elem,posi,vector,n);
        }
        vec_in[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        tempo = clock();
        for(int i=0;i<(n/2);i++){
            elem = aux[i];
            remocao(elem,vector,n);
        }
         for(int i=(n/2);i<n;i++){
            elem = aux[i]+1000000;
            remocao(elem,vector,n);
        }
        vec_re[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=(n/2);i<n;i++){
            elem = aux[i];
            busca_bin(n,vector,elem);
        }
        for(int i=(n/2);i<n;i++){
            elem = aux[i]+1000000;
            busca_bin(n,vector,elem);
        }
        vec_bus[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        k++;
        n = n *10;
    }
    n = 100;
    for(int i=0;i<4;i++){
        printf("%d\n",n);
        printf("inser %lf\n",vec_in[i]);
        printf("Remo  %lf\n",vec_re[i]);
        printf("Busca %lf\n",vec_bus[i]);
        printf("\n\n");
        n=n*10;
    }
    printf("Decrescente\n");
    while(n < 1000000){
        int vector[n];
        posi = -1;
    	tempo = clock();
        for(int i=n;i<=0;i--){
            elem = i;
            posi++;
            insercao(elem,posi,vector,n);
        }
        vec_in[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=(n/2);i<=0;i--){
            elem = i;
            remocao(elem,vector,n);
        }
        for(int i=(n/2);i<n;i++){
            elem = i+n;
           remocao(elem,vector,n);
        }
        vec_re[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;


        tempo = clock();
        for(int i=(n/2);i<n;i++){
            elem = i;
            busca_bin(n,vector,elem);
        }
        for(int i=(n/2);i<n;i++){
            elem = i+n;
            busca_bin(n,vector,elem);
        }
        vec_bus[k] = (clock() - tempo) / (double)CLOCKS_PER_SEC;

        k++;
        n = n *10;
    }
    n = 100;
    for(int i=0;i<4;i++){
        printf("%d\n",n);
        printf("inser %lf\n",vec_in[i]);
        printf("Remo  %lf\n",vec_re[i]);
        printf("Busca %lf\n",vec_bus[i]);
        printf("\n\n");
        n=n*10;
    }
    return 0;
}
