//
//  Bird.cpp
//  FindBaitBirds
//
//  Created by T_Sumida on 2019/04/24.
//

#include "Bird.hpp"
#include "ofApp.h"

Bird::Bird(int x, int y, int z, int absLimitX, int absLimitY, int absLimitZ) : absLimitX(absLimitX), absLimitY(absLimitY), absLimitZ(absLimitZ) {
    this->position = new int[3];
    this->dVector = new int[3];
    memset(this->dVector, 0, sizeof(int)*3);
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
    this->r = 255;
    this->g = 0;
    this->b = 0;
}

void Bird::draw() {
    ofPushMatrix();
    ofTranslate(this->position[0],this->position[1],this->position[2]);
    ofFill();
    ofSetColor(r, g, b);
    ofRotateX(this->rotateX);
    ofRotateY(this->rotateY);
    ofRotateZ(this->rotateZ);
    ofDrawCone(0, 0, 0, 7, 14);
    ofPopMatrix();
}

void Bird::setPosition(int x, int y, int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}


void Bird::setColor(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Bird::move() {
    this->position[0] += this->dVector[0];
    this->position[1] += this->dVector[1];
    this->position[2] += this->dVector[2];
    
    this->rotateX = atan2(this->dVector[0], this->dVector[2]) * (180.0/M_PI);
    this->rotateY = atan2(this->dVector[1], this->dVector[2]) * (180.0/M_PI);
    this->rotateZ = atan2(this->dVector[0], this->dVector[1]) * (180.0/M_PI);
    
    this->checkLimit();
}

void Bird::checkLimit() {
    if(this->position[0] > this->absLimitX) this->position[0] = this->absLimitX;
    if(this->position[0] < (-1)*this->absLimitX) this->position[0] = (-1)*this->absLimitX;
    if(this->position[1] > this->absLimitY) this->position[1] = this->absLimitY;
    if(this->position[1] < (-1)*this->absLimitY) this->position[1] = (-1)*this->absLimitY;
    if(this->position[2] > this->absLimitZ) this->position[2] = this->absLimitZ;
    if(this->position[2] < (-1)*this->absLimitZ) this->position[3] = (-1)*this->absLimitZ;
}
