#ifndef GAME_SETTINGS_H
  
  #define GAME_SETTINGS_H
  #define MIN(a,b) (((a)<(b))?(a):(b))

  int check_players();
  int find_top(struct Card_properties *deck);
  int find_bottom();
  int set_trump (struct Card_properties *deck);
  int count_wins(struct Player player);
  int count_looses(struct Player player);
  int choose_card();
  void play_card(struct Player *player, struct Card_properties field[][MAX_ATTACKS]);
  void set_turn(struct Player *players, int num_of_players);
  int hand_empty(struct Player player);
  int zero_pos(struct Player player);
  int check_cards(int num_of_players, struct Player player, struct Card_properties *deck);
  void num2sym(int number);
  int trumpcheck(struct Player player, int trump);

  
 #endif /* GAME_SETTINGS_H */