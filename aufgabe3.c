#include <stdio.h>
#include <stdlib.h>

int validYear(int year) {
    if (year > 0) {
        return 1;
    } else {
        return 0;
    }
}

int validMonth(int month) {
    if (month > 0 && month <= 12) {
        return 1;
    } else {
        return 0;
    }
}

int isSchaltJahr(int year) {

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            return 0;
        }

        return 1;
        
    }else {
        return 0;
    }
}

int validDay(int day, int month, int year) {
    /* Prüfen welcher Monat ist und wie viele Tage dieser hat */
    if (day > 0 ) {

        if (month == 2)
        {
            if (isSchaltJahr(year))
            {
                if (day <= 29)
                {
                    return 1;
                }else {
                    return 0;
                }
            }else {
                if (day <= 28)
                {
                    return 1;
                }else {
                    return 0;
                }
            }
            
        }else {
            

            if (month % 2 == 0 && month != 7)
            {
                
                if (day <= 30)
                {
                    return 1;
                }else {
                    return 0;
                }
                
            }else {
                if (day <= 31)
                {
                    return 1;
                }else {
                    return 0;
                }
                
            }

        }
        

        
        
        return 1;
    } else {
        return 0;
    }
}

void printWeekDay(int day, int month, int year) {

    if (validDay(day, month, year) == 1 && validMonth(month) == 1 && validYear(year) == 1)
    {
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
    }else {

        printf("Das Datum: %d.%d.%d ist nicht gültig.\n", day,month,year);

    }
    

    


}


int main(void) {
    int year, month, day;
    printWeekDay(24, 1, 1712);
    printWeekDay(18, 11, 2023);
    printWeekDay(19, 11, 2023);
    printWeekDay(20, 11, 2023);
    printWeekDay(17, 11, 2023);
    printWeekDay(29, 2, 2000);
    printWeekDay(1, 3, 2000);
    printWeekDay(30, 2, 1992);
    




    return 0;
}