#ifndef DinnerDone_H
#define DinnerDone_H

#include "OrderProcessState.h"//BOBS ADDITION

/**
 * @class DinnerDone
 * @brief Represents the "Dinner Done" state in the order processing system.
 */
class DinnerDone : public OrderProcessState {
public:
    /**
     * @brief Constructor for creating a DinnerDone state.
     */
    DinnerDone() {
        stateName = "DinnerDone";
    }

    std::string getName();

    /**
     * @brief Execute the DinnerDone state, triggering the requestBill function in the customer.
     */
    void execute(Customer* context);

    /**
     * @brief Handle a change in the state by moving to the next state.
     * @param context A shared pointer to the customer context.
     */
    void handleChange(Customer* context);

    /**
     * @brief Get the current state as a shared pointer to a Customer.
     * @return A shared pointer to the current state.
     */
    //std::shared_ptr<Customer> getState();
};

#endif
