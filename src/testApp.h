#pragma once

#include "ofMain.h"
#include <math.h>

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int);
		void keyReleased(int);
		void mouseMoved(int, int);
		void mouseDragged(int, int, int);
		void mousePressed(int, int, int);
		void mouseReleased(int, int, int);
		void windowResized(int, int);
		void dragEvent(ofDragInfo);
		void gotMessage(ofMessage);

		ofPath polygon(int, float, float, float, float, float);

		ofPath polygon(int, float, float, float);

		ofTrueTypeFont myFont;

		float rot;

        int x, y;

        float step;

        float ceil;

        int sSize;

        int cCount;

        int nCount;

        float v;

};
