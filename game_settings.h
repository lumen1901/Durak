#ifndef GAME_SETTINGS_H

  #define GAME_SETTINGS_H

  int check_players();
  int find_top(struct Card_properties *deck);
  int find_bottom();
  int set_trump (struct Card_properties *deck);
  int count_wins(struct Player player);
  int count_looses(struct Player player);
  int choose_card();
  void play_card(struct Player *player, struct Card_properties field[][MAX_ATTACKS], int index);
  void set_turn(struct Player *players, int num_of_players, int firstplayer);
  int hand_empty(struct Player player);
  int zero_pos(struct Player player);
  int check_cards(int num_of_players, struct Player player, struct Card_properties *deck);
  void num2sym(int number);
  int trumpcheck(struct Player player, int trump);
  int first_player(struct Player *player, int trump, int num_of_players);
  void interaction(struct Player *player1, struct Player *player2, struct Card_properties field[][MAX_ATTACKS], struct Card_properties *deck, int num_of_players);
  int deck_empty(struct Card_properties *deck);
  int cards_on_field(struct Card_properties field[][MAX_ATTACKS]);
  void clean_field(struct Card_properties field[][MAX_ATTACKS]);
  int check_draw(struct Card_properties card, struct Card_properties field[][MAX_ATTACKS]);
  int check_beat(struct Card_properties card1,struct Card_properties card2);
  int count_cards(struct Player player);
  void takecards(struct Player *player, struct Card_properties field [][MAX_ATTACKS]);
  void save_player(struct Player player);
 #endif /* GAME_SETTINGS_H */
