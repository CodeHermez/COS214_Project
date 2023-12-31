/**
 * @file MakeBoiledCrust.h
 * @brief Contains the class declarations for the MakeBoiledCrust class, a subclass of MakeBase, responsible for creating a boiled crust for a food item in the kitchen.
 */

#ifndef __MAKE_BOILED_CRUST_H__
#define __MAKE_BOILED_CRUST_H__

#include "MakeBlueCheese.h"//BOBS ADDITION

/**
 * @class MakeBoiledCrust
 * @brief Represents the MakeBoiledCrust class, responsible for creating a boiled crust for a food item in the kitchen.
 */
class MakeBoiledCrust : public MakeBase {
public:
    /**
     * @brief Constructor for the MakeBoiledCrust class.
     * @param kitchen A shared pointer to the Kitchen where the boiled crust is created.
     */
    MakeBoiledCrust(std::shared_ptr<Kitchen> kitchen, string);
};

#endif
