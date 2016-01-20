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
		printf("Choose a card from your hand to play out\t\t[0]return\nChoice: ");
		scanf("%i", &choice);

		if (choice >= 0 && choice <= MAX_CARDS)
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


// void play_card(struct Player *player, struct Card_properties field[][MAX_ATTACKS], int index){
//
//
// 	int action = player->mode;
//
// 		for (int i = 0; i < MAX_ATTACKS; i++)
// 		{
// 			if (check_draw(player->hand[index], field) == -1) {
//
// 				i--;
//
// 				if (player->mode == 0) {
// 					player->mode = 1;
// 				}
// 				if (player->mode == 1) {
// 					player->mode = 0;
// 				}
// 			}
//
// 			if (field[action][i].value == EMPTY_FIELD && field[action][i].suits == EMPTY_FIELD && check_draw(player->hand[index], field) == 0 )
// 			{
//
//
// 				field[action][i].value = player->hand[index].value;
// 				field[action][i].suits = player->hand[index].suits;
//
//
// 				player->hand[index].value = EMPTY_FIELD;
// 				player->hand[index].suits = EMPTY_FIELD;
//
// 				break;
// 			}
//
//
//
//
// 		}
//  }

 void play_card(struct Player *player, struct Card_properties field[][MAX_ATTACKS], int index){


 	int action = player->mode;

 		for (int i = 0; i < MAX_ATTACKS; i++)
 		{

 			if (field[action][i].value == EMPTY_FIELD && field[action][i].suits == EMPTY_FIELD)
 			{
				if (check_draw(player->hand[index], field ) == 0) {

					field[action][i].value = player->hand[index].value;
	 				field[action][i].suits = player->hand[index].suits;


	 				player->hand[index].value = EMPTY_FIELD;
	 				player->hand[index].suits = EMPTY_FIELD;

				}

				else {
					printf("Wrong suit!\n");
				}


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


			/* ABLAUF

			Player mit Mode Anfgriff wird zuerst gefragt:
			1) Was möchtest du tun:

				Falls 1)
				Suche eine Karte aus deinem Deck aus,
				Spiele die Karte,oder kehre zurück zur auswahl
				komm noch mal mal zurück zum Auswahlmenü, bis finish attack



			*/

			int choice_attacker, choice_defender, index;

			bool play_round = true;
			bool finish_attack = false;
			bool finish_defense = false;


			while (play_round) {


				do {

						if (cards_on_field(field) == 2* MAX_ATTACKS ) {
							printf("Field is full\n");
							finish_attack = true;
							break;
						}

						for (int i = 0; i < MAX_CARDS; i++) {
							deck_ausgabe(deck+i);
						}


						printf("Cards in the deck: %i\n", deck_empty(deck));


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

						printf("Make your choice: ");

						scanf("%i", &choice_attacker);

						switch (choice_attacker) {


							case 1:
							ausgabe_field(field);
							hand_ausgabe(*player1);
							index = choose_card();

							if (index == -1) {
								break;
							}


							play_card(player1,field,index);
							break;

							case 2:

							if (cards_on_field(field) == 0)
							{
								printf("There are no cards on the field yet, you have to play at least one card! \n");
								break;

							}

							else
							{

								finish_attack = true;
								break;

							}


						}


				}while(finish_attack != true);

				do {

						if (cards_on_field(field) == 2* MAX_ATTACKS ) {
							printf("Field is full\n");
							finish_attack = true;
							break;
						}


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

						scanf("%i", &choice_defender);

						switch(choice_defender) {

							case 1:
							ausgabe_field(field);
							hand_ausgabe(*player2);
							index = choose_card();

							if (index == -1) {
								break;
							}

							play_card(player2, field, index);

							for (int i = 0; i < MAX_ATTACKS; i++) {

								if (field[0][i].value != 0 && field[1][i].value != 0 && check_beat(field[0][i],field[1][i]) == 1)
								{
									printf("Card %i is beaten!\n",i);
									finish_defense = true;

								}

							}

							break;

							case 2:
							takecards(player2,field);


							finish_defense = true;

							break;

						}
				}while(finish_defense != true);




				if (finish_attack == true && finish_defense == true)
				{


					for (int j = 0; j < MAX_CARDS; j++)
					{
						if (deck_empty(deck) != 0) {
							printf("Take some new cards!\n");
							cards2hand(deck,player1);
							cards2hand(deck,player2);
						}

					}
					if (player1->mode == 0)
					{
						player1->mode = 1;
					}

					if (player2->mode == 1)
					{
						player2->mode = 0;
					}

					clean_field(field);
					play_round = false;
				}

			}

}

void change_mode(struct Player *players, num_of_players) {

	for (int i = 0; i < num_of_players; i++) {

		if (players[i].mode == 0) {

		}



	}



}



int deck_empty(struct Card_properties *deck){

int counter = 0;

	for (int i = 0; i < MAX_CARDS; i++)
	{
		if (deck[i].value != 0) {
			counter ++;
		}

	}
	return counter;
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

			field[i][j].value = EMPTY_FIELD;
			field[i][j].suits = EMPTY_FIELD;

		}

	}


}

