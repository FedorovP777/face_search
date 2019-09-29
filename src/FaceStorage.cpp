// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "FaceStorage.h"


/**
 * Add new face to storage
 * @param newFace
 */
void FaceStorage::addFace(vector<__m256> newFace,  string &faceID) {

    this->knowFaces.push_back(newFace);
    this->facesId.push_back(faceID);
}

void FaceStorage::initStorage(int size) {

    this->knowFaces.resize(size);
    this->facesId.resize(size);
}

void FaceStorage::reserve(int size) {

    this->knowFaces.reserve(size);
    this->facesId.reserve(size);
}

FaceStorage::FaceStorage() {

}

