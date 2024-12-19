//#include <iostream>
//#include <fstream>
//#include <string>
//#include "glut.h"
//#include <windows.h>
//
//const int screenWidth = 640;
//const int screenHeight = 480;
//GLdouble A, B, C, D;
//
//void myInit(void)
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glColor3f(0.0f, 0.0f, 0.0f);
//    glPointSize(2.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, (GLint)screenWidth, 0.0, (GLint)600);
//}
//
//void hardWiredHouse(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_LINE_LOOP);
//    glVertex2i(200, 50);
//    glVertex2i(200, 300);
//    glVertex2i(300, 500);
//    glVertex2i(400, 300);
//    glVertex2i(400, 50);
//    glEnd();
//    glBegin(GL_LINE_STRIP);
//    glVertex2i(230, 360);
//    glVertex2i(230, 480);
//    glVertex2i(260, 480);
//    glVertex2i(260, 420);
//    glEnd();
//    glFlush();
//    glBegin(GL_LINE_STRIP);
//    glVertex2i(230, 50);
//    glVertex2i(230, 180);
//    glVertex2i(290, 180);
//    glVertex2i(290, 50);
//    glEnd();
//    glBegin(GL_LINE_LOOP);
//    glVertex2i(340, 230);
//    glVertex2i(340, 270);
//    glVertex2i(370, 270);
//    glVertex2i(370, 230);
//    glEnd();
//    glFlush();
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(screenWidth, screenHeight);
//    glutInitWindowPosition(100, 150);
//    glutCreateWindow("House with a hard-wired dimensions");
//    glutDisplayFunc(hardWiredHouse);
//    myInit();
//    glutMainLoop();
//    return 0;
//}
//
