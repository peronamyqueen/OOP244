#include <stdio.h>
#include <string.h>
#include "product.h"

Product inputValues() {
    Product newProduct;
    char input[100];

    printf("Input the name of a product: ");
    while (1) {
        if (!fgets(input, sizeof(input), stdin))
            continue;

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Name cannot be empty. Try again: ");
            continue;
        }

        strncpy(newProduct.name, input, sizeof(newProduct.name) - 1);
        newProduct.name[sizeof(newProduct.name) - 1] = '\0';
        break;
    }

    printf("Input the price of a product: ");
    while (1) {
        if (!fgets(input, sizeof(input), stdin))
            continue;

        if (sscanf(input, "%f", &newProduct.price) != 1 || newProduct.price <= 0) {
            printf("Invalid price. Enter a number > 0: ");
            continue;
        }
        break;
    }

    printf("Input a discount amount for a product: ");
    while (1) {
        if (!fgets(input, sizeof(input), stdin))
            continue;

        if (sscanf(input, "%d", &newProduct.discount) != 1 ||
            newProduct.discount < 0 || newProduct.discount > 90) {
            printf("Discount must be between 0 and 90: ");
            continue;
        }
        break;
    }

    return newProduct;
}

float calculatePrice(float price , int discount){
    return price * (1 - discount / 100.0f);
}

