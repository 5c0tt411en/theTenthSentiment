#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    bSendSerialMessage = false;
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup(0, baud); //open the first device
    nTimesRead = 0;
    nBytesRead = 0;
    readTime = 0;
    memset(bytesReadString, 0, 4);
    
    video1.load("K1D.mov");
    video1.play();
    video1.setFrame(0);
    startSignal = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (nBytesRead > 0 && ((ofGetElapsedTimef() - readTime) <  0.5f)) {
        connection = 1;
    }
    else connection = 0;
    //Timer
    Timer = ofGetElapsedTimef() - timeStamp;
    if (Timer > exitTime) timeStamp = ofGetElapsedTimef();
    if (startSignal) {
        sendMode = 1;
        video1.play();
        video1.setFrame(0);
        startSignal = false;
    }
    if (video1.getCurrentFrame() == video1.getTotalNumFrames() -  1) sendMode = 2;

    valueMap.push_back(sendMode);
    startIteratorvalueMap = valueMap.begin();
    if (valueMap.size() > reserveNumvalueMap) valueMap.erase(startIteratorvalueMap);
    char test = (char)(sendMode);
    serial.writeByte(test);
    
    nTimesRead = 0;
    nBytesRead = 0;
    int nRead  = 0;  // a temp variable to keep count per read
    unsigned char bytesReturned[3];
    memset(bytesReadString, 0, 4);
    memset(bytesReturned, 0, 3);
    while( (nRead = serial.readBytes( bytesReturned, 3)) > 0){
        nTimesRead++;
        nBytesRead = nRead;
    };
    memcpy(bytesReadString, bytesReturned, 3);
    bSendSerialMessage = false;
    readTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (sendMode) {
        case 1:
            ofSetColor(255, 255);
            video1.draw(0,0, ofGetWidth(), ofGetHeight());
            video1.update();
            break;
        case 2:
            ofSetColor(0, 0);
            video1.stop();
        default:
            break;
    }
    ofDrawBitmapStringHighlight(ofToString(sendMode) + " | " + ofToString(video1.getCurrentFrame()) + " | " + ofToString(video1.getTotalNumFrames()), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '0') startSignal = true;
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
