#include <GL/glut.h>
#include <cmath>

void drawHouse() {
    // Square shape
    glColor3f(0.7f, 0.5f, 0.3f); // Light brown color
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.2f); // Bottom left corner
    glVertex2f(0.4f, 0.2f); // Bottom right corner
    glVertex2f(0.4f, 0.4f); // Top right corner
    glVertex2f(0.1f, 0.4f); // Top left corner
    glEnd();

    // Triangle for roof
    glColor3f(0.9f, 0.1f, 0.1f); // Red color
    glBegin(GL_TRIANGLES);
    glVertex2f(0.08f, 0.4f); // Left roof point
    glVertex2f(0.25f, 0.5f); // Top roof point
    glVertex2f(0.42f, 0.4f); // Right roof point
    glEnd();

    // Draw the door (rectangle shape)
    glColor3f(0.3f, 0.2f, 0.1f); // Brown color
    glBegin(GL_QUADS);
    glVertex2f(0.225f, 0.2f); // Bottom left corner
    glVertex2f(0.275f, 0.2f); // Bottom right corner
    glVertex2f(0.275f, 0.3f); // Top right corner
    glVertex2f(0.225f, 0.3f); // Top left corner
    glEnd();

    // Draw the windows (rectangles)
    glColor3f(0.1f, 0.5f, 0.7f); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.15f, 0.3f); // Bottom left corner of window 1
    glVertex2f(0.2f, 0.3f); // Bottom right corner of window 1
    glVertex2f(0.2f, 0.35f); // Top right corner of window 1
    glVertex2f(0.15f, 0.35f); // Top left corner of window 1

    glVertex2f(0.3f, 0.3f); // Bottom left corner of window 2
    glVertex2f(0.35f, 0.3f); // Bottom right corner of window 2
    glVertex2f(0.35f, 0.35f); // Top right corner of window 2
    glVertex2f(0.3f, 0.35f); // Top left corner of window 2
    glEnd();
}

void drawFences() {
    // Draw the fences (multiple vertical lines)
    glColor3f(0.3f, 0.2f, 0.1f); // Brown color
    glLineWidth(4.5f); // Set line width
    glBegin(GL_LINES);
    for (float x = 0.1f; x <= 0.5f; x += 0.1f) {
        glVertex2f(x, 0.17f); // Fence start point
        glVertex2f(x, 0.25f); // Fence end point
    }
    glEnd();
}

void drawSun() {
    // Draw the sun (circle)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.8f, 0.8f); // Center of the sun
    for (int i = 0; i <= 360; i += 10) {
        float angle_rad = i * 3.14159f / 180.0f;
        float x = 0.8f + 0.1f * cos(angle_rad);
        float y = 0.8f + 0.1f * sin(angle_rad);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawMountains() {
    // Draw the mountains
    glColor3f(0.3f, 0.2f, 0.1f); // Brown color
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.4f); // Left mountain point
    glVertex2f(0.2f, 0.8f); // Top mountain point
    glVertex2f(0.4f, 0.4f); // Right mountain point

    glVertex2f(0.3f, 0.4f); // Left mountain point
    glVertex2f(0.5f, 0.7f); // Top mountain point
    glVertex2f(0.7f, 0.4f); // Right mountain point

    glVertex2f(0.6f, 0.4f); // Left mountain point
    glVertex2f(0.8f, 0.6f); // Top mountain point
    glVertex2f(1.0f, 0.4f); // Right mountain point
    glEnd();
}

void drawRiver() {
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f); // Bottom left corner of the river
    glVertex2f(1.0f, 0.0f); // Bottom right corner of the river
    glVertex2f(1.0f, 0.12f); // Top right corner of the river
    glVertex2f(0.0f, 0.12f); // Top left corner of the river
    glEnd();
}

void drawPlants() {
    glColor3f(0.1f, 0.6f, 0.2f); // Green color for the plants
    glBegin(GL_TRIANGLES);
    glVertex2f(0.7f, 0.12f); // Left plant point
    glVertex2f(0.72f, 0.18f); // Top plant point
    glVertex2f(0.74f, 0.12f); // Right plant point

    glVertex2f(0.78f, 0.12f); // Left plant point
    glVertex2f(0.80f, 0.18f); // Top plant point
    glVertex2f(0.82f, 0.12f); // Right plant point

    glVertex2f(0.84f, 0.12f); // Left plant point
    glVertex2f(0.86f, 0.16f); // Top plant point
    glVertex2f(0.88f, 0.12f); // Right plant point

    glVertex2f(0.92f, 0.12f); // Left plant point
    glVertex2f(0.95f, 0.18f); // Top plant point
    glVertex2f(0.97f, 0.12f); // Right plant point
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawMountains();
    drawSun();
    drawHouse();
    drawFences();
    drawRiver();
    drawPlants();
    glFlush();
}

void init() {
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f); // Sky blue background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Scenery");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
