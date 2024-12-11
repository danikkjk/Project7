#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


double f_x(double x) {
    if (x <= 0) {
        return 2 * x - fabs(x + 1);
    }
    else if (x > 0 && x < 4) {
        return 2 * x * log(sqrt(x + 1));
    }
    else {
        return 2 * x / cbrt(x - 1);
    }
}


double f_xy(double x, double y) {
    return 2 * pow(x, 3) + 3 * pow(y, 1.0 / 3) + 2;
}

int main() {

    double a = -1, b = 5, h = 0.1;

    double c = -4, d = 4, hx = 0.1, hy = 0.15;


    printf("Tabulating f(x):\n");
    printf("x\t\tf(x)\n");
    double x = a, max_fx = -INFINITY, min_fx = INFINITY;
    while (x <= b + h / 2) {
        double fx = f_x(x);
        printf("%.2f\t\t%.6f\n", x, fx);
        if (fx > max_fx) max_fx = fx;
        if (fx < min_fx) min_fx = fx;
        x += h;
    }
    printf("Max f(x): %.6f\n", max_fx);
    printf("Min f(x): %.6f\n\n", min_fx);

    printf("Tabulating f(x, y):\n");
    printf("x\t\ty\t\tf(x, y)\n");
    double max_fxy = -INFINITY, min_fxy = INFINITY;
    for (x = a; x <= b + hx / 2; x += hx) {
        for (double y = c; y <= d + hy / 2; y += hy) {
            double fxy = f_xy(x, y);
            printf("%.2f\t\t%.2f\t\t%.6f\n", x, y, fxy);
            if (fxy > max_fxy) max_fxy = fxy;
            if (fxy < min_fxy) min_fxy = fxy;
        }
    }
    printf("Max f(x, y): %.6f\n", max_fxy);
    printf("Min f(x, y): %.6f\n", min_fxy);

    return 0;
}
