#include "alpha.h"
#include "beta.h"
#include "gama.h"

// --- Main Function ---
// <<<<<<<<<<<<<<<<< YEH FINAL MAIN FUNCTION HAI >>>>>>>>>>>>>>>>>

int main()
{
    // FIX 1: Sirf aik object banayenge jo sab kuch kar sakta hai
    Gama G; 

    // FIX 2: Program ke start mein data load karo
    G.load_user();
    G.load_stock();
    G.load_employee();
    G.load_customer();

    string who = " "; 

    while (true)
    {
        clearScreen();
        // Har function ab G object se hi call hoga
        who = G.loginMenu(); 
        if (who == "MANAGER")
        {
            char option = ' ';
            while (true)
            {
                clearScreen();
                option = G.adminMenu();
                clearScreen();
                if (option == '9') break;
                G.mainHeader();
                
                // Data copy karne ki zaroorat nahi
                if (option == '1') G.addstock();
                else if (option == '2') G.updatestock();
                else if (option == '3') G.print_Recd();
                else if (option == '4') G.addemployee();
                else if (option == '5') G.addNewUser();
                else if (option == '6') G.Monthlysalerecord();
                else if (option == '7') G.recordofemployee();
                else if (option == '8') G.viewprofitloss();
                else {
                    cout << "You Chose a Wrong option!\n";
                    pauseScreen();
                }
            }
        }
        else if (who == "CASHIER")
        {
            char UserOption = ' ';
            while (true)
            {
                clearScreen();
                UserOption = G.UserMenu();
                clearScreen();
                if (UserOption == '7') break;
                G.mainHeader();
                
                // Data copy karne ki zaroorat nahi
                if (UserOption == '1') G.addcustomer();
                else if (UserOption == '2') G.printbill();
                else if (UserOption == '3') G.ViewCustomer();
                else if (UserOption == '4') G.leftproducts();
                else if (UserOption == '5') G.viewproducts();
                else if (UserOption == '6') G.Dailysalerecord();
                else {
                    cout << "Wrong selection! Try again\n";
                    pauseScreen();
                }
            }
        }
        else // Handles FAILED login
        {
            cout << "You entered wrong username or password!\n";
            pauseScreen();
        }
    }
    return 0;
}