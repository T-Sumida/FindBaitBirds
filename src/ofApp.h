#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void initBirds();
    void initGUI();
    
    int getRand();
    
    ofEasyCam cam;
    
    ofxPanel gui;
    ofxIntSlider baitX;
    ofxIntSlider baitY;
    ofxIntSlider baitZ;
    ofxIntSlider speed;
    ofxFloatSlider c1;
    ofxFloatSlider c2;
    
    
    // イベントリスナー
    void onBaitPosXChanged(int &x);
    void onBaitPosYChanged(int &y);
    void onBaitPosZChanged(int &z);
    void onSpeedChanged(int &speed);
    void onC1Changed(float &c1);
    void onC2Changed(float &c2);
};
