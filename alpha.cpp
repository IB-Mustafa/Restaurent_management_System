#include "alpha.h"

// --- Alpha Class Functions ---
void Alpha::mainHeader() {
    cout << "\n\n";
    cout << "\t\t\t========================================\n";
    cout << "\t\t\t|    " << BOLD_COLOR << "RESTAURANT MANAGEMENT SYSTEM" << COLOR_RESET << " 🍽    |\n";
    cout << "\t\t\t========================================\n";
    cout << "\n\n";
}
string Alpha::loginMenu() {
    mainHeader();
    string user, password;
    setColor("👤 LOGIN PORTAL");
    cout << "Enter Usernamne : ";
    cin >> user;
    cout << "Enter Password : ";
    cin >> password;
    for (int i = 0; i < userCount; i++) {
        if (usernameA[i] == user && passwordsA[i] == password) {
            loginusername = user;
            return rolesA[i];
        }
    }
    loginusername = "";
    return "FAILED";
}
char Alpha::adminMenu() {
    mainHeader();
    cout << "                >>>>>>>>>>>>>>>>>   " << COLOR << "Login = MANAGER 👑" << COLOR_RESET << "    <<<<<<<<<<<<<<<<" << endl;
    setColor("Main Menu📋 >");
    cout << "---------------------------------\n";
    cout << "1. Add Stock\n";
    cout << "2. Update Stock\n";
    cout << "3. List Of Items\n";
    cout << "4. Add Employee\n";
    cout << "5. Add New User\n";
    cout << "6. Record Of Monthly Sale\n";
    cout << "7. Record Of Salary Of Employees\n";
    cout << "8. View Profit / Loss\n";
    cout << "9. Logout\n";
    cout << "---------------------------------\n";
    setColor("Enter Your option: ");
    cout << "> ";
    cin >> admin_option;
    return admin_option;
}
char Alpha::UserMenu() {
    mainHeader();
    cout << "                >>>>>>>>>>>>>>>>>    " << COLOR << "Login = CASHIER🧾" << COLOR_RESET << "    <<<<<<<<<<<<<<<<" << endl;
    setColor("Main Menu📋 >");
    cout << "---------------------------------\n";
    cout << "1. Add New Customer\n";
    cout << "2. Print Bill\n";
    cout << "3. View Customer Record\n";
    cout << "4. View Products that are Left\n";
    cout << "5. View Total No Of Products\n";
    cout << "6. Daily Sale record\n";
    cout << "7. Logout\n";
    cout << "---------------------------------\n";
    setColor("Enter Your option: ");
    cout << "> ";
    cin >> user_option;
    return user_option;
}
void Alpha::printbill() {
    cout << COLOR << "--- Bill Receipt ---" << COLOR_RESET << "\n";
    cout << "--------------------\n";
    cout << "Customer Name: " << cust_name << endl;
    cout << "Date: " << date << endl;
    cout << "Meal: " << cust_product << endl;;
    cout << "Quantity: "<< cust_quantity << endl;
    cout << "Total Bill : " << totalprice << " PKR" << endl;
    cout << "--------------------" <<endl;
    cout << "Thanks For Coming! <(^_^)>" << endl;
    pauseScreen();
}
void Alpha::updatestock() {
    string namee;
    int quantityy;
    float pricee;
    cout << COLOR << "--- Update Stock ---" << COLOR_RESET << "\n\n";
    cout << "Current Stock:\n";
    cout << "Product\t\tQuantity\n";
    cout << "------------------------\n";
    for (int i = 0; i < count_stock; i++) {
        cout << product_nameA[i] << "\t\t" << add_quantityA[i] << endl;
    }
    cout << "------------------------\n";
    cout << "\nEnter the product Name you want to update : ";
    cin >> namee;
    cout << "Enter the Quantity You Want To Add : ";
    cin >> quantityy;
    cout << "Enter the new Price You Want To Change : ";
    cin >> pricee;
    for (int i = 0; i < count_stock; i++) {
        if (namee == product_nameA[i]) {
            add_quantityA[i] += quantityy;
            add_priceA[i] = pricee;
            cout << "\nStock for '" << namee << "' updated successfully!\n";
            fstream file;
            file.open("addstock.txt", ios::app);
    for (int i = 0; i < count_stock; i++) {
            file << product_nameA[i] << "\t" << add_quantityA[i] << "\t" << add_purchaseA[i] << "\t" << add_priceA[i] << endl;
    }
    file.close();
     pauseScreen();
            break;
        }
    }
}
void Alpha::addNewUser() {
    cout << COLOR << "--- Add New User ---" << COLOR_RESET << "\n";
    string username, pass, role;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> pass;
    cout << "Enter Role (MANAGER or CASHIER in capital): ";
    cin >> role;
    addUser(username, pass, role);
}
void Alpha::addUser(string name, string pass, string role) {
    if (userCount < 10) {
        usernameA[userCount] = name;
        passwordsA[userCount] = pass;
        rolesA[userCount] = role;
        userCount++;
        store_user();
        cout << "\nUser '" << name << "' added successfully!\n";
    } else {
        cout << "No more Space to add Users!\n";
    }
     pauseScreen();
}
void Alpha::load_user() {
    fstream file;
    file.open("adduser.txt", ios::in);
    userCount = 0; // Reset before loading
    while (file >> usernameA[userCount] >> passwordsA[userCount] >> rolesA[userCount]) {
        userCount++;
    }
    file.close();
}

void Alpha::store_user() {
    fstream file;
    file.open("adduser.txt", ios::app);
    for (int i = 0; i < userCount; i++)
    {
        file << usernameA[i] << "\t" << passwordsA[i] << "\t" << rolesA[i] << endl;
    }
    file.close();
}