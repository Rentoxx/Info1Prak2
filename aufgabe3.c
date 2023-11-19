#include <stdio.h>
#include <stdlib.h>

void printWeekDay(int day, int month, int year) {

    int q; int m; int K; int J; int h;

    q = day;
    // printf("q=%d\n", q);

    if(month >= 3) {
        m = month;
        K = year;
    }else {
        m = month + 12;
        K = year-1;
    }
    J = K/100;
    K = K%100;
    

    // printf("m=%d\n", m);
    // printf("K=%d\n", K);
    // printf("J=%d\n", J);

    int firstBraces = ((m+1)*13)/5;
    int secondBraces = K/4;
    int thridBraces = J/4;

    h = (q + firstBraces + K + secondBraces + thridBraces - (2*J)) % 7;

    if (h < 0) {
        h += 7;
    }

    

    printf("Der %d.%d.%d ist der %d. Wochentag!\n", day, month, year, h);

    switch (h)
    {
    case 0:
        printf("Also ein Sammstag!\n\n");
        break;
    case 1:
        printf("Also ein Sonntag!\n\n");
        break;
    case 2:
        printf("Also ein Montag!\n\n");
        break;
    case 3:
        printf("Also ein Dienstag!\n\n");
        break;
    case 4:
        printf("Also ein Mittwoch!\n\n");
        break;
    case 5:
        printf("Also ein Donnerstag!\n\n");
        break;
    case 6:
        printf("Also ein Freitag!\n\n");
        break;
    
    default:
        printf("Error! Der Wochentag wurde fehlerhaft berechnet!\n");
    }


}


int main(void) {
    int year, month, day;
    printWeekDay(24, 1, 1712);
    printWeekDay(18, 11, 2023);
    printWeekDay(19, 11, 2023);
    printWeekDay(20, 11, 2023);
    printWeekDay(17, 11, 2023);
    




    return 0;
}