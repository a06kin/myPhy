#include "testApp.h"

void testApp::genNoise(){

    for (int i = 0; i < x; i++) {
        float noiseVal = ofNoise(getRandom(1,x)*noiseScale,
                                getRandom(1,y)*noiseScale);
        ofLine(i, getRandom(0,y)*80, i, y);
      }
}

void testApp::reset(){
    rot = 1.;

    step = 0.;

    ceil = 90.;

    sSize = 300;

    cCount = 30;

    nCount = 4;

    v = .001;

    c11 = 0;

    c12 = 0;

    c13 = 0;

    c21 = 255;

    c22 = 255;

    c23 = 255;

    line = 1;

    noise = false;
}

void testApp::randomColor(){
    c11 = getRandom(0, 255);

    c12 = getRandom(0, 255);

    c13 = getRandom(0, 255);

    c21 = getRandom(0, 255);

    c22 = getRandom(0, 255);

    c23 = getRandom(0, 255);
}


int testApp::getRandom(int min, int max){
    return min + (rand() % (int)(max - min + 1));
}


//--------------------------------------------------------------
void testApp::setup(){

    ofHideCursor();

    noiseScale = .02;

    reset();

    ofSetFrameRate(20);

    ofBackground(255,255,255);

    ofSetColor(0);

    myFont.loadFont("arial.ttf", 15);

    //ofNoFill();

    ofSetLineWidth( 1 );

    x = ofGetWidth();
    y = ofGetHeight();

    ofEnableSmoothing();

    stringstream helpstreap;

    helpstreap << "up/down: poligon size" << endl
        << "left/right: poligon count" << endl
        << "-/=: speed" << endl
        << "q/w: ceil count" << endl
        << "z/x: polygon type" << endl
        << "p/[/]: color 1+" << endl
        << "l/;/': color 1-" << endl
        << "u/i/o: color 2+" << endl
        << "h/j/k: color 2-" << endl
        << "r: reset" << endl
        << "f: random color" << endl
        << "b: border" << endl
        << "n: noise" << endl;

    helpS = helpstreap.str();

    help = false;

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

    if (noise) genNoise();

    stringstream tmp;

    tmp << "Rotation: " << ceil << endl
        << "Speed: " << v << endl
        << "RNow: " << rot << endl
        << "Size: " << sSize << endl
        << "Count: " << cCount << endl
        << "Poligon type:" << nCount << endl
        << "Color 1:" << c11 << ":" << c12 << ":" << c13 << endl
        << "Color 2:" << c21 << ":" << c22 << ":" << c23 << endl;

    if (help){
        myFont.drawString(tmp.str(), 50, 50);
        myFont.drawString(helpS, x - 250, 50);
    }

    ofTranslate(x / 2, y / 2);

    int ctTmp = sSize/cCount;

    bool cCol = false;

    for(int sTmp = sSize; sTmp > 0; sTmp -= ctTmp) {

        ofRotate(rot);
        //ofRect(0, 0, sTmp, sTmp);

        ofPath dr = polygon(nCount, 0, 0, sTmp);

        dr.setStrokeColor(ofColor::black);
        dr.setStrokeWidth(line);
        dr.setColor(ofColor::black);

        ofColor c1;
        c1.r = c11;
        c1.g = c12;
        c1.b = c13;

        ofColor c2;
        c2.r = c21;
        c2.g = c22;
        c2.b = c23;

        dr.setFillColor(cCol ? c1: c2);

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
            if (sSize > 2) sSize--;
            break;
        case(356): //left
            if (cCount > 2) cCount--;
            break;
        case('w'):
            ceil++;
            rot = 0;
            step = 0;
            break;
        case('q'):
            if (ceil > 1) ceil--;
            rot = 0;
            step = 0;
            break;
        case(45): //-
            if (v > 0.001)  v-=.001;
            rot = 0;
            step = 0;
            break;
        case(61): //=
            v+=.001;
            rot = 0;
            step = 0;
            break;
        case(257): //f1
            help = !help;
            break;
        case('x'): //z
            nCount++;
            break;
        case('z'): //x
            if (nCount > 2) nCount--;
            break;


        case('p'):
            if (c11 < 255) c11++;
            break;
        case('['):
            if (c12 < 255) c12++;
            break;
        case(']'):
            if (c13 < 255) c13++;
            break;

        case('u'):
            if (c11 > 0) c11--;
            break;
        case('i'):
            if (c12 > 0) c12--;
            break;
        case('o'):
            if (c13 > 0) c13--;
            break;






        case('l'):
            if (c21 < 255) c21++;
            break;
        case(';'):
            if (c22 < 255) c22++;
            break;
        case('\''):
            if (c23 < 255) c23++;
            break;

        case('h'):
            if (c21 > 0) c21--;
            break;
        case('j'):
            if (c22 > 0) c22--;
            break;
        case('k'):
            if (c23 > 0) c23--;
            break;

        case('b'):
            if (line == 1) line = 0;
            else line = 1;
            break;

        case('n'):
            noise = !noise;
            break;

        case('r'):
            reset();
            break;
        case('f'):
            randomColor();
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
