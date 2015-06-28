#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <unistd.h>

#define hres 1000 
#define vres 700


#define gridx 300
#define gridy 300

int rsize=gridx/30;
int ssize=gridx/50; 
int posi; 
int one4thy = gridy/2-20;
int three4thy = gridy/2+20;


void drawSquare(int posx, int posy){
	int dy=1;
	glBegin(GL_POLYGON);
		glVertex2d(posx-ssize, posy-ssize-dy);
      		glVertex2d(posx-ssize, posy+ssize+dy);
      		glVertex2d(posx+ssize, posy+ssize+dy);
		glVertex2d(posx+ssize, posy-ssize-dy);
	glEnd();
	glFlush();
}

void drawYellowSquare(int posx, int posy) {
	glColor3f(0,0,0.5);
	drawSquare(posx, posy);
	glColor3f(1,1,1);

}

void drawBlueSquare(int posx, int posy)  {
	glColor3f(0.5,0.5,0);
	drawSquare(posx, posy);
	glColor3f(1,1,1);

}
void eraseSquare(int posx, int posy) {
	glColor3f(0,0,0);
	drawSquare(posx, posy);
	glColor3f(1,1,1);
}

void drawVRect(int pos){
	glBegin(GL_POLYGON);
		glVertex2d(pos-(rsize/2), 0);
      		glVertex2d(pos-(rsize/2), gridy);
      		glVertex2d(pos+(rsize/2), gridy);
		glVertex2d(pos+(rsize/2), 0);
	glEnd();
	glFlush();
}

void drawWhiteVRect(int pos) {
	glColor3f(1,1,1);
	drawVRect(pos);
}

void drawBlackVRect(int pos) {
	glColor3f(0,0,0);
	drawVRect(pos);
	glColor3f(1,1,1);
}

void initGL() {
   // Set "clearing" or background color
   	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glLoadIdentity();
	gluOrtho2D(0, gridx, gridy,0);

}
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

int i=0;
do {
drawVRect(i);
i = i+(2*rsize);
} while( i <= gridy);

glFlush();  // Render now
}

void idleAnimiation(void) {
/*
dreaw two Yello and Black boxes
function to erase and redraw it,
Move but on same speed on loop
*/



//erase two and redraw rect here

/*
Can uptize it to make the square run smothly
just draw the last line moved with the required color

registere keyboard function and hide the background on press of a button
*/
eraseSquare(posi,one4thy);
eraseSquare(posi,three4thy);

drawWhiteVRect((posi/(2*rsize))*(2*rsize));

if(posi+ssize > gridx){
posi=ssize;
}

posi+= ssize;
drawYellowSquare(posi,one4thy);
drawBlueSquare(posi,three4thy);

glFlush();
usleep(129000);

}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	posi=0;
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitWindowSize(hres, vres);   // Set the window's initial width & height
   glutInitWindowPosition(350,0); // Position the window's initial top-left corner
   glutCreateWindow("Yello Blue Boxes");  // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutIdleFunc(idleAnimiation);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}


