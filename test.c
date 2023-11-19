#include <stdio.h>

const char *months[] = {"Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};

// Funktion, um den Wochentag zu erhalten (0 = Sonntag, 1 = Montag, ..., 6 = Samstag)
int getWeekDay(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int dayOfWeek = (day + 13 * (month + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    return (dayOfWeek + 5) % 7;  // Berichtige den Wochentag, um Sonntag = 0, Montag = 1, ..., Samstag = 6 zu erhalten
}

// Funktion, um den korrigierten Wochentag zu erhalten (Montag = 0, Dienstag = 1, ..., Sonntag = 6)
int getCorrectedWeekDay(int weekDay) {
    return (weekDay + 6) % 7;
}

// Funktion, um zu überprüfen, ob ein Tag im Monat gültig ist
int validDay(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1) {
        return 0;
    }
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return day <= 29;
    } else {
        return day <= daysInMonth[month];
    }
}

void printCalendar(int year) {
    for (int m = 1; m <= 12; m++) {
        printf("%s %d\n", months[m - 1], year);

        int firstDayOfMonthWeekDay = getCorrectedWeekDay(getWeekDay(1, m, year));

        for (int f = 0; f < firstDayOfMonthWeekDay; f++) {
            printf("\t");
        }

        for (int d = 1; d <= 31; d++) {
            int weekDay = getCorrectedWeekDay(getWeekDay(d, m, year));
            if (validDay(d, m, year)) {
                printf("%d\t", d);

                if ((firstDayOfMonthWeekDay + d - 1) % 7 == 0) {
                    printf("\n");
                }
            }
        }
        printf("\n\n");
    }
}




int main() {
    printCalendar(2023);
    return 0;
}
