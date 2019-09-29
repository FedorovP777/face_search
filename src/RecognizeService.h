// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef UNTITLED_RECOGNIZESERVICE_H
#define UNTITLED_RECOGNIZESERVICE_H


#include <vector>
#include <chrono>
#include <vector>
#include <x86intrin.h>
#include "immintrin.h"
#include "FaceStorage.h"
#include "FaceProvider.h"
#include <iostream>
#include <cmath>

using namespace std;

class RecognizeService {

public:
    RecognizeService();

    vector<int> result;

    void float_to_m256(faceFloat& points, vector<__m256> &resultConvert);

    float compare_face(vector<__m256> a, vector<__m256> b);

    void
    search_compare_range(const vector<vector<__m256>> &knowFaces, int start, int end, const vector<__m256> &avxFaceCompare,
                         float compare_tolerance);

    void init(int max_memory_size);

    vector<int> search(faceFloat& vectorSearch);

    void addFaces(vector<faceFloat> &facePoints, vector<string> &facesId);

private:
    FaceStorage faceStorage;


};


#endif //UNTITLED_RECOGNIZESERVICE_H
