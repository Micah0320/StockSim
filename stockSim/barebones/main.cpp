#include <iostream>
#include <ctime>
#include <cstdlib>

bool period(int &day)
{
    if (rand() % 100 == 42)
    {
        day = rand() % 5 + 1;
        return 1;
    }

    return 0;
}

int dayType()
{
    return rand() % 5;
}

int cost(int day_type, int start_price)
{
    switch (day_type)
    {
        //Small loss
        case 0:
            return (start_price * -.02);
            break;
            //Big loss
        case 1:
            return (start_price * -.15);
            break;
            //No change
        case 2:
            return 0;
            break;
            //Small Gain
        case 3:
            return (start_price *.02);
            break;
            //Big Gain
        case 4:
            return (start_price * .15);
            break;
    }
    return 0;
}

int main()
{
    //Gives a starting Price and an ending price
    //Initializes the day type
    //declares if there is a period of slump or growth
    int start_price = 50;
    int day_type;
    int p_change;
    bool isPeriod = 0;
    int change = 0;
    int end_price;
    int day = 0;
    
    //Initializes an option variable
    char option = 's';
    
    std::cout << "Welcome to Stumpany Inc (STC). Press 'q' to stop simulating your stocks" << std::endl;
    std::cout << '\n' << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "STC:\n----" << std::endl;
    std::cout << "Price: $" << start_price << std::endl;
    std::cout << "-------------" << std::endl;
    

    while (option != 'q' || start_price > 0)
    {
        if (!isPeriod)
        {
            day_type = dayType();
            isPeriod = period(day);
        }

        if (day > 0)
        {
            --day;
        }

        else
        {
            isPeriod = 0;
        }

        p_change = cost(day_type, start_price);
        start_price += p_change;
        
        std::cout << '\n' << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << "STC:\n----" << std::endl;
        std::cout << "Price: $" << start_price << std::endl;
        std::cout << "-------------" << std::endl;
        std::cin >> option;
    }
    return 0;
}
    
    
