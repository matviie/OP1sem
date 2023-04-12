#include <stdio.h>


void sort(float *mas, int n);


int main() {
    int n;

    printf("Кількість елементів: ");
    scanf("%d", &n);

    float mas[n];

    printf("\nВведені елементи масиву: ");

    for(int i = 0; i < n; ++i) scanf("%f", &mas[i]);

    sort(mas, n);

    for(int i = 0; i < n; ++i) printf("%.3f ", mas[i]);
}


void sort(float *mas, int n) {
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(mas[i] > mas[j]){
                float m = mas[i];
                mas[i] = mas[j];
                mas[j] = m;
            }
        }
    }
}
