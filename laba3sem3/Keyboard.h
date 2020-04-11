#pragma once
#include "ElectricalDevices.h"
class Keyboard :
	public ElectricalDevices
{
public:
	Keyboard(int countKeySh = 102, string nameSh = "Клавиатруа", double costSh = 78.3, TypeGood typeSh = COMPUTER) :
	ElectricalDevices(nameSh, costSh, typeSh), countKey(countKeySh) {}
	Keyboard(const Keyboard &obj) :ElectricalDevices(obj), countKey(obj.countKey) {}

	void setCountKey(int count);
	int getCountKey();

	~Keyboard() {}

private:
	int countKey;
};

