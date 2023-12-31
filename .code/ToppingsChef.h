#ifndef TOPPINGSCHEF_H
#define TOPPINGSCHEF_H

#include "HeadChef.h"//BOBS ADDITION
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

/**
 * @class ToppingsChef
 * @brief A class representing a chef specialized in toppings, derived from Kitchen.
 *
 * This class is responsible for preparing dishes that involve various toppings as primary ingredients or condiments.
 */
class HeadChef;

class ToppingsChef : public Kitchen
{
public:
    /**
     * @brief Constructor for the ToppingsChef class.
     */
    ToppingsChef();

    /**
     * @brief Handle an order for dishes that involve toppings.
     * @param tableNumber The table number for the order.
     * @param commands A vector of shared pointers to MenuItemCommand objects representing the order.
     * @param foodItems A vector of shared pointers to FoodItem objects to work with.
     * This function function will take in orders and the respected cheff will pick the commands that belong to him 
     * or that only he knows how to prepare and passes on the remaining orders to the other chefs in the link
     */
    void handleOrder(int, int, vector<shared_ptr<MenuItemCommand>>, vector<shared_ptr<FoodItem>>);

    /**
     * @brief Execute a MenuItemCommand related to dishes that involve toppings.
     * @param val A shared pointer to the MenuItemCommand to execute.
     * @return A shared pointer to the resulting FoodItem after executing the command.
     * This functoin is used create the concrete products of the toppings chef ie. beef, mushrooms
     */
    shared_ptr<FoodItem> execute(MenuItemCommand*);

    /**
     * @brief This function displays the visual representation of Toppings which is a cow in this case
     */
    void displayToppingsArt();

};

#endif
