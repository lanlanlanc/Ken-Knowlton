#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	img.load("cat1.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0,0, 0);
	float n =16;// size
	float max = 0;
	float r = 1.6;

	for (int i = 0; i < img.getWidth(); i += 10) {
		for (int j = 0; j < img.getHeight(); j += 10) {
			ofColor color = img.getColor(i, j);
			float brightness = color.getBrightness();
			if (brightness > max) {
				max = brightness;
			}
		}
	}  //find the range of brightness


	float di = max / 6; //creat dice range
	float dice[7] = {0,di,di*2,di*3,di*4,di*5,di * 5.5, };

	for (int i = 0; i < img.getWidth(); i += 10) {	
		for (int j = 0; j < img.getHeight(); j += 10) {		

			ofColor color = img.getColor(i, j);
			float bri= color.getBrightness();

			ofSetColor(color);			
			ofDrawRectangle(2*i+2, 2*j+2, n, n); // draw squares

		/*	ofSetColor(255, 255, 255);
			ofDrawRectangle(2 * i + 1.8, 2 * j + 1.8, n+0.8, n+0.8); // draw squares
			ofSetColor(0, 0,0);
			ofDrawRectangle(2 * i + 2.2, 2 * j + 2.2, n, n); // draw squares
*/
			int m=((int)bri+i+j)%2;
			if (m == 0) { m = -1; }
/*
			ofSetColor(255,255,255);
			if (bri < dice[1]) {   
				cout << bri << endl; //1
			//	ofDrawCircle(2 * (i + 5), 2 * (j + 5), r);
			}
			else if (bri > dice[1] &bri< dice[2]) {
				ofDrawCircle(2 * (i + 5), 2 * (j + 5), r);
			}
			else if (bri > dice[2] & bri < dice[3]) {
				ofDrawCircle(2 * (i + 4 - m), 2 * (j + 4 + m), r);           //2
				ofDrawCircle(2 * (i + 6 + m), 2 * (j + 6 - m), r);
			}
			else if (bri > dice[3] & bri < dice[4]) {
				ofDrawCircle(2 * (i + 5 - 2.5*m), 2 * (j + 2.5), r);           //3
				ofDrawCircle(2 * (i + 5), 2 * (j + 5), r);
				ofDrawCircle(2 * (i + 5 + 2.5*m), 2 * (j + 7.5), r);
			}
			else if (bri > dice[4] & bri < dice[5]) {
				ofDrawCircle(2 * (i + 3), 2 * (j + 3), r);           //4
				ofDrawCircle(2 * (i + 7), 2 * (j + 3), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 7), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 7), r);
			}
			else if (bri > dice[5] & bri < dice[6]) {
				ofDrawCircle(2 * (i + 5), 2 * (j + 5), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 3), r);           //5
				ofDrawCircle(2 * (i + 7), 2 * (j + 3), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 7), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 7), r);
			}

			else  {
				ofDrawCircle(2 * (i + 3), 2 * (j + 2), r);           //6
				ofDrawCircle(2 * (i + 3), 2 * (j + 5), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 8), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 2), r);           
				ofDrawCircle(2 * (i + 7), 2 * (j + 5), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 8), r);
			}
*/
			ofSetColor(255, 255, 255);
			if (bri < dice[1]) {                                     //1
				ofDrawCircle(2 * (i + 5), 2 * (j + 5), r);
			}
			else if (bri > dice[1] & bri < dice[2]) {
				ofDrawCircle(2 * (i + 4 - m), 2 * (j + 4 + m), r);           //2
				ofDrawCircle(2 * (i + 6 + m), 2 * (j + 6 - m), r);
			}
			else if (bri > dice[2] & bri < dice[3]) {
				ofDrawCircle(2 * (i + 5 - 2.5*m), 2 * (j + 2.5), r);           //3
				ofDrawCircle(2 * (i + 5), 2 * (j + 5), 2);
				ofDrawCircle(2 * (i + 5 + 2.5*m), 2 * (j + 7.5), r);
			}
			else if (bri > dice[3] & bri < dice[4]) {
				ofDrawCircle(2 * (i + 3), 2 * (j + 3), r);           //4
				ofDrawCircle(2 * (i + 7), 2 * (j + 3), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 7), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 7), r);
			}
			else if (bri > dice[4] & bri < dice[5]) {
				ofDrawCircle(2 * (i + 5), 2 * (j + 5), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 3), r);           //5
				ofDrawCircle(2 * (i + 7), 2 * (j + 3), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 7), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 7), r);
			}
			else if (bri > dice[4] & bri < dice[5] & m == -1) {
				ofDrawCircle(2 * (i + 2), 2 * (j + 3), r);           //6
				ofDrawCircle(2 * (i + 5), 2 * (j + 3), r);
				ofDrawCircle(2 * (i + 8), 2 * (j + 3), r);
				ofDrawCircle(2 * (i + 2), 2 * (j + 7), r);
				ofDrawCircle(2 * (i + 5), 2 * (j + 7), r);
				ofDrawCircle(2 * (i + 8), 2 * (j + 7), r);
			}

			else {
				ofDrawCircle(2 * (i + 3), 2 * (j + 2), r);           //6
				ofDrawCircle(2 * (i + 3), 2 * (j + 5), r);
				ofDrawCircle(2 * (i + 3), 2 * (j + 8), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 2), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 5), r);
				ofDrawCircle(2 * (i + 7), 2 * (j + 8), r);
			}
			
		}
	}


	
		
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
