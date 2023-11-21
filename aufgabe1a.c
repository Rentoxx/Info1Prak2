#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {

    int year = 0;
    int month = 0;
    int day = 0;

    
    if(argc == 4) {
        printf("Programm wurde erfolgreich mit Startparametern ausgeführt!\n");
        day = atoi(argv[1]);
        month = atoi(argv[2]);
        year = atoi(argv[3]);

        printf("Das eingegebene Datum ist der %d.%d.%d \n",day,month,year);
        
    }else {

        printf("Es wurde keine Zahlen für ein Datum festgelegt bitte geben sie diese ein:\n");
        printf("Tag: \n");
        scanf("%d", &day);
        printf("Monat: \n");
        scanf("%d", &month);
        printf("Jahr: \n");
        scanf("%d", &year);

        printf("Das eingegebene Datum ist der %d.%d.%d \n",day,month,year);
    }

    return 0;
}