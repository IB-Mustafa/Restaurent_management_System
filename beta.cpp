#include "beta.h"


// --- Beta Class Functions ---
void Beta::addstock() {
    cout << COLOR << "--- Add New Stock ---" << COLOR_RESET << "\n";
    cout << "Enter Meal Name: ";
    cin >> product;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Purchase Price: ";
    cin >> purch;
    cout << "Enter Sale Price: ";
    cin >> price;
    addStockIntoArray(product, quantity, purch, price);
}
void Beta::addStockIntoArray(string product, float quantity, float purch, float price) {
    if (count_stock < 20) {
        product_nameA[count_stock] = product;
        add_quantityA[count_stock] = quantity;
        add_purchaseA[count_stock] = purch;
        add_priceA[count_stock] = price;
        count_stock++;
        store_stock();
        cout << "\nStock '" << product << "' added successfully!\n";
    } else {
        cout << "No More Space to add Stock!\n";
    }
    pauseScreen();
}
void Beta::load_stock() {
    fstream file;
    file.open("addstock.txt", ios::in);
    count_stock = 0; // Reset
    while (file >> product_nameA[count_stock] >> add_quantityA[count_stock] >> add_purchaseA[count_stock] >> add_priceA[count_stock]) {
        count_stock++;
    }
    file.close();
}
void Beta::store_stock() {
    fstream file;
    file.open("addstock.txt", ios::app);
    for (int i = 0; i < count_stock; i++) {
        file << product_nameA[i] << "\t" << add_quantityA[i] << "\t" << add_purchaseA[i] << "\t" << add_priceA[i] << endl;
    }
    file.close();
}
void Beta::addemployee() {
    string em_name, em_type;
    int em_salary;
    setColor("Main Menu📋 > Add Employee 🧑‍🍳");
    cout << "Enter Employee Name : ";
    cin.ignore();
    getline(cin, em_name);
    cout << "Enter Employee Type : ";
    getline(cin, em_type);
    cout << "Enter Employee Salary : ";
    cin >> em_salary;
    addemployeeintoarray(em_name, em_type, em_salary);
}
void Beta::addemployeeintoarray(string em_name, string em_type, int em_salary) {
    if (count_employee < 20) {
        add_em_name[count_employee] = em_name;
        add_em_type[count_employee] = em_type;
        add_em_salary[count_employee] = em_salary;
        count_employee++;
        store_employee();
        cout << "Employee added successfully!" << endl;
    } else {
        cout << "No More Space to add Employees\n";
    }
    pauseScreen();
}
void Beta::load_employee() {
    fstream file;
    file.open("addemployee.txt", ios::in);
    count_employee = 0; // Reset
    while (file >> add_em_name[count_employee] >> add_em_type[count_employee] >> add_em_salary[count_employee]) {
        count_employee++;
    }
    file.close();
}
void Beta::store_employee() {
    fstream file;
    file.open("addemployee.txt", ios::app);
    for (int i = 0; i < count_employee; i++) {
        file << add_em_name[i] << "\t" << add_em_type[i] << "\t" << add_em_salary[i] << endl;
    }
    file.close();
}
void Beta::addcustomer() {
    cout << COLOR << "--- Add New Customer Order ---" << COLOR_RESET << "\n";
    cout << "Enter Customer Name: ";
    cin >> cust_name;
    cout << "Enter Name Of Meal: ";
    cin >> cust_product;
    cout << "Enter Quantity of Meal: ";
    cin >> cust_quantity;
    totalprice = 0;
    bool found = false;
    for (int i = 0; i < count_stock; i++) {
        if (cust_product == product_nameA[i]) {
            if (add_quantityA[i] >= cust_quantity) {
                totalprice = add_priceA[i] * cust_quantity;
                add_quantityA[i] -= cust_quantity; // Stock kam karo
                store_stock(); // Naya stock save karo
                found = true;
                break;
            } else {
                cout << "Not enough stock!\n";
                return;
            }
        }
    }
    if (!found) {
        cout << "Product not found!\n";
        return;
    }
    cout << "Total Price: " << totalprice << " PKR\n";
    cout << "Enter Date (e.g., DD-MM-YYYY): ";
    cin >> date;
    addCustomerintoarray(cust_name, cust_product, cust_quantity, totalprice, date);
}
void Beta::addCustomerintoarray(string name, string product, int quantity, int t_price, string c_date) {
    if (count_customer < 20) {
        add_cust_name[count_customer] = name;
        add_cust_product[count_customer] = product;
        add_cust_quantity[count_customer] = quantity;
        add_cust_date[count_customer] = c_date;
        add_cust_total[count_customer] = t_price;
        count_customer++;
        store_customer();
        cout << "\nCustomer record added successfully!\n";
    } else {
        cout << "No More Space to add Customers!\n";
    }
    pauseScreen();
}
void Beta::load_customer() {
    fstream file;
    file.open("addcustomer.txt", ios::in);
    count_customer = 0; // Reset
    while (file >> add_cust_name[count_customer] >> add_cust_product[count_customer] >> add_cust_quantity[count_customer] >> add_cust_total[count_customer] >> add_cust_date[count_customer]) {
        count_customer++;
    }
    file.close();
}
void Beta::store_customer() {
    fstream file;
    file.open("addcustomer.txt", ios::app);
    for (int i = 0; i < count_customer; i++) {
        file << add_cust_name[i] << "\t" << add_cust_product[i] << "\t" << add_cust_quantity[i] << "\t" << add_cust_total[i] << "\t" << add_cust_date[i] << endl;
    }
    file.close();
}
void Beta::ViewCustomer() {
    cout << COLOR << "--- Customer Records ---" << COLOR_RESET << "\n";
    cout << "Name\t\tMeal\t\tQuantity\t\tDate\t\tTotal (PKR)\n";
    cout << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < count_customer; i++) {
        cout << add_cust_name[i] << "\t\t" << add_cust_product[i] << "\t\t"
             << add_cust_quantity[i] << "\t\t\t" << add_cust_date[i] << "\t\t" << add_cust_total[i] << endl;
    }
    cout << "-------------------------------------------------------------------------------\n";
    pauseScreen();
}
int Beta::largest(int x) {
    float max = -1.0;
    int index = x;
    for (int i = x; i < count_stock; i++) {
        if (max < add_priceA[i]) {
            max = add_priceA[i];
            index = i;
        }
    }
    return index;
}
void Beta::print_Recd() {
    setColor("Main Menu📋 > List of Items with Prices💲");
    cout << endl;
    cout << "Product  " << "\t" << "Quantity" << "\t" << "Price" << endl;
    for (int i = 0; i < count_stock; i++) {
        cout << product_nameA[i] << "\t\t" << add_quantityA[i] << "\t\t" << add_priceA[i] << endl;
    }
    pauseScreen();
}
