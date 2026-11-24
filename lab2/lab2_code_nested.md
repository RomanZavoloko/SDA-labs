# Програма 1: Вкладені цикли (Варіант 8)

```c
#include <stdio.h>
#include <math.h>


double calc_nested(double x, int n, long long *ops) {
    double sum = 0.0;
    double four_x2 = 4.0 * x * x;
    *ops += 4;


    *ops += 2;
    for (int i = 1; i <= n; i++) {
        double term = 0.5;
        *ops += 1;


        *ops += 2;
        for (int j = 1; j <= i; j++) {
            term *= four_x2 / ((2.0 * j - 1.0) * (2.0 * j));
            *ops += 7;
            *ops += 2;
        }


        sum += term;
        *ops += 2;
        *ops += 2;
    }
    return sum;
}


int main(void) {
    const double x = 1.0 / 3.0;
    int n;


    printf("Enter a natural number n: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Error: n must be a natural number (n >= 1).\n");
        return 1;
    }


    double exact = sinh(x) * sinh(x);
    long long ops = 0;
    double approx = calc_nested(x, n, &ops);
    double error = fabs(exact - approx);


    printf("x = %.7f\n", x);
    printf("Exact value sinh^2(x) = %.7f\n", exact);
    printf("Approx value S(%d)    = %.7f\n", n, approx);
    printf("Absolute error        = %.3e\n", error);
    printf("Operations            = %lld\n", ops);


    return 0;
}
```
