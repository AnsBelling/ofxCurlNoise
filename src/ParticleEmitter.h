#pragma once

#include "ofMain.h"

#define STRINGIFY(...) #__VA_ARGS__
#define WGS 256

class ParticleEmitter{

	// Number of Emitter instances
	static uint count;

	ofVec3f pos, vel, acc;
	ofVec3f prevPos;
	ofVec3f velDir;
	// ofVec3f emissionDir;

	ofShader shader;

	ofQuaternion orientation;
	
	ofParameter<float> radius;
	ofParameter<float> emissionAngle, velocityScale, averageVelocity, velocityVariation;
	ofParameter<float> averageLifespan, lifespanVariation;
	ofParameter<bool> bUseEmitterVelocity, bUseEmitterVelDir;
	
	int id, particleNumber;

	ofQuaternion defaultOrientation;
	float prevTime;

	ofParameterGroup parameters;
	
	public:
		ParticleEmitter(){ id = count; ++count; }
		void setup(int n);
		void update(float x, float y, float z = 0.0);
		void draw();
		void setOrientation(ofQuaternion q){ orientation = q; }

		const ofParameterGroup& getParameters() const { return parameters; }

	private:
		void loadShader();
		string getShaderCode();
		string getMainCode();
		string getEmitterCode();
		string getUtilityCode();
};