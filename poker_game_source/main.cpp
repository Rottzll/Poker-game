#include "Card_Deck.h"
#include "Game_player.h"

int main() {
	Deck deck_card;
	int GamerCount;
	int play = 1;
	int highcost = 0;

	cout << endl;
	cout << "\t\t ��	POKER GAME	��" << endl;

	cout << "		�� ���� ������ �����ϳ���? >> ";
	while (1) {
		cin >> GamerCount;
		if (GamerCount < 1)
			cout << "1�� �̻� �Է����ּ���. >> ";
		else
			break;
	}

	Gamer* player = new Gamer[GamerCount];
	Gamer dealer("����", 0, 0);

	for (int i = 0; i < GamerCount; i++) {
		string inputName;
		cout << endl << i + 1 << "��° �����ϴ� ��� �̸��� : ";
		cin >> inputName;
		player[i].setName(inputName);
		player[i].setPoint(0);
		player[i].setwin();
	}

	while (play) {
		system("cls");
		cout << "	��		" << dealer.getName() << "�� �� ��			��" << endl;
		deck_card.play_game();
		dealer.setPoint(deck_card.result_point());

		for (int i = 0; i < GamerCount; i++) {
			cout << "	��		" << player[i].getName() << " ���� �� ��			�� " << endl;
			deck_card.play_game();
			player[i].setPoint(deck_card.result_point());
			cout << "		���� >> " << player[i].getPoint() << endl;
			cout << endl;
		}

		for (int i = 0; i < GamerCount; i++) {
			if (player[i].getPoint() > dealer.getPoint()) {
				cout << endl;
				cout << player[i].getName() << "���� �������� �ºο��� �̰���ϴ�." << endl;
				player[i].plus_win(player[i].getPoint());
			}
			else if (player[i].getPoint() == dealer.getPoint()) {
				cout << endl;
				cout << player[i].getName() << "���� �������� �ºο��� �����ϴ�." << endl;
			}
			else {
				if (GamerCount == 1)
				{
					dealer.plus_win(dealer.getPoint());
				}
				cout << endl;
				cout << player[i].getName() << "���� �������� �ºο��� �����ϴ�." << endl;


			}
		}
		cout << endl;
		cout << "�ºθ� ��� �����Ͻðڽ��ϱ�? (���� = 1, �׸��α� = 0)>> ";
		while (true) {
			cin >> play;
			if (play == 1)
				break;
			else if (play == 0)
				break;
			else
				cout << "�ٽ� �Է����ֽñ� �ٶ��ϴ�. (���� = 1, �׸��α� = 0)>> ";
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
			cout << "�ִ� ���� >> " << dealer.getwin() << " ��" << endl;
			cout << "���� == " << dealer.getName() << " == " << endl;
		}
		else
		{
			cout << "�ִ� ���� >> " << highcost << " ��" << endl;
			cout << "���� == " << player[0].getName() << " == " << endl;
		}
	}

	else
	{
		for (int i = 0; i < GamerCount; i++)
			if (highcost == player[i].getwin()) {
				cout << "�ִ� ���� >> " << highcost << " ��" << endl;
				cout << "���� == " << player[i].getName() << " == " << endl;
			}
	}

	deck_card.clear();

	system("pause");
}