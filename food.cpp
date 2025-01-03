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
