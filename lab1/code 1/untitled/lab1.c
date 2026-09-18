#include <stdio.h>

int main(void) {
    float x, y;
    printf("Please enter x: ");
    scanf("%f", &x);

    if (x >= 11) {
        y = -x * x * x / 7 + 10;
        printf("%.2f\n", y);
    }
    else if (x >= 0) {
        if (x < 7) {
            y = -6 * x * x + 8;
            printf("%.2f\n", y);
        }
        else {
            printf("No value for x\n");
        }
    }
    else if (x <= -10) {
        y = -x * x * x / 7 + 10;
        printf("%.2f\n", y);
    }
    else {
        printf("No value for x\n");
    }

    return 0;
}