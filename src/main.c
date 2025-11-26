#include <stdio.h>
#include <stdlib.h>

int main() {
    int fromCurrency, toCurrency;
    double amount, result;
    char cont;

    do {
        clearScreen();
        printf("Currency conveter\n");
        printf("\n");
        printf("\n\n");

        showCurrencies();

        printf("\nEnter FROM currency (1-6): ");
        scanf("%d", &fromCurrency);

        printf("Enter TO currency (1-6): ");
        scanf("%d", &toCurrency);

        if (fromCurrency == toCurrency) {
            printf("\nError: Both currencies cannot be the same!\n");
            printf("Press Enter to try again...");
            getchar(); getchar();
            continue;
        }

        printf("\nEnter amount: ");
        scanf("%lf", &amount);

        double rate = getRate(fromCurrency, toCurrency);

        if (rate == 0.0) {
            printf("\nConversion rate not found!\n");
        } else {
            result = convert(amount, rate);
            printf("\n\n");
            printf("  %.2f (Currency %d)  =  %.2f (Currency %d)\n",
                   amount, fromCurrency, result, toCurrency);
            printf("\n");
        }

        printf("\nDo you want to convert again? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    printf("\nThank you for using the Advanced Converter!\n");
    return 0;
}
