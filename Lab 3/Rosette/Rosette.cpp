#include <GL/glut.h>
#include <cmath> 
#include <iostream>
#include <vector>

const int numVertices = 12; // Change this value to draw a polygon with a different number of vertices
const GLfloat radius = 0.7;
const GLfloat centerX = 0.0;
const GLfloat centerY = 0.0;
const GLfloat pi = 3.14159265358979323846;

void drawPolygonWithLines() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numVertices; ++i) {
        GLfloat angle = 2.0 * pi * static_cast<GLfloat>(i) / numVertices;
        GLfloat x = centerX + radius * cos(angle);
        GLfloat y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);
    for (int i = 0; i < numVertices; ++i) {
        GLfloat angle1 = 2.0 * pi * static_cast<GLfloat>(i) / numVertices;
        GLfloat x1 = centerX + radius * cos(angle1);
        GLfloat y1 = centerY + radius * sin(angle1);

        for (int j = i + 1; j < numVertices; ++j) {
            GLfloat angle2 = 2.0 * pi * static_cast<GLfloat>(j) / numVertices;
            GLfloat x2 = centerX + radius * cos(angle2);
            GLfloat y2 = centerY + radius * sin(angle2);

            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);  // Set color to white

    drawPolygonWithLines();

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
    glutCreateWindow("Polygon with All Lines");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}