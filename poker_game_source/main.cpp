#include "Card_Deck.h"
#include "Game_player.h"

int main() {
	Deck deck_card;
	int GamerCount;
	int play = 1;
	int highcost = 0;

	cout << endl;
	cout << "\t\t ☆	POKER GAME	☆" << endl;

	cout << "		몇 명이 게임을 진행하나요? >> ";
	while (1) {
		cin >> GamerCount;
		if (GamerCount < 1)
			cout << "1명 이상 입력해주세요. >> ";
		else
			break;
	}

	Gamer* player = new Gamer[GamerCount];
	Gamer dealer("딜러", 0, 0);

	for (int i = 0; i < GamerCount; i++) {
		string inputName;
		cout << endl << i + 1 << "번째 게임하는 사람 이름은 : ";
		cin >> inputName;
		player[i].setName(inputName);
		player[i].setPoint(0);
		player[i].setwin();
	}

	while (play) {
		system("cls");
		cout << "	↓		" << dealer.getName() << "의 손 패			↓" << endl;
		deck_card.play_game();
		dealer.setPoint(deck_card.result_point());

		for (int i = 0; i < GamerCount; i++) {
			cout << "	↓		" << player[i].getName() << " 님의 손 패			↓ " << endl;
			deck_card.play_game();
			player[i].setPoint(deck_card.result_point());
			cout << "		점수 >> " << player[i].getPoint() << endl;
			cout << endl;
		}

		for (int i = 0; i < GamerCount; i++) {
			if (player[i].getPoint() > dealer.getPoint()) {
				cout << endl;
				cout << player[i].getName() << "님이 딜러와의 승부에서 이겼습니다." << endl;
				player[i].plus_win(player[i].getPoint());
			}
			else if (player[i].getPoint() == dealer.getPoint()) {
				cout << endl;
				cout << player[i].getName() << "님은 딜러와의 승부에서 비겼습니다." << endl;
			}
			else {
				if (GamerCount == 1)
				{
					dealer.plus_win(dealer.getPoint());
				}
				cout << endl;
				cout << player[i].getName() << "님은 딜러와의 승부에서 졌습니다." << endl;


			}
		}
		cout << endl;
		cout << "승부를 계속 진행하시겠습니까? (진행 = 1, 그만두기 = 0)>> ";
		while (true) {
			cin >> play;
			if (play == 1)
				break;
			else if (play == 0)
				break;
			else
				cout << "다시 입력해주시길 바랍니다. (진행 = 1, 그만두기 = 0)>> ";
		}
	}

	for (int i = 0; i < GamerCount; i++) {
		if (highcost < player[i].getwin())
			highcost = player[i].getwin();
		else
			highcost = highcost;
	}
	if (GamerCount == 1) {
		if (dealer.getwin() > player[0].getwin()) {
			cout << "최대 승점 >> " << dealer.getwin() << " 점" << endl;
			cout << "승자 == " << dealer.getName() << " == " << endl;
		}
		else
		{
			cout << "최대 승점 >> " << highcost << " 점" << endl;
			cout << "승자 == " << player[0].getName() << " == " << endl;
		}
	}

	else
	{
		for (int i = 0; i < GamerCount; i++)
			if (highcost == player[i].getwin()) {
				cout << "최대 승점 >> " << highcost << " 점" << endl;
				cout << "승자 == " << player[i].getName() << " == " << endl;
			}
	}

	deck_card.clear();

	system("pause");
}