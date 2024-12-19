#ifndef CANVAS_H
#define CANVAS_H

#include "glut.h"

// A simple Point2 class to represent 2D coordinates
class Point2 {
public:
    float x, y;

    Point2() : x(0), y(0) {}
    Point2(float x, float y) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void set(float newX, float newY) {
        x = newX;
        y = newY;
    }
};

// Canvas class for managing drawing, movement, and coordinate changes
class Canvas {
private:
    int width, height;
    const char* title;

public:
    Canvas(int width, int height, const char* title)
        : width(width), height(height), title(title) {
        init();
    }
    void setBackgroundColor(float r, float g, float b) {
        glClearColor(r, g, b, 1.0f);  // Use OpenGL function to set the background color
    }
    // Initialization function for the OpenGL canvas
    void init() {
        glClearColor(1.0, 1.0, 1.0, 1.0); // Set the background color to black
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(0.0, width, 0.0, height); // Set up the coordinate system
    }

    // Draw a filled rectangle (useful for drawing the bullet)
    void drawRect(float x, float y, float width, float height) {
        glColor3f(1, 0.0, 0.0);
        glBegin(GL_QUADS);
        glVertex2f(x, y);             // Bottom left
        glVertex2f(x + width, y);     // Bottom right
        glVertex2f(x + width, y + height); // Top right
        glVertex2f(x, y + height);    // Top left
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex2f((x - width  / 2)+4, y + height); // Bottom-left of triangle
        glVertex2f((x + width + width / 2)-4, y + height); // Bottom-right of triangle
        glVertex2f(x + width / 2, y + height + width / 2); // Top vertex of triangle
        glEnd();
    }

    // Set the current color (RGB format)
    void setColor(float r, float g, float b) {
        glColor3f(r, g, b);
    }

    // Function to clear the screen
    void clearScreen() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    // Function to refresh the canvas
    void refresh() {
        glutSwapBuffers();
    }
    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }
};

#endif // CANVAS_H
