// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef UNTITLED_FACESTORAGE_H
#define UNTITLED_FACESTORAGE_H


#include <iostream>
#include <chrono>
#include <vector>

#include <x86intrin.h>
#include "immintrin.h"
#include <boost/log/trivial.hpp>
#include <string>

using namespace std;


class FaceStorage {


public:

    FaceStorage();

    vector<vector<__m256>> knowFaces;
    vector<string> facesId;

    void addFace(vector<__m256> newFace, string &faceId);


    void initStorage(int size);

    void reserve(int size);

};

#endif //UNTITLED_FACESTORAGE_H
