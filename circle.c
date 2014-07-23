// Draw circle
// gcc -o cir circle.c -lGL -lglut -lGLU -lm
//
//
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void display(void);
void idleAnime(void);
void keyboard(unsigned char key, int x, int y);
void drawCircle(int x, int y, int r, float red, float green, float blue);

int gridX=400;
int gridY=400;
int counter=10;

#define maxCircleR 50
#define size 20

int x[size];
int y[size];
int r[size];
float red[size];
float green[size];
float blue[size];


int main(int argc, char *argv[] ){

	glutInit(&argc, argv);
	glutInitWindowSize(gridX,gridY);
	glutCreateWindow("Circle Animi");

	glutDisplayFunc(display);
	glutIdleFunc(idleAnime);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
void idleAnime(void){
	int i;

	drawCircle(x[0], y[0], r[0], 0, 0, 0); //erase
	//drawCircle(x[0], y[0], r[0]-5, 0, 0, 0); //erase


	for(i=1;i<size;i++){
		x[i-1] = x[i];
		y[i-1] = y[i];
		r[i-1] = r[i];

		red[i-1] = red[i];
		green[i-1] = green[i];
		blue[i-1] = blue[i];
	}
//	printf(" i = %d  %d ", i, size);
	x[i-1] = rand()%gridX;
	y[i-1] = rand()%gridY;
	r[i-1] = rand()%maxCircleR;

	red[i-1] = (rand()%100)/100.0;
	green[i-1] = (rand()%100)/100.0;
	blue[i-1] = (rand()%100)/100.0;

	for(i=0;i<size; i++) {
				drawCircle(x[i],y[i], r[i], 0, 0, 0);
				r[i] -=3;
				//if( r[i] <0){
				//	printf("%d is negative\n", r[i]);
				//	r[i]=0;
				//}
//		}
//	for(i=0;i<size;i++){
				drawCircle(x[i],y[i], r[i], red[i], green[i], blue[i]);
		//		drawCircle(x[i],y[i], r[i]-5, red[i], green[i], blue[i]);

	}
	usleep(111000);
}
void display(void) {
	glLineWidth(2.0);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0, gridX, gridY, 0); // left right bottom top

	glColor3f(1.0, 1.0, 1.0);
//	drawCircle(gridX/2, gridY/2, 20);
	int i;
	for(i=0; i<size; i++) {
	// initialize all

	x[i] = rand()%gridX;
	y[i] = rand()%gridY;

	r[i] = rand()%maxCircleR;

	red[i] = (rand()%100)/100.0;
	green[i] = (rand()%100)/100.0;
	blue[i] = (rand()%100)/100.0;

	drawCircle(x[i],y[i], r[i], red[i], green[i], blue[i]);
//	drawCircle(x[i],y[i], r[i]-5, red[i], green[i], blue[i]);

}

	
	glFlush();
}


void keyboard(unsigned char key, int x, int y) {
	if(key == 27){
		exit(0);
	}
}

void drawCircle(int x, int y, int r, float red, float green, float blue){
//	printf("drawCicle\n");
//	glBegin(GL_LINE_LOOP);
//		glVertex2f(x-r,y-r);
//		glVertex2f(x+r,y-r);
//		glVertex2f(x+r,y+r);
//		glVertex2f(x-r,y+r);
	
	int i;
	float tx,ty;
	float thita=0;
	float incrThita = 12*3.1415/180;
	
	glColor3f(red, green, blue);
	glBegin(GL_LINE_LOOP);
	for(i=0;i<30;i++){
		tx =x+r*sin(thita+incrThita);
		ty = y+r*cos(thita+=incrThita);
		glVertex2f(tx,ty);
	}
	glEnd();
	glFlush();
}
