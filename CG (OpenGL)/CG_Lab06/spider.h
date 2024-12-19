#ifndef SPIDER_H
#define SPIDER_H

#include "pixMap.h"
#include "canvas.h"
#include <iostream>
#include "glut.h" // Include necessary GLUT headers
#include <windows.h>

enum State { ALIVE, DEAD };
enum ModeType { STAY, LEFT, RIGHT, DIE };

// Global canvas instance
const int screenWidth = 640;
const int screenHeight = 480;
Canvas cv(screenWidth, screenHeight, "Bullet V Spider");
RGBApixmap background;


class Spider {
public:
    RGBApixmap pix[2]; // Two images: Alive and Dead
    State state;
    ModeType mode;

    float pos_X, pos_Y; // Position of the spider
    float Vx;           // Velocity of the spider along X-axis
    float Vy; // Vertical velocity of the spider
    bool moving_right;
    float spiderWidth = 40; // Approximate width (you may adjust based on image size)
    float spiderHeight = 40; // Approximate height (you may adjust based on image size)
    int deathTime;  // Time at which the spider died

    // Constructor: Initializes spider position, state, and loads BMP images
    Spider(Point2 pos) {
        pix[0].readBMPFile("spider.bmp", 1);  // Alive image
        pix[1].readBMPFile("mak3.bmp", 1); // Dead image

        this->pos_X = pos.getX();
        this->pos_Y = pos.getY();
        this->Vx = 5;
        this->Vy = 3; // You can adjust this value to control the vertical speed
        this->state = ALIVE;
        this->moving_right = true;
        this->deathTime = -1;  // Initialize to -1 (not dead)
    }

    void increaseSpeed(int score) {
        // Increase speed by a small value after every 50 points
        if (score % 50 == 0 && score != 0) {
            Vx += 1.0f; // Increase speed by 1 unit (or any desired value)
        }

    }
    // Change the position of the spider
    void changePosition(float dx, float dy) {
        this->pos_X += dx;
        this->pos_Y += dy;
    }

    // Handle the spider's actions: movement and state changes
    void action() {
        if (state == ALIVE) {
            if (pos_X >= screenWidth - spiderWidth) {
                moving_right = false;
            }
            if (pos_X <= 0) {
                moving_right = true;
            }
            if (pos_Y >= screenHeight - spiderHeight) {
                Vy = -Vy; // Reverse direction when hitting the top boundary
            }
            if (pos_Y <= 0) {
                Vy = -Vy; // Reverse direction when hitting the bottom boundary
            }

            changePosition(this->Vx * (moving_right ? 1 : -1), this->Vy);  // Move spider diagonally
        }
        else if (state == DEAD) {
            // Dead spider logic: render dead spider until 2 seconds pass
            int currentTime = glutGet(GLUT_ELAPSED_TIME);
            if (currentTime - deathTime >= 2000) {
                revive(); // After 2 seconds, revive the spider
            }
        }
    }


    State getState() const { return state; } // Getter for state

    // Render the spider based on its mode and state
    void render() {
        if (state == ALIVE) {
            glRasterPos2i(this->pos_X, this->pos_Y);
            pix[0].mDraw(); // Draw alive spider
        }
        else if (state == DEAD) {
            glRasterPos2i(this->pos_X, this->pos_Y);
            pix[1].mDraw(); // Draw dead spider
        }
    }

    // Move the spider to the right
    void run() {
        changePosition(this->Vx, 0);
        glRasterPos2i(this->pos_X, this->pos_Y);
        pix[0].mDraw(); // Drawing alive spider
    }

    // Move the spider to the left
    void back() {
        changePosition(-(this->Vx), 0);
        glRasterPos2i(this->pos_X, this->pos_Y);
        pix[0].mDraw(); // Drawing alive spider
    }

    // Handle the spider's death
    void die() {
        this->state = DEAD;
        this->deathTime = glutGet(GLUT_ELAPSED_TIME);  // Record the time of death
    }

    // Revive the spider after 2 seconds
    void revive() {
        this->state = ALIVE;
        this->pos_X = 300; // Reset position (or set to initial position as needed)
    }

    // Collision detection between spider and bullet
    bool checkCollision(float bulletX, float bulletY, float bulletWidth, float bulletHeight) {
        // Bounding box collision detection
        return (bulletX + bulletWidth >= pos_X && bulletX <= pos_X + spiderWidth &&
            bulletY + bulletHeight >= pos_Y && bulletY <= pos_Y + spiderHeight);
    }
};


class Bullet {
public:
    float pos_X, pos_Y, width, height;
    float Vx;
    float Vy;
    bool firing;

    Bullet(float width, float height) {
        this->pos_X = screenWidth / 2;
        this->pos_Y = height + width + 2;
        this->Vx = 10;
        this->Vy = 20;
        this->width = width;
        this->height = height;
        this->firing = false;
    }

    void changePosition(float dx, float dy) {
        this->pos_X += dx;
        this->pos_Y += dy;
    }

    void resetPosition() {
        this->pos_X = screenWidth / 2;
        this->pos_Y = height + width + 2;
    }

    // Draw the bullet as a rectangle
    void drawBullet() {
        cv.setColor(1.0f, 0.0f, 0.0f);  // Set color to red
        cv.drawRect(pos_X - width / 2, pos_Y - height, width, height);  // Draw rectangle bullet
    }

    void right() {
        if (this->pos_X < screenWidth - width / 2) {
            changePosition(Vx, 0);
        }
    }

    void left() {
        if (this->pos_X > width / 2) {
            changePosition(-Vx, 0);
        }
    }

    void fire() {
        if (firing) {
            if (this->pos_Y < screenHeight) {
                changePosition(0, Vy);
                drawBullet();
            }
            else {
                firing = false;
                resetPosition();
            }
        }
    }

    void startFiring() {
        if (!firing) {
            firing = true;
        }
    }
};

class Score {
private:
    int score;

public:
    Score() : score(0) {}

    void increaseScore(int amount) {
        score += amount;
    }

    int getScore() const {
        return score;
    }

    void displayScore() const {
        // Display score on screen
        char scoreText[50];
        snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
        glColor3f(1.0, 0.0, 0.0); // Black color
        glRasterPos2i(10, cv.getHeight() - 20); // Position text
        for (char* c = scoreText; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }
};

#endif
