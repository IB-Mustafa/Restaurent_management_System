#include "gama.h"

void Gama::Dailysalerecord() {
    total = 0;
    setColor("Main Menu📋 > Daily Sale Record 🗓");
    cout << "Name\t\tMeal\t\tQuantity\t\tDate\t\tTotal Price \n";
    for (int i = 0; i < count_customer; i++) {
        cout << add_cust_name[i] << "\t\t" << add_cust_product[i] << "\t\t"
             << add_cust_quantity[i] << "\t\t\t" << add_cust_date[i] << "\t\t" << add_cust_total[i] << endl;
        total += add_cust_total[i];
    }
    cout << "--------------------------------------------------------------\n";
    cout << "Total Daily Sale is : " << total << " PKR\n";
    cout << "--------------------------------------------------------------\n";
    pauseScreen();
}
void Gama::Monthlysalerecord() {
    total = 0;
    cout << "Main Menu > Monthly Sale Record  \n";
    cout << "Name\t\tMeal\t\tQuantity\t\tDate\t\tTotal Price \n";
    for (int i = 0; i < count_customer; i++) {
        cout << add_cust_name[i] << "\t\t" << add_cust_product[i] << "\t\t"
             << add_cust_quantity[i] << "\t\t\t" << add_cust_date[i] << "\t\t" << add_cust_total[i] << endl;
        total += add_cust_total[i];
    }
    cout << "---------------------------------------------------------\n";
    cout << "Total Monthly Sale is : " << total * 30 << " PKR\n";
    cout << "--------------------------------------------------------------\n";
    pauseScreen();
}
void Gama::leftproducts() {
    setColor("Main Menu📋 > Left Products 🧺");
    cout << "Name\t\tQuantity\tPrice\n";
    for (int i = 0; i < count_stock; i++) {
        cout << product_nameA[i] << "\t\t" << add_quantityA[i] << "\t\t" << add_priceA[i] << endl;
    }
    pauseScreen();
}
void Gama::viewprofitloss() {
    total = 0;
    pur_total = 0;
    setColor("Main Menu📋 > View Profit / Loss 📈");
    cout << " Total Purchase  " << "\t" << " Total Sale " << "\t" << " Profit This Month " << endl;
    for (int i = 0; i < count_customer; i++) {
        total += add_cust_total[i];
    }
    for (int i = 0; i < count_stock; i++) {
        pur_total += (add_purchaseA[i] * add_quantityA[i]);
    }
    mtotal = 30 * total;
    cout << "---------------------------------------------------------\n";
    cout << " " << pur_total << " PKR"
         << "\t                  " << mtotal << " PKR"
         << "\t         " << mtotal - pur_total << " PKR\n";
    cout << "--------------------------------------------------------------\n";
    pauseScreen();
}
void Gama::recordofemployee() {
    cout << COLOR << "--- Employee Records ---" << COLOR_RESET << "\n";
    cout << "Name\t\tType\t\tSalary (PKR)\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < count_employee; i++) {
        cout << add_em_name[i] << "\t\t" << add_em_type[i] << "\t\t" << add_em_salary[i] << endl;
    }
    cout << "-------------------------------------------\n";
    pauseScreen();
}
void Gama::viewproducts() {
    cout << COLOR << "--- All Available Products ---" << COLOR_RESET << "\n";
    cout << "Name\t\tQuantity\t\tPrice (PKR)\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < count_stock; i++) {
        cout << product_nameA[i] << "\t\t" << add_quantityA[i] << "\t\t" << add_priceA[i] << endl;
    }
    cout << "-------------------------------------------\n";
    pauseScreen();
}
