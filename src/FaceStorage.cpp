//
// Created by user on 17.08.19.
//

#include "FaceStorage.h"


/**
 * Add new face to storage
 * @param newFace
 */
void FaceStorage::addFace(vector<__m256> newFace) {

    this->knowFaces.push_back(newFace);
}

void FaceStorage::initStorage(int size) {

    this->knowFaces.resize(size);
}

void FaceStorage::reserve(int size) {

    this->knowFaces.reserve(size);
}
