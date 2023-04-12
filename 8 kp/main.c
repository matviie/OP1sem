#include <stdio.h>
#include <math.h>


typedef struct {
    double real;
    double imag;
} complex;


complex result(complex a, complex b, complex c, complex d){
    complex res;
    res.real = (a.real * c.real + b.imag * d.imag) / (c.real * c.real + d.imag * d.imag);
    res.imag = (b.imag * c.real - a.real * d.imag) / (c.real * c.real + d.imag * d.imag);
    return res;
}


int main() {

    complex a, b, c, d, z;

    unsigned int n;
    printf("Оберіть коливальний контур (1, 2, 3, 4): ");
    scanf("%u", &n);

    double r1, r2;
    if (n < 3){
        printf("\nR = ");
        scanf("%lf", &r1);
    } else if (n == 3 || n == 4){
        printf("\nR1 = ");
        scanf("%lf", &r1);
        printf("\nR2 = ");
        scanf("%lf", &r2);
    }

    double l, c1, fmin, fmax, df;
    printf("\nL = ");
    scanf("%lf", &l);
    printf("\nC = ");
    scanf("%lf", &c1);
    printf("\nfmin = ");
    scanf("%lf", &fmin);
    printf("\nfmax = ");
    scanf("%lf", &fmax);
    printf("\ndf = ");
    scanf("%lf", &df);

    double w, f0;

    for (double f = fmin; f <= fmax; f += df) {
        w = 2 * M_PI * f;

        switch (n) {
            case 1:
                a.real = l / c1;
                b.imag = - (r1 / (w * c1));
                c.real = r1;
                d.imag = w * l - 1 / (w * c1);
                z = result(a, b, c, d);
                printf("\nf = %f\tZ = %e + i * %e", f, z.real, z.imag);
                break;
            case 2:
                a.real = l / c1;
                b.imag = r1 / (w * c1);
                c.real = r1;
                d.imag = w * l - 1 / (w * c1);
                z = result(a, b, c, d);
                printf("\nf = %f\tz = %e + i * %e", f, z.real, z.imag);
                break;
            case 3:
                a.real = r1 * r2;
                b.imag = r1 * (w * l - 1 / (w * c1));
                c.real = r1 + r2;
                d.imag = w * l - 1 / (w * c1);
                z = result(a, b, c, d);
                printf("\nf = %f\tZ = %e + i * %e", f, z.real, z.imag);
                break;
            case 4:
                a.real = r1 * r2 + l / c1;
                b.imag = w * l * r1- r2 / (w * c1);
                c.real = r1 + r2;
                d.imag = w * l - 1 / (w * c1);
                z = result(a, b, c, d);
                printf("\nf = %f\tZ = %e + i * %e", f, z.real, z.imag);
                break;
        }
    }

    f0 = 1 / (2 * M_PI * sqrt(l * c1));
    printf("\nf0 = %f", f0);
}
