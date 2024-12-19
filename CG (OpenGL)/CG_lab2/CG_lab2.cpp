//#include "glut.h"
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // GL_POINTS example
//    // glPointSize(5.0); // Set the point size to 5.0 pixels
//    // glBegin(GL_POINTS);
//    // glVertex2f(0.1, 0.1);
//    // glVertex2f(0.1, -0.1);
//    // glVertex2f(-0.1, -0.1);
//    // glVertex2f(-0.1, 0.1);
//    // glEnd();
//
//    // // GL_LINES example
//    // glBegin(GL_LINES);
//    // glVertex2f(-0.5, 0.5);
//    // glVertex2f(-0.7, 0.7);
//    // glVertex2f(0.5, 0.5);
//    // glVertex2f(0.7, 0.7);
//    // glEnd();
//
//    // // GL_LINE_STRIP example
//    // glBegin(GL_LINE_STRIP);
//    // glVertex2f(0.2, 0.2);
//    // glVertex2f(0.4, 0.4);
//    // glVertex2f(0.6, 0.2);
//    // glEnd();
//
//    // // GL_LINE_LOOP example
//    // glBegin(GL_LINE_LOOP);
//    // glVertex2f(-0.2, -0.2);
//    // glVertex2f(-0.2, -0.4);
//    // glVertex2f(0.0, -0.6);
//    // glVertex2f(0.2, -0.4);
//    // glVertex2f(0.2, -0.2);
//    // glEnd();
//
//    // // GL_POLYGON example
//    // glBegin(GL_POLYGON);
//    // glVertex2f(-0.6, 0.2);
//    // glVertex2f(-0.8, 0.4);
//    // glVertex2f(-0.7, 0.6);
//    // glVertex2f(-0.5, 0.6);
//    // glVertex2f(-0.4, 0.4);
//    // glEnd();
//
//    // // GL_TRIANGLE_STRIP example
//    // glBegin(GL_TRIANGLE_STRIP);
//    // glVertex2f(0.2, -0.7);
//    // glVertex2f(0.6, -0.7);
//    // glVertex2f(0.4, -0.9);
//    // glVertex2f(0.8, -0.9);
//    // glEnd();
//
//    // // GL_TRIANGLES example
//    glBegin(GL_TRIANGLES);
//    glVertex2f(0.8, 0.2);
//    glVertex2f(0.9, 0.4);
//    glVertex2f(0.7, 0.4);
//    glEnd();
//
//    // // GL_TRIANGLE_FAN example
//    // glBegin(GL_TRIANGLE_FAN);
//    // glVertex2f(-0.6, -0.2);
//    // glVertex2f(-0.8, -0.4);
//    // glVertex2f(-0.7, -0.6);
//    // glVertex2f(-0.5, -0.6);
//    // glVertex2f(-0.4, -0.4);
//    // glEnd();
//
//    // // GL_QUADS example
//    // glBegin(GL_QUADS);
//    // glVertex2f(-0.3, 0.8);
//    // glVertex2f(-0.5, 0.8);
//    // glVertex2f(-0.5, 0.6);
//    // glVertex2f(-0.3, 0.6);
//    // glEnd();
//
//    // // GL_QUAD_STRIP example
//    // glBegin(GL_QUAD_STRIP);
//    // glVertex2f(0.2, 0.8);
//    // glVertex2f(0.3, 0.8);
//    // glVertex2f(0.2, 0.6);
//    // glVertex2f(0.3, 0.6);
//    // glVertex2f(0.4, 0.8);
//    // glVertex2f(0.4, 0.6);
//    // glEnd();
//
//    glFlush();
//}
//
//void init() {
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glColor3f(1, 0, 0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(400, 400);
//    glutCreateWindow("OpenGL Static Image");
//    glutDisplayFunc(display);
//    init();
//    glutMainLoop();
//    return 0;
//}
