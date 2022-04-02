

#include <stdio.h>
#include <time.h>


void swap(int* a, int * b)
{
    register int temp = *a;
    *a=*b;
    *b = temp;
}




void insertSort(int tab[], int n)
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
    register int i, j, temp;
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
    int tab[10000];
    int n = sizeof(tab)/sizeof(tab[0]);
    fullfillArray(tab, n);
    selectionSort(tab, n);
    tab[4999] = 7;
    
    printArray(tab, n);
    for (int i = 0; i < 100000000; i++);
    int ticks = clock();

    //insertSort(tab, n);
    //exchangeSort(tab, n);
    //selectionSort(tab, n);
    
    

    

    
    printArray(tab, n);

    printf("TIME: %f\n\n\n\n", (float)ticks/CLOCKS_PER_SEC);
    return 0;
}
