/*
Workshop 3
Filename: CC.cpp
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

#include "CC.h"
#include "cstr.h"
#include <iostream>
using namespace std;
namespace seneca {

void CC::aloCopy(const char *cc_name) {
  // Allocate memory for the name and copy it
  int length = strlen(cc_name);
  name = new char[length + 1];
  strcpy(name, cc_name);
}

void CC::freeMem() {
  // Deallocate memory and set pointer to nullptr
  delete[] name;
  name = nullptr;
}

bool CC::validate(const char *name, unsigned long long cardNo, short cvv,
                  short expMon, short expYear) const {
  bool valid = true;

  if (name == nullptr || strlen(name) <= 2) {
    valid = false;
  }

  if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) {
    valid = false;
  }

  if (cvv < 100 || cvv > 999) {
    valid = false;
  }

  if (expMon < 1 || expMon > 12) {
    valid = false;
  }

  if (expYear < 24 || expYear > 32) {
    valid = false;
  }

  return valid;
}

void CC::prnNumber(unsigned long long no) const {
  cout << no / 1000000000000ull << " ";
  no %= 1000000000000ull;
  cout.fill('0');
  cout.width(4);
  cout.setf(ios::right);
  cout << no / 100000000ull << " ";
  no %= 100000000ull;
  cout.width(4);
  cout << no / 10000ull << " ";
  no %= 10000ull;
  cout.width(4);
  cout << no;
  cout.unsetf(ios::right);
  cout.fill(' ');
}

void CC::display(const char *name, unsigned long long number, short expYear,
                 short expMon, short cvv) const {
  char lname[31]{};
  strncpy(lname, name, 30);
  lname[30] = '\0';
  cout << "| ";
  cout.width(30);
  cout.fill(' ');
  cout.setf(ios::left);
  cout << lname << " | ";
  prnNumber(number);
  cout << " | " << cvv << " | ";
  cout.unsetf(ios::left);
  cout.setf(ios::right);
  cout.width(2);
  cout << expMon << "/" << expYear << " |" << endl;
  cout.unsetf(ios::right);
}

// Constructors
CC::CC() {
  set(); // Initialize to safe empty state
}

// Overloaded constructor
CC::CC(const char *cc_name, unsigned long long cc_no, short cc_cvv,
       short cc_expMon, short cc_expYear) {
  set();
  // If all arguments are valid, set the values
  if (validate(cc_name, cc_no, cc_cvv, cc_expMon, cc_expYear)) {
    aloCopy(cc_name);
    cardNo = cc_no;
    cvv = cc_cvv;
    expMon = cc_expMon;
    expYear = cc_expYear;
  }
}

// Destructor
CC::~CC() {
  freeMem(); // Deallocate any dynamic resources
}

void CC::set() {
  // Set to safe empty state
  name = nullptr;
  cvv = 0;
  expMon = 0;
  expYear = 0;
  cardNo = 0;
}

bool CC::isEmpty() const {
  return name == nullptr; // Returns true if cardholder name pointer is nullptr
}

void CC::set(const char *cc_name, unsigned long long cc_no, short cc_cvv,
             short cc_expMon, short cc_expYear) {
  // First deallocate existing memory and set to safe empty state
  freeMem();
  set();
  // If all arguments are valid, set the values
  if (validate(cc_name, cc_no, cc_cvv, cc_expMon, cc_expYear)) {
    aloCopy(cc_name);
    cardNo = cc_no;
    cvv = cc_cvv;
    expMon = cc_expMon;
    expYear = cc_expYear;
  }
}

void CC::display() const {
  if (isEmpty()) {
    cout << "Invalid Credit Card Record" << endl;
  } else {
    display(name, cardNo, expYear, expMon, cvv);
  }
}
} // namespace seneca
