#pragma once

#include <gl/glut.h>

float gx, gy, r = 3, gd = 1;

//bhoot axis initialization
int bhoot_1_x = 32; int bhoot_1_y = 95;
int bhoot_2_x = 66; int bhoot_2_y = 86;
int bhoot_3_x = 96; int bhoot_3_y = 54;
int bhoot_4_x = 66; int bhoot_4_y = 46;
int bhoot_5_x = 44; int bhoot_5_y = 4;

int bhoot_1_min = 95; int bhoot_1_max = 20;
int bhoot_2_min = 94; int bhoot_2_max = 20;
int bhoot_3_min = 95; int bhoot_3_max = 65;
int bhoot_4_min = 66; int bhoot_4_max = 32;
int bhoot_5_min = 4; int bhoot_5_max = 20;

bool bhoot_1_check = false;
bool bhoot_2_check = false;
bool bhoot_3_check = false;
bool bhoot_4_check = false;
bool bhoot_5_check = false;


void drawBhoot(int x, int y) {
	//head
	float color_1 = rand() % 255;
	float color_2 = rand() % 255;
	float color_3 = rand() % 255;

	glColor3f(color_1 / 255, color_2 / 255, color_3 / 255);
	for (float a = 0;a < 3.142;a += 0.01) {
		glBegin(GL_POLYGON);
		glVertex2f(x + cos(a) * r, y + sin(a) * r);
		glVertex2f(x + cos(a + 0.01) * r, y + sin(a + 0.01) * r);
		glVertex2f(x, y);
		glEnd();
	}
	//body
	glBegin(GL_POLYGON);
	glVertex2f(x + r, y);
	glVertex2f(x + r, y - r);
	glVertex2f(x + r / 2, y - r + gd);
	glVertex2f(x, y - r);
	glVertex2f(x - r / 2, y - r + gd);
	glVertex2f(x - r, y - r);
	glVertex2f(x - r, y);
	glEnd();

	//Eyes
	glColor3f(115.0f / 255, 4.0f / 255, 15.0f / 255);
	for (float a = 0;a < 2 * 3.142;a += 0.01) {
		glBegin(GL_POLYGON);
		glVertex2f((x - 1) + cos(a) * 0.5, (y + 0.5) + sin(a) * 0.5);
		glVertex2f((x - 1) + cos(a + 0.01) * 0.5, (y + 0.5) + sin(a + 0.01) * 0.5);
		glVertex2f(x - 1, y + 0.5);
		glEnd();
	}
	glColor3f(115.0f / 255, 4.0f / 255, 15.0f / 255);
	for (float a = 0;a < 2 * 3.142;a += 0.01) {
		glBegin(GL_POLYGON);
		glVertex2f((x + 1) + cos(a) * 0.5, (y + 0.5) + sin(a) * 0.5);
		glVertex2f((x + 1) + cos(a + 0.01) * 0.5, (y + 0.5) + sin(a + 0.01) * 0.5);
		glVertex2f((x + 1), (y + 0.5));
		glEnd();
	}

}

void moveBhoots() {
	//moving Bhoot 1
	if (bhoot_1_y == bhoot_1_min) {
		bhoot_1_check = true;
	}
	if (bhoot_1_y == bhoot_1_max) {
		bhoot_1_check = false;
	}
	if (bhoot_1_check == false) {
		bhoot_1_y++;
	}
	else
		bhoot_1_y--;

	//moving Bhoot 2
	if (bhoot_2_y == bhoot_2_min) {
		bhoot_2_check = true;
	}
	if (bhoot_2_y == bhoot_2_max) {
		bhoot_2_check = false;
	}
	if (bhoot_2_check == false) {
		bhoot_2_y = bhoot_2_y + 2;
	}
	else
		bhoot_2_y = bhoot_2_y - 2;

	//moving Bhoot 3
	if (bhoot_3_x == bhoot_3_min) {   //95    
		bhoot_3_check = false;
	}
	if (bhoot_3_x == bhoot_3_max) { //66
		bhoot_3_check = true;
	}
	if (bhoot_3_check == false) {
		bhoot_3_x = bhoot_3_x - 1;
	}
	else
		bhoot_3_x = bhoot_3_x + 1;

	//moving Bhoot 4
	if (bhoot_4_x == bhoot_4_min) {   //95    
		bhoot_4_check = false;
	}
	if (bhoot_4_x == bhoot_4_max) { //66
		bhoot_4_check = true;
	}
	if (bhoot_4_check == false) {
		bhoot_4_x = bhoot_4_x - 1;
	}
	else
		bhoot_4_x = bhoot_4_x + 1;

	//moving Bhoot 5
	if (bhoot_5_y == bhoot_5_min) {   //95    
		bhoot_5_check = false;
	}
	if (bhoot_5_y == bhoot_5_max) { //66
		bhoot_5_check = true;
	}
	if (bhoot_5_check == false) {
		bhoot_5_y = bhoot_5_y + 1;
	}
	else
		bhoot_5_y = bhoot_5_y - 1;

}