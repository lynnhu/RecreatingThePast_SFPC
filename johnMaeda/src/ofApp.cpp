#include "ofApp.h"


string textCn = "所有的風";
float w0;
float h0;
float hwratio;
float minTypeWidth = 2.0;

float scaleFactor;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 900);
    
    ofBackground(242);
    ofSetColor(0);
    
    // ---- GUI Setup -----
    // Defaults are optimized for the string "所有的風"
    gui.setup();
    gui.add(lines.setup("Lines", 514, 100, 1000));
    gui.add(powBegin.setup("Pow curve begin", 3.3, 1.0, 30));
    gui.add(powEnd.setup("Pow curve end", 430, 30, 800));
    gui.add(powFactor.setup("Speed of shrink", -2.0, -1.0, -5.0));
    
    
    // ---- Chinese Type settings -----
    // This typeface also supports Japanese and Latin
    ofTrueTypeFontSettings settingsCn("HiraKakuStdN-W9.otf", 120);
    settingsCn.antialiased = true;
    settingsCn.contours = true;
    settingsCn.dpi = 72;
    settingsCn.addRanges(ofAlphabet::Chinese);

    
    // Load the settings
    fontCn.load(settingsCn);
    
    // Calculating the string's height / weight ratio for easier transformation later
    // Basically treating it as a fixed ratio rectangle
    w0 = fontCn.stringWidth(textCn);
    h0 = fontCn.stringHeight(textCn);
    hwratio = h0 / w0;
        
    // Setting tighter letter spacing
    fontCn.setLetterSpacing(0.9);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    ofTranslate(0, -5);
    
    float xPos = 0;
    float yPos = 0;
    
    ofRectangle original = fontCn.getStringBoundingBox(textCn, 0, 0);
    
    // I assume John Maeda used a pow function to size the type down
    // From GUI we get the start X and end X
    // Map it using the function that takes the pow factor
    float outBegin = pow(powBegin, powFactor);
    float outEnd = pow(powEnd, powFactor);
    
    for (int i = 0; i < lines; i ++){
        // Where should this line be on the X axis?
        float index = ofMap(i, 0, lines, powBegin, powEnd);
        
        // Calculate the size based on function
        float wtemp = pow(index, powFactor);
        
        // Map it again from Minimum width to Canvas width
        float wTarget = ofMap(wtemp, outBegin, outEnd, ofGetWidth(), minTypeWidth);
        
        // Calculate how much we need to scale down the first line
        float scale = wTarget / original.getWidth();
        
        // Calculate X & Y position to translate to
        xPos = (ofGetWidth() - wTarget) * 0.5;
        
        // The type comes with padding between lines. Reducing height by % to mimic the poster look
        yPos += wTarget * hwratio * 0.94;
        
        // Draw
        ofPushMatrix();
            ofTranslate(xPos, yPos);
            ofScale(scale, scale);
            fontCn.drawString(textCn, 0, 0);
        ofPopMatrix();
    }
    
    // --- Zach's example ----
        
    //    ofRectangle originalRectangle = fontCn.getStringBoundingBox(textCn, 0,0);
    //    ofPoint diffFromStart = originalRectangle.getPosition() - ofPoint(0,0);
    //
    //    // setup the target
    //    ofRectangle target (300,300,mouseX-300, mouseY-300);
    //    ofFill();
    //    ofSetColor(255,0,0);
    //    ofDrawRectangle(target);
    //
    //    // scale to the target
    //    ofRectangle scaled = originalRectangle;
    //    scaled.scaleTo(target);
    //    ofSetColor(0,255,0);
    //    ofDrawRectangle(scaled);
    //
    //    // figure out how much we need to move and scale
    //    ofPoint diff = scaled.getPosition() - originalRectangle.getPosition();
    //    float scale = (float)scaled.getWidth() / (float)originalRectangle.getWidth();
    //
    //    // move and scale and draw
    //    ofPushMatrix();
    //    ofSetColor(255);
    //    ofTranslate(diff.x, diff.y);
    //    ofTranslate(diffFromStart + ofPoint(0,scaled.getHeight()));
    //    ofScale(scale, scale);
    //    fontCn.drawString(textCn, 0,0);
    //    ofPopMatrix();
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
