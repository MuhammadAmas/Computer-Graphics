#pragma once

#include <gl/glut.h>

void drawWalls() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);

	//wall number 1
	glColor3f(0.75f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(14, 0);
	glVertex2f(14, 16);
	glVertex2f(0, 16);
	glEnd();

	//wall number 2
	glBegin(GL_POLYGON);
	glVertex2f(0, 24);
	glVertex2f(28, 24);
	glVertex2f(28, 58);
	glVertex2f(0, 58);
	glEnd();

	//wall number 3
	glBegin(GL_POLYGON);
	glVertex2f(0, 66);
	glVertex2f(28, 66);
	glVertex2f(28, 100);
	glVertex2f(0, 100);
	glEnd();

	//wall number 4
	glBegin(GL_POLYGON);
	glVertex2f(36, 90);
	glVertex2f(62, 90);
	glVertex2f(62, 100);
	glVertex2f(36, 100);
	glEnd();

	//wall number 5
	glBegin(GL_POLYGON);
	glVertex2f(36, 50);
	glVertex2f(62, 50);
	glVertex2f(62, 82);
	glVertex2f(36, 82);
	glEnd();

	//wall number 6
	glBegin(GL_POLYGON);
	glVertex2f(36, 24);
	glVertex2f(62, 24);
	glVertex2f(62, 42);
	glVertex2f(36, 42);
	glEnd();

	//wall number 7
	glBegin(GL_POLYGON);
	glVertex2f(22, 0);
	glVertex2f(40, 0);
	glVertex2f(40, 16);
	glVertex2f(22, 16);
	glEnd();

	//wall number 8
	glBegin(GL_POLYGON);
	glVertex2f(48, 0);
	glVertex2f(100, 0);
	glVertex2f(100, 16);
	glVertex2f(48, 16);
	glEnd();

	//wall number 9
	glBegin(GL_POLYGON);
	glVertex2f(70, 24);
	glVertex2f(100, 24);
	glVertex2f(100, 50);
	glVertex2f(70, 50);
	glEnd();

	//wall number 10
	glBegin(GL_POLYGON);
	glVertex2f(70, 58);
	glVertex2f(100, 58);
	glVertex2f(100, 82);
	glVertex2f(70, 82);
	glEnd();

	//wall number 11
	glBegin(GL_POLYGON);
	glVertex2f(70, 90);
	glVertex2f(100, 90);
	glVertex2f(100, 100);
	glVertex2f(70, 100);
	glEnd();

	//closed Doors
	//1
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0, 16);
	glVertex2f(1, 16);
	glVertex2f(1, 24);
	glVertex2f(0, 24);
	glEnd();

	//2
	glBegin(GL_POLYGON);
	glVertex2f(0, 58);
	glVertex2f(1, 58);
	glVertex2f(1, 66);
	glVertex2f(0, 66);
	glEnd();

	//3
	glBegin(GL_POLYGON);
	glVertex2f(28, 99);
	glVertex2f(36, 99);
	glVertex2f(36, 100);
	glVertex2f(28, 100);
	glEnd();

	//4
	glBegin(GL_POLYGON);
	glVertex2f(62, 99);
	glVertex2f(70, 99);
	glVertex2f(70, 100);
	glVertex2f(62, 100);
	glEnd();

	//5
	glBegin(GL_POLYGON);
	glVertex2f(99, 50);
	glVertex2f(100, 50);
	glVertex2f(100, 58);
	glVertex2f(99, 58);
	glEnd();

	//6
	glBegin(GL_POLYGON);
	glVertex2f(99, 16);
	glVertex2f(100, 16);
	glVertex2f(100, 24);
	glVertex2f(99, 24);
	glEnd();

	//7
	glBegin(GL_POLYGON);
	glVertex2f(40, 0);
	glVertex2f(48, 0);
	glVertex2f(48, 1);
	glVertex2f(40, 1);
	glEnd();
}