//
//  Bait.cpp
//  FindBaitBirds
//
//  Created by T_Sumida on 2019/04/24.
//

#include "Bait.hpp"
#include "ofApp.h"

Bait::Bait(int x, int y, int z, int size) {
    this->position = new int[3];
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
    this->size = size;
}

void Bait::draw() {
    ofSetHexColor(0xffff00);
    ofNoFill();
    ofDrawSphere(this->position[0],this->position[1],this->position[2],size);
}

void Bait::setPosition(int x, int y, int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
