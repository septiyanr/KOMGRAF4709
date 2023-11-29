#include <GL/glut.h>

float scaleX = 3.0f;
float scaleY = 3.0f;

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); // Red color

    // Original line before scaling
    drawLine(1.0f, 3.0f, 3.0f, 7.0f); // Updated starting and ending points

    glColor3f(0.0f, 0.0f, 1.0f); // Blue color

    // Scaled line
    drawLine(1.0f * scaleX, 3.0f * scaleY, 3.0f * scaleX, 7.0f * scaleY); // Updated starting and ending points

    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 30.0, 0.0, 30.0); // Window coordinates
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Scaling Garis");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
