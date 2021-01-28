#include <iostream>
#include <cstdlib>
#include <ctime>
#include "company.h"

void Company::print() const
{
    std::cout << "Company Name: " << name_ << std::endl;
    std::cout << "Stock Price: " << price_ << std::endl;
    std::cout << std::endl;
}

void Company::update(int i)
{
    switch (i)
    {
        case 0: //Increase
            rep_ += .05;
            sales_ += .05;
            climate_ += .05;
            break;
        case 1: //stagnent
            rep_ += .00;
            sales_ += .0;
            climate_ += .0;
            break;
        case 2: //decrease
            rep_ -= .15;
            sales_ -= .05;
            climate_ -= .35;
            break;
    }
}

void Company::get_price()
{
    if (stability_ > .6 && stability_ <= .75)
    {
        price_ += price_ * .5;
    }
    if (stability_ >.75)
    {
        price_ *= 2;
    }

    if (stability_ >= .25 && stability_ < .4 || sales_ < .35)
    {
        price_ -= price_ * .25;
    }
    if (stability_ <.25 || sales_ < .2)
    {
        price_ -= price_ * .75;
    }
    
}

double Company::stability()
{
    return stability_;
}

void Company::update_stats()
{
    rep_ = (rand() * 1.0) / RAND_MAX;
    sales_ = (rand() * 1.0) / RAND_MAX;
    climate_ = (rand() * 1.0) / RAND_MAX;
    stability_ = (rep_ + sales_ + climate_) / 3;
    
}
int Company::price()
{
    return price_;
}

void Company::set_price()
{
    price_ = rand() % 25 + 1;
}
void Company::set_price(int i)
{
    price_ = i;
}

