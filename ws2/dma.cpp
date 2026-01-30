/*
Workshop 2
Filename: dma.cpp
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

#include "dma.h"
#include "cstr.h"

namespace seneca {

Samples *CreateSamples(const char *title) {
    Samples *newSample = new Samples;

    newSample->m_title = new char[strlen(title) + 1];
    strcpy(newSample->m_title, title);

    newSample->m_data = nullptr;
    newSample->m_size = 0;

    return newSample;
}

void add(Samples &S, const int data[], int size) {
    if (S.m_data == nullptr) {
        S.m_data = new int[size];

        for (int i = 0; i < size; i++) {
            S.m_data[i] = data[i];
        }

        S.m_size = size;
    } else {
        append(S.m_data, S.m_size, data, size);
        S.m_size += size;
    }
}

void append(int *&data, int size, const int appendedData[], int dataSize) {
    int *temp = new int[size + dataSize];

    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    for (int i = 0; i < dataSize; i++) {
        temp[size + i] = appendedData[i];
    }

    delete[] data;

    data = temp;
}

void freemem(Samples *&s) {
    if (s != nullptr) {
        delete[] s->m_title;
        delete[] s->m_data;
        delete s;
        s = nullptr;
    }
}
} // namespace seneca
