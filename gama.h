#ifndef GAMA_H
#define GAMA_H

#include "beta.h" // Alpha class ko include karo

class Gama : public Beta
{
public:
    // All your public functions from Gama class go here
    void Dailysalerecord();
    void Monthlysalerecord();
    void leftproducts();
    void viewprofitloss();
    void recordofemployee();
    void viewproducts();
};

#endif // GAMA_H