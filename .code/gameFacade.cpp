#include "gameFacade.h"
#include <iostream>
#include <string>
#include <thread>
#include <functional>
#include <cstring>

using namespace std;

GameFacade::GameFacade()
{
    id = 0;
    customerNames.push_back("Edd");
    customerNames.push_back("Emily");
    customerNames.push_back("Stef");
    customerNames.push_back("Robert");
    customerNames.push_back("Tyler");
    customerNames.push_back("Manny");
    customerNames.push_back("Eve");
    customerNames.push_back("Stacy");
    customerNames.push_back("Beth");
    customerNames.push_back("Samual");
    customerNames.push_back("Ebert");
    customerNames.push_back("Lucy");
}

std::vector<std::shared_ptr<Customer>> GameFacade::generateCustomerGroup(int size)
{
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<gameElement>> customerElements;
    std::shared_ptr<Customer> temp;
    for (size_t i = 0; i < size; i++)
    {
        temp = std::make_shared<Customer>(id, (float)generateRandom(100, 100000));
        temp->setGameEngine(mediator);
        temp->setName(customerNames.at(generateRandom(0,customerNames.size()-1)));
        customers.push_back(temp);
        customerElements.push_back(std::dynamic_pointer_cast<gameElement>(temp));
        id++;
    }
    mediator->addGameElements(customerElements);
    return customers;
}

void GameFacade::gameSetUp()
{

    // print out the intro
    const std::string CYAN_COLOR = "\033[0;36m";
    const std::string RESET_COLOR = "\033[0m";

    int textWidth = 40; // Adjust the width as needed

    std::ifstream file("intro.txt"); // Open the file for reading
    if (file.is_open()) { // Check if the file was opened successfully
        std::string line = "";
        while (std::getline(file, line)) {
            if (line == "		   	Welcome to Home Slice :)") {
                for (char c : line) {
                    std::cout << CYAN_COLOR << c << RESET_COLOR;
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                }
            }
            else {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                std::cout << CYAN_COLOR << line << RESET_COLOR;
            }
            std::cout << std::endl;
        }
        file.close(); // Close the file when done
    }
    else {
        std::cerr << "Failed to open the file." << std::endl;
    }


    //std::cout << "\033[47;30mWould you like to configure the game before starting? (yes/no)\033[0m" << std::endl;

    //string input;
    //cin >> input;
    //if (input == "no")
    //{
        numCustomerGroups = 2;
        floorsize = 4;
        tableSize = 4;
    /*}
    else
    {
        std::cout << "\033[47;30mHow many rounds of customer would you like the game to have?\033[0m" << std::endl;
        cin >> numCustomerGroups;

        std::cout << "\033[47;30mThe restaurant floor is a square matrix. How many tiles would you like one side of the square to have?\033[0m" << std::endl;
        cin >> floorsize;

        std::cout << "\033[47;30mHow many seats would you like each table to have?\033[0m" << std::endl;
        cin >> tableSize;
    }*/

    mediator = std::make_shared<Pager>();

    std::vector<std::shared_ptr<gameElement>> gmElements = createGameElements();
    mediator->addGameElements(gmElements);
}

std::vector<std::shared_ptr<gameElement>> GameFacade::createGameElements()
{
    std::vector<std::shared_ptr<gameElement>> gmElements;


    shared_ptr<Floor> floorObj = make_shared<Floor>(3, 3);

    //Floor* floor1 = new Floor(3,3);
    maitreD = std::make_shared<MaitreD>("Steve", floorObj);
    maitreD->setGameEngine(mediator);
    gmElements.push_back(maitreD);
    //gmElements.push_back();
    shared_ptr<RegularWaiter> VAL = std::make_shared<RegularWaiter>(RegularWaiter(0, { 0 }, floorObj));
    VAL->setGameEngine(mediator);
    gmElements.push_back(VAL);
    // added
    shared_ptr<RegularWaiter> newWaiter1 = RegularWaiter::createRegularWaiter(1, vector<int>{0, 1, 2, 3}, floorObj);
    shared_ptr<RegularWaiter> newWaiter2 = RegularWaiter::createRegularWaiter(2, vector<int>{4, 5, 6}, floorObj);
    newWaiter1->setGameEngine(mediator);
    newWaiter2->setGameEngine(mediator);


    for (int i = 1; i < floorsize + 1; i++)
    {
        int count = 0;
        vector <int> intstables;

        while (count > floorsize) {
            intstables.push_back(count);

        }
        gmElements.push_back(std::make_shared<RegularWaiter>(i, intstables, floorObj));
    }
    shared_ptr<KitchenInterface> t = std::make_shared<KitchenInterface>();
    t->setGameEngine(mediator);
    gmElements.push_back(t);
    return gmElements;
}

void GameFacade::runGame()
{
    gameSetUp();
    for (int i = 0; i < numCustomerGroups; i++)
    {
        singleRound();
        std::cout << "Press Enter to continue" << std::endl;
        std::cin.ignore(1000000000, '\n');
    }

    const std::string CYAN_COLOR = "\033[0;36m";
    const std::string RESET_COLOR = "\033[0m";

    int textWidth = 40; // Adjust the width as needed

    std::ifstream file("done.txt"); // Open the file for reading
    if (file.is_open()) { // Check if the file was opened successfully
        std::string line = "";
        // Read and display each line of the file with color
        while (std::getline(file, line)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << CYAN_COLOR << line << RESET_COLOR << std::endl;
        }
        file.close(); // Close the file when done
    }
    else {
        std::cerr << "Failed to open the file." << std::endl;
    }
    donut();
}

