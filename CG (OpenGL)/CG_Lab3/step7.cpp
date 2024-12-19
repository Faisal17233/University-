//#include <string>
//#include "glut.h"
//
//void drawText(std::string text, int x, int y) {
//    glRasterPos2f(x, y);
//    int Len = text.length();
//    for (int i = 0; i < Len; i++) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
//    }
//}
//
//// changing background color
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//void display() {
//    changeWindowColor(0.545, 0.034, 0.74, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//
//    glColor3f(1, 1, 1);
//    drawText("HELLO!", 250, 370);
//    drawText("Hi", 250, 390);
//    drawText("This is OpenGL LAB.", 250, 410);
//
//    glFlush();
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0, width, height, 0, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("Step 7");
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    changeWindowColor(0.545, 0.034, 0.74, 1.0);
//
//    glutMainLoop();
//    return 0;
//}
