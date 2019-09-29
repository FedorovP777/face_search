//
// Created by user on 17.08.19.
//

#ifndef UNTITLED_FACEPROVIDER_H
#define UNTITLED_FACEPROVIDER_H

#include <vector>
#include <array>

using namespace std;

typedef std::array<float, 128> faceFloat;

class FaceProvider {

public:
    faceFloat getRecognizeFace();

    faceFloat getStoredFace();
};


#endif //UNTITLED_FACEPROVIDER_H
