#include <iostream>
#include <cassert>
#include <cmath>

extern "C" {
    #include "product.h"
}

int main() {

    /* =======================
       TEST 1 — Black-box test
       Normal valid input
       ======================= */
    {
        float price = 100.0f;
        int discount = 25;
        float expected = 75.0f;

        float result = calculatePrice(price, discount);

        assert(std::fabs(result - expected) < 0.001f);
        std::cout << "Test 1 passed: Normal discount calculation\n";
    }

    /* =======================
       TEST 2 — Black-box test
       Boundary case: 0% discount
       ======================= */
    {
        float price = 120.0f;
        int discount = 0;
        float expected = 120.0f;

        float result = calculatePrice(price, discount);

        assert(std::fabs(result - expected) < 0.001f);
        std::cout << "Test 2 passed: Zero discount\n";
    }

    /* =======================
       TEST 3 — Black-box test
       Boundary case: maximum discount (90%)
       ======================= */
    {
        float price = 200.0f;
        int discount = 90;
        float expected = 20.0f;

        float result = calculatePrice(price, discount);

        assert(std::fabs(result - expected) < 0.001f);
        std::cout << "Test 3 passed: Maximum allowed discount\n";
    }

    /* =======================
       TEST 4 — White-box test
       Floating-point precision check
       ======================= */
    {
        float price = 99.99f;
        int discount = 33;

        float manual = price * (1 - discount / 100.0f);
        float result = calculatePrice(price, discount);

        assert(std::fabs(result - manual) < 0.001f);
        std::cout << "Test 4 passed: Floating-point precision\n";
    }

    /* =======================
       TEST 5 — White-box test
       Defensive test: negative price
       ======================= */
    {
        float price = -100.0f;
        int discount = 10;

        float expected = price * (1 - discount / 100.0f);
        float result = calculatePrice(price, discount);

        assert(std::fabs(result - expected) < 0.001f);
        std::cout << "Test 5 passed: Negative price handling\n";
    }

    std::cout << "\nAll tests passed successfully.\n";
    return 0;
}

