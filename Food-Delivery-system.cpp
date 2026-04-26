#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

/* ===================== CUSTOMER ===================== */
class Customer {
public:
    string name;
    string phone;

    void getDetails() {
       

        cout << "Enter your name: " << endl;
        getline(cin, name);

        cout << "Enter your phone number: " << endl;
        cin >> phone;
    }
};

/* ===================== ORDER ===================== */
class Order {
public:
    string itemName;
    int price;
    int quantity;

    Order(string name, int p, int q) {
        itemName = name;
        price = p;
        quantity = q;
    }

    int getTotal() {
        return price * quantity;
    }
};

/* ===================== RESTAURANT (ABSTRACT) ===================== */
class Restaurant {
protected:
    string rName;

public:
    virtual void showMenu() = 0;

    virtual Order takeOrder() = 0;

    string getName() {
        return rName;
    }

    virtual ~Restaurant() {}
};

/* ===================== KFC ===================== */
class KFC : public Restaurant {
public:
    KFC() {
        rName = "KFC";
    }

    void showMenu() override {
        cout << endl;
        cout << "----- KFC MENU -----" << endl;
        cout << "1. Zinger Burger - 550" << endl;
        cout << "2. Family Bucket - 2500" << endl;
        cout << "3. Hot Wings     - 450" << endl;
    }

    Order takeOrder() override {
        int choice, qty;

        showMenu();

        cout << "Enter your choice: " << endl;
        cin >> choice;

        cout << "Enter quantity: " << endl;
        cin >> qty;

        if (choice == 1)
            return Order("Zinger Burger", 550, qty);
        else if (choice == 2)
            return Order("Family Bucket", 2500, qty);
        else
            return Order("Hot Wings", 450, qty);
    }
};

/* ===================== DOMINOS ===================== */
class Dominos : public Restaurant {
public:
    Dominos() {
        rName = "Dominos";
    }

    void showMenu() override {
        cout << endl;
        cout << "----- DOMINOS MENU -----" << endl;
        cout << "1. Large Pizza  - 1800" << endl;
        cout << "2. Garlic Bread - 400" << endl;
        cout << "3. Lava Cake    - 500" << endl;
    }

    Order takeOrder() override {
        int choice, qty;

        showMenu();

        cout << "Enter your choice: " << endl;
        cin >> choice;

        cout << "Enter quantity: " << endl;
        cin >> qty;

        if (choice == 1)
            return Order("Large Pizza", 1800, qty);
        else if (choice == 2)
            return Order("Garlic Bread", 400, qty);
        else
            return Order("Lava Cake", 500, qty);
    }
};

/* ===================== MAIN FUNCTION ===================== */
int main() {

    Customer user;

    KFC kfc;
    Dominos dominos;

    Restaurant* restaurant = NULL;

    vector<Order> cart;

    int resChoice;
    char more;

    cout << "===============================" << endl;
    cout << "   FOOD ORDERING SYSTEM" << endl;
    cout << "===============================" << endl;

    user.getDetails();

    do {
        cout << endl;
        cout << "Choose a restaurant:" << endl;
        cout << "1. KFC" << endl;
        cout << "2. Dominos" << endl;
        cout << "Enter choice: " << endl;

        cin >> resChoice;

        if (resChoice == 1)
            restaurant = &kfc;
        else
            restaurant = &dominos;

        Order order = restaurant->takeOrder();
        cart.push_back(order);

        cout << endl;
        cout << "Do you want to order more? (y/n): " << endl;
        cin >> more;

    } while (more == 'y' || more == 'Y');

    /* ===================== RECEIPT ===================== */
    int totalBill = 0;

    cout << endl;
    cout << "================ RECEIPT ================" << endl;
    cout << "Customer Name: " << user.name << endl;
    cout << "Phone Number: " << user.phone << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < cart.size(); i++) {
        cout << cart[i].itemName << " x" << cart[i].quantity
             << " = " << cart[i].getTotal() << " PKR" << endl;

        totalBill += cart[i].getTotal();
    }

    cout << "----------------------------------------" << endl;
    cout << "TOTAL BILL: " << totalBill << " PKR" << endl;
    cout << "========================================" << endl;

    /* ===================== FILE SAVE ===================== */
    ofstream file("bill.txt");

    file << "Customer: " << user.name << endl;
    file << "Phone: " << user.phone << endl;
    file << "----------------------------------" << endl;

    for (int i = 0; i < cart.size(); i++) {
        file << cart[i].itemName << " x" << cart[i].quantity
             << " = " << cart[i].getTotal() << endl;
    }

    file << "TOTAL BILL: " << totalBill << endl;

    file.close();

    cout << endl;
    cout << "Bill saved successfully in bill.txt" << endl;

    return 0;
}
