
#ifndef GAME_INIT_H

  #define GAME_INIT.H

  #define MAX_CARDS 36
  #define MAX_HAND 6
  #define MAX_PLAYERS 4

  #define MAX_ATTACKS 6
  #define INTERACTION 2

  #define MODE_ATTACK 0
  #define MODE_DEFEND 1
  #define MODE_PASSIVE 2

  #define EMPTY_FIELD 0


 void cards2hand(struct Card_properties *deck, struct Player *player);
 void hand_ausgabe(struct Player player);
 void deck_ausgabe(struct Card_properties *deck);
 void init_field(struct Card_properties field [][MAX_ATTACKS]);
 void ausgabe_field(struct Card_properties field [][MAX_ATTACKS]);
 int first_player(struct Player *player, int trump, int num_of_players);
 void hand_on_field(struct Player Player);

 #endif /* INIT_DURAK_H */
