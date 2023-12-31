/*@file MakeSauce.cpp
 *@brief contains the MakeSauce class
 *       which is a subclass of MenuItemCommand
 *       and creates a sauce for a food item
 *       in the kitchen
 *@bug No known bugs.
*/
#include "MakeSauce.h"
#include "SauceChef.h"
using namespace std;

MakeSauce::MakeSauce(shared_ptr<Kitchen> state) : MenuItemCommand() {
    this->state = state;
    while (!dynamic_pointer_cast<SauceChef>(this->state))
        this->state = this->state->getNextChef();
}

shared_ptr<FoodItem> MakeSauce::execute() {
    return state->execute(this);
}