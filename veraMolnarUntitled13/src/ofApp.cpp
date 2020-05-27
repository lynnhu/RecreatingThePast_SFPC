#include "ofApp.h"

// Set window size to be roughly A4 paper at 96PPI with left & right margin
int width = 794;
int height = 1123;
float lineWidth = 2;


//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(squareNum.setup("Squares per side", 5, 2, 20));
    gui.add(squareInnerNum.setup("Layers per square", 10, 2, 20));
    gui.add(inc.setup("Increment", 6, 2, 20));
    gui.add(minsqWidth.setup("Smallest square", 12, 5, 50));
    gui.add(noiseThres.setup("Randomness", 0.97, 0.7, 1));
    gui.add(randomSeed.setup("Seed", 0, 0, 1000));
        
    ofSetWindowShape(width, height);
    ofSetBackgroundColor(239, 236, 232);
    ofSetLineWidth(lineWidth);
    
}


//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    ofSetColor(71, 60, 51);
    ofNoFill();
    ofSeedRandom(randomSeed);
    
    // Calulations
    float squareWidth = minsqWidth + inc * (squareInnerNum - 1) * 2;
    float drawWidth = squareWidth * squareNum + inc * (squareNum - 1);
    float drawX0 = (width - drawWidth) / 2;
    float drawY0 = (height - drawWidth) / 2;
    
    // Move to draw area
    ofTranslate(drawX0, drawY0);
    for (int i = 0; i < squareNum; i ++){
        // Move horizontally to the right
        ofPushMatrix();
        ofTranslate(i * (squareWidth + inc), 0);

        for (int j = 0; j < squareNum; j ++){
            // Move vertically downwards
            ofPushMatrix();
            ofTranslate(0, j * (squareWidth + inc));
            
            for (int k = 0; k < squareInnerNum; k ++){
                ofSetColor(71 + ofRandom(-10, +10), 60 + ofRandom(-10, +10), 51 + ofRandom(-10, +10));
                
                // Draw layers within a square
                ofPushMatrix();
                ofTranslate(inc * k, inc * k);
                if ( ofRandom(0, 1) < noiseThres ){
                    ofDrawRectangle(0, 0, squareWidth - inc * k * 2, squareWidth - inc * k * 2);
                }
                ofPopMatrix();
            }
            ofPopMatrix();
        }
        ofPopMatrix();
    }
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
