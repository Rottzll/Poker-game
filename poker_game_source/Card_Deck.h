#ifndef __CARD_DECK_H_  
#define __CARD_DECK_H_  

#include <vector>  
#include <ctime>  
#include <string>  
#include <iostream>

using namespace std;

enum
{
	HIGH_CARD,
	ONE_PAIR,
	TWO_PAIR,
	THREE,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR,
	STRAIGHT_FLUSH
};

const int CARDNUMBER = 52;

class Card {
	int number;
public:
	Card(int number);
	int cardnum();
	int shapenum();
	void show_cardnum();
	void show_shape();
	Card() {
		number = 51;
	}
};

class Deck {
	vector<Card> number;
	int handOrder = 0;
	int Game_Point = 0;

public:

	Deck();

	void New_Deck();

	void shuffle();

	void show_hand();

	void hand_check();

	void result_card();

	int result_point();

	void play_game();

	void clear();

};

#endif /* _CARD_DECK_H_ */
