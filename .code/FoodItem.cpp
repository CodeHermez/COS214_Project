#include "FoodItem.h"

FoodItem::FoodItem(string nm)
{
	name = nm;
}

string FoodItem::getName()
{
	return name;
}

double FoodItem::getPrice()
{
	return price;
}

string FoodItem::toString()
{
	string val = "";
	val += "Name: " + name + "\tPrice: " + to_string(price) + "\n";
	return val;
}