#include <stdio.h>
#include <stdlib.h>

int validYear(int year)
{
    if (year > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validMonth(int month)
{
    if (month > 0 && month <= 12)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSchaltJahr(int year)
{

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
    }
    else
    {
        return 0;
    }
}

int validDay(int day, int month, int year)
{
    /* Prüfen welcher Monat ist und wie viele Tage dieser hat */
    if (day > 0)
    {

        if (month == 2)
        {
            if (isSchaltJahr(year))
            {
                if (day <= 29)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if (day <= 28)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {

            if (month % 2 == 0 && month != 7)
            {

                if (day <= 30)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if (day <= 31)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int year, month, day;

    int valid = 0;
    // Prüfen, ob das Programm mit Startparametern gestartet wurde
    if (argc == 4)
    {
        printf("Programm wurde erfolgreich mit Startparametern ausgeführt!\n");
        day = atoi(argv[1]);
        month = atoi(argv[2]);
        year = atoi(argv[3]);

        valid = 1;

        if (validDay(day, month, year) == 0)
        {
            valid = 0;
            printf("Fehlerhafter Tag. Bitte geben Sie das Datum erneut ein! \n");
        }
        if (validMonth(month) == 0)
        {
            valid = 0;
            printf("Fehlerhafter Monat. Bitte geben Sie das Datum erneut ein! \n");
        }
        if (validYear(year) == 0)
        {
            valid = 0;
            printf("Fehlerhaftes Jahr. Bitte geben Sie das Datum erneut ein! \n");
        }

        if (valid == 1)
        {
            printf("Das eingegebene Datum ist der %d.%d.%d \n", day, month, year);
            return 0;
        }
    }

    if (argc != 4)
    {
        printf("Das Programm wurde ohne Startparameter gestartet. Bitte geben Sie ein Datum ein!\n");
    }

    // Eingabe vom Datum so lange erwarten bis ein gültiges Datum eingegeben wurde
    while (valid == 0)
    {
        year = 0;
        month = 0;
        day = 0;

        printf("Tag: \n");
        scanf("%d", &day);
        printf("Monat: \n");
        scanf("%d", &month);
        printf("Jahr: \n");
        scanf("%d", &year);

        valid = 1;
        if (validDay(day, month, year) == 0)
        {
            valid = 0;
            printf("Fehlerhafter Tag. Bitte wiederholen! \n");
        }
        if (validMonth(month) == 0)
        {
            valid = 0;
            printf("Fehlerhafter Monat. Bitte wiederholen! \n");
        }
        if (validYear(year) == 0)
        {
            valid = 0;
            printf("Fehlerhaftes Jahr. Bitte wiederholen! \n");
        }
    }
    printf("Das eingegebene Datum ist der %d.%d.%d \n", day, month, year);

    return 0;
}