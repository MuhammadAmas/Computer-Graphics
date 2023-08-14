#include <GL/glut.h>

void drawPentagon() {
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 0.9);    // Top
    glVertex2f(-0.9, 0.3);   // Top-left
    glVertex2f(-0.6, -0.8);  // Bottom-left
    glVertex2f(0.6, -0.8);   // Bottom-right
    glVertex2f(0.9, 0.3);    // Top-right
    glEnd();
}

void drawDiagonals() {
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.9);    // Top vertex
    glVertex2f(-0.6, -0.8);  // Bottom-left vertex

    glVertex2f(0.0, 0.9);    // Top vertex
    glVertex2f(0.6, -0.8);   // Bottom-right vertex

    glVertex2f(-0.9, 0.3);   // Top-left vertex
    glVertex2f(0.9, 0.3);    // Top-right vertex
    glEnd();
}

void drawStarLines() {
    glBegin(GL_LINES);
    glVertex2f(-0.6, -0.8);  // Bottom-left vertex
    glVertex2f(0.9, 0.3);    // Top-right vertex

    glVertex2f(0.6, -0.8);   // Bottom-right vertex
    glVertex2f(-0.9, 0.3);   // Top-left vertex
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  // Set color to white

    drawPentagon();
    drawDiagonals();
    drawStarLines();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pentagon with Star");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}