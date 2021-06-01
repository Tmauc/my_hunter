/*
** EPITECH PROJECT, 2017
** window
** File description:
**
*/

#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

void missing1(int missing, sfRenderWindow* window, sfVector2f squarehearth1, sfVector2f squarehearth2, sfVector2f squarehearth3)
{
        if (missing == 3) {
                my_printf("Game Over, You missing %i%s\n", missing, " times");
                sfRenderWindow_close(window);
        } else
                my_printf("You missing %i%s\n", missing, " time");
}

void score1(int score)
{
        my_printf("Your score is %i\n", score);
}

int main()
{
	srand(time(NULL));
	int a = 0;
	int vitesse = 0;
	int nbrvitesse = 18;
	int direction = 1;
	int score = 0;
	int missing = 0;
	sfRenderWindow* window;
	sfVideoMode window2;
	sfEvent event;
	sfTexture *texture;
	sfSprite *sprite;
	sfTexture *texture1;
	sfSprite *sprite1;
	sfTexture *texturehearth1;
	sfSprite *spritehearth1;
	sfTexture *texturehearth2;
	sfSprite *spritehearth2;
	sfTexture *texturehearth3;
	sfSprite *spritehearth3;
	sfIntRect square;
	sfVector2f square2;
	sfVector2f squarehearth1;
	sfVector2f squarehearth2;
	sfVector2f squarehearth3;
	sfVector2f invers;
	sfClock *clock;
	sfTime tmp;
	float seconds;
	clock = sfClock_create();

	square.left = 0;
	square.top = 0;
	square.width = 110;
	square.height = 769;

	square2.x = 0;
	square2.y = randnum();

	squarehearth1.x = 1150;
	squarehearth1.y = 660;

	squarehearth2.x = 1040;
	squarehearth2.y = 660;

	squarehearth3.x = 930;
	squarehearth3.y = 660;
	
	invers.x = -1;
	invers.y = 1;

	window2.width = 1280;
	window2.height = 769;

	texture = sfTexture_createFromFile("pictures/background.png", NULL);
	sprite = sfSprite_create();
	texture1 = sfTexture_createFromFile("pictures/spritesheet.png", NULL);
	sprite1 = sfSprite_create();
	texturehearth1 = sfTexture_createFromFile("pictures/hearth.png", NULL);
	spritehearth1 = sfSprite_create();
	texturehearth2 = sfTexture_createFromFile("pictures/hearth.png", NULL);
	spritehearth2 = sfSprite_create();
	texturehearth3 = sfTexture_createFromFile("pictures/hearth.png", NULL);
	spritehearth3 = sfSprite_create();
	
	window = sfRenderWindow_create(window2, "my_hunter", sfDefaultStyle, NULL);

	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTexture(sprite1, texture1, sfTrue);
	sfSprite_setTexture(spritehearth1, texturehearth1, sfTrue);
	sfSprite_setTexture(spritehearth2, texturehearth2, sfTrue);
	sfSprite_setTexture(spritehearth3, texturehearth3, sfTrue);
	sfSprite_setPosition(sprite1, square2);
	sfSprite_setTextureRect(sprite1, square);
	sfSprite_setPosition(spritehearth1, squarehearth1);
	sfSprite_setPosition(spritehearth2, squarehearth2);
	sfSprite_setPosition(spritehearth3, squarehearth3);
	
	while (sfRenderWindow_isOpen(window))
	{
		tmp = sfClock_getElapsedTime(clock);
		seconds = tmp.microseconds / 2500000.0;
		if (seconds > 0.10) {
			if (square.left == 220) {
				square.left = 0;
			} else {
				square.left = square.left + 110;
			}
			sfSprite_setTextureRect(sprite1, square);
			sfClock_restart(clock);
		}
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			if (event.type == sfEvtMouseButtonPressed) {
				if (direction == 1) {
					if (event.mouseButton.x >= square2.x
					    && event.mouseButton.x <= square2.x + 110 && event.mouseButton.y >= square2.y && event.mouseButton.y <= square2.y + 110) {
						square2.x = -100;
						square2.y = randnum();
						score++;
						score1(score);
						if (nbrvitesse > 3) {
							nbrvitesse = nbrvitesse - 1;
						}
					} else {
						missing++;
						if (missing == 1) {
							squarehearth3.x = -1000;
							squarehearth3.y = -1000;
							sfSprite_setPosition(spritehearth3, squarehearth3);
						}
						if (missing == 2) {
							squarehearth2.x = -1000;
							squarehearth2.y = -1000;
							sfSprite_setPosition(spritehearth2, squarehearth2);
						}
						if (missing == 3) {
							squarehearth1.x = -1000;
							squarehearth1.y = -1000;
							sfSprite_setPosition(spritehearth1, squarehearth1);
						}
						missing1(missing, window, squarehearth1, squarehearth2, squarehearth3);
					}
				}
				if (direction == 2) {
					if (event.mouseButton.x >= square2.x - 110
					    && event.mouseButton.x <= square2.x && event.mouseButton.y >= square2.y && event.mouseButton.y <= square2.y + 110) {
						square2.x = -100;
						square2.y = randnum();
						score++;
						score1(score);
						direction = 1;
						sfSprite_scale(sprite1, invers);
						if (nbrvitesse > 3) {
							nbrvitesse = nbrvitesse - 1;
						}
					} else {
						missing++;
						if (missing == 1) {
							squarehearth3.x = -100;
							squarehearth3.y = -100;
							sfSprite_setPosition(spritehearth3, squarehearth3);
						}
						if (missing == 2) {
							squarehearth2.x = 100;
							squarehearth2.y = 100;
							sfSprite_setPosition(spritehearth2, squarehearth2);
						}
						if (missing == 3) {
							squarehearth1.x = 100;
							squarehearth1.y = 100;
							sfSprite_setPosition(spritehearth1, squarehearth1);
						}
						missing1(missing, window, squarehearth1, squarehearth2, squarehearth3);
					}
				}
				vitesse = 0;
			}
		}
		if (vitesse == nbrvitesse) {
			if (direction == 1)
				square2.x = square2.x + 5;
			else
				square2.x = square2.x - 5;
			sfSprite_setPosition(sprite1, square2);
			if (square2.x == 1250) {
				sfSprite_scale(sprite1, invers);
				direction = 2;
			} else if (square2.x == -100) {
				sfSprite_scale(sprite1, invers);
				direction = 1;
			}
			vitesse = 0;
		}
		vitesse++;
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_drawSprite(window, sprite1, NULL);
		sfRenderWindow_drawSprite(window, spritehearth1, NULL);
		sfRenderWindow_drawSprite(window, spritehearth2, NULL);
		sfRenderWindow_drawSprite(window, spritehearth3, NULL);
		sfRenderWindow_display(window);
	}
	sfSprite_destroy(spritehearth3);
	sfSprite_destroy(spritehearth2);
	sfSprite_destroy(spritehearth1);
	sfSprite_destroy(sprite);
	sfSprite_destroy(sprite1);
	sfRenderWindow_destroy(window);
	return (0);
}
