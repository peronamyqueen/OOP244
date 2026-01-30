// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char name[25];   // Name of the product (null-terminated string)
    float price;     // Original price of the product
    int discount;    // Discount percentage (0–90)
} Product;

/**
 * This function interactively reads the product name, price, and discount
 * from standard input. Input validation is performed to ensure the name
 * is not empty, the price is greater than zero, and the discount is within
 * the allowed range.
 *
 * @return A Product structure populated with valid user input.
 */
Product inputValues();

/**
 * This function computes the discounted price using the given price and
 * discount percentage. It performs a simple mathematical calculation and
 * does not perform input validation.
 *
 * @param price The original price of the product.
 * @param discount The discount percentage to apply.
 *
 * @return The final price after the discount is applied.
 */
float calculatePrice(float price, int discount);

#ifdef __cplusplus
}
#endif

#endif

