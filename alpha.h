#ifndef ALPHA_H
#define ALPHA_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// In constants ko header file mein rakhna behtar hai
const string COLOR = "\033[38;5;218m";
const string BOLD_COLOR = "\033[1;38;5;218m";
const string COLOR_RESET = "\033[0m";
const string LIGHT_COLOR = "\033[38;5;183m";


// Common functions ki definition
inline void setColor(string s){
    cout << LIGHT_COLOR << s << COLOR_RESET << endl;
}

inline void clearScreen() {
    cout << "\033[2J\033[H";
}

inline void pauseScreen() {
    cout << COLOR << "\n\nPress Enter to continue..." << COLOR_RESET;
    cin.ignore(); 
    cin.get(); 
}




class Alpha
{
protected:
    // All your protected members from Alpha class go here
    string usernameA[10];
    string passwordsA[10];
    string rolesA[10];
    int userCount = 0;
    int total = 0;
    int a, op;
    int mtotal;
    int pur_total = 0;
    int temptotal;
    char admin_option;
    char user_option;
    int count_stock = 0;
    string product_nameA[20];
    float add_quantityA[20];
    float add_purchaseA[20];
    float add_priceA[20];
    string add_em_name[20];
    string add_em_type[20];
    int add_em_salary[20];
    int count_employee = 0;
    string add_cust_name[20];
    string add_cust_product[20];
    int add_cust_quantity[20];
    string add_cust_date[20];
    int add_cust_total[20];
    int left_quantity[20];
    int count_customer = 0;
    string cust_name, cust_product, date;
    int cust_quantity, totalprice = 0;
    string loginusername = " ";
    string product;
    float quantity, purch, price;

public:
    // All your public functions from Alpha class go here
    void mainHeader();
    string loginMenu();
    char adminMenu();
    char UserMenu();
    void printbill();
    void updatestock();
    void addNewUser();
    void addUser(string name, string pass, string role);
    void load_user();
    void store_user();
};

#endif // ALPHA_H