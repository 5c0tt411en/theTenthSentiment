#pragma once

#include "ofMain.h"

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
		
    ofTrueTypeFont		font;
    
    bool		bSendSerialMessage;			// a flag for sending serial
    char		bytesRead[3];				// data from serial, we will be  trying to read 3
    char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
    int			nBytesRead;					// how much did we read?
    int			nTimesRead;					// how many times did we read?
    float		readTime;					// when did we last read?
    ofSerial	serial;
    int testNum = 0;
    int sendMode;
    int connection;
    
    vector<float> valueMap;
    vector<float>::iterator startIteratorvalueMap;
    const int reserveNumvalueMap = 800;
    const int range = 255;
    const int intercept = 0 ;
    const float speed = 3;
    
    float Timer, timeStamp;
    bool startSignal;
    const float exitTime = 600;
    
    ofVideoPlayer video1;
};
