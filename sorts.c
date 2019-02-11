#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_sorted(int *a, int n);
void shuffle(int *a, int n);
void bogosort(int *a, int n);
void printArray(int arr[], int size);
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);

//------------- Permutation_Sort

bool is_sorted(int *a, int n)
{
    while ( --n >= 1 ) {
        if ( a[n] < a[n-1] )
            return false;
    }
    return true;
}

void shuffle(int *a, int n)
{
    int i, t, r;
    for(i=0; i < n; i++) {

        t = a[i];
        r = rand() % n;
        a[i] = a[r];
        a[r] = t;
        printArray(a,n);
    }
}

void bogosort(int *a, int n)
{
    while ( !is_sorted(a, n) ) shuffle(a, n);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//-------------- Bubble_Sort

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                printArray(arr, n);
            }
}


int main() {
    int i, n, secim;

    printf("dizinin boyutunu giriniz : ");
    scanf("%d", &n);

    int numbers[n];

    printf("diziye %d tane eleman giriniz : ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("permutasyon siralamasi icin 0; kabarcik siralamasi icin 1 : \n");
    scanf("%d", &secim);

    switch (secim) {
        case 0 :
            printf("permutasyon siralamasi\n");
            bogosort(numbers, n);
            break;

        case 1 :
            printf("kabarcik siralamasi\n");
            bubbleSort(numbers, n);
            break;

        default :
            break;
    }

    return 0;
}