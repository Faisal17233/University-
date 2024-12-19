//#include <cmath>
//#include <iostream>
//#include "glut.h"
//#include <Windows.h>
//const float PI = 3.14159265359f;
//
//// Function to draw an arc
//void drawArc(float radius, float startAngle, float endAngle, int numSegments) {
//    glBegin(GL_LINE_STRIP);  // Use line strip to draw connected segments
//    for (int i = 0; i <= numSegments; ++i) {
//        float angle = startAngle + (endAngle - startAngle) * i / numSegments;
//        float x = radius * cosf(angle);
//        float y = radius * sinf(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//// Function to draw a rectangular window
//void drawRectangle(float x1, float y1, float x2, float y2) {
//    glBegin(GL_POINT);  // Use GL_QUADS to draw a filled rectangle
//    glVertex2f(x1, y1);  // Bottom-left corner
//    glVertex2f(x2, y1);  // Bottom-right corner
//    glVertex2f(x2, y2);  // Top-right corner
//    glVertex2f(x1, y2);  // Top-left corner
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Draw the rectangular part of the window
//    glColor3f(1.0, 0.0, 0.0);  // color for the window
//    drawRectangle(-0.4f, -0.4f, 0.4f, 0.0f);  // Rectangle from (-0.4, -0.4) to (0.4, 0.0)
//
//    // Draw the arc on top of the window
//    glColor3f(1.0, 0.0, 0.0);  // color for the arc
//    drawArc(0.4f, 0.0f, PI, 50);  // Arc with radius 0.4 from 0 to 180 degrees
//
//    // Draw window frame (outline) for both the rectangle and arc
//    glColor3f(1.0f, 0.0f, 0.0f);  // color for the outline
//    glLineWidth(3.0f);
//
//    // Rectangle outline
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(-0.4f, -0.4f);
//    glVertex2f(0.4f, -0.4f);
//    glVertex2f(0.4f, 0.0f);
//    glVertex2f(-0.4f, 0.0f);
//    glEnd();
//
//    // Arc outline (semi-circle on top)
//    drawArc(0.4f, 0.0f, PI, 50);  // Outline for the arc
//
//    glFlush();
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set orthographic projection
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("Window with Arc on Top");
//
//    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color 
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}