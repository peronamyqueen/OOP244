#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstddef>
#include <cstdio> 

namespace seneca {

   struct PhoneRec {
      char name[16];
      char lastname[26];
      long long phone;
   };

   void read(char* name);

   void print(long long phone);

   void print(const PhoneRec& rec, size_t& row, const char* filter = nullptr);

   bool read(PhoneRec& rec, FILE* fptr);

   void print(PhoneRec* recs[], size_t size, const char* filter = nullptr);

   void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size);

   void sort(PhoneRec* ptrs[], size_t size, bool byLastName);

}

#endif 

