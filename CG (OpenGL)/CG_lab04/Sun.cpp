//#include <cmath>
//#include "glut.h"
//#include <Windows.h>
//
//
//const int numTriangles = 12; 
//const float triangleGap = 0.1f;
//
//void drawSunWithTriangles() {
//    float circleRadius = 0.3f;
//    float triangleRadius = 0.7f; // Distance from center to the triangle tip
//    float angleIncrement = 2.0f * 3.14159 / numTriangles;
//
//    // Draw the center circle
//    glColor3f(1.0, 1.0, 0.0);
//    glBegin(GL_TRIANGLE_FAN);
//    for (int i = 0; i <= 120; ++i) {
//        float theta = 2.0f * 3.14159 * float(i) / float(100);
//        float x = circleRadius * cosf(theta);
//        float y = circleRadius * sinf(theta);
//        glVertex2f(x, y);
//    }
//    glEnd();
//
//    // Draw isosceles triangles around the circumference
//    glColor3f(1.0, 1.0, 0.0); 
//    for (int i = 0; i < numTriangles; ++i) {
//        float angle = i * angleIncrement;
//
//        // Vertex at the tip of the triangle
//        float x1 = triangleRadius * cosf(angle);
//        float y1 = triangleRadius * sinf(angle);
//
//        // Base points of the triangle with added gap
//        float x2 = (circleRadius + triangleGap) * cosf(angle + angleIncrement / 2);
//        float y2 = (circleRadius + triangleGap) * sinf(angle + angleIncrement / 2);
//
//        float x3 = (circleRadius + triangleGap) * cosf(angle - angleIncrement / 2);
//        float y3 = (circleRadius + triangleGap) * sinf(angle - angleIncrement / 2);
//
//        glBegin(GL_TRIANGLES);
//        glVertex2f(x1, y1);
//        glVertex2f(x2, y2);
//        glVertex2f(x3, y3);
//        glEnd();
//    }
//
//    glFlush();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawSunWithTriangles();
//}
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("Sun Design with Isosceles Triangles");
//
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
