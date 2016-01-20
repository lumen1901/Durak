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
	bool return2menu = false;
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

				for (int i = 0; i < num_of_players; i++)
				{
					save_player(players_num[i]);
				}

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

				while (return2menu = true) {

					interaction(&players_num[counter%num_of_players],&players_num[(counter+1)%num_of_players], field, deck, num_of_players);
					players_num[(counter+1)%num_of_players].mode = 0;
					players_num[(counter)%num_of_players].mode = 1;

					counter++;

					for (int i = 0; i < num_of_players; i++) {

						if (deck_empty(deck) == 0 && count_cards(players_num[i]) == 0) {
							printf("%s has won the game!!\n",players_num[i].name);
							return2menu = true;
						}
					}



				}



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



	return 0;
 }
