/*@file HeadChef.cpp
    *@brief contains the HeadChef class
    *       which is a subclass of Kitchen
    *       and creates a pizza
    *@bug No known bugs.
*/
#include "HeadChef.h"

HeadChef::HeadChef() : Kitchen() {
    nextChef = nullptr;
}

void HeadChef::handleOrder(int waiterID, int customerID, vector<shared_ptr<FoodItem>> order) {
    pizzaPairs.push_back(make_shared<pair<int, shared_ptr<Pizza>>>(customerID, bakePizza(order)));
    //cout << "CHEF_ADDRESS::::::: " << this << endl;
    //cout << getNextChef() << endl;
    if (!nextChef->ordersComplete()) {
        nextChef->handleOrder(waiterID);
    } else {
        completeOrders.first = waiterID;
        completeOrders.second = pizzaPairs;
        setOperation("COLLECTORDER");
        changed();
    }
}

shared_ptr<Pizza> HeadChef::bakePizza(vector<shared_ptr<FoodItem>> order) {
    shared_ptr<Pizza> pizza = make_shared<Pizza>();
    for (shared_ptr<FoodItem> item : order) {
        if (dynamic_pointer_cast<Base>(item)) {
            addBase(pizza, item);
            pizza->price += item->getPrice();
        }
    } 
    for (shared_ptr<FoodItem> item : order) {
        if (dynamic_pointer_cast<Toppings>(item)) {
            addTopping(pizza, item);
            pizza->price += item->getPrice();
        }
    } 
    for (shared_ptr<FoodItem> item : order) {
        if (dynamic_pointer_cast<Sauce>(item)) {
            addSauce(pizza, item);
            pizza->price += item->getPrice();
        }
    }
    for (shared_ptr<FoodItem> item : order) {
        if (dynamic_pointer_cast<Cheese>(item)) {
            addCheese(pizza, item);
            pizza->price += item->getPrice();
        }
    }
    return pizza;
}

void HeadChef::addTopping(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->toppingsList.push_back(item);
}

void HeadChef::addSauce(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->sauceList.push_back(item);
}

void HeadChef::addBase(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->base = item;
}

void HeadChef::addCheese(shared_ptr<Pizza> pizza, shared_ptr<FoodItem> item) {
    pizza->cheeseList.push_back(item);
}

int HeadChef::getWaiterID() {
    return completeOrders.first;
}

pair<int, std::vector<std::shared_ptr<pair<int, std::shared_ptr<Pizza>>>>> HeadChef::collectOrder() {
    return completeOrders;
}
