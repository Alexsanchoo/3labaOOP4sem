#pragma once
#include<iostream>
#include<iomanip>
#include "ElectricalDevices.h"
#include"Department.h"
#include "ValidValue.h"

using namespace std;

class DepartmentManager
{
public:
	static void addGood(ElectricalDevices *good, Department &obj);
	static int showGoods(Department &obj);
	static void editGood(int index, int fieldIndex, Department &obj);
	static ElectricalDevices* removeGood(int index, Department &obj);
};

