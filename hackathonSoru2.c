#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

float kaydedici(char koordinat, int sira);
float w1Set(float ax, float ay, float bx, float by, float cx, float cy, float px, float py);
float w2Set(float py, float ay, float w1, float by, float cy);
int isInside(float w1, float w2);

int isInside(float w1, float w2)
{
    printf("w1 : %.2f ve w2 : %.2f\n", w1, w2);
    //icinde ise 1 değilse 0 döner
    if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

float w2Set(float py, float ay, float w1, float by, float cy)
{
    float w2Top = py - ay - w1 * (by - ay);
    float w2Bottom = cy - ay;
    return w2Bottom == 0 ? 9999 : w2Top / w2Bottom; //Payda 0 kontrolu
}

float w1Set(float ax, float ay, float bx, float by, float cx, float cy, float px, float py)
{
    float w1Top = ax * (cy - ay) + (py - ay) * (cx - ax) - px * (cy - ay);
    float w1Bottom = (by - ay) * (cx - ax) - (bx - ax) * (cy - ay);

    return w1Bottom == 0 ? 9999 : w1Top / w1Bottom; //Payda 0 kontrolu
}

float kaydedici(char koordinat, int sira)
{
    float temp;
    if (sira == 4)
    {
        printf("Merak ettiginiz noktanin %c koordinatini giriniz: ", koordinat);
    }
    else
    {
        printf("%d. noktanin %c koordinatini giriniz: ", sira, koordinat);
    }

    scanf("%f", &temp);
    return temp;
}
int main()
{
    int bitirici;

    while (bitirici != 0)
    {
        float ax, ay, bx, by, cx, cy, px, py, w1, w2;
        int isInsideResult;

        ax = kaydedici('x', 1);
        ay = kaydedici('y', 1);
        bx = kaydedici('x', 2);
        by = kaydedici('y', 2);
        cx = kaydedici('x', 3);
        cy = kaydedici('y', 3);
        px = kaydedici('x', 4);
        py = kaydedici('y', 4);

        w1 = w1Set(ax, ay, bx, by, cx, cy, px, py);
        w2 = w2Set(py, ay, w1, by, cy);

        if (w1 != 9999 && w2 != 9999)
        {
            isInsideResult = isInside(w1, w2);
            if (isInsideResult == 1)
            {
                printf("(%.2f,%.2f) koordinatli nokta belirttiginiz ucgenin icinde \n", px, py);
            }
            else
            {
                printf("(%.2f,%.2f) koordinatli nokta belirttiginiz ucgenin icinde degil \n", px, py);
            }
        }
        else
        {
            printf("Girdiginiz ucgenin ucgen olduguna emin olunuz...\n");
        }

        //printf("\n%.2f \n%.2f \n%.2f \n%.2f \n%.2f \n%.2f \n%.2f \n%.2f", ax, ay, bx, by, cx, cy, px, py);

        printf("Devam etmek için herhangi bir sayi bitirmek icin 0'i tuslayiniz:");
        if (scanf(" %d", &bitirici) != 1) //Harfse
        {
            printf("Program sayi yerine harf girdiginiz icin kapatildi...\n");
            bitirici = 0;
        }
    }
    return 0;
}