#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"//incluye la libreria que esta en el src.


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofVideoGrabber video;//toma img desde la camara
		ofxCvColorImage imaCv;
		ofxCvGrayscaleImage imaBn;
		ofxCvGrayscaleImage imaBnFondo;
		ofxCvGrayscaleImage imaDif;//imagen para la captura de fondo

		ofxCvContourFinder contorno; //incluidio arriba

		int  umbral;

		bool fondo;

};
