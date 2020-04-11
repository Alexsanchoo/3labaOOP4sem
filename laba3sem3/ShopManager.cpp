#include "ShopManager.h"

void ShopManager::addGood(Shop &shop)
{
	ElectricalDevices* device = nullptr;
	int ch = 0;
	while (ch != 5)
	{
		cout << "��������, ����� ����� �� ������ ��������: " << endl;
		cout << "1. �������" << endl;
		cout << "2. ����������" << endl;
		cout << "3. �����������" << endl;
		cout << "4. ����" << endl;
		cout << "5. �����" << endl;
		cout << "�������� �����: ";
		ch = ValidValue<>::getValue();

		system("cls");
		switch (ch)
		{
		case 1:
			device = new Monitor();
			DepartmentManager::addGood(device, shop.getComputerDep());
			cout << "������� ������� �������� � �����������!" << endl << endl;
			break;

		case 2:
			device = new Keyboard();
			DepartmentManager::addGood(device, shop.getComputerDep());
			cout << "���������� ������� ��������� � �����������!" << endl << endl;
			break;

		case 3:
			device = new Fridge();
			DepartmentManager::addGood(device, shop.getHouseholdDep());
			cout << "����������� ������� �������� � �����������!" << endl << endl;
			break;

		case 4:
			device = new Iron();
			DepartmentManager::addGood(device, shop.getHouseholdDep());
			cout << "���� ������� �������� � �����������!" << endl << endl;
			break;

		case 5:
			system("cls");
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}
}


void ShopManager::showGoods(Shop &shop)
{
	if (!DepartmentManager::showGoods(shop.getComputerDep()))
	{
		cout << "~~~" << shop.getComputerDep().getName() << "~~~" << endl;
		cout << "��� ������!" << endl;
	}
	cout << endl;
	if (!DepartmentManager::showGoods(shop.getHouseholdDep()))
	{
		cout << "~~~" << shop.getHouseholdDep().getName() << "~~~" << endl;
		cout << "��� ������!" << endl;
	}
}

void ShopManager::placeOrder(ClientData *&clientData, Order &order, Shop & shop)
{
	{
		int ch = 0;
		while (ch != 7)
		{
			cout << "���������� ������: " << endl;
			cout << "1. ���������� ������ ������ �������" << endl;
			cout << "2. ������� ����� �� ������������� ������" << endl;
			cout << "3. ������� ����� �� �������� ������" << endl;
			cout << "4. ����������� ��������� ������" << endl;
			cout << "5. ������ ����� �� ������" << endl;
			cout << "6. ��������� �����" << endl;
			cout << "7. �����" << endl;
			cout << "�������� �����: ";
			ch = ValidValue<>::getValue();

			system("cls");
			switch (ch)
			{
			case 1:
				if (clientData == nullptr)
				{
					try
					{
						cout << "������� ���: ";  string name = ValidValue<string>::getInitials();
						cout << "������� �������: "; string lastname = ValidValue<string>::getInitials();
						string adress;
						cout << "������� �����: "; getline(cin, adress);
						cout << "������� ����� �����: "; int cardNumber = ValidValue<>::getValue();
						system("cls");
						clientData = new ClientData(name, lastname, adress, cardNumber);
						order.setData(clientData);
					}
					catch (bad_alloc ex)
					{
						cout << "ERROR: " << ex.what() << "!" << endl << endl;
					}
					catch (ExpShop ex)
					{
						cout << ex.what() << endl << endl;
					}
				}
				else
				{
					cout << "������ � ������� ��� ���������!" << endl << endl;
				}
				break;

			case 2:
			{
				int ch = 0;
				ElectricalDevices *device = nullptr;
				if (DepartmentManager::showGoods(shop.getComputerDep()))
				{
					cout << endl << "�������� ����� ������: ";
					bool isValidInput = false;
					while (!isValidInput)
					{
						try
						{
							ch = ValidValue<>::getValue();
							if (ch <  1 || ch > shop.getComputerDep().getGoods().size())
							{
								throw ExpShop("error", 1);
							}
							isValidInput = true;
						}
						catch (ExpShop ex)
						{
							cout << ex.what();
						}
					}


					device = DepartmentManager::removeGood(ch - 1, shop.getComputerDep());
					OrderManager::addGood(device, order);
					system("cls");
				}
				else
				{
					cout << "� ������������ ������ ���������� �����!" << endl << endl;
				}
			}
			break;

			case 3:
			{
				int ch = 0;
				ElectricalDevices* device = nullptr;
				if (DepartmentManager::showGoods(shop.getHouseholdDep()))
				{
					bool isValidInput = false;
					while (!isValidInput)
					{
						try
						{
							ch = ValidValue<>::getValue();
							if (ch < 1 || ch > shop.getHouseholdDep().getGoods().size())
							{
								throw ExpShop("error", 1);
							}
							isValidInput = true;
						}
						catch (ExpShop ex)
						{
							cout << ex.what();
						}
					}
					device = DepartmentManager::removeGood(ch - 1, shop.getHouseholdDep());
					OrderManager::addGood(device, order);
					system("cls");
				}
				else
				{
					cout << "� ������� ������ ���������� �����!" << endl << endl;
				}
			}
			break;

			case 4:
				if (!OrderManager::showGoods(order))
				{
					cout << "~~~�����~~~" << endl;
					cout << "��� �������!" << endl;
				}
				system("pause>>void");
				system("cls");
				break;

			case 5:
			{
				int ch = 0;
				if (OrderManager::showGoods(order))
				{
					cout << "�������� �����, ������� ������ ������: ";
					bool isValidInput = false;
					while (!isValidInput)
					{
						try
						{
							ch = ValidValue<>::getValue();
							if (ch < 1 || ch > order.getGoods().size())
							{
								throw ExpShop("error", 1);
							}
							isValidInput = true;
						}
						catch (ExpShop ex)
						{
							cout << ex.what();
						}
					}

					ElectricalDevices* good = OrderManager::removeGood(ch - 1, order);
					switch (good->getType())
					{
					case HOUSEHOLD:
						DepartmentManager::addGood(good, shop.getHouseholdDep());
						break;

					case COMPUTER:
						DepartmentManager::addGood(good, shop.getComputerDep());
						break;

					default:
						break;
					}
					system("cls");
				}
				else
				{
					cout << "� ������ ��� ��� �������!" << endl << endl;
				}
			}
			break;

			case 6:
			{
				if (clientData != nullptr && OrderManager::showGoods(order))
				{
					cout << endl;
					cout << "����� �����: " << order.getTotalSum() << "$" << endl;
					system("pause>>void");
					system("cls");
					exit(0);
				}
				else
				{
					cout << "������ ����� ���� ��� ������ � ������� ��� �� ���������!" << endl << endl;
				}
			}
			break;

			case 7:
				break;

			default:
				cout << "�������� �����!" << endl << endl;
				break;
			}
		}
	}
}
