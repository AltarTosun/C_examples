#include <stdio.h>
#include <string.h>

#define limit 500

void sifreleme(char[], int);
void sifreCoz(char[], int);
int bul(char[], char);

char kelime[limit];
int alfabeBoyutu;

int main() {

    char alfabe[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    int kaydir = 2;
    alfabeBoyutu = strlen(alfabe);

    strcpy(kelime, "OmUcEnG");
    printf("---kelimenin ilk hali---\n%s\n", kelime);
    sifreleme(alfabe, kaydir);
    printf("---kelimenin sifrelenmis hali---\n%s\n",kelime);
    sifreCoz(alfabe, kaydir);
    printf("---kelimenin cozulmus hali---\n%s\n", kelime);

    return 0;
}

void sifreleme(char alfabe[], int kaydir) {
    int i;
    int harfSirasi;
    int kelimeBoyutu = strlen(kelime);
    for (i = 0; i < kelimeBoyutu; i++) {
        harfSirasi = bul(alfabe, kelime[i]);
        if (harfSirasi != -1) {
            harfSirasi = (harfSirasi + kaydir) % alfabeBoyutu;
            if (harfSirasi < 0)
                harfSirasi += alfabeBoyutu;
            kelime[i] = alfabe[harfSirasi];
        }
        kaydir += 2;
        if (kaydir == 10)
            kaydir = 2;
    }


}

void sifreCoz(char alfabe[], int kaydir) {
    int i;
    int harfSirasi;
    int kelimeBoyutu = strlen(kelime);
    for (i = 0; i < kelimeBoyutu; i++) {
        harfSirasi = bul(alfabe, kelime[i]);
        if (harfSirasi != -1) {
            harfSirasi = (harfSirasi - kaydir) % alfabeBoyutu;
            if (harfSirasi < 0)
                harfSirasi += alfabeBoyutu;
            kelime[i] = alfabe[harfSirasi];
        }
        kaydir += 2;
        if (kaydir == 10)
            kaydir = 2;
    }

}

int bul(char alfabe[], char arananHarf) {

    int i, counter = -1;

    for (i = 0; i < strlen(alfabe); i++) {
        if (arananHarf == alfabe[i])
            counter = i;
    }
    return counter;
}