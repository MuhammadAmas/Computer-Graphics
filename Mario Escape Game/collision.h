#pragma once

#include <gl/glut.h>
#include "Bhoot.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int mario_x = 16; int mario_y = 1;
bool game_stop = false;
bool game_over = false;

void checkBhootCollision() {
	std::cout << "bhoot x y" << std::endl;
	std::cout << bhoot_5_x << std::endl;
	std::cout << bhoot_5_y << std::endl;
	if ((mario_x + 8 >= bhoot_1_x || mario_y + 8 == bhoot_1_y || mario_y == bhoot_1_y + 3) && mario_x + 2 <= bhoot_1_x) {

		if (mario_x + 8 >= bhoot_1_x && ((bhoot_1_y <= mario_y + 5 && abs(bhoot_1_y - mario_y) <= 4) || (bhoot_1_y >= mario_y - 5 && abs(bhoot_1_y - mario_y) <= 4))) {
			game_over = true;
			game_stop = true;
		}
		else if ((mario_y + 8 == bhoot_1_y || mario_y - 3 == bhoot_1_y) && mario_x + 2 == bhoot_1_x) {

			game_over = true;
			game_stop = true;
		}
	}

	//checking bhoot 2

	if ((mario_x + 8 >= bhoot_2_x || mario_y + 8 == bhoot_2_y || mario_y == bhoot_2_y + 3) && mario_x + 2 <= bhoot_2_x) {

		if (mario_x + 8 >= bhoot_2_x && ((bhoot_2_y <= mario_y + 5 && abs(bhoot_2_y - mario_y) <= 4) || (bhoot_2_y >= mario_y - 5 && abs(bhoot_2_y - mario_y) <= 4))) {
			std::cout << "collision detected **********************2-1" << std::endl;
			game_over = true;
			game_stop = true;
		}
		else if ((mario_y + 8 == bhoot_2_y || mario_y - 3 == bhoot_2_y) && mario_x + 2 == bhoot_2_x) {
			std::cout << "collision detected **********************2-2" << std::endl;
			game_over = true;
			game_stop = true;
		}
		//checking bhoot 3

		if ((mario_x + 8 >= bhoot_3_x || mario_y + 8 == bhoot_3_y || mario_y == bhoot_3_y + 3) && mario_x + 2 <= bhoot_3_x) {

			if (mario_x + 8 >= bhoot_3_x && ((bhoot_3_y <= mario_y + 5 && abs(bhoot_3_y - mario_y) <= 4) || (bhoot_3_y >= mario_y - 5 && abs(bhoot_3_y - mario_y) <= 4))) {
				std::cout << "collision detected **********************3-1" << std::endl;
				game_over = true;
				game_stop = true;
			}
			else if ((mario_y + 8 == bhoot_3_y || mario_y - 3 == bhoot_3_y) && mario_x + 2 == bhoot_3_x) {
				std::cout << "collision detected **********************3-2" << std::endl;
				game_over = true;
				game_stop = true;
			}
		}
	}
	//checking bhoot 4

	if ((mario_x + 8 >= bhoot_4_x || mario_y + 8 == bhoot_4_y || mario_y == bhoot_4_y + 3) && mario_x + 2 <= bhoot_4_x) {

		if (mario_x + 8 >= bhoot_4_x && ((bhoot_4_y <= mario_y + 5 && abs(bhoot_4_y - mario_y) <= 4) || (bhoot_4_y >= mario_y - 5 && abs(bhoot_4_y - mario_y) <= 4))) {
			std::cout << "collision detected **********************4-1" << std::endl;
			game_over = true;
			game_stop = true;
		}
		else if ((mario_y + 8 == bhoot_4_y || mario_y - 3 == bhoot_4_y) && mario_x + 2 == bhoot_4_x) {
			std::cout << "collision detected **********************4-2" << std::endl;
			game_over = true;
			game_stop = true;
		}
	}
	//checking bhoot 5

	if ((mario_x + 8 >= bhoot_5_x || mario_y + 8 == bhoot_5_y || mario_y == bhoot_5_y + 3) && mario_x + 2 <= bhoot_5_x) {

		if (mario_x + 8 >= bhoot_5_x && (((bhoot_5_y <= mario_y + 5 && abs(bhoot_5_y - mario_y) <= 3)) || (bhoot_5_y >= mario_y - 5 && abs(bhoot_5_y - mario_y) <= 3))) {
			std::cout << "collision detected **********************5-1" << std::endl;
			game_over = true;
			game_stop = true;
		}
		else if ((mario_y + 8 == bhoot_5_y || mario_y - 3 == bhoot_5_y) && mario_x + 2 == bhoot_5_x) {
			std::cout << "collision detected **********************5-2" << std::endl;
			game_over = true;
			game_stop = true;
		}
	}
}