#include <iostream>
#include <ctime>
#include <cstdlib>
#include "company.h"

int period()
{
    return rand() % 5;
}
int variability()
{
    return rand() % 3;
}

int main()
{
    srand((unsigned int) time(NULL));
    Company smith("Ulfgar's Weapons", 50), tailor("The Whispering Thread", 25), potion("The Bubbling Stew", 45);
    smith.print();
    tailor.print();
    potion.print();

    char input;
    std::cout << "c = continue, q = quit, e = edit" << std::endl;
    std::cin >> input;
    while (input != 'q')
    {
        if (input == 'e')
        {
            int p;
            std::cout << "Ulfgar's Weapons Stock Price: ";
            std::cin >> p;
            smith.set_price(p);
            
            std::cout << "The Wispering Thread Stock Price: ";
            std::cin >> p;
            tailor.set_price(p);
            
            std::cout << "The Bubbling Stew Stock Price: ";
            std::cin >> p;
            potion.set_price(p);
        }
        smith.update_stats();
        tailor.update_stats();
        potion.update_stats();
        
        int days = period();
        
        for (int k = 0; k < days; ++k)
        {
            smith.update(variability());
            tailor.update(variability());
            potion.update(variability());
        }
        
        smith.get_price();
        tailor.get_price();
        potion.get_price();

        if (smith.price() == 0)
        {
            smith.set_price();
        }

         if (tailor.price() == 0)
        {
            tailor.set_price();
        }

         if (potion.price() == 0)
        {
            potion.set_price();
        }
        smith.print();
        tailor.print();
        potion.print();
        std::cin >> input;
    }
    return 0;
}
