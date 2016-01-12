#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <wchar.h>

#include "init_durak.h"
#include "game_settings.h"

int check_players() {

	bool exit = false;
	int players;

	do {

		printf("\n");
		printf("  ******************************************************************************\n");
		printf("  * * * * * *                                                        * * * * * *\n");
		printf("                                   									            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("                                                                                \n");
		printf("                                                                                \n");
		printf("                                                                                \n");
		printf("                                                                                \n");
		printf("                        How many players are in the game?         				\n");
		printf("                               [2] 2 players                                    \n");
		printf("                               [3] 3 players                                    \n");
		printf("                               [4] 4 players                                    \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("                                                                         	    \n");
		printf("                                                                                \n");
		printf("  ******************************************************************************\n");

		printf("Make your choice: " );
		scanf("%i",&players);
		printf("\n");


		if (players < 5 && players >= 2)
		{
			exit = true;
			return players;
		}

		else {
			printf("Wrong input!\n");
			return -1;
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

int set_trump (struct Card_properties *deck) {

	int position = find_bottom();
	int trump = deck[position].suits;

	switch(trump) {

		case 1:
		printf("♠ is trump \n");
		break;

		case 2:
		printf("♥ is trump\n");
		break;

		case 3:
		printf("♦ is trump\n");
		break;

		case 4:
		printf("♣ is trump\n");
		break;
	}
	return trump;
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
			return -1;
		}

	 }while(exit != true);
 }

void set_turn(struct Player *players, int num_of_players, int firstplayer) {

	// Spieler, der den niedrigsten Trumpf auf der Hand hat

	for (int i = 0; i < num_of_players ;i++)
	{
		players[i].mode = MODE_PASSIVE;

		if (i == (firstplayer-1)) {

			players[i].mode = MODE_ATTACK;

			if (i == num_of_players-1) {
				players[0].mode = MODE_DEFEND;
			}

		}
		if (i == firstplayer) {

			players[i].mode = MODE_DEFEND;
		}



	}

	for (int i = 0; i<num_of_players;i++) {
		printf("Modus %s %i\n",players[i].name,players[i].mode );
	}

 }


void play_card(struct Player *player, struct Card_properties field[][MAX_ATTACKS]){

	int index = choose_card();

	int action = player->mode;

		for (int i = 0; i < MAX_ATTACKS; i++)
		{
			if (field[action][i].value == EMPTY_FIELD && field[action][i].suits == EMPTY_FIELD )
			{
				field[action][i].value = player->hand[index].value;
				field[action][i].suits = player->hand[index].suits;

				player->hand[index].value = EMPTY_FIELD;
				player->hand[index].suits = EMPTY_FIELD;

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

return -1;
}

int zero_pos(struct Player player){

	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (player.hand[i].value != 0 && player.hand[i].suits != 0)
		{
			return i;
		}
		else
			printf("\n");
			return -1;
	}

return -1;
 }

int check_cards(int num_of_players, struct Player player, struct Card_properties *deck) {

	int how_much_cards = 0;

		for (int j = 0; j < MAX_HAND; j++)
		{
			if (player.hand[j].value == 0)
			{
				how_much_cards ++;
			}

		}



	return how_much_cards;

 }

int first_player(struct Player *player, int trump, int num_of_players) {


	int min;
	int first_player;
	int i,j;

	for ( i = 0; i < num_of_players; i++) {		//locate first trump

		for ( j = 0; j < MAX_CARDS; j++) {

			if (player[i].hand[j].suits == trump) {

				min = player[i].hand[j].value;
				first_player = (i+1);

				break;

			}

		}

	if (player[i].hand[j].suits == trump) {break;}

	}

	if (first_player == 0)
	{
		printf("There are no trumps in your hands!\n");
		first_player = 1;
	}



	for (int i = 0; i < num_of_players; i++) {		// locate smallest trump

		for (int j = 0; j < MAX_CARDS; j++) {

			if (player[i].hand[j].suits == trump && player[i].hand[j].value < min) {

				min = player[i].hand[j].value;
				first_player = (i+1);
			}
		}
	}

	return first_player;

}

void interaction(struct Player *player1, struct Player *player2, struct Card_properties field[][MAX_ATTACKS], struct Card_properties *deck, int num_of_players) {

	int choice, choice2;
	bool finish = false;

	printf("\n");
	printf("  ******************************************************************************\n");
	printf("  * * * * * *                                                        * * * * * *\n");
	printf("                                   									            \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                       What do you want to do now, %s?         					\n", player1->name);
	printf("                               [1] Play a card                                  \n");
	printf("                               [2] Finish the attack                            \n");
	printf("                               				                                    \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("           			                                                            \n");
	printf("                                                                         	    \n");
	printf("                                                                                \n");
	printf("  ******************************************************************************\n");



	do {

		if (cards_on_field(field) == 2* MAX_ATTACKS ) {
			printf("Field is full\n");
			finish = true;
		}


		scanf("%i", &choice);
		switch(choice) {

			case 1:
			hand_ausgabe(*player1);
			play_card(player1,field);
			ausgabe_field(field);

			printf("\n");
			printf("  ******************************************************************************\n");
			printf("  * * * * * *                                                        * * * * * *\n");
			printf("                                   									            \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                          Time to defend, %s!			       				    \n", player2->name);
			printf("                               [1] Play a card                                  \n");
			printf("                               [2] Take cards to hand                           \n");
			printf("                               				                                    \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("           			                                                            \n");
			printf("                                                                         	    \n");
			printf("                                                                                \n");
			printf("  ******************************************************************************\n");

			scanf("%i", &choice2);
			switch (choice2) {


					case 1:
					hand_ausgabe(*player2);
					play_card(player2, field);
					ausgabe_field(field);


					break;

					case 2:
					break;



			}


			break;

			case 2:


			printf("Take some new cards!\n");
			for (int i = 0; i < num_of_players; i++)
			{
				for (int j = 0; j < MAX_CARDS; j++)
				{

						cards2hand(deck,player1);
						cards2hand(deck,player2);
				}

			}

			finish = true;
			break;
		}

		printf("\n");
		printf("  ******************************************************************************\n");
		printf("  * * * * * *                                                        * * * * * *\n");
		printf("                                   									            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("                                                                                \n");
		printf("                                                                                \n");
		printf("                                                                                \n");
		printf("                                                                                \n");
		printf("                           Well done %s, now choose again         				\n", player1->name);
		printf("                               [1] Play a card                                  \n");
		printf("                               [2] Finish the attack                            \n");
		printf("                               				                                    \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("           			                                                            \n");
		printf("                                                                         	    \n");
		printf("                                                                                \n");
		printf("  ******************************************************************************\n");


		}while (finish != true);






}

int deck_empty(struct Card_properties *deck){

	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (deck[i].value != 0 && deck[i].suits != 0)
		{
			return 1;
		}
		else
			return 0;

	}
}

int cards_on_field(struct Card_properties field[][MAX_ATTACKS]) {

	int cards = 0;

	for (int i = 0; i < INTERACTION; i++) {

		for (int j = 0; j < MAX_ATTACKS; j++ ) {

			if (field[i][j].value != EMPTY_FIELD && field[i][j].suits != EMPTY_FIELD)
			{
					cards++;
			}

		}

	}

	return cards;


}

void clean_field(struct Card_properties field[][MAX_ATTACKS]) {

	for (int i = 0; i < INTERACTION; i++) {

		for (int j = 0; j < MAX_ATTACKS; j++ ) {

			field[i][j].value != EMPTY_FIELD;
			field[i][j].suits != EMPTY_FIELD;
			
		}

	}


}
