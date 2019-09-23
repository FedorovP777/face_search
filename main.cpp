// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


#include <iostream>
#include <chrono>
#include <vector>
#include <x86intrin.h>
#include "immintrin.h"
#include "./src/FaceStorage.h"
#include "src/FaceProvider.h"
#include "src/RecognizeService.h"
#include <thread>
#include <mutex>
#include <time.h>
#include <string>

typedef const __m256d d;

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



//    op.resize(10);
//
//    vector<thread> threads;
//
//


    FaceStorage faceStorage;
    FaceProvider faceProvider;
    RecognizeService recognizeService(faceStorage);
    int countFaces = 100;
    recognizeService.init(countFaces);

    vector<float> floatFaceCompare;
    faceProvider.getRecognizeFace(floatFaceCompare);

    vector<vector<float >> floatFacesIn;
    floatFacesIn.resize(countFaces);
    for (int i = 0; i < countFaces; ++i) {
        faceProvider.getStoredFace(floatFacesIn[i]);

    }

    vector<string> idFaces;
    idFaces.resize(countFaces);
    for (int i = 0; i < countFaces; ++i) {
//        std::string f_str = std::to_string(i);
        idFaces[i] = std::to_string(i);
//        cout << f_str << endl;
    }

    recognizeService.search(floatFaceCompare);
    return 1;
//    vector<vector<float >> floatFacesIn;
//    vector<float> floatFaceCompare;
//    vector<__m256> avxFaceCompare;
//    int inSizeFaces = 1100000;
//    vector<int> result;
//
//    faceStorage.initStorage(inSizeFaces);
//
//    float compare_tolerance = 2;
////    compare_tolerance = compare_tolerance * compare_tolerance;
//
//    cout << "Start load float vector" << endl;
//    floatFacesIn.resize(inSizeFaces);
//    cout << "End load float vector" << endl;
////    result.resize(inSizeFaces);
//    recognizeService.result.reserve(inSizeFaces);
//    vector<float> storeFace;
//
//    faceProvider.getRecognizeFace(floatFaceCompare);
//    recognizeService.float_to_m256(floatFaceCompare, avxFaceCompare);
////
////
//    for (int i = 0; i < inSizeFaces; ++i) {
//        faceProvider.getStoredFace(floatFacesIn[i]);
//
//    }
//
//

//
//    for (int i = 0; i < inSizeFaces; ++i) {
//        recognizeService.float_to_m256(floatFacesIn[i], faceStorage.knowFaces[i]);
//    }
//
//    floatFacesIn.clear();
//    time_t start, end;
//
//    std::thread t1(&RecognizeService::search_compare, &recognizeService, faceStorage.knowFaces, 1, 250000,
//                   avxFaceCompare,
//                   compare_tolerance);
//    std::thread t2(&RecognizeService::search_compare, &recognizeService, faceStorage.knowFaces, 250000, 500000,
//                   avxFaceCompare,
//                   compare_tolerance);
//    std::thread t3(&RecognizeService::search_compare, &recognizeService, faceStorage.knowFaces, 500000, 750000,
//                   avxFaceCompare,
//                   compare_tolerance);
//    std::thread t4(&RecognizeService::search_compare, &recognizeService, faceStorage.knowFaces, 750000, 1000000,
//                   avxFaceCompare,
//                   compare_tolerance);
//    std::cout << "Done!" << std::endl;
//    time(&start);
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();
//    time(&end);
//
//    std::cout << "Elapsed time: " << difftime(end, start) << " s\n";
//    std::cout << "Result size: " << recognizeService.result.size() << " s\n";
//    return 1;
////
////    auto start = std::chrono::high_resolution_clock::now();
////    for (int i = 0; i < inSizeFaces; ++i) {
////        resultCompare = recognizeService.compare_face(faceStorage.knowFaces[i], avxFaceCompare);
////        if (resultCompare > compare_tolerance) {
////            result.push_back(i);
////        }
////        cout << resultCompare << endl;
////    }
////    auto finish = std::chrono::high_resolution_clock::now();
////    auto elapsed = finish - start;
////    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
////    return 1;
//
}
