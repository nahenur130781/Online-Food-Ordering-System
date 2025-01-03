#include <bits/stdc++.h>
#include<fstream>
using namespace std;

class MenuItem {
public:
    string name;
    int price;

    MenuItem(string itemName, int itemPrice) {
        name = itemName;
        price = itemPrice;
    }
};

class Order {
private:
    vector<MenuItem> pizzas, burgers, sandwiches, rolls, biryanis;
    string customerName;
    int totalBill;

public:
    Order() {
        pizzas = {MenuItem("Chicken Fajita", 250), MenuItem("Chicken BBQ", 590), MenuItem("Peri Peri", 1000), MenuItem("Creamy Max", 1000)};
        burgers = {MenuItem("Zinger Burger", 180), MenuItem("Chicken Burger", 150), MenuItem("Beef Burger", 160)};
        sandwiches = {MenuItem("Club Sandwich", 240), MenuItem("Chicken Crispy Sandwich", 160), MenuItem("Extreme Veg Sandwich", 100)};
        rolls = {MenuItem("Chicken Chatni Roll", 150), MenuItem("Chicken Mayo Roll", 100), MenuItem("Veg Roll With Fries", 120)};
        biryanis = {MenuItem("Chicken Biryani", 160), MenuItem("Prawn Biryani", 220), MenuItem("Beef Biryani", 140)};
        totalBill = 0;
    }

    void takeCustomerName() {
        cout << "Please Enter Your Name: ";
        getline(cin, customerName);
        while (customerName.empty()) {
            cout << "Name cannot be empty. Please enter your name: ";
            getline(cin, customerName);
        }
    } // nahenur push
void displayMenu() {
        cout << "\n\t\t\t---------- HUNGER -----------\n\n";
        cout << "Hello " << customerName << "!\nWhat would you like to order?\n\n";
        cout << "\t\t\t-------- Menu --------\n\n";
        cout << "1) Pizzas\n";
        cout << "2) Burgers\n";
        cout << "3) Sandwiches\n";
        cout << "4) Rolls\n";
        cout << "5) Biryani\n";
    }

    void displayItems(const vector<MenuItem> &items) {
        for (size_t i = 0; i < items.size(); i++) {
            cout << i + 1 << ") " << items[i].name << " (Tk." << items[i].price << ")\n";
        }
    }

    void processOrder(int choice) {
        int itemChoice, quantity;
        string category;
        vector<MenuItem> selectedMenu;

        if (choice == 1)
        {
            category = "Pizza";
            selectedMenu = pizzas;
        }
        else if (choice == 2) 
        {
            category = "Burger";
            selectedMenu = burgers;
        }
        else if (choice == 3) 
        {
            category = "Sandwich";
            selectedMenu = sandwiches;
        }
        else if (choice == 4) 
        {
            category = "Roll";
            selectedMenu = rolls;
        }
        else if (choice == 5) 
        {
            category = "Biryani";
            selectedMenu = biryanis;
        }

        cout << "\nAvailable " << category << " options:\n";
        displayItems(selectedMenu);

        cout << "\nPlease select an option: ";
        while (!(cin >> itemChoice) || itemChoice < 1 || itemChoice > selectedMenu.size()) {
            cout << "Invalid input. Please select a valid option: ";
        }

        cout << "\nEnter quantity: ";
        while (!(cin >> quantity) || quantity <= 0) {
            cout << "Invalid input. Please enter a valid quantity: ";
        } // Alma push