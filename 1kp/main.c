#include <stdio.h>


int roman(int i, int j, char c) {
    while (i >= j) {
        putchar(c);
        i -= j;
    }


    return i;
}


int main() {
    int number;

    printf("Enter a number: ");
    scanf("%u", &number);

    number = roman(number, 1000, 'M');
    number = roman(number, 500, 'D');
    number = roman(number, 100, 'C');
    number = roman(number, 50, 'L');
    number = roman(number, 10, 'X');
    number = roman(number, 5, 'V');
    number = roman(number, 1, 'I');

}
