#include "Card_Deck.h"  


Card::Card(int number)
{
	this->number = number;
}

int Card::cardnum() {
	int cardnum;

	cardnum = number % 13;

	return cardnum;
}

void Card::show_cardnum()
{
	int card_num;

	card_num = cardnum();


	if (card_num > 1 && card_num < 11) {
		cout << card_num << " ";
	}
	else {
		switch (card_num) {
		case 0:
			cout << "K";
			break;
		case 1:
			cout << "A";
			break;
		case 11:
			cout << "J";
			break;
		case 12:
			cout << "Q";
			break;
		}
	}
}

int Card::shapenum() {
	int suit;
	suit = number / 13;

	return suit;
}

void Card::show_shape() {
	int suit;
	suit = shapenum();


	switch (suit)
	{
	case 0:
		cout << "	  ¡Ş";
		break;
	case 1:
		cout << "	  ¢»";
		break;
	case 2:
		cout << "	  ¢½";
		break;
	case 3:
		cout << "	  ¢¿";
		break;
	default:
		break;
	}
}

Deck::Deck() {
	srand(time(NULL));
	New_Deck();
}

void Deck::shuffle() {
	for (int i = 0; i < 50; i++) {
		Card temp;
		int left;
		int right;

		left = rand() % CARDNUMBER;
		right = rand() % CARDNUMBER;
		temp = number[left];
		number[left] = number[right];
		number[right] = temp;
	}
}

void Deck::New_Deck() {
	number.clear();
	for (int i = 0; i < 52; i++) {
		number.push_back(i + 1);
	}
}

void Deck::show_hand()
{
	for (int i = 0; i < 5; i++) {
		number[i].show_shape();
		number[i].show_cardnum();
	}
	cout << endl;
}


