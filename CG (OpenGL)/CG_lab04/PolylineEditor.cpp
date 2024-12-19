//#include <vector>
//#include <iostream>
//#include "glut.h"
//
//struct Point {
//    float x, y;
//};
//
//// Global variables to store points and polylines
//std::vector<Point> currentPolyline;  // Current polyline being edited
//std::vector<std::vector<Point>> polylines;  // Completed polylines
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Draw completed polylines
//    glColor3f(0.0f, 1.0f, 0.0f);  // Green for completed polylines
//    for (const auto& polyline : polylines) {
//        glBegin(GL_LINE_STRIP);
//        for (const auto& point : polyline) {
//            glVertex2f(point.x, point.y);
//        }
//        glEnd();
//    }
//
//    // Draw current polyline being edited
//    glColor3f(1.0f, 0.0f, 0.0f);  // Red for current polyline
//    glBegin(GL_LINE_STRIP);
//    for (const auto& point : currentPolyline) {
//        glVertex2f(point.x, point.y);
//    }
//    glEnd();
//
//    glFlush();
//}
//
//// Function to convert screen coordinates to world coordinates
//Point screenToWorld(int x, int y) {
//    Point pt;
//    pt.x = (float)x / (glutGet(GLUT_WINDOW_WIDTH) / 2.0f) - 1.0f;
//    pt.y = 1.0f - (float)y / (glutGet(GLUT_WINDOW_HEIGHT) / 2.0f);
//    return pt;
//}
//
//// Mouse callback to handle left and right clicks
//void mouse(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        // Add point to current polyline
//        Point pt = screenToWorld(x, y);
//        currentPolyline.push_back(pt);
//        glutPostRedisplay();  // Trigger a redraw
//    }
//    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//        // Finish current polyline and store it
//        if (!currentPolyline.empty()) {
//            polylines.push_back(currentPolyline);
//            currentPolyline.clear();
//        }
//        glutPostRedisplay();  // Trigger a redraw
//    }
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("Polyline Editor");
//
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color to black
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutMouseFunc(mouse);  // Set mouse callback
//
//    glutMainLoop();
//    return 0;
//}
