

#include <stdio.h>
#include <time.h>


void swap(int* a, int * b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}




void insertionSort(int tab[], int n)
{
    register int i, k, j;
    for (i = 1; i < n; i++)
    {
        k = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > k) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = k;
    }
}

void exchangeSort(int tab[], int n) {
    int i, j;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = (i + 1); j < n; j++)
        {
            if (tab[i] > tab[j])// znak zamienia kolejnosc sortowania
            {
                swap(&tab[i], &tab[j]);
            }
        }
    }
}

void selectionSort(int tab[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++) {
        k = i;
        for (j = i + 1; j < n; j++) 
            if (tab[j] < tab[k]) 
                k = j;
        swap(&tab[k], &tab[i]);
    }
}



void printArray(int tab[], int n)
{
    register int i = 0;
    for (i; i < n; i++)
        printf("%d ", tab[i]);
    printf("\n\n\n\n\n");
}

void fullfillArray(int tab[], int n)
{
    register int i = 0;
    srand(time(0));
    for (i; i < n; i++)
        tab[i] = rand(time)%201-100 ;
    printf("\n");
}

int main()
{

    //insertionSort(tab, n);
    //exchangeSort(tab, n);
    //selectionSort(tab, n);
    int tab[1000];
    int n = sizeof(tab)/sizeof(tab[0]);
    fullfillArray(tab, n);
    insertionSort(tab, n);//tutaj tworzymy wstepnie posortowana tablice (dowolne sortowanie)
    //printArray(tab, n);
    tab[500] = 70;
    long before = clock();//mierzenie czasu

    exchangeSort(tab, n);

    long after = clock();
   // printArray(tab, n);
    
    double elapsed = (double)(after - before) / CLOCKS_PER_SEC;
   
    printf("%lf seconds elapsed\n", elapsed);

    



    
    return 0;
}
