#include <bits/stdc++.h>
#include<fstream>
using namespace std;
class RestaurantOrder{
    public:
    virtual void menu()=0;
    virtual void process(int choice)=0;
    virtual void finalize()=0;
    virtual ~RestaurantOrder(){}
};

class MenuItem {
public:
    string name;
    int price;

    MenuItem(string itemName, int itemPrice) {
        name = itemName;
        price = itemPrice;
    }
};

class Order:public RestaurantOrder
 {
private:
    vector<MenuItem> pizzas, burgers, sandwiches, rolls, biryanis;
    string customer;
    int bill;

public:
Order();
void takeName();
void menu()override;
void items(const vector<MenuItem>&list);
void process(int choice)override;
void finalize()override;
void save();
void records();
 };
   Order:: Order() {
        pizzas = {MenuItem("Chicken Fajita", 250), MenuItem("Chicken BBQ", 590), MenuItem("Peri Peri", 1000), MenuItem("Creamy Max", 1000)};
        burgers = {MenuItem("Zinger Burger", 180), MenuItem("Chicken Burger", 150), MenuItem("Beef Burger", 160)};
        sandwiches = {MenuItem("Club Sandwich", 240), MenuItem("Chicken Crispy Sandwich", 160), MenuItem("Extreme Veg Sandwich", 100)};
        rolls = {MenuItem("Chicken Chatni Roll", 150), MenuItem("Chicken Mayo Roll", 100), MenuItem("Veg Roll With Fries", 120)};
        biryanis = {MenuItem("Chicken Biryani", 160), MenuItem("Prawn Biryani", 220), MenuItem("Beef Biryani", 140)};
        bill = 0;
    }

    void Order::takeName() {
        cout << "Please Enter Your Name: ";
        getline(cin,customer);
        while (customer.empty()) {
            cout << "Name cannot be empty. Please enter your name: ";
            getline(cin, customer);
        }
    } // nahenur push
void Order:: menu() {
        cout << "\n\t\t\t---------- HUNGER -----------\n\n";
        cout << "Hello " << customer << "!\nWhat would you like to order?\n\n";
        cout << "\t\t\t-------- Menu --------\n\n";
        cout << "1) Pizzas\n";
        cout << "2) Burgers\n";
        cout << "3) Sandwiches\n";
        cout << "4) Rolls\n";
        cout << "5) Biryani\n";
    }

    void Order::items(const vector<MenuItem> &list) {
        for (size_t i = 0; i < list.size(); i++) {
            cout << i + 1 << ") " << list[i].name << " (Tk." << list[i].price << ")\n";
        }
    }

    void Order::process(int choice) {
        int itemChoice, qty;
        string type;
        vector<MenuItem> list;

        if (choice == 1)
        {
            type = "Pizza";
            list = pizzas;
        }
        else if (choice == 2) 
        {
           type= "Burger";
           list = burgers;
        }
        else if (choice == 3) 
        {
            type = "Sandwich";
            list = sandwiches;
        }
        else if (choice == 4) 
        {
            type = "Roll";
            list = rolls;
        }
        else if (choice == 5) 
        {
           type= "Biryani";
            list = biryanis;
        }

        cout << "\nAvailable " << type << " options:\n";
        items(list);

        cout << "\nPlease select an option: ";
        while (!(cin >> itemChoice) || itemChoice < 1 || itemChoice > list.size()) {
            cout << "Invalid input. Please select a valid option: ";
        }

        cout << "\nEnter quantity: ";
        while (!(cin >> qty) || qty<= 0) {
            cout << "Invalid input. Please enter a valid quantity: ";
        } // Alma push
