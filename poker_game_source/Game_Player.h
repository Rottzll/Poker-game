#ifndef __GAME_PLAYER__  
#define __GAME_PLAYER__  

#include "Card_Deck.h"

class Person {
	string name;
public:
	Person() {};
	Person(string name);

	string getName() const;
	void setName(string name);
};


class Gamer :public Person {
	int Point;
	int win;
public:
	Gamer() {}
	Gamer(int Point);
	Gamer(string name, int Point, int win);

	int getPoint() const;
	void setPoint(int point);
	void plus_Point(int point);
	void setwin();
	int getwin() const;
	void plus_win(int win);

};

#endif /* _GAME_PALYER_ */  