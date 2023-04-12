#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float max_delta(float *delta, int n){
    float max = delta[0];

    for (int i = 1; i < n; i++){
        if (delta[i] > max){
            max = delta[i];
        }
    }
    return max;
}

int main() {
    printf("Програма розв’язує системи лінійних алгебраїчних рівнянь (СЛАР)");

    printf("\nCЛАР: \na11x1 + a12x2 + ... + a1nxn = b1 \na21x1 + a22x2 + ... + a2nxn = b2 \n................................ \nan1x1 + an2x2 + ... + annxn = bn");

    int n;
    printf("\nУкажіть розмір матриці (n*n), n = ");
    scanf("%d", &n);

    float **a = (float **) calloc(n, sizeof(float *));
    for(int i = 0; i < n; i++)  a[i] = (float *) calloc(n, sizeof(float));

    float *b = (float *) calloc(n, sizeof(float));

    printf("\nВведіть коефіцієнти. ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("\na%d%d = ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
        printf("\nb%d = ", i + 1);
        scanf("%f", &b[i]);
    }

    float e, sum;
    printf("\ne = ");
    scanf("%f", &e);

    float *x = (float *) calloc(n, sizeof(float));
    float *xp = (float *) calloc(n, sizeof(float));
    float *delta = (float *) calloc(n, sizeof(float));

    for (int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if(i != j){
                sum += a[i][j];
            }
            if(fabsf(a[i][i]) <= sum){
                printf("Помилка");
                return 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        xp[i] = b[i] / a[i][i];
    }

    do{
        for(int i = 0; i < n; i++){
            sum = -a[i][i] * xp[i];
            for (int j = 0; j < n; j++){
                sum += a[i][j] * xp[j];
            }
            if(a[i][i] == 0){
                printf("Помилка");
                return 1;
            }
            x[i] = (b[i] - sum) / a[i][i];
            delta[i] = fabsf(x[i] - xp[i]);
            xp[i] = x[i];
        }
    } while (max_delta(delta, n) > e);

    for(int i = 0; i < n; i++){
        printf("\nx%d = %f", i + 1, x[i]);
    }

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    free(x);
    free(xp);
    free(delta);
}
