#include <windows.h> //suitable when using Windows 95/98/NT
#include <gl/Gl.h>
#include <gl/Glu.h>
#include "glut.h"

void displayWire(void)
{
    glMatrixMode(GL_PROJECTION); // set the view volume shape
    glLoadIdentity();
    glOrtho(-2.0 * 64 / 48.0, 2.0 * 64 / 48.0, -2.0, 2.0, 0.1, 100);
    glMatrixMode(GL_MODELVIEW); // position and aim the camera
    glLoadIdentity();
    gluLookAt(2.0, 2.2, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT); // clear the screen
    glColor3d(0, 0, 0); // draw black lines
    glPushMatrix();
    glTranslated(1.0, 1.0, 0); // sphere at (1,1,0)
    glutWireSphere(0.25, 10, 8);
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.0, 0, 1.0); // cone at (1,0,1)
    glutWireCone(0.2, 0.5, 10, 8);
    glPopMatrix();
    glPushMatrix();
    glTranslated(1, 1, 1);
    glutWireTeapot(0.2); // teapot at (1,1,1)
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 1.0, 0); // torus at (0,1,0)
    glRotated(90.0, 1, 0, 0);
    glutWireTorus(0.1, 0.3, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.0, 0, 0); // dodecahedron at (1,0,0)
    glScaled(0.15, 0.15, 0.15);
    glutWireDodecahedron();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1.5, 0, 0); // trinagle at (1.5,0,0)
    glScaled(0.25, 0.25, 0.25);
    glutWireTetrahedron();
    glPopMatrix();
    glPushMatrix();
    glTranslated(1, 1.6, 0); // Octahedron at (1.5,0,0)
    glScaled(0.25, 0.25, 0.25);
    glutWireOctahedron();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.6, 0, 1.9); // icosahedron at (1.5,0,0)
    glScaled(0.25, 0.25, 0.25);
    glutWireIcosahedron();
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 1.0, 1.0); // small cube at (0,1,1)
    glutWireCube(0.25);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 0, 1.0); // cylinder at (0,0,1)
    GLUquadricObj* qobj;
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_LINE);
    gluCylinder(qobj, 0.2, 0.2, 0.4, 8, 8);
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Wireframe");
    glutDisplayFunc(displayWire);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // background is white
    glViewport(0, 0, 640, 480);
    glutMainLoop();
}