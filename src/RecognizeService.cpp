//
// Created by user on 17.08.19.
//

#include "RecognizeService.h"

#include <utility>
#include "FaceStorage.h"


RecognizeService::RecognizeService(FaceStorage faceStorage) {

    this->faceStorage = std::move(faceStorage);
};


void RecognizeService::init(int countFaces) {

    this->faceStorage.reserve(countFaces);
}


/**
 * Convert vector float to m256(packed float to size 8 vector)
 * @param points
 * @param result
 */
void RecognizeService::float_to_m256(const vector<float> points, vector<__m256> &result) {

    int pointsSize = points.size();
    int pointPackageSize = 8;
    for (int i = 0; i < pointsSize; i += 8) {

        alignas(32) float package_points[pointPackageSize];

        for (int k = 0; k < pointPackageSize; ++k) {
            package_points[k] = points[i + k];
        }

        result.push_back(_mm256_load_ps(package_points));
    }
}

float RecognizeService::compare_face(vector<__m256> a, vector<__m256> b) {


    float result1 = 0;
    alignas(32) float in[8];


    for (int i = 0; i < a.size(); i++) {
        __m256 aa = _mm256_sub_ps(a[i], b[i]);
        __m256 bb = _mm256_mul_ps(aa, aa);
        _mm256_store_ps(in, bb);

        for (int q = 0; q < 8; ++q) {
            result1 += abs(bb[q]);
        }
    }

    return sqrt(result1);
}

void RecognizeService::search_compare(const vector<vector<__m256>> &knowFaces, int start, int end,
                                      const vector<__m256> &avxFaceCompare, float compare_tolerance) {

    float resultCompare = 0;
    for (int i = start; i < end; ++i) {
        resultCompare = this->compare_face(knowFaces[i], avxFaceCompare);
        if (resultCompare > compare_tolerance) {
            this->result.push_back(i);
        }

    }
}


void RecognizeService::search(vector<float> vector) {

}

void RecognizeService::addFaces(vector<vector<float>> facePoints, vector<string> facesId) {

}

