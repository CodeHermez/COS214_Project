/**
 * @file MakeGouda.h
 * @brief Contains the class declarations for the MakeGouda class, a subclass of MakeCheese, responsible for creating a Gouda cheese topping for a food item in the kitchen.
 */

#ifndef __MAKE_GOUDA_H__
#define __MAKE_GOUDA_H__

#include "MakeDoubleDecker.h"//BOBS ADDITION

/**
 * @class MakeGouda
 * @brief Represents the MakeGouda class, responsible for creating a Gouda cheese topping for a food item in the kitchen.
 */
class MakeGouda : public MakeCheese {
public:
    /**
     * @brief Constructor for the MakeGouda class.
     * @param kitchen A shared pointer to the Kitchen where the Gouda cheese topping is created.
     */
    MakeGouda(std::shared_ptr<Kitchen> kitchen);
};

#endif
