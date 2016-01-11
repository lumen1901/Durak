#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "game_init.h"
#include "cards.h"
#include "tools.h"
#include "game_settings.h"

void init_cards (struct Card_properties *deck) {

	 deck[0].value = SIX;
	 deck[0].suits = SPADES;
	 deck[1].value = SEVEN;
	 deck[1].suits = SPADES;
	 deck[2].value = EIGHT;
	 deck[2].suits = SPADES;
	 deck[3].value = NINE;
	 deck[3].suits = SPADES;
	 deck[4].value = TEN;
	 deck[4].suits = SPADES;
	 deck[5].value = JOKER;
	 deck[5].suits = SPADES;
	 deck[6].value = QUEEN;
	 deck[6].suits = SPADES;
	 deck[7].value = KING;
	 deck[7].suits = SPADES;
	 deck[8].value = ACE;
	 deck[8].suits = SPADES;

	 deck[9].value = SIX;
	 deck[9].suits = HEARTS;
	 deck[10].value = SEVEN;
	 deck[10].suits = HEARTS;
	 deck[11].value = EIGHT;
	 deck[11].suits = HEARTS;
	 deck[12].value = NINE;
	 deck[12].suits = HEARTS;
	 deck[13].value = TEN;
	 deck[13].suits = HEARTS;
	 deck[14].value = JOKER;
	 deck[14].suits = HEARTS;
	 deck[15].value = QUEEN;
	 deck[15].suits = HEARTS;
	 deck[16].value = KING;
	 deck[16].suits = HEARTS;
	 deck[17].value = ACE;
	 deck[17].suits = HEARTS;

	 deck[18].value = SIX;
	 deck[18].suits = DIAMONDS;
	 deck[19].value = SEVEN;
	 deck[19].suits = DIAMONDS;
	 deck[20].value = EIGHT;
	 deck[20].suits = DIAMONDS;
	 deck[21].value = NINE;
	 deck[21].suits = DIAMONDS;
	 deck[22].value = TEN;
	 deck[22].suits = DIAMONDS;
	 deck[23].value = JOKER;
	 deck[23].suits = DIAMONDS;
	 deck[24].value = QUEEN;
	 deck[24].suits = DIAMONDS;
	 deck[25].value = KING;
	 deck[25].suits = DIAMONDS;
	 deck[26].value = ACE;
	 deck[26].suits = DIAMONDS;

	 deck[27].value = SIX;
	 deck[27].suits = CLUBS;
	 deck[28].value = SEVEN;
	 deck[28].suits = CLUBS;
	 deck[29].value = EIGHT;
	 deck[29].suits = CLUBS;
	 deck[30].value = NINE;
	 deck[30].suits = CLUBS;
	 deck[31].value = TEN;
	 deck[31].suits = CLUBS;
	 deck[32].value = JOKER;
	 deck[32].suits = CLUBS;
	 deck[33].value = QUEEN;
	 deck[33].suits = CLUBS;
	 deck[34].value = KING;
	 deck[34].suits = CLUBS;
	 deck[35].value = ACE;
	 deck[35].suits = CLUBS;
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
