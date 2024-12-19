#include "glut.h"

//using namespace std;

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1f, 0.1f, 0.1f, 0.0);
    glColor3f(1, 1, 1);
    glFlush();
}

int screenWidth = 640;
int screenHeight = 480;


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(50, 90);
    glutCreateWindow("HT FirstOGL Program");

    glutDisplayFunc(myDisplay);

    glutMainLoop();

    return 0;

}

