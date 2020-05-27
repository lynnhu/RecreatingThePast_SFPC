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
		
        // GUI sliders
        ofxFloatSlider minsqWidth;
        ofxFloatSlider inc;
        ofxFloatSlider noiseThres;
        ofxFloatSlider randomSeed;

        ofxIntSlider squareNum;
        ofxIntSlider squareInnerNum;
        
        ofxPanel gui;
};


// Set squares layout basics
//float minsqWidth = 12;
//float inc = 6;
//
//int squareNum = 5;
//int squareInnerNum = 10;
//
//float lineWidth = 2;
//float noiseThres = 0.97;
