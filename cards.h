#ifndef CARDS_H



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
 int choose_card();
 void play_card(struct Player *player, struct Card_properties field[][MAX_ATTACKS]);
 int hand_empty(struct Player player);
 int zero_pos(struct Player player);
 int check_cards(int num_of_players, struct Player player, struct Card_properties *deck);


 #endif /* CARDS.H */
