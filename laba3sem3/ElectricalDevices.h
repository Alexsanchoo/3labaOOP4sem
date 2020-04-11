#pragma once
#include<string>

using namespace std;

enum TypeGood {
	NONE,
	HOUSEHOLD,
	COMPUTER
};

class ElectricalDevices
{
public:
	ElectricalDevices(string nameSh = "", double costSh = 0.0, TypeGood typeSh = NONE) : 
		name(nameSh), cost(costSh), type(typeSh) {}
	ElectricalDevices(const ElectricalDevices &obj) : name(obj.name), cost(obj.cost), type(obj.type) {}

	void setName(string name);
	void setCost(double cost);
	void setType(TypeGood type);
	string getName();
	double getCost();
	TypeGood getType();

	virtual ~ElectricalDevices() {}

protected:
	string name;
	double cost;
	TypeGood type;
};

