#include <stdio.h>
#include <math.h>


int main() {

    float a, b, c;

    printf("Введіть значення сторони a: ");
    scanf("%f", &a);

    printf("Введіть значення сторони b: ");
    scanf("%f", &b);

    printf("Введіть значення сторони c: ");
    scanf("%f", &c);

    if (a <= 0 || b <= 0 || c <= 0 || (a + b) <= c || (a + c) <= b || (b + c) <= a ) {
        printf("Хмм... Спробуйте ввести інші значення  \n");
        return 1;
    }

    float s, perimeter, p = (a + b + c) / 2;

    s = sqrtf(p * (p - a) * (p - b) * (p - c));
    printf("Площа = %f \n", s);

    perimeter = a + b + c;
    printf("Периметр = %f \n", perimeter);

    float ha, hb, hc;

    ha = (2 * sqrtf(p * (p - a) * (p - b) * (p - c))) / a;
    printf("Висота, проведена до сторони a = %f \n", ha);

    hb = (2 * sqrtf(p * (p - a) * (p - b) * (p - c))) / b;
    printf("Висота, проведена до сторони b = %f \n", hb);

    hc = (2 * sqrtf(p * (p - a) * (p - b) * (p - c))) / c;
    printf("Висота, проведена до сторони c = %f \n", hc);

    float ma, mb, mc;

    ma = sqrtf(2 * b * b + 2 * c * c - a * a) / 2;
    printf("Медіана, проведена до сторони a = %f \n", ma);

    mb = sqrtf(2 * a * a + 2 * c * c - b * b) / 2;
    printf("Медіана, проведена до сторони b = %f \n", mb);

    mc = sqrtf(2 * a * a + 2 * b * b - c * c) / 2;
    printf("Медіана, проведена до сторони c = %f \n", mc);

    float ba, bb, bc;

    ba = (2 / (b + c)) * sqrtf(b * c * p * (p - a));
    printf("Бісектриса, проведена до сторони a = %f \n", ba);

    bb = (2 / (a + c)) * sqrtf(a * c * p * (p - b));
    printf("Бісектриса, проведена до сторони b = %f \n", bb);

    bc = (2 / (a + b)) * sqrtf(a * b * p * (p - c));
    printf("Бісектриса, проведена до сторони c = %f \n", bc);

}


