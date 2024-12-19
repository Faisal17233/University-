//#include <iostream>
//#include <vector>
//#include <cmath>
//
//#include <Windows.h>
//#include "glut.h"
//
//
//struct PolygonData {
//    int sides;
//    float radius;
//    float x, y; // Position of the polygon
//    float r, g, b; // Color of the polygon
//};
//
//std::vector<PolygonData> polygons;
//
//#define M_PI 3.14159265358979323846
//// Function to draw a regular n-sided polygon (ngon)
//void ngon(int n, float radius, float x, float y) {
//    if (n < 3) return; // A polygon must have at least 3 sides
//
//    float angleIncrement = 2.0f * M_PI / n;
//
//    glBegin(GL_POLYGON);
//    for (int i = 0; i < n; ++i) {
//        float angle = i * angleIncrement;
//        float xPos = x + radius * cosf(angle);
//        float yPos = y + radius * sinf(angle);
//        glVertex2f(xPos, yPos);
//    }
//    glEnd();
//}
//
//void drawMultipleNgons() {
//    // Clear the screen with a black background
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Call ngon() with different parameters to draw multiple polygons
//
//    // Draw a triangle
//    glColor3f(1.0f, 0.0f, 0.0f); // Red color
//    ngon(3, 0.3f, -0.6f, 0.5f); // 3-sided polygon (triangle)
//
//    // Draw a square
//    glColor3f(0.0f, 1.0f, 0.0f); // Green color
//    ngon(4, 0.3f, 0.6f, 0.5f); // 4-sided polygon (square)
//
//    // Draw a pentagon
//    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
//    ngon(5, 0.3f, 0.0f, -0.5f); // 5-sided polygon (pentagon)
//
//    glFlush(); // Render now
//}
//
//void drawPolygons() {
//    for (const auto& polygon : polygons) {
//        // Set the color for each polygon
//        glColor3f(polygon.r, polygon.g, polygon.b);
//
//        // Draw the polygon
//        ngon(polygon.sides, polygon.radius, polygon.x, polygon.y);
//    }
//
//    glFlush(); // Render now
//}
//
//// Function to take user input for the number of polygons
//void takePolygonInput() {
//    int numPolygons;
//    std::cout << "Enter the number of polygons to draw: ";
//    std::cin >> numPolygons;
//
//    polygons.clear(); // Clear previous data
//
//    for (int i = 0; i < numPolygons; ++i) {
//        PolygonData polygon;
//        std::cout << "Enter number of sides for polygon " << i + 1 << ": ";
//        std::cin >> polygon.sides;
//
//        std::cout << "Enter radius for polygon " << i + 1 << ": ";
//        std::cin >> polygon.radius;
//
//        std::cout << "Enter position (x y) for polygon " << i + 1 << ": ";
//        std::cin >> polygon.x >> polygon.y;
//
//        std::cout << "Enter color (r g b) for polygon " << i + 1 << ": ";
//        std::cin >> polygon.r >> polygon.g >> polygon.b;
//
//        polygons.push_back(polygon); // Store the polygon data
//    }
//}
//
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    drawPolygons();
//    //drawMultipleNgons();
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
//    // Input for polygons
//    takePolygonInput();
//    
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("Draw Ngons");
//
//    // Set the background color to black
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}