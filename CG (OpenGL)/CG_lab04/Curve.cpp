//#include <cmath>
//#include <iostream>
//#include "glut.h"
//#include <Windows.h>
//const int numSegments = 100;  // Number of segments for smoothness
//
//// Function to plot points for a polynomial of degree 1 (Linear)
//void drawDegree1(float a, float b) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numSegments; ++i) {
//        float x = -1.0f + 2.0f * i / numSegments;  // Normalized x from -1 to 1
//        float y = a * x + b;                       // Linear equation
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//// Function to plot points for a polynomial of degree 2 (Quadratic)
//void drawDegree2(float a, float b, float c) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numSegments; ++i) {
//        float x = -1.0f + 2.0f * i / numSegments;
//        float y = a * x * x + b * x + c;           // Quadratic equation
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//// Function to plot points for a polynomial of degree 3 (Cubic)
//void drawDegree3(float a, float b, float c, float d) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numSegments; ++i) {
//        float x = -1.0f + 2.0f * i / numSegments;
//        float y = a * x * x * x + b * x * x + c * x + d;  // Cubic equation
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//// Function to plot points for a higher degree polynomial (Quartic example)
//void drawDegree4(float a, float b, float c, float d, float e) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numSegments; ++i) {
//        float x = -1.0f + 2.0f * i / numSegments;
//        float y = a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;  // Quartic equation
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Draw Degree 1 Polynomial (Linear)
//    glColor3f(1.0, 0.0, 0.0);  // Red
//    drawDegree1(1.0f, 0.0f);   // y = x
//
//    // Draw Degree 2 Polynomial (Quadratic)
//    glColor3f(0.0, 1.0, 0.0);  // Green
//    drawDegree2(1.0f, 0.0f, -0.5f);  // y = x^2 - 0.5
//
//    // Draw Degree 3 Polynomial (Cubic)
//    glColor3f(0.0, 0.0, 1.0);  // Blue
//    drawDegree3(1.0f, -0.5f, 0.0f, 0.0f);  // y = x^3 - 0.5x^2
//
//    // Draw Degree 4 Polynomial (Quartic)
//    glColor3f(1.0, 1.0, 0.0);  // Yellow
//    drawDegree4(1.0f, 0.0f, -0.5f, 0.0f, 0.0f);  // y = x^4 - 0.5x^2
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
//    glutCreateWindow("Curves Using Polynomials");
//
//    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color 
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}
