#include <stdio.h>
#include <math.h>


int main() {
    printf("Програма розвʼязує кубічне рівняння (де a, b, c - коефіцієнти кубічного рівняння)\n");

    float a, b, c;

    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    printf("c = ");
    scanf("%f", &c);

    float p, q;

    p = b - (powf(a, 2) / 3);
    q = (2 * powf(a, 3) / 27) - (a * b / 3) + c;

    float d;

    d = (powf(p, 3) / 27) + (powf(q, 2) / 4);

    float y1, y2, y3, u, v, y, z, x1, x2, x3, r, fi;

    y = -q / 2 + sqrtf(d);
    u = cbrtf(y);


    if (u == 0 || p == 0){
        printf("Помилка");
        return 1;
    }

    if (d > 0){
        v = -p / (3 * u);
        z = sqrtf(3) * (u - v) / 2;
        y1 = u + v;
        y2 = -(y1 / 2);
        x1 = y1 - a / 3;
        x2 = y2 - a / 3;

        printf("x1 = %f\nx2 = %f + i * %f\nx3 = %f - i * %f\n", x1, x2, z, x2, z);

    } else if (d < 0){
        if (-powf(p, 3) / 27 >= 0){
            r = sqrtf(powf(p, 3) / -27);
            fi = acosf(-q / (2 * r));
            y1 = 2 * fabsf(cbrtf(r)) * cosf(fi / 3);
            y2 = 2 * fabsf(cbrtf(r)) * cosf((fi + 2 * M_PI) / 3);
            y3 = 2 * fabsf(cbrtf(r)) * cosf((fi + 4 * M_PI) / 3);
            x1 = y1 - a / 3;
            x2 = y2 - a / 3;
            x3 = y3 - a / 3;
            printf("x1 = %f\nx2 = %f\nx3 = %f\n", x1, x2, x3);
        }
    } else{
        y1 = 3 * q / p;
        y2 = -(3 * q / (2 * p));
        x1 = y1 - a / 3;
        x2 = y2 - a / 3;
        printf("x1 = %f\nx2 = %f\nx3 = %f\n", x1, x2, x2);

    }
}
