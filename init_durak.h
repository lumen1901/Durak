
#ifndef INIT_DURAK_H
  
  #define INIT_DURAK_H

  #define MAX_CARDS 36
  #define MAX_HAND 6
  #define MAX_PLAYERS 4

  #define MAX_ATTACKS 6
  #define INTERACTION 2

  #define MODE_ATTACK 0
  #define MODE_DEFEND 1
  #define MODE_PASSIVE 2

  #define EMPTY_FIELD 0

 
 enum values{ SIX = 6, SEVEN, EIGHT, NINE, TEN, JOKER, QUEEN, KING, ACE };

 enum suits{ SPADES = 1, HEARTS, DIAMONDS, CLUBS };
 

 struct Card_properties  {

	int value;
	int suits;

 };

 struct Player {

	int wins;
	int looses;
	int mode;

	struct Card_properties hand[MAX_CARDS];
 };
 
 void init_cards (struct Card_properties *deck);
 void swap(struct Card_properties *eintrag1, struct Card_properties *eintrag2);
 void randomize ( struct Card_properties *arr, int n );
 void cards2hand(struct Card_properties *deck, struct Player *player);
 void hand_ausgabe(struct Player player);
 void deck_ausgabe(struct Card_properties *deck);
 void init_field(struct Card_properties field [][MAX_ATTACKS]);
 void ausgabe_field(struct Card_properties field [][MAX_ATTACKS]);

 #endif /* INIT_DURAK_H */

