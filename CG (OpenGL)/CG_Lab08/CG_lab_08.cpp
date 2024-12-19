#include <cmath>
#include "canvas.h"
#include "glut.h"

float turtle_x = 0.0f;
float turtle_y = 0.0f;
float turtle_angle = 0.0f;
Canvas cvs;

void forward(float length, int draw) {
    float angle_radians = turtle_angle * (3.142 / 180.0f); // Convert to radians
    float delta_x = length * cos(angle_radians); //change in x
    float delta_y = length * sin(angle_radians); //change in y

    float new_x = turtle_x + delta_x; //new x position
    float new_y = turtle_y + delta_y; //new y position

    if (draw) { //if true then draw line from CP to NP
        glBegin(GL_LINES);
        glVertex2f(turtle_x, turtle_y); //starting of newline
        glVertex2f(new_x, new_y); //ending of new line
        glEnd();
    }

    turtle_x = new_x;
    turtle_y = new_y;
}

void moveTo(float x, float y) {
    turtle_x = x;
    turtle_y = y;
}

void turn(float angle) {
    turtle_angle += angle;
}

void flakeMotif(float L) {
    glPushMatrix();
    moveTo(0.0, 0.1 * L);
    turn(0);
    forward(2 * L, 1);
    turn(60);
    forward(1 * L, 1);
    turn(270);
    forward(0.2 * L, 1);
    turn(270);
    forward(0.9 * L, 1);
    turn(120);
    forward(1 * L, 1);
    turn(60);
    forward(0.9 * L, 1);
    turn(270);
    forward(0.2 * L, 1);
    turn(270);
    forward(0.8 * L, 1);
    turn(120);
    forward(1 * L, 1);
    turn(330);
    forward(0.2 * L, 1);
    turn(30);
    glPopMatrix();
}

void drawFlake() {
    for (int i = 0; i < 6; i++) {
        flakeMotif(10);
        cvs.scale2D(1.0, -1.0);
        flakeMotif(10);
        cvs.scale2D(1.0, -1.0);
        cvs.rotate2D(60.0);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    drawFlake();
    glutSwapBuffers();
}

const int screenWidth = 640;
const int screenHeight = 480;
void myInit(void)
{
    glViewport(0, 0, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glPointSize(2.0);
    glLoadIdentity();
    gluOrtho2D(-screenWidth / 2, screenWidth / 2, -screenHeight / 2, screenHeight / 2);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Drawing Turtle Figures part a");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}