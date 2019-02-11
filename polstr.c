#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int polindrom_mu(char*);
//void kopyala_str(char*, char*);
//int uzunluk_str(char*);
void tersle_str(char*);
int karsilastir_str(char*,char*);

int polindrom_mu(char* string)
{
    int kontrol, uzunluk;
    char *tersle;

    uzunluk = strlen(string);
    tersle = (char*)malloc((size_t) (uzunluk + 1));

    strcpy(tersle,string);
    tersle_str(tersle);

    kontrol = karsilastir_str(string, tersle);

    free(tersle);

    if(kontrol == 0 )
        return 1;
    else
        return 0;
}

void tersle_str(char *string)
{
    int uzunluk, i;
    char *basla, *son, temp;

    uzunluk = strlen(string);

    basla = string;
    son = string;

    for (i = 0; i < (uzunluk - 1); i++)
        son++;

    for(i = 0; i < uzunluk/2; i++)
    {
        temp = *son;
        *son = *basla;
        *basla = temp;

        basla++;
        son--;
    }
}

int karsilastir_str(char *ilk, char *ikinci)
{
    while (*ilk == *ikinci)
    {
        if( *ilk == '\0' || *ikinci == '\0')
            break;

        ilk++;
        ikinci++;
    }

    if( *ilk == '\0' && *ikinci == '\0')
        return 0;
    else
        return -1;
}

/*void kopyala_str(char *kopya, char *kaynak)  || <string.h> sagolsun :)
{
    while(*kaynak)
    {
        *kopya = *kaynak;
        kaynak++;
        kopya++;
    }
    *kopya = '\0';
}

int uzunluk_str(char *string)
{
    int uzunluk = 0;

    while(*string)
    {
        uzunluk++;
        string++;
    }
    return uzunluk;
}*/

int main() {

    char string[100];
    int sonuc;

    printf("Bir keliime giriniz\n");
    gets(string);

    sonuc = polindrom_mu(string);

    if (sonuc == 1)
        printf("\"%s\" palindrom bir kelimedir.\n", string);
    else
        printf("\"%s\" polindrom bir kelime degildir.\n", string);

    return 0;
}