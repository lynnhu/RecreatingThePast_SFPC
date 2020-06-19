#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    float alpha = ofMap(60, 0, 100, 0, 255);
    
    ofEnableAlphaBlending();
    ofSetColor(47, 188, 51, alpha);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofVec3f p1(0, 100);
    ofVec3f p2(0, -100);
    ofVec3f p3(50, -100);
    
    int num = 20;

    ofTranslate(400, 400);

    for (int i = 0; i < num; i ++){
        ofPushMatrix();
            ofRotateRad(i * 2*PI/num);
            ofTranslate(0, 150);
            ofRotateRad(ofGetElapsedTimef());
            ofDrawTriangle(p1, p2, p3);
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
