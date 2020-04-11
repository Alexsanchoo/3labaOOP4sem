#include<iostream>
#include<Windows.h>
#include "ShopManager.h"

using namespace std;

void term_func();


//����������
//��������
//��������������
//��������
//�����

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.exceptions(ios::failbit | ios::badbit);
	set_terminate(term_func);

	Shop shop("�������-��������");
	ClientData *clientData = nullptr;
	Order order;
		
	int choice = 0;
	while (choice != 4)
	{
		cout << "~~~~~" << shop.getName() << "~~~~" << endl;
		cout << "1. �������� ����� � �����������" << endl;
		cout << "2. ����������� �����������" << endl;
		cout << "3. �������� �����" << endl;
		cout << "4. �����." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "�������� �����: ";
		choice = ValidValue<>::getValue();

		system("cls");
		switch (choice)
		{
		case 1:
			ShopManager::addGood(shop);
			system("cls");
			break;

		case 2:
			ShopManager::showGoods(shop);
			system("pause>>void");
			system("cls");
			break;

		case 3:
			ShopManager::placeOrder(clientData, order, shop);
			system("cls");
			break;

		case 4:
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}

	delete clientData;
	return 0;
}


void term_func()
{
	system("cls");
	cout << "������! ��������� ��������� ���� ������!" << endl;
	system("pause>>void");
	exit(0);
}
