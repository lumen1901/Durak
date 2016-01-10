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


				init_cards(deck);
				randomize(deck, MAX_CARDS);


				// for (int i = 0; i < MAX_CARDS; i++)
				// {
				// 	deck_ausgabe(deck+i);
				// }

				for (int i = 0; i < num_of_players; i++)
				{
					cards2hand(deck,&players_num[i]);
				}

				int trump;

				printf("TRUMPCHECK%i\n",trumpcheck(players_num[0],set_trump(deck)) );
				
				init_field(field);

				set_turn(players_num, num_of_players);

					hand_ausgabe(players_num[0]);

					play_card(&players_num[0],field);

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

			

				// do {

				// 	set_turn(players_num, num_of_players);

				// 	hand_ausgabe(players_num[0]);
				// 	hand_ausgabe(players_num[1]);


				// 	play_card(&players_num[i],field);

				// 	hand_ausgabe(players_num[0]);

				// 	// play_card(players_num[i+1],field);

				// 	// ausgabe_field(field);



				// 	i++;

				// 	for (int i = 0; i < num_of_players; i++)
				// 	{
				// 		for (int j = 0; j < MAX_CARDS; j++)
				// 		{
							
				// 			if (players_num[i].hand[j].value == 0 && players_num[i].hand[j].suits == 0 )
				// 			{
				// 				cards2hand(deck,&players_num[i]);
				// 				hand_ausgabe(players_num[0]);


				// 			}

				// 		}
						
				// 	}


				// 	if (i == num_of_players)
				// 	{
				// 		i = 0;
				// 	}

				// }while(hand_empty(players_num[0])!=0);		// muss noch geschrieben werden!!

				
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


