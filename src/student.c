#include <stdio.h>
#include <stdlib.h>

void showCurrencies() {
    printf("Available Currencies:\n");
    printf("1. USD - United States Dollar\n");
    printf("2. EUR - Euro\n");
    printf("3. GBP - British Pound\n");
    printf("4. INR - Indian Rupee\n");
    printf("5. JPY - Japanese Yen\n");
    printf("6. AUD - Australian Dollar\n");
}


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


double convert(double amount, double rate) {
    return amount * rate;
}


double getRate(int from, int to) {
    double rates[6][6] = {
        // USD   EUR    GBP     INR      JPY     AUD
        {1.0,  0.91,  0.78,  83.20,  143.50, 1.48},   // USD
        {1.10, 1.0,   0.86,  91.20,  158.40, 1.62},   // EUR
        {1.28, 1.16,  1.0,  105.80, 180.22, 1.88},    // GBP
        {0.012,0.011,0.0094, 1.0,   1.71,  0.018},    // INR
        {0.007,0.0063,0.0055,0.58,   1.0,  0.010},    // JPY
        {0.67, 0.62,  0.53,  54.40,  98.00, 1.0}      // AUD
    };

    if (from < 1 || from > 6 || to < 1 || to > 6)
        return 0.0;

    return rates[from - 1][to - 1];
}
