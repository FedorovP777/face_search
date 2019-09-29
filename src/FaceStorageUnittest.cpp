#include <gtest/gtest.h>
#include "FaceStorage.h"
#include "FaceProvider.h"
#include "RecognizeService.h"

using namespace std;
namespace {


    TEST(RecognizeService1, Negative) {

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
        ASSERT_TRUE(true);
    }
}