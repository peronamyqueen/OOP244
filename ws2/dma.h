/* 
Workshop 2
Filename: dma.h
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

#ifndef SENECA_DMA_H
#define SENECA_DMA_H

namespace seneca {
struct Samples {
    char* m_title;
    int* m_data;
    int m_size;
};

Samples* CreateSamples(const char* title);
void add(Samples& S, const int data[], int size);
void append(int*& data, int size, const int appendedData[], int dataSize);
void freemem(Samples*& s);
}

#endif
