#include<iostream>
#include<Windows.h>
#include "ShopManager.h"

using namespace std;

void term_func();


//добавление +
//удаление +
//редактирование
//просмотр +
//поиск

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.exceptions(ios::failbit | ios::badbit);
	set_terminate(term_func);

	Shop shop("Электро-экспресс");
	ClientData *clientData = nullptr;
	Order order;
		
	int choice = 0;
	while (choice != 6)
	{
		cout << "~~~~~" << shop.getName() << "~~~~" << endl;
		cout << "1. Добавить товар в ассортимент" << endl;
		cout << "2. Просмотреть ассортимент" << endl;
		cout << "3. Удалить товар из ассортимента" << endl;
		cout << "4. Изменить цены на товары в ассортименте" << endl;
		cout << "5. Оформить заказ" << endl;
		cout << "6. Выход." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Сделайте выбор: ";
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
			ShopManager::removeGood(shop);
			system("cls");
			break;

		case 4:
			ShopManager::editGood(shop);
			system("cls");
			break;

		case 5:
			ShopManager::placeOrder(clientData, order, shop);
			system("cls");
			break;

		case 6:
			break;

		default:
			cout << "Неверный выбор!" << endl << endl;
			break;
		}
	}

	delete clientData;
	return 0;
}


void term_func()
{
	system("cls");
	cout << "Ошибка! Программа завершает свою работу!" << endl;
	system("pause>>void");
	exit(0);
}
