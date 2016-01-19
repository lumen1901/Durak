#include <stdio.h>


#include "display.h"





void print_welcome() {

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

}


void print_choose_players () {
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


}

void print_choose_action(char* name) {
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
	printf("                       What do you want to do now, %s?         					\n", name);
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


}

void print_defend (char* name) {
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
			printf("                          Time to defend, %s!			       				    \n", name);
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

}

void print_well_done (char* name) {
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
		printf("                           Well done, now choose again %s         				\n", name);
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


}



void print_goodbye () {
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
