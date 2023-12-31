//#include "Disgruntaled.h"
#include "Customer.h"
Disgruntaled::Disgruntaled()
{
    emotion = "Disgruntaled";
}
float Disgruntaled::getTip()
{
    tip = 0;
    return tip;
}
void Disgruntaled::handleChange(Customer* context)
{
    std::shared_ptr<EmotionState> ptr;
    int num = getRandomNumber();
    if (num <= 25)
    {
        ptr = make_shared<Satisfied>();
    }
    else if (num > 25 && num <= 50)
    {
        ptr = make_shared<Disgruntaled>();
    }
    else if (num > 50 && num <= 75)
    {
        ptr = make_shared<Frustrated>();
    }
    else
    {
        ptr = make_shared<Happy>();
    }
    context->setEmotionState(ptr);
}