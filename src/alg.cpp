// Copyright 2022 NNTU-CS
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return value;
    } else if (!(n & 1)) {
        return pown(value * value, n / 2);
    } else {
        return value * pown(value * value, n / 2);
    }
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint64_t i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    long double result = 0.0;
    for (uint16_t i = 0; i <= count; i++) {
        result += pown(x, i) / fact(i);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    long double result = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        result += (pown(-1, i) / fact(2 * i + 1)) * pown(x, 2 * i + 1);
    }
    return result;
}

double cosn(double x, uint16_t count) {
    long double result = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        result += (pown(-1, i) * pown(x, 2 * i)) / fact(2 * i);
    }
    return result;
}
