// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "RecognizeService.h"


#include <utility>
#include "FaceStorage.h"
#include "FaceProvider.h"


RecognizeService::RecognizeService() {

//    this->faceStorage = new FaceStorage();
};


void RecognizeService::init(int countFaces) {

    this->faceStorage.reserve(countFaces);
    this->result.reserve(countFaces);
}


/**
 * Convert vector float to m256(packed float to size 8 vector)
 * @param points
 * @param resultConvert
 */
void RecognizeService::float_to_m256(faceFloat& points, vector<__m256> &resultConvert) {

    int pointsSize = points.size();
    int pointPackageSize = 8;
    for (int i = 0; i < pointsSize; i += 8) {

        alignas(32) float package_points[pointPackageSize];

        for (int k = 0; k < pointPackageSize; ++k) {
            package_points[k] = points[i + k];
        }

        resultConvert.push_back(_mm256_load_ps(package_points));
    }
}

/**
 * Compare 2 face
 * @param a
 * @param b
 * @return
 */
float RecognizeService::compare_face(vector<__m256> a, vector<__m256> b) {


    float result1 = 0;
    alignas(32) float in[8];


    for (unsigned long i = 0; i < a.size(); i++) {
        __m256 aa = _mm256_sub_ps(a[i], b[i]);
        __m256 bb = _mm256_mul_ps(aa, aa);
        _mm256_store_ps(in, bb);

        for (int q = 0; q < 8; ++q) {
            result1 += abs(bb[q]);
        }
    }

    return sqrt(result1);
}

void RecognizeService::search_compare_range(const vector<vector<__m256>> &knowFaces, int start, int end,
                                            const vector<__m256> &avxFaceCompare, float compare_tolerance) {

    float resultCompare = 0;
    for (int i = start; i < end; ++i) {
        resultCompare = this->compare_face(knowFaces[i], avxFaceCompare);
        if (resultCompare > compare_tolerance) {
            this->result.push_back(i);
        }

    }
}


vector<int> RecognizeService::search(faceFloat& vectorSearch) {

    vector<__m256> searchFace;
    this->float_to_m256(vectorSearch, searchFace);
    this->search_compare_range(this->faceStorage.knowFaces, 0, this->faceStorage.knowFaces.size(), searchFace, 0.6);
    return this->result;
}

/**
 *
 * @param facePoints вектор с координатами из dlib
 * @param facesId ид лиц в string
 */
void RecognizeService::addFaces(vector<faceFloat> &facePoints, vector<string> &facesId) {

    /**
     * Конверим в m256 и сохраняем в storage
     */

    cout << 16 * sizeof(__m256) * facePoints.size() << endl;
    for (unsigned long i = 0; i < facePoints.size(); i++) {
        vector<__m256> resultConvertToM256;
        this->float_to_m256(facePoints[i], resultConvertToM256);
        this->faceStorage.addFace(resultConvertToM256, facesId[i]);
    }
}

