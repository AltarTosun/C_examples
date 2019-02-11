#include <stdio.h>
#include <string.h>

int karsilastir(char s1[], char s2[], int n);
void sirala(char s1[], char s2[], int n);


int main() {

    char s1[] = "ihbar";
    char s2[] = "bahir";

    int n = strlen(s1);

    sirala(s1,s2,n);
    int a = karsilastir(s1,s2,n);

    if (a ==0)
        printf("kelimeler anagram degildir");
    else
        printf("kelimeler anagramdir");

    return 0;
}

int karsilastir(char s1[], char s2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(s1[i] != s2[i])
            return 0;
    }
}

void sirala(char s1[], char s2[], int n)
{
    int i,j;
    char temp;

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (s1[i] > s1[j]) {
                temp  = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
            }
            if (s2[i] > s2[j]) {
                temp  = s2[i];
                s2[i] = s2[j];
                s2[j] = temp;
            }
        }
    }
}