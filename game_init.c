
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "game_init.h"
#include "cards.h"
#include "tools.h"
#include "game_settings.h"




 void cards2hand(struct Card_properties *deck, struct Player *player) {

	int i, k;


		for (i=zero_pos(*player),k=0;i < MAX_HAND; i++, k++)
		{
			if (deck[k].value == 0 && deck[k].suits == 0)
			{
				k++;
				i--;
				continue;
			}

			if (player->hand[i].value == 0 && player->hand[i].suits == 0 )
			{
				player->hand[i].value = deck[k].value;
				player->hand[i].suits = deck[k].suits;

				deck[k].value = EMPTY_FIELD;
				deck[k].suits = EMPTY_FIELD;
			}

		}

 }



void init_field(struct Card_properties field [][MAX_ATTACKS]) {

	for (int i = 0; i < INTERACTION; i++)
	{
		for (int j = 0; j < MAX_ATTACKS; j++)
		{

		field[i][j].value = EMPTY_FIELD;
		field[i][j].suits = EMPTY_FIELD;


		}
	}

 }

void ausgabe_field(struct Card_properties field [][MAX_ATTACKS]) {

	for (int i = 0; i < INTERACTION; i++)
	{
		printf("MODE %i\n",i+1 );
		for (int j = 0; j < MAX_ATTACKS; j++)
		{

		printf("FIELD %i\t",j+1);
		printf("VALUE.........:%i\t",   field[i][j].value );
  		printf("SUITS.......:%i\n",   field[i][j].suits);

		}
	}

 }





void hand_ausgabe(struct Player player) {


		for (int j = 0; j < MAX_HAND; j++)
		{
			printf("CARD %i\t\t", j+1);
		}

		printf("\n");

		for (int j = 0; j < MAX_HAND; j++)
		{
			printf("%i\t\t", player.hand[j].value );
		}

		printf("\n");

		for (int j = 0; j < MAX_HAND; j++)
		{
			printf("%i\t\t", player.hand[j].suits );
		}
		printf("\n");


 }

void hand_on_field(struct Player Player) {

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
		 		printf("                                  до свидания!                                  \n");
		 		printf("                                                                                \n");
		 		printf("           			                                                            \n");
		 		printf("           			                                                            \n");
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
		 		printf("\n");


}

void deck_ausgabe(struct Card_properties *deck) {

   printf("\nVALUE.........:%i\n",   deck->value );
   printf("SUITS.......:%i\n",   deck->suits);

 }

 int first_player(struct Player *player, int trump, int num_of_players) {

 	int a, a_old;

 	for (int i = 0; i < num_of_players; i++) {

 		for (int j = 0; j < MAX_CARDS; j++) {


 			if (player[i].hand[j].suits == trump && player[i].hand[j].value <= a)
 			{

 				a_old = a;



 			}

 		}


 	}
 }