void Deck::hand_check() {
	Card temp;
	int conut = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (number[j].cardnum() > number[j + 1].cardnum()) {
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
	if (((number[0].shapenum() == number[1].shapenum()) && (number[1].shapenum() == number[2].shapenum())
		&& (number[2].shapenum() == number[3].shapenum()) && (number[3].shapenum() == number[4].shapenum()))
		&&
		((number[4].cardnum() - number[3].cardnum()) == 1 && (number[3].cardnum() - number[2].cardnum()) == 1
			&& (number[2].cardnum() - number[1].cardnum()) == 1 && (number[1].cardnum() - number[0].cardnum()) == 1))

		handOrder = STRAIGHT_FLUSH;

	else if (((number[0].cardnum() == number[1].cardnum()) && (number[1].cardnum() == number[2].cardnum())
		&& (number[2].cardnum() == number[3].cardnum()))
		||
		((number[0].cardnum() == number[1].cardnum()) && (number[1].cardnum() == number[3].cardnum())
			&& (number[3].cardnum() == number[4].cardnum()))
		||
		((number[1].cardnum() == number[2].cardnum()) && (number[2].cardnum() == number[3].cardnum())
			&& (number[3].cardnum() == number[4].cardnum())))

		handOrder = FOUR;

	else if (((number[0].cardnum() == number[1].cardnum()) && (number[2].cardnum() == number[3].cardnum())
		&& (number[3].cardnum() == number[4].cardnum()))
		||
		((number[0].cardnum() == number[2].cardnum()) && (number[1].cardnum() == number[3].cardnum())
			&& (number[3].cardnum() == number[4].cardnum()))
		||
		((number[0].cardnum() == number[3].cardnum()) && (number[1].cardnum() == number[2].cardnum())
			&& (number[2].cardnum() == number[4].cardnum()))
		||
		((number[0].cardnum() == number[4].cardnum()) && (number[1].cardnum() == number[2].cardnum())
			&& (number[2].cardnum() == number[3].cardnum()))
		||
		((number[1].cardnum() == number[2].cardnum()) && (number[0].cardnum() == number[3].cardnum())
			&& (number[3].cardnum() == number[4].cardnum()))
		||
		((number[1].cardnum() == number[3].cardnum()) && (number[0].cardnum() == number[2].cardnum())
			&& (number[2].cardnum() == number[4].cardnum()))
		||
		((number[1].cardnum() == number[4].cardnum()) && (number[0].cardnum() == number[2].cardnum())
			&& (number[2].cardnum() == number[3].cardnum()))
		||
		((number[2].cardnum() == number[3].cardnum()) && (number[0].cardnum() == number[1].cardnum())
			&& (number[1].cardnum() == number[4].cardnum()))
		||
		((number[2].cardnum() == number[4].cardnum()) && (number[0].cardnum() == number[1].cardnum())
			&& (number[1].cardnum() == number[3].cardnum()))
		||
		((number[3].cardnum() == number[4].cardnum()) && (number[0].cardnum() == number[1].cardnum())
			&& (number[1].cardnum() == number[2].cardnum())))

		handOrder = FULL_HOUSE;

	else if ((number[0].shapenum() == number[1].shapenum()) && (number[1].shapenum() == number[2].shapenum())
		&& (number[2].shapenum() == number[3].shapenum()) && (number[3].shapenum() == number[4].shapenum()))

		handOrder = FLUSH;

	else if ((number[4].cardnum() - number[3].cardnum()) == 1 && (number[3].cardnum() - number[2].cardnum()) == 1
		&& (number[2].cardnum() - number[1].cardnum()) == 1 && (number[1].cardnum() - number[0].cardnum()) == 1)

		handOrder = STRAIGHT;

	else if (((number[0].cardnum() == number[1].cardnum()) && (number[1].cardnum() == number[2].cardnum()))
		|| ((number[0].cardnum() == number[1].cardnum()) && (number[1].cardnum() == number[3].cardnum()))
		|| ((number[0].cardnum() == number[1].cardnum()) && (number[1].cardnum() == number[4].cardnum()))
		|| ((number[0].cardnum() == number[2].cardnum()) && (number[2].cardnum() == number[3].cardnum()))
		|| ((number[0].cardnum() == number[2].cardnum()) && (number[2].cardnum() == number[4].cardnum()))
		|| ((number[0].cardnum() == number[3].cardnum()) && (number[3].cardnum() == number[4].cardnum()))
		|| ((number[1].cardnum() == number[2].cardnum()) && (number[2].cardnum() == number[3].cardnum()))
		|| ((number[1].cardnum() == number[2].cardnum()) && (number[2].cardnum() == number[4].cardnum()))
		|| ((number[1].cardnum() == number[3].cardnum()) && (number[3].cardnum() == number[4].cardnum()))
		|| ((number[2].cardnum() == number[3].cardnum()) && (number[3].cardnum() == number[4].cardnum())))

		handOrder = THREE;

	else if (((number[0].cardnum() == number[1].cardnum()) && (number[2].cardnum() == number[3].cardnum()))
		|| ((number[0].cardnum() == number[1].cardnum()) && (number[2].cardnum() == number[4].cardnum()))
		|| ((number[0].cardnum() == number[1].cardnum()) && (number[3].cardnum() == number[4].cardnum()))
		|| ((number[0].cardnum() == number[2].cardnum()) && (number[1].cardnum() == number[3].cardnum()))
		|| ((number[0].cardnum() == number[2].cardnum()) && (number[2].cardnum() == number[3].cardnum()))
		|| ((number[0].cardnum() == number[2].cardnum()) && (number[3].cardnum() == number[4].cardnum()))
		|| ((number[0].cardnum() == number[3].cardnum()) && (number[1].cardnum() == number[2].cardnum()))
		|| ((number[0].cardnum() == number[3].cardnum()) && (number[1].cardnum() == number[4].cardnum()))
		|| ((number[0].cardnum() == number[3].cardnum()) && (number[2].cardnum() == number[4].cardnum()))
		|| ((number[0].cardnum() == number[4].cardnum()) && (number[1].cardnum() == number[2].cardnum()))
		|| ((number[0].cardnum() == number[4].cardnum()) && (number[1].cardnum() == number[3].cardnum()))
		|| ((number[0].cardnum() == number[4].cardnum()) && (number[2].cardnum() == number[3].cardnum()))
		|| ((number[1].cardnum() == number[2].cardnum()) && (number[3].cardnum() == number[4].cardnum()))
		|| ((number[1].cardnum() == number[3].cardnum()) && (number[2].cardnum() == number[4].cardnum()))
		|| ((number[1].cardnum() == number[4].cardnum()) && (number[2].cardnum() == number[3].cardnum())))

		handOrder = TWO_PAIR;

	else if ((number[0].cardnum() == number[1].cardnum()) || (number[0].cardnum() == number[2].cardnum())
		|| (number[0].cardnum() == number[3].cardnum()) || (number[0].cardnum() == number[4].cardnum())
		|| (number[1].cardnum() == number[2].cardnum()) || (number[1].cardnum() == number[3].cardnum())
		|| (number[1].cardnum() == number[4].cardnum()) || (number[2].cardnum() == number[3].cardnum())
		|| (number[2].cardnum() == number[4].cardnum()) || (number[3].cardnum() == number[4].cardnum()))

		handOrder = ONE_PAIR;

	else
		handOrder = HIGH_CARD;

}

void Deck::result_card() {

	if (handOrder == ONE_PAIR)
		cout << "One Pair";
	else if (handOrder == TWO_PAIR)
		cout << "Two Pair";
	else if (handOrder == THREE)
		cout << "Three";
	else if (handOrder == STRAIGHT)
		cout << "Straight";
	else if (handOrder == FLUSH)
		cout << "Flush";
	else if (handOrder == FULL_HOUSE)
		cout << "Full House";
	else if (handOrder == FOUR)
		cout << "FourCard";
	else if (handOrder == STRAIGHT_FLUSH)
		cout << "Straigt Flush";
	else
		cout << "HighCard";
}

int Deck::result_point() {

	if (handOrder == ONE_PAIR)
		Game_Point = ONE_PAIR;
	else if (handOrder == TWO_PAIR)
		Game_Point = TWO_PAIR;
	else if (handOrder == THREE)
		Game_Point = THREE;
	else if (handOrder == STRAIGHT)
		Game_Point = STRAIGHT;
	else if (handOrder == FLUSH)
		Game_Point = FLUSH;
	else if (handOrder == FULL_HOUSE)
		Game_Point = FULL_HOUSE;
	else if (handOrder == FOUR)
		Game_Point = FOUR;
	else if (handOrder == STRAIGHT_FLUSH)
		Game_Point = STRAIGHT_FLUSH;
	else
		Game_Point = HIGH_CARD;

	return Game_Point;
}

void Deck::play_game() {
	shuffle();
	show_hand();
	hand_check();
	cout << "		== ";
	result_card();
	cout << "	== " << endl;
	cout << endl;
}

void Deck::clear() {
	number.clear();
}