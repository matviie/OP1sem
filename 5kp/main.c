#include <stdio.h>
#include <string.h>


void sort(char **list, int n_str){
    for(int i = 0; i < n_str - 1; i++){ 
        for(int j = i + 1; j < n_str; j++){
            if (strcmp(list[i], list[j]) > 0){
                char *tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}

int main() {
    printf("Програма зчитує кількість елементів масиву рядків і сам масив, виводить на екран впорядкований масив рядків.");

    int n_str, str_n_s;

    printf("\nВведіть кількість рядків: ");
    scanf("%d", &n_str);
    printf("\nВведіть кількість символів у рядку: ");
    scanf("%d", &str_n_s);

    char list[n_str][str_n_s];
    char *addr[n_str];
    int i;

    for (i = 0; i < n_str; i++){
        printf("\n%d >> ", i + 1);
        scanf("%s", &list[i]);
        if(str_n_s != strlen(list[i])){
            printf("Помилка");
            return 1;
        }
    }

    for (i = 0; i < n_str; i++) addr[i] = list[i];

    sort(addr, n_str);

    printf("\n");
    for (i = 0; i < n_str; i++){
        for (int j = 0; j < str_n_s; j++){
            printf("%c ", addr[i][j]);
        }
        printf("\n");
    }
}
