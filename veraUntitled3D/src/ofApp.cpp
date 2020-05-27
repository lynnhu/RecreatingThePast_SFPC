#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(239, 236, 232);
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);

    cam.enableOrtho();
    // cam.disableOrtho();
    
    cam.begin();
    
    // Move horizontally
    for (int j = 0; j < 5; j ++){
        ofPushMatrix();
        ofTranslate(105 * j - 200, 0, 0);
        
        // Move vertically
        for (int k = 0; k < 5; k ++){
            ofPushMatrix();
            ofTranslate(0, 105 * k - 200, 0);
            
            // Draw inner square
            for (int i = 0; i < 10; i ++){
                    ofPushMatrix();
                    
                    ofTranslate(0, 0, -10 * i);
                    if ( ofRandom(0, 1) < 0.97 ){
                        ofDrawRectangle(0, 0, 100 - 10 * i, 100 - 10 * i);
                    }
                    ofPopMatrix();
            }
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    
    cam.end();
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
