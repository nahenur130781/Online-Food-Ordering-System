int cost = list[itemChoice - 1].price * qty;
    bill += cost;

    cout << "\n\t\t-------- Your Order --------\n";
    cout << qty << " x " << list[itemChoice - 1].name << "\n";
    cout << "Cost: Tk. " << cost << "\n\n";
}

void Order::finalize() {
    cout << "\n\t\t-------- Order Summary --------\n";
    cout << "Customer Name: " << customer << "\n";
    cout << "Total Bill: Tk. " << bill << "\n";
    cout << "Your order will be delivered soon!\n";
    cout << "Thank you for ordering from HUNGER!\n\n";
    save();
}

void Order::save() {
    ofstream outFile("orders.txt", ios::app);
    if (!outFile.is_open()) {
        cerr << "Error opening file for saving order data.\n";
        return;
    }
    outFile << "Customer Name: " << customer << '\n';
    outFile << "Total Bill: Tk. " << bill << '\n';
    outFile << "Thank you for ordering from HUNGER!\n";
    outFile << "------------------------\n";
    outFile.close();
}

void Order::records() {
    ifstream inFile("orders.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading order data.\n";
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << '\n';
    }
    inFile.close();
}//Saba push
