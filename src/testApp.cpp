#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    rot = 1.;

    ofSetFrameRate(20);

    ofBackground(255,255,255);

    ofSetColor(0);

    myFont.loadFont("arial.ttf", 15);

    //ofNoFill();

    ofSetLineWidth( 1 );

    x = ofGetWidth();
    y = ofGetHeight();

    ofEnableSmoothing();

    step = 0.;

    ceil = 90.;

    sSize = 100;

    cCount = 30;

    nCount = 4;

    v = .001;
}


//--------------------------------------------------------------
void testApp::update(){

    step = rot > ceil/2 ? step - v: step + v;

    rot+=step;

    if (( rot > (1.5 * ceil) ) || ( rot < -(1.5 * ceil))){
        rot = 0;
        step = 0;
    }

}

//--------------------------------------------------------------
void testApp::draw(){

    stringstream tmp;

    tmp << "Rot: " << rot << endl
        << "V: " << v << endl
        << "Ceil: " << ceil << endl
        << "Size: " << sSize << endl
        << "Count: " << cCount << endl;

    myFont.drawString(tmp.str(), 50, 50);

    ofTranslate(x / 2, y / 2);

    int ctTmp = sSize/cCount;

    bool cCol = false;

    for(int sTmp = sSize; sTmp > 0; sTmp -= ctTmp) {

        ofRotate(rot);
        //ofRect(0, 0, sTmp, sTmp);

        ofPath dr = polygon(nCount, 0, 0, sTmp);

        dr.setColor(ofColor(cCol ? 0 : 255));

        cCol = ! cCol;

        dr.draw();
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
switch(key){
    case(357): //up
        sSize++;
        break;
    case(358): //right
        cCount++;
        break;
    case(359): //down
        sSize--;
        break;
    case(356): //left
        cCount--;
        break;
    case(334): //plus(NumLk)
        ceil++;
        rot = 0;
        step = 0;
        break;
    case(333): //minus(NumLk)
        ceil--;
        rot = 0;
        step = 0;
        break;
    case(328): //8(NumLk)
        break;
    case(326): //6(NumLk)
        break;
    case(322): //2(NumLk)
        break;
    case(324): //4(NumLk)
        break;
    case(45): //-
        v-=.001;
        rot = 0;
        step = 0;
        break;
    case(61): //=
        v+=.001;
        rot = 0;
        step = 0;
        break;
    case(257): //f1
        break;
    case('z'): //z
        nCount++;
        break;
    case('x'): //x
        nCount--;
        break;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
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

//--------------------------------------------------------------
ofPath testApp::polygon(int n, float cx, float cy, float w, float h, float startAngle)
{
    ofPath pts;

    pts.setMode(ofPath::POLYLINES);

    float angle = (M_PI*2) / n;

    w = w / 2.0;
    h = h / 2.0;

    for (int i = 0; i < n; i++)
    {
        pts.lineTo( cx + w * cos(startAngle + angle * i),
        cy + h * sin(startAngle + angle * i));
    }

    pts.close();

    return pts;
}

//--------------------------------------------------------------
ofPath testApp::polygon(int n, float cx, float cy, float r)
{
    return polygon(n, cx, cy, r * 2.0, r * 2.0, 0.0);
}
