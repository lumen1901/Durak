#include <stdio.h>
#include <stdlib.h>
#include "init_durak.h"



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
	 deck[35].suits = CLUBS; }

void swap(struct Card_properties *eintrag1, struct Card_properties *eintrag2) {

  struct Card_properties temp;


  temp = *eintrag1;
  *eintrag1 = *eintrag2;
  *eintrag2 = temp;

 }

void randomize ( struct Card_properties *arr, int n )
 {

    // Use a different seed value so that we don't get same
    // result each time we run this program
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
 }

void cards2hand(struct Card_properties *deck, struct Player *player) {

	int i, k;
	
	
		for (i=0,k=0;i < MAX_HAND; i++, k++)
		{
			if (deck[k].value == 0 && deck[k].suits == 0)
			{
				k++;
				i--;
				continue;
			}
			
			player->hand[i].value = deck[k].value;
			player->hand[i].suits = deck[k].suits;


			deck[k].value = EMPTY_FIELD;
			deck[k].suits = EMPTY_FIELD;
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
			printf("CARD %i\t", j+1);
	  		printf("VALUE.........:%i\t", player.hand[j].value );
	  		printf("SUITS.......:%i\n",   player.hand[j].suits);

		}
		

	

 }

void deck_ausgabe(struct Card_properties *deck) {

   printf("\nVALUE.........:%i\n",   deck->value );
   printf("SUITS.......:%i\n",   deck->suits);

 }

