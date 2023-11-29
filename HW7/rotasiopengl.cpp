#include <GL/glut.h>
#include <cmath>

float angle = 30.0f; // Rotation angle in degrees

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void rotatePoint(float& x, float& y, float angle, float pivotX, float pivotY) {
    // Convert angle from degrees to radians
    float radian = angle * (M_PI / 180.0);

    // Translate rotation center to the initial point
    x -= pivotX;
    y -= pivotY;

    // Rotate around the rotation center
    float rotatedX = x * cos(radian) - y * sin(radian);
    float rotatedY = x * sin(radian) + y * cos(radian);

    // Translate back to the initial position
    x = rotatedX + pivotX;
    y = rotatedY + pivotY;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); // Red color

    float x1 = 1.0f, y1 = 3.0f, x2 = 3.0f, y2 = 7.0f; // Updated coordinates

    // Original line before rotation
    drawLine(x1, y1, x2, y2);

    glColor3f(0.0f, 0.0f, 1.0f); // Blue color

    // Rotate the line endpoints before drawing the rotated line
    rotatePoint(x1, y1, angle, 3.0f, 3.0f);
    rotatePoint(x2, y2, angle, 3.0f, 3.0f);

    // Rotated line
    drawLine(x1, y1, x2, y2);

    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 10.0, 0.0, 10.0); // Window coordinates
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Rotasi Garis");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
