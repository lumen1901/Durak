# Durak

## rules

With How Many Cards Do I Play With?
Reduced poker deck with 36 cards from 6 to Ace.

What is the object of the game?
To get rid of all your cards.

How Should I Deal?
Each player is dealt 6 cards face down. The top card of the remaining deck is placed face-up. This card defines the trump suit for the game. The rest of the deck is placed above the face-up trump card. The first time it does not matter who deals. The following times the dealer will be the person who lost the previous game.

How Should I Play Durak?
Like in many other card games such as poker and rummy, the first person to play is the one who holds the lowest trump suit in his hand. The game proceeds in a clockwise direction. The player who started to play acts an attacker and the player sitting next to him in a clockwise direction acts as a defender. The attacker throws any card he wishes from his hand and the defender must beat this card.

A card can be beaten by a higher card of the same suit or any card of the trump suit, unless the card is itself from the trump suit. In the latter case it can only be beaten by a higher trump. If the defender cannot or does not want to beat the card of the attacker he must collect it and add it to his hand. If the defender beats the card the attacker can add another card of the same rank of one of the cards on the table. The defender must beat this card too. 

Apart from this, other players at the table can attack the defender if they had cards from the same rank of one of those on the table. The defender cannot be attacked by a number of cards that exceeds the number of cards in his hand. Besides, in the most common variation of Durak this number cannot exceed 6, even if the defender has more cards. 

If the defender cannot beat one or more cards he has been attacked with he must collect all the cards at the table and add them to his hand. If the defender succeeds to beat all the cards, these cards are discarded and placed in a separate heap called otboy. In the next turn, the defender will attack. 

After the turn is over, no matter whether the defender succeeds to beat all the cards or has to take them, the players who have less than 6 six in their hands compensate their hands from the remaining deck, so everyone at the table will have at least 6 cards. 

The cards are taken by the attackers of the previous turn in the clockwise direction starting with the person who has attacked first. The defender is the last person to take cards. If there are no cards left in the remaining deck the face-up trump card is taken by the person whose turn is to take cards. After this no more cards are taken and the game continues until all people one by one get rid of their hands. The person who remains with the cards is called Durak.

## functions, structures & structured data types

###game settings

######int check_players();<br />
Checks how many players are in the game

######int find_top(struct Card_properties *deck);<br />

Locates the top card of the deck and returns its position in the deck

######int find_bottom();<br />

Locates the bottom card of the deck and returns its position in the deck

######void set_trump (struct Card_properties *deck);<br />

Sets the trump card for the game

######int count_wins(struct Player player);<br />

Counts the wins of every player

######int count_looses(struct Player player);<br />

Counts the looses of every player

######int choose_card();<br />

Function for choosing a card of the hand. Returns the number of the card

######void play_card(struct Player player, struct Card_properties field[][MAX_ATTACKS]);<br />

Player (attacker or defender) chooses a card (choose_card()) and the chosen card gets transferred to the field 

######void set_turn(struct Player *players, int num_of_players);<br />

Function sets the mode-variable of the player to : ATTACK, DEFEND, PASSIVE

######int hand_empty(struct Player player);<br />

returns 0, if the hand of the player is empty


###game initialization

######void init_cards (struct Card_properties *deck); <br />
Function creates 36 cards (structure) with 2 integers (value, suit) and puts every card in a slot.

######void swap(struct Card_properties *eintrag1, struct Card_properties *eintrag2);<br />

Typical swap function with struct-elements

######void randomize ( struct Card_properties *arr, int n );<br />

Function gets an array and shuffles the entries randomly

######void cards2hand(struct Card_properties *deck, struct Player *player);<br />

Every player gets 6 cards from the deck. The taken cards of the deck get 0 as value and suit. 

######void hand_ausgabe(struct Player player);<br />

Function prints cards from the hand

######void deck_ausgabe(struct Card_properties *deck);<br />

Function prints cards from the deck

######void init_field(struct Card_properties field [][MAX_ATTACKS]);<br />

Function initializes a 2x6 field for playing cards

######void ausgabe_field(struct Card_properties field [][MAX_ATTACKS]);<br />

Function prints field

###structures

######struct Card_properties {int value, int suits};<br />

A card needs a value and suits. With enum value (6-7-8-9-10-Joker(11)-Queen(12)-King(13)-Ace(14)) and enum suits (Spades(1),Hearts(2), Diamonds(3), Clubs(4)).

######struct Player{ int wins;int looses;int mode;struct Card_properties hand[MAX_CARDS]}

Structure for creating an array with the size of the attending players.Each of the hast their own variables. There is also a nested structure for giving a hand to every player.

###structured datatypes

######struct Card_properties deck [MAX_CARDS];

Deck of the card game

######struct Card_properties field[INTERACTION][MAX_ATTACKS];

2x6 game field, 6 cards for attack-mode, 6 cards for defense mode

######struct Player *players_num;

Pointer to a struct variable. Later used as dynamic array. Size of array depends on number of players.

