#include "testApp.h"
//ofxCvImage

//QUE LE HACEMO MUCHACHO???

//--------------------------------------------------------------
void testApp::setup(){

//inicializo las variables
ofEnableAlphaBlending();
video.initGrabber(320,240);

imaCv.allocate(320,240);
imaBn.allocate(320,240);
imaBnFondo.allocate(320,240);
imaDif.allocate(320,240);

fondo = true;
umbral = 80; //defino el valor de umbral, para la imagen dif

//pelicula.loadMovie("fingers.mov");
//pelicula.play();

}

//--------------------------------------------------------------
void testApp::update(){

    video.update();

    if (video.isFrameNew()){

        //traspasa los pixeles delvideo a imaCv;
        //nombre.setFromPixels(video.getPixels(),ancho,alto); ancho alto del video.
        imaCv.setFromPixels(video.getPixels(),video.getWidth(),video.getHeight());

        //imaCv.mirror(40,40);//gira la imagen
        //imaCv.blur(15);//da blur a la imagen

        imaBn=imaCv;//copia la imagen a color en una imagen blanco y negro.

        //pregunta si el fondo esta en true, y si es así iguala la
        //imagen fondo a la de imagen blanco y negro, y lo pone en false
        if (fondo == true){
			imaBnFondo = imaBn;
			fondo = false;
		}

		imaDif.absDiff(imaBnFondo, imaBn);
		//saca la diferencia entre la imagen fondo y la imagen blanco y negro.

		imaDif.threshold(umbral);

        //imaCv.rotate(90,100 ,50);

        contorno.findContours( imaDif, 180, (320*240)/2, 10, false);

        for(int i=0; i< contorno.blobs.size(); i++){

            contorno.blobs[i].centroid.x;
            contorno.blobs[i].centroid.y;
        }

    }

}

//--------------------------------------------------------------
void testApp::draw(){
    video.draw(0,0);//para mostrar el video;
    imaCv.draw(320,0);
    imaBn.draw(0,240);
    imaBnFondo.draw(320,240);
    imaDif.draw(640,0);
    contorno.draw(0,0);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    switch (key){
		case ' ':
			fondo = true;
			break;

        case '+':
        umbral ++;
        break;

        case '-':
        umbral --;
        break;
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