void GameFacade::singleRound()
{
    std::vector<std::shared_ptr<Customer>> customers = generateCustomerGroup(generateRandom(3, 6));

    std::cout << endl;
    std::cout << " ~ " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\033[A\033[K";

    std::cout << "   ~ " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\033[A\033[K";

    std::cout << "      ~ " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\033[A\033[K";

    std::cout << "~         ~ " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\033[A\033[K";

    std::cout << "   ~        " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\033[A\033[K";

    std::cout << "      ~     " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\033[A\033[K";

    std::cout << "         ~  " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "\033[A\033[K";

    std::cout << "\033[46;30m ~ A new group of "<< std::to_string(customers.size()) <<" customers has just entered the restuarant! ~\033[0m" << std::endl;


    /*for (int i = 0; i < customers.size(); i++)
        //std::cout << customers.at(i)->printCustomer() << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');*/

    maitreD->seatCustomers(customers);
    //std::cout << "\033[46;30m ~ The customer group has been seated! ~\033[0m" << std::endl;

    std::cout << "\033[46;30m ~ Welcome to the customers: ~\033[0m" << std::endl;
    for (int i = 0; i < customers.size(); i++)
        std::cout << customers.at(i)->printCustomer() << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');

    for (int i = 0; i < customers.size(); i++) {
        if (i == 0) {
            customers.at(i)->createOrder(false);
        }
        else {
            customers.at(i)->createOrder(true);
        }
    }

    std::cout << "\033[46;30m ~ The customers have placed their orders! ~\033[0m" << std::endl;

    waiterToKitchen();
        

    //for (int i = 0; i < customers.size(); i++)
        customers.at(0)->talkToWaiter();

    for (int i = 0; i < customers.size(); i++)
        std::cout << customers.at(i)->printCustomer() << std::endl;

    std::cout << "Press Enter to continue" << std::endl;
    std::cin.ignore(1000000000, '\n');

    //for (int i = 0; i < customers.size(); i++)
    //    customers.at(i)->requestBill();

    // to request the bill
    customers.at(0)->requestBill();

    for (int i = 0; i < customers.size(); i++)
        mediator->removeGameElement(std::dynamic_pointer_cast<gameElement>(customers.at(i)));

}

int GameFacade::generateRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

GameFacade::~GameFacade()
{
}

void GameFacade::runGame2() {
    shared_ptr<Pager> mediator1 = make_shared<Pager>();
    shared_ptr<KitchenInterface> kitchenInterface = make_shared<KitchenInterface>();
    mediator1->addGameElement(kitchenInterface);
    shared_ptr<Customer> c = make_shared<Customer>(234);
    mediator1->addGameElement(c);
    c->setGameEngine(mediator1);
    c->setOperation("getKitchenReference");
    c->changed();
}

void GameFacade::waiterToKitchen() {

    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << endl;
    std::cout << "\033[46;30m ~ The waiter will take your order to the kitchen now :) ~\033[0m" << std::endl;
    cout << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));


    std::cout << "             o  " << std::endl;
    std::cout << "           ./|\\" << std::endl;
    std::cout << "            / \\ " << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "\033[A\033[K"; // move up a line and erase
    std::cout << "\033[A\033[K";
    std::cout << "\033[A\033[K";

    std::cout << "          o  " << std::endl;
    std::cout << "        ./|\\" << std::endl;
    std::cout << "         / \\ " << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "\033[A\033[K"; // move up a line and erase
    std::cout << "\033[A\033[K";
    std::cout << "\033[A\033[K";

    std::cout << "       o  " << std::endl;
    std::cout << "     ./|\\" << std::endl;
    std::cout << "      / \\ " << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "\033[A\033[K"; // move up a line and erase
    std::cout << "\033[A\033[K";
    std::cout << "\033[A\033[K";

    std::cout << "    o  " << std::endl;
    std::cout << "  ./|\\" << std::endl;
    std::cout << "   / \\ " << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    std::cout << "\033[A\033[K"; // move up a line and erase
    std::cout << "\033[A\033[K";
    std::cout << "\033[A\033[K";

    std::cout << "  o  " << std::endl;
    std::cout << "./|\\" << std::endl;
    std::cout << " / \\ " << std::endl;

    cout << endl;
}


void GameFacade::delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void GameFacade::donut() {
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];
    printf("[2J");
    for (; ; ) {
        delay(30);//delay can be changed as per requirement to speed up the trasitions
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; 6.28 > j; j += 0.07) {
            for (i = 0; 6.28 > i; i += 0.02) {
                float sini = sin(i),
                    cosj = cos(j),
                    sinA = sin(A),
                    sinj = sin(j),
                    cosA = cos(A),
                    cosj2 = cosj + 2,
                    mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5),
                    cosi = cos(i),
                    cosB = cos(B),
                    sinB = sin(B),
                    t = sini * cosj2 * cosA - sinj * sinA;
                int x = 40 + 30 * mess * (cosi * cosj2 * cosB - t * sinB),
                    y = 12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB),
                    o = x + 80 * y,
                    N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);
                if (22 > y && y > 0 && x > 0 && 80 > x && mess > z[o]) {
                    z[o] = mess;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("[d");
        for (int k = 0; 1761 > k; k++)
            putchar(k % 80 ? b[k] : 10);
        A += 0.04;
        B += 0.02;
    }
}