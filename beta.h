#ifndef BETA_H
#define BETA_H

#include "alpha.h" // Alpha class ko include karo

class Beta : public Alpha
{
public:
    // All your public functions from Beta class go here
    void addstock();
    void addStockIntoArray(string product, float quantity, float purch, float price);
    void load_stock();
    void store_stock();
    void addemployee();
    void addemployeeintoarray(string em_name, string em_type, int em_salary);
    void load_employee();
    void store_employee();
    void addcustomer();
    void addCustomerintoarray(string cust_name, string cust_product, int cust_quantity, int totalprice, string date);
    void load_customer();
    void store_customer();
    void ViewCustomer();
    int largest(int x);
    void print_Recd();
};

#endif // BETA_H