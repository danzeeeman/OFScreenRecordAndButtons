#include "ofApp.h"
#include "ofxAndroidUtils.h"
//--------------------------------------------------------------

int texID;

void ofApp::setup(){
    backGroundColor = ofColor(0, 0, 0);
    ofAddListener(ofxAndroidEvents().menuItemSelected,this,&ofApp::menuItemSelected,OF_EVENT_ORDER_APP);
    ofxAndroidRequestPermission(OFX_ANDROID_PERMISSION_WRITE_EXTERNAL_STORAGE);
    fbo.allocate(1080, 1920, GL_RGB);
    texID = fbo.getTexture().getTextureData().textureID;
}
extern "C" {
    JNIEXPORT jint
    Java_cc_openframeworks_androidScreenRecording_ButtonActivity_getTexID(JNIEnv *env, jobject obj) {
        ofLog() << "SENDING TEXID TO JAVA: " << texID;
        return texID;
    }
}
//--------------------------------------------------------------
void ofApp::update(){
    fbo.begin();
    ofClear(0, 0, 0);
    ofBackground(backGroundColor);
    ofPushMatrix();
    ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
    ofRotateXDeg(ofGetFrameNum());
    ofSetColor(255, 255, 255);
    ofDrawRectangle(0, 0, 100, 100);
    ofPopMatrix();
    fbo.end();
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
    fbo.draw(0, 0);
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
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    texID = fbo.getTexture().getTextureData().textureID;
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
