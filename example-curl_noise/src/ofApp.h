#pragma once

#include "ofMain.h"

#include "ofxGui.h"

#include "ofxCurlNoise.h"

class ofApp : public ofBaseApp{

	// ParticleEmitter particleEmitter;
	vector<ParticleEmitter> particleEmitters;
	ofxCurlNoise curlNoise;
	// ofVbo particlesVbo;

	ofEasyCam cam;

	ofxFloatSlider speedCoeff;
	ofxLabel fps;
	ofxPanel gui;

	public:
		void setup();
		void update();
		void draw();
		
};
