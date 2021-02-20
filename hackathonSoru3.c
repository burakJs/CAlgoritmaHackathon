#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int atKonumlar[7] = {2, 5, 4, 12, 4, 5, 2};

int anaMenu();
int sayiyaCevir(char k[10]);
void konumaCevir(int s);
void at(int s);
void piyon(int s);
void kale(int s);
void sah(int s);
void fil(int s);
void vezir(int s);

void vezir(int s)
{
    kale(s);
    fil(s);
}
void fil(int s)
{
    int baslangic = s - 9; //19
    for (int i = 2; i <= 8; i += 2)
    {
        konumaCevir(baslangic);
        baslangic += i;
        konumaCevir(baslangic);
        baslangic += 8 * i;
        konumaCevir(baslangic);
        baslangic -= i;
        konumaCevir(baslangic);
        baslangic -= 8 * i;
        baslangic -= 9;
    }
}

void sah(int s)
{
    int baslangic = s - 9; //19

    for (int i = 1; i <= 3; i++) //i 1
    {
        for (int j = 0; j < 3; j++) //j=1 2
        {
            if (s == baslangic)
            {
                baslangic++;
                continue;
            }
            konumaCevir(baslangic); //19 20 21
            baslangic++;            //19 + 0 = 19 => 20 21
        }
        baslangic = s - 9;
        baslangic += 8 * i; //19
    }
}
void kale(int s)
{
    int temp = s % 8 == 0 ? s / 8 : (s / 8) + 1;
    for (int i = 1; i <= 8; i++)
    {
        if (s == (temp * 8) - (8 - i))
        {
            continue;
        }
        konumaCevir((temp * 8) - (8 - i));
    }
    for (int i = 0; i < 8; i++)
    {
        if (s == (s % 8) + (8 * i))
        {
            continue;
        }
        konumaCevir((s % 8) + (8 * i));
    }
}
void piyon(int s)
{
    if (s > 56)
    {
        printf("Gidilicek hamle yok...\n");
    }
    else
    {
        konumaCevir(s + 8);
    }

    printf("\n");
}
void at(int s)
{
    int baslangic = s - 17;
    printf("Atin konumlari : \n");
    if (baslangic > 0)
    {
        konumaCevir(baslangic);
    }
    printf("\n");
    for (int i = 0; i < 7; i++)
    {

        baslangic += atKonumlar[i];
        if (baslangic < 0)
        {
            continue;
        }
        konumaCevir(baslangic);
        printf("\n");
    }
}

void konumaCevir(int s)
{
    char k[10];

    int temp = (s % 8) == 0 ? 8 : (s % 8);
    char a = 64 + temp;
    int temp2 = (s % 8) == 0 ? (s / 8) : (s / 8) + 1;
    char b = temp2 + '0';

    k[0] = a;
    k[1] = b;
    k[2] = '\0';
    if (isalpha(k[0]) && isdigit(k[1]) && k[1] < 9 + '0' && k[1] > 0 + '0')
    {
        printf("\n");
        printf("%s", k);
    }
}

int sayiyaCevir(char k[10])
{
    int sayi = (k[1] + '0') - 96;

    int sifre = (8 * sayi) - (72 - k[0]);
    printf("\n");
    return sifre;
}

int anaMenu()
{
    int secim;

    printf("1- Piyon\n");
    printf("2- Sah\n");
    printf("3- Fil\n");
    printf("4- Vezir\n");
    printf("5- At\n");
    printf("6- Kale\n");
    scanf("%d", &secim);

    return secim;
}
int main()
{
    int bitirici = 1;

    while (bitirici != 0)
    {
        int secim;
        char konum[10];
        char a[10];
        secim = anaMenu();

        printf("Konum giriniz: ");
        scanf(" %s", konum);

        switch (secim)
        {
        case 1:
            piyon(sayiyaCevir(konum));
            break;
        case 2:
            sah(sayiyaCevir(konum));
            break;
        case 3:
            fil(sayiyaCevir(konum));
            break;
        case 4:
            vezir(sayiyaCevir(konum));
            break;
        case 5:
            at(sayiyaCevir(konum));
            break;
        case 6:
            kale(sayiyaCevir(konum));
            break;
        default:
            break;
        }

        printf("\n");
        printf("Devam etmek için herhangi bir sayi bitirmek icin 0'i tuslayiniz:");
        if (scanf(" %d", &bitirici) != 1) //Harfse
        {
            printf("Program sayi yerine harf girdiginiz icin kapatildi...\n");
            bitirici = 0;
        }
    }
}