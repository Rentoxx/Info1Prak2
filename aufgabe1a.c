#include <stdio.h>



int main(int year, int month, int day) {

    year = 0;
    month = 0;
    day = 0;

    
    if(!year || !month || !day) {
        // printf("Es wurde keine Zahlen für ein Datum festgelegt bitte geben sie diese ein:\n");
        printf("Tag: \n");
        scanf("%d", &day);
        printf("Monat: \n");
        scanf("%d", &month);
        printf("Jahr: \n");
        scanf("%d", &year);

        printf("Das eingegebene Datum ist der %d.%d.%d \n",day,month,year);
    }else {
        printf("Das eingegebene Datum ist der %d.%d.%d \n",day,month,year);
    }

    return 0;
}