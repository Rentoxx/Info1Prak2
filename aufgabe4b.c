#include <stdio.h>
#include <stdlib.h>

char months[12][10] = {  // 2D Array mit 12 Zeichenketten mit jeweils 10 Zeichen für die Monate
        "Januar", "Februar", "März", "April", "Mai", "Juni",
        "Juli", "August", "September", "Oktober", "November", "Dezember"
};

int validYear(int year) {  // Prüfen ob es sich um ein valides Jahr handelt
    if (year > 0) {
        return 1;
    } else {
        return 0;
    }
}

int validMonth(int month) { // Prüfen ob es sich um eine Valide Zahl für einen Monat handel(kleiner gleich 12 und größer als 0)
    if (month > 0 && month <= 12) {
        return 1;
    } else {
        return 0;
    }
}

int isSchaltJahr(int year) { // Prüft ob es sich bei der Zahl um ein Schaltjahr handelt

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
            if (isSchaltJahr(year)) //wenn der Monat ein Februar ist wird geguckt ob dieser in einem Schaltjahr liegt
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

int getWeekDay(int day, int month, int year) { // Funktion zur bestimmung des wochentags für ein bestimmtes Datum mithilfe des vorgegebenen Alogrythmus

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

    return h;

}

int getCorrectedWeekDay(int WeekDay) { // Verschiebung des Wochentags so, dass Montag = 1, Dienstag = 2, ... , Sonntag = 7
    if (WeekDay >= 2)
    {
        return WeekDay - 1;
    }else {
        return WeekDay + 6;
    }
    
}

void printCalender(int year) {

    if (year >= 1582 && year < 9999) // Jahr 1582 einführung des Gregorianischden Kalenders
    {
        for (int m = 1; m < 13; m++) //Durch die einzelnen Monate für das Jahr gehen
        {
            printf("%s %d \n",months[m-1], year); // Überschrift ausgeben bsp. Januar 2021
            int firstDayOfMonthWeekDay = getCorrectedWeekDay(getWeekDay(1,m,year)); //Ersten Wochentag des Monats in Korrigiertem Format abfragen

            if (firstDayOfMonthWeekDay > 1) //Wenn der erste Tag des Monats kein Monatag also = 1 ist passend viele Tabs ergänzen 
            {
                for (int f = 1; f < firstDayOfMonthWeekDay; f++)
                {
                    printf("\t");
                }
                
            }
            

            for (int d = 1; d < 32; d++) //Durch jeden Tag gehen
            {
                int WeekDay = getCorrectedWeekDay(getWeekDay(d,m,year)); //Wochentag bekommen und berichtigen, sodass Monatag = 0, Dienstag = 1 etc.
                if (validDay(d,m,year))
                { 
                    if (WeekDay % 7 == 0) //Alle 7 ausgegebenene Tage einen Zeilenumbruch anstelle von einem Tab ausgeben
                    {
                        printf("%d \n", d);
                    }else {
                        printf("%d \t", d);
                    }
                    
                    
                }
                
            }
            printf("\n\n"); //Abstand zwischen den Monaten
            
        }
    }

}


int main(void) {
    int year;


    printCalender(2000); //Testfall

    

    return 0;
}