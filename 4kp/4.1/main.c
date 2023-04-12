#include <stdio.h>
#include <math.h>

int main() {

    float x1, x2, dx, e;

    printf("x1 = ");
    scanf("%f", &x1);

    printf("\nx2 = ");
    scanf("%f", &x2);

    printf("\ndx = ");
    scanf("%f", &dx);

    printf("\ne = ");
    scanf("%f", &e);

    if (x1 < x2 && dx < 0) {
        printf("Помилка, значення dx має бути більше нуля при x1 < x2");
        return 1;
    }
    if (x1 > x2 && dx > 0) {
        printf("Помилка, значення dx має бути менше нуля при x1 > x2");
        return 1;
    }
    if (dx == 0){
        printf("Помилка, значення dx не може дорівнювати нулю");
        return 1;
    }

    float sinx, x, delta;

    printf("\tx\t\tsin(x)\t\tsin(Taylor)\tsin(x)-sin(Taylor)\n");

    if (x1 > x2){
        float tmp = x1;
        x1 = x2;
        x2 = tmp;
        dx = -dx;
    }

    for(x = x1; x <= x2; x += dx){
        sinx = 1;
        delta = 1;

        float n = 1;
        float xr;
        xr = x * M_PI / 180;
        sinx = delta = xr;

        while (fabsf(delta) >= e){
            delta = delta * (-powf(xr, 2)) / ((n + 1) * (n + 2));
            sinx += delta;
            n += 2;
        }

        printf("%f\t%f\t%f\t%f\n", x, sinf(xr), sinx, sinf(xr) - sinx);
    }
}
