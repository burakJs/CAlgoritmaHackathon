#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *sifreleme(char m[], int k);
char *sifreCozme(char m[], int k);
void dongu();

char *sifreleme(char m[], int k)
{
    int metinUzunlugu = strlen(m);
    char sifreliMetin[100] = "";
    char kontrol, temp;

    for (int i = 0; i < metinUzunlugu; i++)
    {
        kontrol = m[i];
        int asciiNumber = m[i];

        if (kontrol == ' ')
        {
            sifreliMetin[i] = ' ';
            continue;
        }
        if (isalpha(kontrol))
        {
            if (kontrol == tolower(kontrol)) //Harf kucuk olursa
            {
                if (asciiNumber + k > 122)
                {
                    temp = 97 + (k - (123 - asciiNumber));
                }
                else
                {
                    temp = asciiNumber + k;
                }
            }
            else //Harf buyukse
            {
                if (asciiNumber + k > 90)
                {
                    temp = 65 + (k - (91 - asciiNumber));
                }
                else
                {
                    temp = asciiNumber + k;
                }
            }
        }
        else
        {
            temp = kontrol;
        }

        sifreliMetin[i] = temp;
    }

    return sifreliMetin;
}

char *sifreCozme(char m[], int k)
{
    int metinUzunlugu = strlen(m);
    char cozulenMetin[100] = "";
    char kontrol, temp;

    for (int i = 0; i < metinUzunlugu; i++)
    {
        kontrol = m[i];
        int asciiNumber = m[i];

        if (kontrol == ' ')
        {
            cozulenMetin[i] = ' ';
            continue;
        }

        if (isalpha(kontrol))
        {
            if (kontrol == tolower(kontrol)) //Harf kucuk olursa
            {
                if (asciiNumber - k < 97)
                {
                    temp = 123 - (k - (asciiNumber - 97));
                }
                else
                {
                    temp = asciiNumber - k;
                }
            }
            else //Harf buyukse
            {
                if (asciiNumber - k < 65)
                {
                    temp = 91 - (k - (asciiNumber - 65));
                }
                else
                {
                    temp = asciiNumber - k;
                }
            }
        }
        else
        {
            temp = kontrol;
        }

        cozulenMetin[i] = temp;
    }

    return cozulenMetin;
}

void dongu()
{
    int bitirici;

    while (bitirici != 0)
    {
        int durum = 0;
        int kod;
        char metin[100] = "";
        char s[100];
        char bos[100];
        //Butun islemler buraya
        printf("Metni giriniz\n");
        scanf(" %[^\n]", metin);

        while (1)
        {
            printf("Sifreleme kodu giriniz\n");
            scanf(" %d", &kod);
            if (kod <= 20 || kod >= 1)
            {
                break;
            }
            printf("Tekrar kod giriniz, Gecerli aralik (1,21)");
        }

        printf("1- Sifreyi Cozmek\n");
        printf("2- Sifrelemek\n");
        scanf(" %d", &durum);

        if (durum == 1)
        {
            strcpy(s, sifreCozme(metin, kod));
            printf("Sifreli metin : %s \nCozulmus metin : %s \n", metin, s);
        }
        else if (durum == 2)
        {
            //sifrelemek
            strcpy(s, sifreleme(metin, kod));
            printf("Sifreli metin : %s \n", s);
        }
        else
        {
            printf("hatalı şifre girdiniz\n");
        }

        //bitirme kontrolu
        printf("Devam etmek için herhangi bir sayi bitirmek icin 0'i tuslayiniz:");
        if (scanf(" %d", &bitirici) != 1) //Harfse
        {
            printf("Program sayi yerine harf girdiginiz icin kapatildi...\n");
            bitirici = 0;
        }
    }
}

int main()
{
    dongu();

    return 0;
}
