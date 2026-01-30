/*
Workshop 3
Filename: CC.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work
-----------------------------------------------------------
*/

#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
class CC {
        // Private Attributes
        char *name;                // Cardholder's name (dynamically allocated)
        short cvv;                 // CVV (3-digit security code)
        short expMon;              // Expiry month (1-12)
        short expYear;             // Expiry year (24-32)
        unsigned long long cardNo; // Credit card number
        // Private Methods - Dynamic Memory Management
        void aloCopy(const char *name);
        void freeMem();
        // Private Methods - Validation and Display
        bool validate(const char *name, unsigned long long cardNo, short cvv,
                      short expMon, short expYear) const;
        void display(const char *name, unsigned long long number, short expYear,
                     short expMon, short cvv) const;
        void prnNumber(unsigned long long no) const;

    public:
        // Constructors
        CC(); // No-argument constructor
        CC(const char *cc_name, unsigned long long cc_no, short cc_cvv,
           short cc_expMon = 12,
           short cc_expYear = 26); // Five-argument constructor
        // Destructor
        ~CC();
        // Public Methods
        void set();           // Set to safe empty state
        bool isEmpty() const; // Check if empty
        void set(const char *cc_name, unsigned long long cc_no, short cc_cvv,
                 short cc_expMon,
                 short cc_expYear); // Set with validation
        void display() const;       // Public display method
};
} // namespace seneca
#endif // !SENECA_CC_H_
