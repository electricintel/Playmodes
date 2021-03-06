#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	grabber.initGrabber(640,480);
	vBuffer.setup(grabber,400);
	vHeader.setup(vBuffer);
	recloop.setup(vBuffer,vHeader);

	ofBackground(0);

	recloop.alpha=127;
    recloop.tintR=255;
    recloop.tintG=255;
    recloop.tintB=255;
    recloop.minmaxBlend=true;


	vHeader.setDelay( 10*1e6 );
	bFreeze = false;
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	recloop.draw();

	vBuffer.draw();
	vHeader.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key==' '){
		if(bFreeze){
			vBuffer.resume();
			recloop.resume();
			vHeader.setDelay(10*1e6);
			vHeader.setLoopMode(false);
		}else{
			vHeader.setDelay(0);
			vHeader.setFps(30);
			vHeader.setLoopMode(true);
			vBuffer.stop();
			recloop.stop();
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
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
