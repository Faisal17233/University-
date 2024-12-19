// CG_lab_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

#include <iostream>
#include "canvas.h"
#include "spider.h"
#include "glut.h"

// Global canvas and game components
Spider spider(Point2(300, screenHeight / 2));
Bullet bullet(10, 40);
Score score;

// Function declarations
void display();
void timer(int);
void keyboard(unsigned char key, int x, int y);
void idle();
void refreshGame(); // Function to handle game refresh

// Display function to render the scene
void display() {
    cv.clearScreen();
    glRasterPos2i(0, 0);
    float zoomX = (float)screenWidth / background.nCols;  // Scale X to match screen width
    float zoomY = (float)screenHeight / background.nRows;  // Scale Y to match screen height
    glPixelZoom(zoomX, zoomY);
    background.mDraw(); // Draw the background image
    spider.render();
    bullet.drawBullet();
    score.displayScore(); // Display the score

    glutSwapBuffers();
}

// Timer function to update the game state
void timer(int) {

    //glutTimerFunc(16, timer, 0); // Schedule the next frame update (60 FPS)
    if (spider.getState() == DEAD) {
        // Dead spider remains on screen until the revive condition is met
        spider.action(); // Continue to check the revival condition
    }
    else {
        spider.action();  // Update spider position and state
        bullet.fire();    // Update bullet position and state

        // Check for collision between bullet and spider
        if (bullet.firing && spider.checkCollision(bullet.pos_X, bullet.pos_Y, bullet.width, bullet.height)) {
            PlaySound(TEXT("hit_sound.wav"), NULL, SND_ASYNC);  // Play sound on hit
            spider.die(); // Kill the spider
            score.increaseScore(10); // Increase score
            spider.increaseSpeed(score.getScore()); // Increase spider speed based on score
            bullet.resetPosition(); // Reset bullet position after hit
            bullet.firing = false; // Stop bullet firing
        }
    }

    glutPostRedisplay(); // Redraw screen with updated objects
    glutTimerFunc(16, timer, 0); // Schedule the next frame update (60 FPS)
}

// Keyboard input handling
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':  // Move bullet left
        bullet.left();
        break;
    case 'd':  // Move bullet right
        bullet.right();
        break;
    case 'w':  // Fire bullet
        bullet.startFiring();
        break;
    case 27:  // Escape key
        exit(0);
        break;
    }
}

// Idle function for continuous updates
void idle() {
    glutPostRedisplay(); // Request a new frame to be drawn
}

// Function to handle game refresh after spider is killed
void refreshGame() {
    spider.revive(); // Revive spider after 2 seconds
    bullet.firing = false; // Stop bullet firing
    bullet.resetPosition(); // Reset bullet

}

// Main function to set up and run the game
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("spider shooter");

    cv.init(); // Initialize Canvas

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    background.readBMPFile("bg.bmp", 1);
    glutMainLoop();
    return 0;
}