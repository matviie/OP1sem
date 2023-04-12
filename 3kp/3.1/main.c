#include <stdio.h>
#include <math.h>


int main() {

    printf("Програма знаходить значення у із заданою точністю в залежності від введеного значення х і k (х під корнем в k степені). \n");

    float y = 1, x, k, e, d = 1;

    printf("x = ");
    scanf("%f", &x);

    printf("k = ");
    scanf("%f", &k);

    if (k > 0){
        if ((int)k % 2 == 0 && x < 0){
            printf("Помилка");
            return 1;
        }
    } else if (k < 0){
        if ((int)k % 2 == 0 && x <= 0){
            printf("Помилка");
            return 1;
        } else if ((int)k % 2 != 0 && x == 0){
            printf("Помилка");
            return 1;
        }
    } else{
        printf("Помилка");
        return 1;
    }

    printf("е = ");
    scanf("%f", &e);

    while (fabsf(d) >= e){
        d = (1 / fabsf(k)) * ((x / powf(y, (fabsf(k) - 1)) - y));
        y += d;
    }
    if (k < 0){
        y = 1 / y;
    }

    printf("y = %f", y);
}
