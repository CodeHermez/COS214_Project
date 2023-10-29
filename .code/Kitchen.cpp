#include "Kitchen.h"


Kitchen::Kitchen(shared_ptr<Kitchen> ptr)
{
	nextChef = ptr;
}
void Kitchen::handleOrder(int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>)
{
	cout << "Nothing was handled";

}

void Kitchen::handleOrder(pair<int, vector<shared_ptr<Order>>> pr)
{	
	cout << "Nothing was handled";
}

shared_ptr<FoodItem> Kitchen::execute()
{
	cout << "Nothing was executed";
	return 0;
}

void Kitchen::handleOrder(pair<int, vector<shared_ptr<Order>>>)
{
	cout << "Nothing was handled";
}

shared_ptr<FoodItem> Kitchen::createFoodItem()
{
	cout << "Nothing was created";
	return 0;
}