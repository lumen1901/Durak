#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "init_durak.h"
#include "game_settings.h"

int check_players() {

	bool exit = false;
	int players;

	do {

		printf("How many players are in the game?\n");

		scanf("%i",&players);		

		if (players < 6 && players > 0)
		{
			exit = true;
			return players;
		}
		
		else {
			printf("Wrong input!\n");
		}

	}while(exit != true);

 }

int find_top(struct Card_properties *deck) {
 int i;

	while(deck[i].value == 0 && deck[i].suits == 0) {

		i++;
 	}

 	return i;
 }

int find_bottom() {

	return MAX_CARDS-1;
 } 

void set_trump (struct Card_properties *deck) {

	int position = find_bottom();
	int trump = deck[position].suits;

	switch(trump) {

		case 1: 
		printf("Trump will be spades\n");
		break;

		case 2:
		printf("Trump will be hearts\n");
		break;

		case 3:
		printf("Trump will be diamonds\n");
		break;

		case 4:
		printf("Trump will be clubs\n");
		break;
	}
 }

int count_wins(struct Player player) {

	player.wins ++;

	return player.wins;
 }

int count_looses(struct Player player) {

	player.looses ++;

	return player.looses;

 }



int choose_card(){

	int choice;
	bool exit = false;

	do {

		printf("Choose a card from your hand to play out\nChoice: ");
		scanf("%i", &choice);

		if (choice > 0 && choice <= MAX_CARDS)
		{
			exit = true;
			return (choice-1);
		}

		else {

			printf("Choose from hand pls.\n");
		}

	 }while(exit != true);
 }

void set_turn(struct Player *players, int num_of_players) {

	// Spieler, der den niedrigsten Trumpf auf der Hand hat

	players->mode = MODE_ATTACK; 
	(players+1)->mode = MODE_DEFEND;
		


 }

void play_card(struct Player player, struct Card_properties field[][MAX_ATTACKS]){

	int index = choose_card();

	int action = player.mode;

		for (int i = 0; i < MAX_ATTACKS; i++)
		{
			if (field[action][i].value == EMPTY_FIELD && field[action][i].suits == EMPTY_FIELD )
			{
				field[action][i].value = player.hand[index].value;
				field[action][i].suits = player.hand[index].suits;

				player.hand[i].value = EMPTY_FIELD;
				player.hand[i].suits = EMPTY_FIELD;


				break;
			}

		}
 }

int hand_empty(struct Player player){

	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (player.hand[i].value != 0 && player.hand[i].suits != 0)
		{
			return 1;
		}
		else 
			return 0;

	}


}



