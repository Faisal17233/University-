#include "Mario.h"
#include "glut.h"

const int screenWidth = 640;
const int screenHeight = 480;



void myInit(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0);
    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m.changeMode(Mario::STAY);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m.render();

    

    glFlush();
}

void spinner(int t) {
    glutPostRedisplay();
    glutTimerFunc(500, spinner, t);
}



void mySpecialKeyHandler(int key, int mx, int my) {
        switch (key) {

        case GLUT_KEY_RIGHT:
            m.changeMode(Mario::RUN);
            break;

        case GLUT_KEY_LEFT:
            m.changeMode(Mario::BACK);
            break;

        case GLUT_KEY_UP:
            // m.changeMode(Mario::JUMP);
            if (m.pos_Y <= 0) {
                m.changeMode(Mario::JUMP);
            }
            else if (m.pos_Y > 60) {
                m.changeMode(Mario::GROUNDED);
            }

            break;

        case GLUT_KEY_DOWN:
            m.changeMode(Mario::SIT);
            break;
        }

        glutPostRedisplay();

    
}


void mySpecialKeyRelease(int key, int mx, int my) {
    
        switch (key) {

        case GLUT_KEY_RIGHT:
            m.changeMode(Mario::STAY);
            break;

        case GLUT_KEY_LEFT:
            m.changeMode(Mario::STAY);
            break;

        case GLUT_KEY_UP:
            m.changeMode(Mario::GROUNDED);
            break;

        case GLUT_KEY_DOWN:
            m.changeMode(Mario::STAY);
            break;
        }
    
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Run Mario Run");


    glutDisplayFunc(display);
    glutSpecialFunc(mySpecialKeyHandler);
    glutSpecialUpFunc(mySpecialKeyRelease);

    myInit();
    glutIdleFunc(display);
    glutMainLoop();

}
