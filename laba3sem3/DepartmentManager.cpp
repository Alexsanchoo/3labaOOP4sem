#include "DepartmentManager.h"

void DepartmentManager::addGood(ElectricalDevices * good, Department & obj)
{
	obj.getGoods().push_back(good);
}

int DepartmentManager::showGoods(Department & obj)
{
	if (!obj.getGoods().size())
	{
		return 0;
	}

	cout << "~~~" << obj.getName() << "~~~" << endl;
	for (size_t i = 0; i < obj.getGoods().size(); i++)
	{
		cout << fixed << setprecision(2) << left << 
			i + 1 << ". " << setw(15) << obj.getGoods()[i]->getName() << " | " << setw(15) << obj.getGoods()[i]->getManufacturer()
			<< " | " << obj.getGoods()[i]->getCost() << "$" << endl;
	}
	return 1;
}

void DepartmentManager::editGood(int index, int fieldIndex, Department & obj)
{
	cout << "Название товара: " << obj.getGoods()[index]->getName() << endl;
	switch (fieldIndex) {
	case 1:
	{
		cout << "Производитель: " << obj.getGoods()[index]->getManufacturer() << endl << endl;
		cout << "Введите нового производителя: ";
		obj.getGoods()[index]->setManufacturer(ValidValue<string>::getString());
	}
		break;

	case 2:
	{
		cout << "Цена: " << obj.getGoods()[index]->getCost() << "$" << endl << endl;
		cout << "Введите новую цену: ";
		obj.getGoods()[index]->setCost(ValidValue<double>::getValue());
	}
		break;

	default:
		return;
	}
}

ElectricalDevices * DepartmentManager::removeGood(int index, Department & obj)
{
	ElectricalDevices* temp = obj.getGoods()[index];
	obj.getGoods().erase(obj.getGoods().begin() + index);
	return temp;
}
