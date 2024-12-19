//#include <iostream>
//#include <fstream>
//#include <math.h>
//#include "glut.h"
//
//using namespace std;
//
//const float PI = 3.14;
//const int numVertices = 50; // Number of vertices to approximate the arc
//
//void drawArc(float centerX, float centerY, float radius, float startAngle, float endAngle) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numVertices; ++i) {
//        float angle = startAngle + (endAngle - startAngle) * static_cast<float>(i) / numVertices;
//        float x = centerX + radius * cos(angle);
//        float y = centerY + radius * sin(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//void display() {
//    glClearColor(0, 0, 0, 1.0);       // background color is black
//    glColor3f(1, 1, 1);         // drawing color is white
//
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glPointSize(10.0);
//
//    // Draw an arc centered at (0, 0) with a radius of 5, from 45 degrees to 135 degrees
//    drawArc(0.0, 0.0, 5.0, 45.0 * PI / 180.0, 135.0 * PI / 180.0);
//
//    glFlush();
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Act 7");
//
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}
