//
// Created by user on 17.08.19.
//

#ifndef UNTITLED_FACESTORAGE_H
#define UNTITLED_FACESTORAGE_H


#include <iostream>
#include <chrono>
#include <vector>

#include <x86intrin.h>
#include "immintrin.h"
#include <boost/log/trivial.hpp>

using namespace std;


class FaceStorage {


public:
    vector<vector<__m256>> knowFaces;

    void addFace(vector<__m256> newFace);

    void initStorage(int size);

    void reserve(int size);

};

#endif //UNTITLED_FACESTORAGE_H
