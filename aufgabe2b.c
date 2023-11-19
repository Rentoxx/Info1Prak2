#include <stdio.h>
#include <stdlib.h>
#define ENGLAND 0
#define USA 1
#define NETHERLAND 2
#define CHINA 3
#define CANADA 4

void printDate(int day, int month, int year, int countryCode) {

    switch (countryCode)
    {
    case ENGLAND:
        printf("Das Datum ist der %d.%d.%d\n", day, month, year);
        break;
    
    case USA:
        printf("Das Datum ist der %d.%d.%d\n", month, day, year);
        break;

    case NETHERLAND:
        printf("Das Datum ist der %d.%d.%d\n", day, month, year);
        break;
    case CHINA:
        printf("Das Datum ist der %d.%d.%d\n", year, month, day);
        break;
    
    case CANADA:
        printf("Das Datum ist der %d.%d.%d\n", month, day, year);
        break;
    
    default:
        printf("Der eingegebene Ländercode konnte nicht zugeordenet werden!\nBitte starten sie das Programm wie folgt:\n<Tag> <Monat> <Jahr> <Land(EN=0,USA=1,NE=2,CHINA=3,CA=4)> \n");
        break;
    }
    

}


int main(int argc, char *argv[]) {
    int year, month, day, countryCode;

    if (argc == 5)
    {
        day = atoi(argv[1]);
        month = atoi(argv[2]);
        year = atoi(argv[3]);
        countryCode = atoi(argv[4]);
        printDate(day, month, year, countryCode);
    }else {
        printf("Ohne Startparameter gestartet!\nBitte geben sie ein Datum ein oder starten Sie das Programm mit 4 Parametern wie folgt:\n<Tag> <Monat> <Jahr> <Land(EN=0,USA=1,NE=2,CHINA=3,CA=4)> \n");

        printf("Tag: \n");
        scanf("%d", &day);
        printf("Monat: \n");
        scanf("%d", &month);
        printf("Jahr: \n");
        scanf("%d", &year);
        printf("Land(EN=0,USA=1,NE=2,CHINA=3,CA=4): \n");
        scanf("%d", &countryCode);

        printDate(day, month, year, countryCode);
    }

    return 0;
}