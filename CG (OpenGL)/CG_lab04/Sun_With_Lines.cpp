//#include <math.h>
//#include <Windows.h>
//#include "glut.h"
//
//
//void drawSunWithLines() {
//    // Draw the center circle
//    float radius = 0.2f;
//    int numSegments = 120;
//    glColor3f(1.0, 1.0, 0.0); // Yellow color for the circle
//    glBegin(GL_POLYGON);
//    for (int i = 0; i < numSegments; ++i) {
//        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
//        float x = radius * cosf(theta);
//        float y = radius * sinf(theta);
//        glVertex2f(x, y);
//    }
//    glEnd();
//
//    // Draw the sun rays
//    glColor3f(1.0, 0.6, 0.0); // Orange color for the rays
//    for (int i = 0; i < 12; ++i) {
//        float angle = 2.0f * 3.1415926f * i / 12;
//        float x1 = radius * cos(angle);
//        float y1 = radius * sin(angle);
//        float x2 = (radius + 0.2f) * cos(angle);
//        float y2 = (radius + 0.2f) * sin(angle);
//
//        glBegin(GL_LINES);
//        glVertex2f(x1, y1);
//        glVertex2f(x2, y2);
//        glEnd();
//    }
//
//    glFlush();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawSunWithLines();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Sun Design with Lines");
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
