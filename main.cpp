// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


#include <iostream>
#include <chrono>
#include <vector>
#include <x86intrin.h>
#include "immintrin.h"
#include "src/FaceStorage.h"
#include "src/FaceProvider.h"
#include "src/RecognizeService.h"
#include <thread>
#include <mutex>
#include <time.h>
#include <string>

//typedef const __m256d d;


std::mutex mtx;
static int counter = 0;
static const int MAX_COUNTER_VAL = 100;

using namespace std;

//
//void sub_matrix(vector<float>, vector<float>, vector<float>);
//
//float compare_face(vector<__m256> a, vector<__m256> b, float *p);
//
//void float_to_m256(vector<float> a, vector<vector<__m256>> &r, int i);
//
//void float_to_m256_1(vector<float> a, vector<__m256> &r);
//
//vector<int> op;
//
//void task1(int i) {
//    op[i] = 19;
//    std::cout << i << endl;
//}
//
int main(int argc, const char *argv[]) {


    FaceProvider faceProvider;
    RecognizeService recognizeService;
    int countFaces = 20000;
    recognizeService.init(countFaces);

    faceFloat floatFaceCompare;
    floatFaceCompare = faceProvider.getRecognizeFace();



    vector<faceFloat> floatFacesIn;
    floatFacesIn.resize(countFaces);
    for (int i = 0; i < countFaces; ++i) {
        floatFacesIn[i] = faceProvider.getStoredFace();

    }

    cout << sizeof(faceFloat) * floatFacesIn.size() << endl;

    vector<string> idFaces;
    idFaces.resize(countFaces);
    for (int i = 0; i < countFaces; ++i) {
        idFaces[i] = std::to_string(i);
    }
    cout << "faces generated" << endl;

    recognizeService.addFaces(floatFacesIn, idFaces);
    cout << "faces loaded" << endl;
    floatFacesIn.clear();
    idFaces.clear();
    cout << 0 << endl;
    vector<int> resultSearch = recognizeService.search(floatFaceCompare);
    return 1;
}
