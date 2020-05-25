#include "ofApp.h"

// Set window size to be roughly A4 paper at 96PPI with left & right margin
int width = 794;
int height = 1123;
int margin = 110;

// Set squares layout basics
int squareNum = 5;
int squareInnerNum = 10;

float minWidth = 12;
float lineWidth = 2;

// Calulations
float drawAreaWidth = width - margin * 2;
float gap = (drawAreaWidth - minWidth * squareNum) / ((squareInnerNum - 1) * 2 * squareNum + squareNum - 1);
float maxWidth = minWidth + gap * (squareInnerNum - 1) * 2;


void drawVeraSquare(int layers){
    for (int i = 0; i < layers; i ++){
        ofPushMatrix();
        ofTranslate(gap * i, gap * i);
        // ofSeedRandom(0);
        float r = ofRandom(0, 1);
        if (r < 0.2){
            ofDrawRectangle(0, 0, maxWidth - gap * i * 2, maxWidth - gap * i * 2);
        }
        ofPopMatrix();
    }
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(width, height);
    ofSetBackgroundColor(239, 236, 232);
    ofSetLineWidth(lineWidth);
    
}


//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(71, 60, 51);
    ofNoFill();
    ofSeedRandom(0);
    
    ofTranslate(margin, (height - drawAreaWidth) / 2);
    for (int i = 0; i < squareNum; i ++){
        // Move horizontally to the right
        ofPushMatrix();
        ofTranslate(i * maxWidth + (i - 1) * gap, 0);

        for (int j = 0; j < squareNum; j ++){
            // Move vertically downwards
            ofPushMatrix();
            ofTranslate(0, j * maxWidth + (j - 1) * gap);

            //drawVeraSquare(squareInnerNum);

            for (int k = 0; k < squareInnerNum; k++){
                ofPushMatrix();
                ofTranslate(gap * k, gap * k);
                if (ofRandom(0, 1) < 0.99) {
                //if ( ofNoise(i*0.1, j*0.1, k*0.1) < 0.95) {
                    ofDrawRectangle(0, 0, maxWidth - gap * k * 2, maxWidth - gap * k * 2);
                }
                ofPopMatrix();
            }
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    
    // drawVeraSquare(squareInnerNum);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
