#ifndef COMPANY_H
#define COMPANY_H
#include <iostream>
#include <string>
class Company
{
public:
    Company()
    {
        std::cout << "Company Name: ";
        std::cin.getline(name_, 1023);
        std::cout << "Base Price: ";
        std::cin >> price_;
        rep_ = (rand() * 1.0) / RAND_MAX;
        sales_ = (rand() * 1.0) / RAND_MAX;
        climate_ = (rand() * 1.0) / RAND_MAX;
        stability_ = (rep_ + sales_ + climate_) / 3;
    }
    Company(const char x[], int i)
        : price_(i)
    {
        int k = 0;
        while (1)
        {
            name_[k] = x[k];
            if (name_[k] == '\0')
                break;
            ++k;
        }

        rep_ = (rand() * 1.0) / RAND_MAX;
        sales_ = (rand() * 1.0) / RAND_MAX;
        climate_ = (rand() * 1.0) / RAND_MAX;
        stability_ = (rep_ + sales_ + climate_) / 3;
    }

    void print() const;
    void update(int i = 1);
    void update_stats();
    void get_price();
    int price();
    void  set_price();
     void  set_price(int);
    double stability();
private:
    char name_[1024];
    int price_;
    double rep_;
    double sales_;
    double climate_;
    double stability_;
    
};

//std::ostream & operator>>(std::ostream &, const Company &);

#endif
