#include <GL/glut.h>
#include<cmath>
#include<iostream>
using namespace std;
float speed = 0;
float deg = 0;

void drawRoof() {
    glBegin(GL_QUADS);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f); // Set the initial color to green

    glVertex2f(-4.0f, 0.0f); // Top left
    glColor3f(1.0f, 0.5f, 0.0f); // Set the gradient color to orange
    glVertex2f(-4.0f, 4.0f); // Top right

    glColor3f(0.5f, 0.0f, 0.5f); // Set the gradient color to purple
    glVertex2f(4.0f, 4.0f); // Bottom right
    glColor3f(1.0f, 1.0f, 0.0f); // Set the gradient color to yellow
    glVertex2f(4.0f, 0.0f); // Bottom left

    glEnd();
}

void drawBody() {
    glBegin(GL_QUADS);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Set the initial color to white

    glVertex2f(-6.0f, -3.0f); // Top left
    glColor3f(1.0f, 0.5f, 0.0f); // Set the gradient color to orange
    glVertex2f(-6.0f, 3.0f); // Top right

    glColor3f(0.0f, 1.0f, 0.0f); // Set the gradient color to green
    glVertex2f(6.0f, 3.0f); // Bottom right
    glColor3f(1.0f, 1.0f, 0.0f); // Set the gradient color back to yellow
    glVertex2f(6.0f, -3.0f); // Bottom left

    glEnd();
}


void drawTyre() {
    // Draw the outer circle of the tire
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f); // Set color to dark gray
    for (int i = 0; i < 360; i++) {
        float radian = i * 3.14159265358979323846 / 180;
        float x = cos(radian) * 2.0f;
        float y = sin(radian) * 2.0f;
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the inner circle of the tire
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f); // Set color to light gray
    for (int i = 0; i < 360; i++) {
        float radian = i * 3.14159265358979323846 / 180;
        float x = cos(radian) * 1.5f;
        float y = sin(radian) * 1.5f;
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the spokes to simulate motion
    glPushMatrix();
    glRotatef(deg, 0, 0, 1);
    glBegin(GL_LINES);
    glColor3f(0.1f, 0.1f, 0.1f); // Set color to dark gray for spokes
    for (int i = 0; i < 360; i += 30) {
        float start_x = cos(i * 3.14159265358979323846 / 180) * 1.5f;
        float start_y = sin(i * 3.14159265358979323846 / 180) * 1.5f;
        float end_x = cos(i * 3.14159265358979323846 / 180) * 2.0f;
        float end_y = sin(i * 3.14159265358979323846 / 180) * 2.0f;
        glVertex2f(0.0f, 0.0f); // Center of the tire
        glVertex2f(start_x, start_y); // Spoke
        glVertex2f(0.0f, 0.0f); // Center of the tire
        glVertex2f(end_x, end_y); // Spoke
    }
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (speed >= 27) {
        speed = -27;
    }
    glPushMatrix();
    glTranslatef(speed, 4, 0);
    drawRoof();
    glPushMatrix();
    glTranslatef(0, -2, 0);
    drawBody();
    glPushMatrix();
    glTranslatef(-4, -2, 0);
    drawTyre();
    glPushMatrix();
    glTranslatef(8, 0, 0);
    drawTyre();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glFlush();
}
void Timer(int value)
{
    speed += 0.25;
    deg += 10;
    display();
    glutTimerFunc(30, Timer, 1);
}
void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400, 1400);
    glutCreateWindow("Car");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(30, Timer, 1);
    glutMainLoop();
    return 0;
}