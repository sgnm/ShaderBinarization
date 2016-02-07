#include "ofApp.h"

#define STRINGIFY(x) #x

static string binShader =
STRINGIFY(
    const float R_LUMINANCE = 0.298912;
    const float G_LUMINANCE = 0.586611;
    const float B_LUMINANCE = 0.114478;
    uniform sampler2DRect tex;
    uniform float threshold;
    void main(){
        vec4 color = texture2DRect(tex, gl_TexCoord[0].xy);
        float thres = threshold / 255.0;
        float val = color.x * R_LUMINANCE + color.y * G_LUMINANCE + color.z * B_LUMINANCE;
        if (val <= thres) {
            val = 1.0;
        } else {
            val = 0.0;
        }
        gl_FragColor = vec4(vec3(val), 1.0);
    }
);

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("img.jpg");
    video.initGrabber(640, 480);
    
    shader.setupShaderFromSource(GL_FRAGMENT_SHADER, binShader);
    shader.linkProgram();
    
    gui.setup();
    gui.add(threshold.setup("threshold", 100, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0, 0);
    video.draw(0, 480, 640, 480);
    
    shader.begin();
        shader.setUniform1f("threshold", threshold);
        img.draw(640, 0);
        video.draw(640, 480, 640, 480);
    shader.end();
    
    ofDrawBitmapStringHighlight("fps: " + ofToString(ofGetFrameRate(), 2), 20, 20);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f') ofToggleFullscreen();
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
