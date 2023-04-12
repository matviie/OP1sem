#include <stdio.h>


int main() {

    printf("Програму – календар, яка за введеною датою (виключно дня, місяця, року) виводить день тижня прописом. \n");

    int year, month, date, n;
    char s;

    printf("Рік: ");
    if (scanf("%4u%c", &year, &s) != 2 || s != '\n'){
        printf("error");
        return 1;
    }

    printf("Місяць: ");
    if (scanf("%2u%c", &month, &s) != 2 || s != '\n'){
        printf("error");
        return 1;
    }

    printf("Число: ");
    if (scanf("%2u%c", &date, &s) != 2 || s != '\n'){
        printf("error");
        return 1;
    }

    if (year < 0 || month <= 0 || month > 12 || date <= 0 || date > 31){
        printf("Error \n");
        return 1;
    }

    short int leap_year = (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);


    if (leap_year && month <= 2) {
        n = 1;
    }
    else if (!leap_year && month <= 2) {
        n = 2;
    }
    else if (month > 2) {
        n = 0;
    }

    int day = ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;

    switch (day) {
        case 0: // "у випадку"
            printf("Понеділок \n");
            break;
        case 1:
            printf("Вівторок \n");
            break;
        case 2:
            printf("Середа \n");
            break;
        case 3:
            printf("Четвер \n");
            break;
        case 4:
            printf("Пʼятниця \n");
            break;
        case 5:
            printf("Субота \n");
            break;
        case 6:
            printf("Неділя \n");
            break;
    }
}
