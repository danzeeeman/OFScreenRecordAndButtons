#include "ofApp.h"
#include "ofxAndroidUtils.h"
//--------------------------------------------------------------
void ofApp::setup(){
    backGroundColor = ofColor(0, 0, 0);
    ofAddListener(ofxAndroidEvents().menuItemSelected,this,&ofApp::menuItemSelected,OF_EVENT_ORDER_APP);
}

//--------------------------------------------------------------
void ofApp::update(){

}


void ofApp::menuItemSelected(string & buttonName){
    if(buttonName == "my_button") {
        backGroundColor = ofColor(255, 255, 0);
    }else if(buttonName == "record_button"){
        backGroundColor = ofColor(255, 0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(backGroundColor);
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateXDeg(ofGetFrameNum());
    ofSetColor(255, 255, 255);
    ofDrawRectangle(0, 0, 100, 100);
	ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
