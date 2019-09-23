//
// Created by user on 17.08.19.
//

#ifndef UNTITLED_FACEPROVIDER_H
#define UNTITLED_FACEPROVIDER_H

#include <vector>

using namespace std;

class FaceProvider {

public:
    void getRecognizeFace(vector<float> &result);

    void getStoredFace(vector<float> &result);
};


#endif //UNTITLED_FACEPROVIDER_H
