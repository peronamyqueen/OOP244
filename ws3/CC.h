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
  char *name;
  short cvv;
  short expMon;
  short expYear;
  unsigned long long cardNo;
  void aloCopy(const char *name);
  void freeMem();
  bool validate(const char *name, unsigned long long cardNo, short cvv,
                short expMon, short expYear) const;
  void display(const char *name, unsigned long long number, short expYear,
               short expMon, short cvv) const;
  void prnNumber(unsigned long long no) const;

public:
  CC();
  CC(const char *cc_name, unsigned long long cc_no, short cc_cvv,
     short cc_expMon = 12, short cc_expYear = 26);

  ~CC();

  void set();
  bool isEmpty() const;
  void set(const char *cc_name, unsigned long long cc_no, short cc_cvv,
           short cc_expMon, short cc_expYear);
  void display() const;
};
} // namespace seneca
#endif
