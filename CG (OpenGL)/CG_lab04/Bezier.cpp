//#include <cmath>
//#include "glut.h"
//#include <Windows.h>
//
//// Number of points to generate the curve
//const int numSegments = 100;
//
//// Function to draw a Quadratic Bezier curve
//void drawQuadraticBezier(float P0[2], float P1[2], float P2[2]) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numSegments; ++i) {
//        float t = float(i) / numSegments;
//        float x = (1 - t) * (1 - t) * P0[0] + 2 * (1 - t) * t * P1[0] + t * t * P2[0];
//        float y = (1 - t) * (1 - t) * P0[1] + 2 * (1 - t) * t * P1[1] + t * t * P2[1];
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//// Function to draw a Cubic Bezier curve
//void drawCubicBezier(float P0[2], float P1[2], float P2[2], float P3[2]) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numSegments; ++i) {
//        float t = float(i) / numSegments;
//        float x = (1 - t) * (1 - t) * (1 - t) * P0[0] +
//            3 * (1 - t) * (1 - t) * t * P1[0] +
//            3 * (1 - t) * t * t * P2[0] +
//            t * t * t * P3[0];
//        float y = (1 - t) * (1 - t) * (1 - t) * P0[1] +
//            3 * (1 - t) * (1 - t) * t * P1[1] +
//            3 * (1 - t) * t * t * P2[1] +
//            t * t * t * P3[1];
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Control points for the Quadratic Bezier curve
//    float P0[2] = { -0.8f, -0.8f };
//    float P1[2] = { 0.0f, 0.8f };
//    float P2[2] = { 0.8f, -0.8f };
//
//    // Draw the Quadratic Bezier curve (red)
//    glColor3f(1.0f, 0.0f, 0.0f);
//    drawQuadraticBezier(P0, P1, P2);
//
//    // Control points for the Cubic Bezier curve
//    float P3[2] = { -0.8f, 0.8f };
//    float P4[2] = { -0.4f, -0.6f };
//    float P5[2] = { 0.4f, 0.6f };
//    float P6[2] = { 0.8f, -0.8f };
//
//    // Draw the Cubic Bezier curve (blue)
//    glColor3f(0.0f, 0.0f, 1.0f);
//    drawCubicBezier(P3, P4, P5, P6);
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
//    glutCreateWindow("Bezier Curves");
//
//    glClearColor(0.0, 0.0, 0.0, 1.0);  // BG color
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}
