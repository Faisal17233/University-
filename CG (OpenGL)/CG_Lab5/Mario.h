#include "pixMap.h"
#include <iostream>
#include <chrono>
#include <thread>

class Point2 {

	private:
		float x, y;
		
	public:
		Point2() { x = y = 0.0f;}
		Point2(float xx,float yy) { this->x = xx; this->y = yy;}
		void set(float xx,float yy) { this->x = xx; this->y = yy;} 
		float getX() { return this->x; }
		float getY() { return this->y; }
		
		void draw(void) {
			glPointSize(2.0);
			
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); 
			glEnable(GL_POINT_SMOOTH);

			glBegin(GL_POINTS);
				glVertex2f((GLfloat)this->x, (GLfloat)this->y);
			glEnd();

			glDisable( GL_POINT_SMOOTH);
		}
};


class Mario {
	public:
		RGBApixmap pix[5]; // make six empty pixmaps, one for each side of cube
		enum State	{ STANDING,	RUNNING1, RUNNING2,	RUNNING3, JUMPING,GROUND} state;
		enum ModeType { STAY, RUN, BACK, JUMP, GROUNDED, SIT, DEAD } mode;

		float pos_X, pos_Y;
		
		Mario(Point2 pos) {
			pix[0].readBMPFile("MarioStanding.bmp", 1);
			pix[1].readBMPFile("MarioJump.bmp", 1);
			pix[2].readBMPFile("MarioRun1.bmp", 1);
			pix[3].readBMPFile("MarioRun2.bmp", 1);  
			pix[4].readBMPFile("MarioRun3.bmp", 1);
			
			for(int i=0;i<6;i++)
				pix[i].setChromaKey(192, 192, 192);

			
			this->pos_X = pos.getX();
			this->pos_Y = pos.getY();
			
		}
		
		void changePosition(float dx, float dy) {
			if (this->pos_X > 600) this->pos_X = 0.0;
			else if (this->pos_X < 0) this->pos_X = 599;
			else this->pos_X += dx;  this->pos_Y += dy;
		}

		void render();
		void changeMode(ModeType m);
		void run();
		void back();
		void jump();
		void grounded();
};

Mario m(Point2 (0,0));

void Mario::render() {
    
	switch( mode ) {
	
		case STAY:
			glRasterPos2i(this->pos_X, this->pos_Y);
			pix[STAY].mDraw();
			break;

		case RUN:
			run();
			break;
			
		case BACK:
			back();
			break;

		case JUMP:
			jump();
			break;
			
		case GROUNDED:
			grounded();
			break;
			
	}

}


void Mario::run() {
	switch( state ) {

		case RUNNING1:
			state = RUNNING2;
			break;

		case RUNNING2:
			state = RUNNING3;
			break;

		case RUNNING3:	
			state = RUNNING1;
			break;
	}
	
	changePosition(0.15, 0);
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[state].mDraw();
	if (this->pos_Y > 0) {
		state = JUMPING;
		changePosition(0.05, -(0.10));
		pix[state].mDraw();
	}
}

void Mario::back() {
	
	switch (state) {
		
		case RUNNING1:
			state = RUNNING2;
			break;

		case RUNNING2:
			state = RUNNING3;
			break;

		case RUNNING3:
			state = RUNNING1;
			break;
	}
	
	changePosition(-0.1, 0);
	glRasterPos2i(this->pos_X,this->pos_Y);
	pix[state].mDraw();
}

void Mario::changeMode(ModeType m)
{
	if( mode == m )
		return;

	switch( m ) {
		case STAY:
			state = STANDING;
			break;

		case RUN:
			state = RUNNING1;
			break;
			
		case BACK:
			state = RUNNING1;
			break;

		case JUMP:
			state = JUMPING;
			break;
			
		case GROUNDED:
			state = GROUND;
			break;
			
	}

	mode = m;
}

void Mario::jump() {   
	switch( state ) {
		
	case RUNNING1:
	
		state = RUNNING2;
		break;

	case RUNNING2:

		state = RUNNING3;
		break;

	case RUNNING3:
			
		state = RUNNING1;
		break;

	}
    changePosition(0.1, 0.1);
	glRasterPos2i(this->pos_X,this->pos_Y);
	pix[state].mDraw();
}

void Mario::grounded() {  
	if (this->pos_Y > 0) {
		state = JUMPING;
		changePosition(0.1, -(0.1));
	}
	glRasterPos2i(this->pos_X, this->pos_Y);
	pix[state].mDraw();
	if (this->pos_Y <= 0) {
		state = STANDING;
	}
}

