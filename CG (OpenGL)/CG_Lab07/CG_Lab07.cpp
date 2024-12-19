/*
This is a program which displays several primitives as well as animates objects.
Your task is to make the plane that makes a crash landing, but unlike the movies,
it doesn't burst into flames.The background contains a triangle for windmill.
You need to complete it using transformation then make it animate*/
#include <windows.h>
#include <iostream>
#include <cmath>
#include "glut.h"
#define PI 3.141592

void display(void); // draw everything
void drawWind(void);  // draw single blade 
void drawwindmill(void); //complete this to complete windmill i.e. call drawWind() in it
void drawplane();  // work in this function
//  for crash landing of plane i.e. animate and collision with land 

void drawlandscape();// do nothing with it 
void Timer(int value); // update varible for animation here

//void keyboard(unsigned char key, int x, int y);
void init(void);
//void reshape(GLsizei w, GLsizei h);




void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawlandscape();
    drawplane();
    drawwindmill();

    glutSwapBuffers();
}


void drawWind() // single Triangle
{

    glBegin(GL_TRIANGLES);

    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(125.0, 90.0);
    glVertex2f(140.0, 120.0);
    glVertex2f(160.0, 120.0);
    glEnd();

}

float rotationAngle = 0.0f;
void drawwindmill() { // complete windmill in this body
    /* Draw a windmill */
    glPushMatrix();
    glTranslatef(125.0, 90.0, 0.0); // Translate to the windmill's position
    glRotatef(rotationAngle, 0.0, 0.0, 1.0); // Rotate the windmill blades
    glTranslatef(-125.0, -90.0, 0.0); // Translate back to the original position

    for (int i = 0; i < 4; i++) {
        glTranslatef(125.0, 90.0, 0.0); // Translate to the windmill's position
        glRotatef(i * 90.0f, 0.0f, 0.0f, 1.0f); // Rotate each blade by 100 degrees
        glTranslatef(-125.0, -90.0, 0.0); // Translate back to the original position
        drawWind(); // Draw a single blade
    }
    glPopMatrix();

}

void Timer(int value) // work in this function after completing windmill to animate it
{
    //update variables here
    rotationAngle += 2.0;
    glutPostRedisplay();
    // glutTimerFunc(16, Timer, 1);
    glutTimerFunc(15, Timer, 0);
}



//static GLfloat w = 0.0;
static GLfloat x = 0.0;
static GLfloat y = 0.0;
//static GLfloat z = 0.0;
static GLfloat planeSpeed = 2.2;

void drawplane()// work in this function to animate and crash plane
{
    /* Draw a plane */
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(245.0, 230.0);
    glVertex2f(245.0, 240.0);
    glVertex2f(215.0, 230.0);

    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(244.0, 228.0);
    glVertex2f(244.0, 235.0);
    glVertex2f(228.0, 235.0);

    glEnd();
    glPopMatrix();

    // Check if the plane has reached the X-coordinate limits and reset if necessary to keep it within the screen
    if (x > -200) {
        x -= planeSpeed;
    }
    else if (x == -200) {
        x = -200;
    }

    // Check if the plane has reached the Y-coordinate limits and reset if necessary to keep it within the screen
    if (y > -180) {
        y -= 2;
    }
    else if (y == -180) {
        y = -180;
    }

    

    
    if ( y == -180) {
        //std::cout << "ok";
        float circleRadius = 15.9f;
        int numTriangles = 12;
        float angleIncrement = 2.0f * 3.14159 / numTriangles;
        glColor3f(1.0, 0.7, 0.0);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i <= 120; ++i) {
            float theta = 2.0f * 3.14159 * float(i) / float(100);
            float aaa = (circleRadius * cosf(theta))+30;
            float yyy = (circleRadius * sinf(theta))+57;
            glVertex2f(aaa, yyy);
        }
        glEnd();
        glBegin(GL_POINTS);

        for (int i = 0; i < 200; ++i) {
            // Generate random positions for the particles in a triangular-like shape
            float x = rand() % 30 + 15;
            float y = rand() % 28 + 43;

            // Assign random colors for fire particles
            float red = (rand() % 100) / 100.0f + 0.5f;   // Random red between 0.5 and 1.0
            float green = (rand() % 50) / 100.0f;         // Random green between 0.0 and 0.5
            float blue = 0.0f;                            // No blue for a fire effect

            glColor3f(red, green, blue);
            glVertex2f(x, y);
        }

        glEnd();
        //glFlush();
    
    }
}


void drawlandscape() {
    /* Draw a box of grass */
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(250.0, 0.0);
    glColor3f(0.0, 0.9, 0.0);
    glVertex2f(250.0, 50.0);
    glColor3f(0.0, 0.8, 0.0);
    glVertex2f(0.0, 50.0);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    /* An attempt at a few snow covered mountains */

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.6);
    glVertex2f(250.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(200.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(150.0, 50.0);

    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(200.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(150.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);

    glColor3f(0.0, 0.0, 0.7);
    glVertex2f(150.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(100.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(50.0, 50.0);

    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(50.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(0.0, 50.0);

    glEnd();

    /* Draw the body of a windmill */
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.0);
    glVertex2f(145.0, 50.0);
    glVertex2f(135.0, 100.0);
    glVertex2f(115.0, 100.0);
    glVertex2f(105.0, 50.0);
    glEnd();

}


void init() {
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


//void reshape(GLsizei w, GLsizei h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}


//void keyboard(unsigned char key, int x, int y) {
    //switch (key) {
    //case 27:
    //    exit(0);
    //    break;
    //}
//}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Faisal");
    init();
    glutDisplayFunc(display);
    //glutReshapeFunc(reshape);
    //glutKeyboardFunc(keyboard);
    glutTimerFunc(15, Timer, 0);
    glutMainLoop();
    return 1;
}