#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "init_durak.h"
#include "game_settings.h"






int main(int argc, char const *argv[]) {

	/* structure initialisations */

	struct Card_properties deck [MAX_CARDS];
	struct Card_properties field[INTERACTION][MAX_ATTACKS];
	struct Player *players_num;


	bool exit = false;
	int i, temp;
	int choice;
	int num_of_players;
	srand ( time(NULL) );

	FILE *data = NULL;

	do {
		 printf("\n");
		 printf("  ****************************************************************************** \n");
		 printf("  * * * * * *                                                        * * * * * * \n");
		 printf("                                   									          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("                                      DURAK                                      \n");
 		 printf("                                      *****                                      \n");
  		 printf("                                                                                 \n");
		 printf("                                                                                 \n");
		 printf("        [1] RULES 	   [2] PLAY 	  [3] CREDITS 	   [4] QUIT                   \n");
		 printf("                                                                                 \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("           			                                                          \n");
		 printf("                                                                         	      \n");
		 printf("                                                                                 \n");
		 printf("  ****************************************************************************** \n");


		 printf("\nYour choice:\n");
		 scanf("%i", &choice);

		 switch(choice) {

		 	case 0:

			case 1:

				if (data == NULL)
				{
					data = fopen("rules.txt","r");
				}

				while((temp = fgetc(data)) != EOF) {
					printf("%c", temp);
				}

				break;

			case 2:

				num_of_players = check_players();
				players_num = malloc (num_of_players*sizeof(struct Player));
				ask_names(players_num, num_of_players);


				init_cards(deck);
				randomize(deck, MAX_CARDS);

				for (int i = 0; i < num_of_players; i++)
				{
					cards2hand(deck,&players_num[i]);
				}

				init_field(field);

				int trump = set_trump(deck);

				int firstplayer = first_player(players_num, trump,num_of_players);

				printf("%s goes first!\n",players_num[firstplayer-1].name);

				set_turn(players_num, num_of_players, firstplayer);


				for (int i = 0; i< num_of_players; i++) {

					printf("\n");
					printf("%s\n",players_num[i].name );
					hand_ausgabe(players_num[i]);
				}

				bubblesort(players_num, num_of_players);

				printf("right order:\n");
				for (int i = 0; i < num_of_players; i++) {
					printf("%s\n",players_num[i].name);
				}

				int counter = 0;


				while(deck_empty(deck) != 1) {

					interaction(&players_num[counter%num_of_players],&players_num[(counter+1)%num_of_players], field, deck, num_of_players);

					counter++;

				}

						printf("%i cards needed\n",check_cards(num_of_players, players_num[0], deck) );

						ausgabe_field(field);
						hand_ausgabe(players_num[0]);

						for (int i = 0; i < num_of_players; i++)
						{
							for (int j = 0; j < MAX_CARDS; j++)
							{

									cards2hand(deck,&players_num[i]);
							}

						}

						// check_cards(num_of_players, *players_num, deck);
						hand_ausgabe(players_num[0]);


				break;

			//case 3:	Tobias

			case 4:
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


				exit = true;

				break;

		 }


	 } while (exit != true);

	 fclose(data);






	// /* initializing the game */

	// init_cards(deck);

	// cards2hand(deck, hand, num_of_players);

	// set_trump(deck);

	// init_field(field);




	// ausgabe_field(field);		// nur zum anschauen

	// // ask_age(player);

	// // for (int i = 0; i < MAX_CARDS; i++)
	// // {
	// // 	printf("%i",i );
	// // 	deck_ausgabe(deck+i);

	// // }

	// //hand_ausgabe(hand,num_of_players);	// nur zum anschauen
	// int i;

	// do {

	// 	hand_ausgabe(hand,num_of_players);
	// 	ausgabe_field(field);

	// 	set_turn(player, num_of_players);
	// 	play_card(hand,field,player+i);

	// 	i++;

	// }while((hand+i)->player->value != EMPTY_FIELD && (hand+i)->player->suits != EMPTY_FIELD);


 // //	ausgabe_field(field);






	return 0;
 }
