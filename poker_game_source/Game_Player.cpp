//person.cpp  
#include "game_Player.h"  

//======================================================  
Person::Person(string name) {
	this->name = name;
}

string Person::getName() const {
	return name;
}

void Person::setName(string name) {
	this->name = name;
}

//=====================================================  

Gamer::Gamer(int Point) {
	this->Point = Point;
}

Gamer::Gamer(string name, int Point, int win) :Person(name) {
	this->Point = Point;
	this->win = win;
}

int Gamer::getPoint() const {
	return Point;
}

void Gamer::setPoint(int point) {
	this->Point = point;

}

void Gamer::plus_Point(int point) {
	this->Point += point;
}

void Gamer::setwin() {
	this->win = 0;
}

void Gamer::plus_win(int win) {
	this->win += win;
}

int Gamer::getwin() const {
	return win;
}