int check_draw(struct Card_properties card, struct Card_properties field[][MAX_ATTACKS]) {

struct Card_properties field_card;

	for (int i = 0; i < INTERACTION; i++) {
		for (int j = 0; j < MAX_ATTACKS; j++) {

			if (field[i][j].value == 0 && j != 0) {
				printf("CASE 1 %i %i\n",i, j );
				field_card.value = field[i][j-1].value;
				field_card.suits = field[i][j-1].suits;
				break;

			}
			if (field[i][j].value == 0 && j == 0) {
				printf("CASE 2 %i %i\n",i, j );

				field_card.value = field[i-1][j].value;
				field_card.suits = field[i-1][j].suits;
				break;
			}

		}
	}
	printf("FC first %i\n",field[0][0].value );
	printf("FC v%i\n",field_card.value);
	printf("FC s%i\n",field_card.suits);


	// case 1:

	if (cards_on_field(field) == 0) {
		return 0;
	}

	// case 2:

	if (cards_on_field(field) % 2 != 0) {

		printf("field_card.suits = %i\n",field_card.suits  );
		printf("card.suits = %i\n",card.suits  );

		if (field_card.suits == card.suits) {
			return 0;
		}
		else
			return -1;
	}

	// case 3:

	else
	{
		for (int i = 0; i < INTERACTION; i++) {
			for (int j = 0; j < MAX_ATTACKS; j++) {

				if (field[i][j].value == card.value) {
					return 0;
				}


			}
		}

		return -1;

	}
}

int check_beat(struct Card_properties card1,struct Card_properties card2) {


	if (card1.value < card2.value && card1.suits == card2.suits) {
		return 1;
	}
	else
		return 0;

}

int count_cards(struct Player player){

	int k = 0;

	for(int i = 0; i < MAX_CARDS; i++){
			if(player.hand[i].value != 0){
					k++;
			}
		}

	return(k);
}

void takecards(struct Player *player, struct Card_properties field [][MAX_ATTACKS]){

		int k = count_cards(*player);
		for (int i = 0; i < INTERACTION; i++) {
				for (int j = 0; j < MAX_ATTACKS; j++){

						if(field[i][j].value != 0){
								player->hand[k].value = field[i][j].value;
								player->hand[k].suits = field[i][j].suits;
								k++;
						}

				}
		}

}

void save_player(struct Player my_player){

		FILE* player;
		player = fopen("player.txt", "w");

		fprintf(player, "%s = ", "name ");
		fprintf(player, "%s\n",my_player.name);

		fprintf(player, "%s = ", "wins ");
		fprintf(player, "%d\n",my_player.wins);

		fprintf(player, "%s = ", "looses ");
		fprintf(player, "%d\n", my_player.looses);


}
