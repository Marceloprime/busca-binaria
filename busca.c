#include "arvore.h"

/*primeiro eh ordenado  a o vector, antes da busca */
void merge(int vector[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    //vetores auxiliares
    int L[n1], R[n2];

    /*Prenchimento dos vetores auxiliares*/
    for (i = 0; i < n1; i++)
        L[i] = vector[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vector[m + 1+ j];

    //inicializacoes
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vector[k] = L[i];
            i++;
        }
        else
        {
            vector[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        vector[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        vector[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int vector[], int l, int r) {
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(vector, l, m);
        mergeSort(vector, m+1, r);

        merge(vector, l, m, r);
    }
}

int busca_bin(int n,int *vector,int elem){
    int ini =0;
    int fim = n-1;
    int meio;

    mergeSort(vector,0,n);
    /*Enquanto a parte restante for maior que zero*/
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(elem < vector[meio]){
            fim = meio-1;
        }
        else if(elem > vector[meio]){
            ini = meio+1;
        }
        else{

            return meio;
        }
    }

    return -1;//caso o elemento nao seja encontrado

}

int insercao(int elem,int posi,int *vector,int n){
    //Para garantir que nao haja repeticoes no vetor
    if(busca_bin(n,vector,elem) == -1){
        return -1;
    }
    posi = posi+1;
    if(posi == n){
        return -1;
    }
    else{
        vector[posi] = elem;
        return 1;
    }
}


int remocao(int elem,int *vector,int n){
    int aux;
    //Localizacao do elemento
    aux = busca_bin(n,vector,elem);
    if(aux == -1){
         return -1;
    }
    else{
        if(aux == n-1){
            return aux;
        }
        //remocoa
        for(int i=aux;i<n;i++){
            vector[i] = vector[i+1];
            return n-1;
        }
    }
}
