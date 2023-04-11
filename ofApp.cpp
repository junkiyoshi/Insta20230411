#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto radius = 250;

	for (int i = 0; i < 20; i++) {

		auto noise_seed = ofRandom(1000);
		vector<glm::vec3> vertices;
		for (int deg = 0; deg < 360; deg += 1) {

			auto vertex = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
			auto rotate_deg = ofMap(ofNoise(noise_seed, vertex.x * 0.0003 + ofGetFrameNum() * 0.0005), 0, 1, -360, 360);
			auto rotation = glm::rotate(glm::mat4(), rotate_deg * (float)DEG_TO_RAD, glm::vec3(1, 0, 0));

			vertex = glm::vec4(vertex, 0) * rotation;

			vertices.push_back(vertex);
		}

		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}