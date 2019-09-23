//
// Created by user on 17.08.19.
//

#ifndef UNTITLED_RECOGNIZESERVICE_H
#define UNTITLED_RECOGNIZESERVICE_H


#include <vector>
#include <chrono>
#include <vector>
#include <x86intrin.h>
#include "immintrin.h"
#include "FaceStorage.h"
#include <iostream>
#include <cmath>

using namespace std;

class RecognizeService {

public:
    RecognizeService(FaceStorage faceStorage);

    vector<int> result;

    void float_to_m256(vector<float> points, vector<__m256> &result);

    float compare_face(vector<__m256> a, vector<__m256> b);

    void
    search_compare(const vector<vector<__m256>> &knowFaces, int start, int end, const vector<__m256> &avxFaceCompare,
                   float compare_tolerance);

    void init(int max_memory_size);

    void search(vector<float> vector);

    void addFaces(vector<vector<float>> facePoints, vector<string> facesId);

private:
    FaceStorage faceStorage;


};


#endif //UNTITLED_RECOGNIZESERVICE_H
