#include <stdio.h>
#include <math.h>


const float ALFA = 0.00001;


float pold (float a, float b, float e, float y, float (*fpr)(float , float )){
    float x;
    while(fabsf(b - a) > e){
        x = (a + b) / 2;
        ((*fpr)(a, y) * (*fpr)(x, y) > 0) ? (a = x) : (b = x);
    }
    return x;
}


float func1 (float x, float y) {
    return (cosf(y / x) - 2 * sinf(1 / x) + 1 / x);
}


float func2 (float x, float y) {
    return (sinf(logf(x)) - cosf(logf(x)) + y * logf(x));
}


float newton (float b, float e, float y, float (*fpr)(float, float)){
    float delta, x, derivative;
    x = b;
    derivative = ((*fpr)(x + ALFA, y) - (*fpr)(x, y)) / ALFA;
    delta = (*fpr)(x, y) / derivative;

    while (fabsf(delta) > e){
        x = x - delta;
        derivative = ((*fpr)(x + ALFA, y) - (*fpr)(x, y)) / ALFA;
        delta = (*fpr)(x, y) / derivative;
    }
    return x;
}


float (*fpr)(float, float);


int main() {
    printf("Програма обчислює корені нелінійних рівнянь на заданому проміжку.");

    float a, b, x, y, e;

    printf("\na = ");
    scanf("%f", &a);
    printf("\nb = ");
    scanf("%f", &b);
    printf("\ny = ");
    scanf("%f", &y);
    printf("\ne = ");
    scanf("%f", &e);

    printf("\nОберіть функцію для розрахунку: \n1. cosf(y / x) - 2 * sinf(1 / x) + 1 / x \n2. sinf(logf(x)) - cosf(logf(x)) + y * logf(x)\n");
    int nf, nm;
    scanf("%d", &nf);
    printf("\nОберіть метод для розрахунку функції: \n1) метод половинного ділення \n2) метод Ньютона\n");
    scanf("%d", &nm);

    if (nf == 1){
        fpr = func1;
        if(nm == 1){
            x = pold(a, b, e, y, fpr);
        } else {
            x = newton(b, e, y, fpr);
        }
    } else{
        fpr = func2;
        if(nm == 1){
            x = pold(a, b, e, y, fpr);
        } else{
            x = newton(b, e, y, fpr);
        }
    }
    if(x > a && x < b){
        printf("x = %f", x);
    } else{
        printf("Помилка. Даний метод не підходить для розрахунку цієї функції.");
        return 1;
    }
}




