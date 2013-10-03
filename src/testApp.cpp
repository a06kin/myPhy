#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    rot = 1.;

    ofSetFrameRate(20);

    ofBackground(255,255,255);

    maxD = ofDist(0, 0, ofGetWidth(), ofGetHeight());

    mouseX = mouseY = 5;

    //ofNoFill();

    ofSetLineWidth( 70 );

    x = ofGetWidth();
    y = ofGetHeight();

    ofSetRectMode(OF_RECTMODE_CENTER);

    ofEnableSmoothing();

    direct = true;
    step = 0.;

    ceil = 180.;

    sSize = 500;

    cCount = 30;
}


//--------------------------------------------------------------
void testApp::update(){

    if (direct){
        if (rot > ceil/2 ) step-=.1;
        else step+=.1;

        rot+=step;
        if ( rot > ceil ){
            rot = 0;
            //direct = !direct;
            step = 0;
        }
    }else{
        if (rot < -ceil/2 ) step-=.1;
        else step+=.1;

        rot-=step;
        if ( rot < -ceil ){
            rot = 0;
            direct = !direct;
            step = 0;
        }
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    /*ofTranslate(150, 150, 0);

    ofRotate((rot * ( 4 * PI ) / 360)*50);

    ofSetLineWidth( 3 );

    ofSetColor( 255 * abs( sin( 45 + float(rot) / 10 ))  , 255 * abs( sin( float(rot) / 10 )), 255 * abs( sin( 90 + float(rot) / 10 )));

    ofRect( -75, -75, 150, 150 );

    ofTranslate(-150, -150, 0);*/

    /*for(int i = 0; i <= ofGetWidth(); i += 20) {
        for(int j = 0; j <= ofGetHeight(); j += 20) {
          float size = ofDist(mouseX, mouseY, i, j);
          size = size/maxD * 66;
          ofEllipse(i, j, size, size);
        }
    }*/


    ofTranslate(x / 2, y / 2);

    int ctTmp = sSize/cCount;

    bool cCol = false;

    for(int sTmp = sSize; sTmp > 0; sTmp = sTmp - ctTmp) {
        //ofRotate((mouseX + mouseY) / 10.0);
        ofSetColor(cCol ? 0 : 255);

        cCol = ! cCol;

        ofRotate(rot);
        ofRect(0, 0, sTmp, sTmp);
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
