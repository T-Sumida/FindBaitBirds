#include "ofApp.h"
#include "Bird.hpp"
#include "PSO.hpp"
#include "Bait.hpp"
#include <random>

Bird** birds;
PSO* pso;
Bait* bait;

#define BIRDS_NUM 10000
#define RADIUS 3000
#define CAMERA_X -5100
#define CAMERA_Y 5100
#define CAMERA_Z 5100
#define SPEED_MIN 3
#define SPEED_MAX 12
#define C_MIN 0.001
#define C_MAX 0.1
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    cam.setDistance(5000);
    
    initBirds();
    bait = new Bait(0,0,0,25);
    pso = new PSO(BIRDS_NUM, 3, 10);
    for(int i = 0;i < BIRDS_NUM;i++) {
        pso->optimizeFirst(i, birds[i]->position, bait->position);
    }
    initGUI();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0;i < BIRDS_NUM;i++) {
        pso->optimize(i, birds[i]->position, birds[i]->dVector,bait->position);
        birds[i]->move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofNoFill();
    ofSetColor(255, 255, 255, 100);
    ofDrawBox(0, 0, 0, RADIUS, RADIUS, RADIUS);
    
    for(int i = 0;i < BIRDS_NUM;i++) birds[i]->draw();
    
    bait->draw();
    cam.end();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case ' ':
            for(int i = 0;i < BIRDS_NUM;i++) {
                birds[i]->position[0] = getRand();
                birds[i]->position[1] = getRand();
                birds[i]->position[2] = getRand();
            }
            break;
            
        default:
            break;
    }
    pso->reset();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}


void ofApp::initBirds() {
    int x,y,z;
    birds = new Bird *[BIRDS_NUM];
    static std::mt19937_64 mt64(0);
    for(int i = 0;i < BIRDS_NUM;i++) {
        x = getRand();
        y = getRand();
        z = getRand();
        birds[i] = new Bird(x,y,z, RADIUS/2, RADIUS/2, RADIUS/2);
    }
}

int ofApp::getRand() {
    static std::mt19937_64 mt64(0);
    std::uniform_int_distribution<int> gen_rand_uni_int( -RADIUS/2, RADIUS/2 );
    return gen_rand_uni_int(mt64);
}

void ofApp::initGUI() {
    gui.setup();
    gui.add(baitX.setup("BAIT_X",bait->position[0],-RADIUS/2, RADIUS/2));
    gui.add(baitY.setup("BAIT_Y",bait->position[1],-RADIUS/2, RADIUS/2));
    gui.add(baitZ.setup("BAIT_Z",bait->position[2],-RADIUS/2, RADIUS/2));
    gui.add(speed.setup("SPEED",pso->getVLimit(),SPEED_MIN, SPEED_MAX));
    gui.add(c1.setup("C1", pso->getC1(), C_MIN, C_MAX));
    gui.add(c2.setup("C2", pso->getC2(), C_MIN, C_MAX));
    
    // リスナー設定
    this->baitX.addListener(this, &ofApp::onBaitPosXChanged);
    this->baitY.addListener(this, &ofApp::onBaitPosYChanged);
    this->baitZ.addListener(this, &ofApp::onBaitPosZChanged);
    this->speed.addListener(this, &ofApp::onSpeedChanged);
    this->c1.addListener(this, &ofApp::onC1Changed);
    this->c2.addListener(this, &ofApp::onC2Changed);
}

void ofApp::onBaitPosXChanged(int &x){
    bait->setPosition(x, bait->position[1], bait->position[2]);
    pso->reset();
}

void ofApp::onBaitPosYChanged(int &y){
    bait->setPosition(bait->position[0], y, bait->position[2]);
    pso->reset();
}

void ofApp::onBaitPosZChanged(int &z){
    bait->setPosition(bait->position[0], bait->position[1], z);
    pso->reset();
}

void ofApp::onSpeedChanged(int &speed) {
    pso->setVLimit(speed);
}

void ofApp::onC1Changed(float &c1) {
    pso->setC1((double)c1);
}

void ofApp::onC2Changed(float &c2) {
    pso->setC2((double)c2);
}
