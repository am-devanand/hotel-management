#include <iostream>

using namespace std;

// Class for customer information
class Customer {
protected:
    string name;
    string phone;
public:
    void getCustomerDetails() {
        cout << "Enter Customer Name: ";
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
    }
};

// Class for menu and order
class Menu {
protected:
    string items[5] = {"Paneer Butter Masala", "Veg Biryani", "Gobi Manchurian", "Dosa", "Veg Noodles"};
    float prices[5] = {250.0, 180.0, 150.0, 100.0, 130.0};
    int quantity[5] = {0};
public:
    void showMenu() {
        cout << "\n--- VEG MENU ---\n";
        for (int i = 0; i < 5; ++i) {
            cout << i+1 << ". " << items[i] << " - ₹" << prices[i] << endl;
        }
    }

    void takeOrder() {
        cout << "\nEnter quantity for each item:\n";
        for (int i = 0; i < 5; ++i) {
            cout << items[i] << ": ";
            cin >> quantity[i];
        }
    }
};

// Final class for bill generation using Multiple Inheritance
class Bill : public Customer, public Menu {
public:
    void generateBill() {
        float total = 0;
        cout << "\n\n----------- A2B HOTEL BILL -----------\n";
        cout << "Customer: " << name << " | Phone: " << phone << endl;
        cout << "--------------------------------------\n";
        cout    << " \t Item"   << "\t Qty"  << "\t Price" << "\t  Total\n";
        
        for (int i = 0; i < 5; ++i) {
            if (quantity[i] > 0) {
                float itemTotal = prices[i] * quantity[i];
                total += itemTotal;
                cout << items[i] <<"\t"<< quantity[i] << "\t ₹" <<  prices[i] << "\t ₹" << itemTotal << endl;
            }
        }

        float discount = 0;
        if (total > 1000) {
            discount = total * 0.2;
        }

        float finalAmount = total - discount;

        cout << "--------------------------------------\n";
        cout << "Original Total: ₹" << total << endl;
        if (discount > 0)
            cout << "Discount (20%): -₹" << discount << endl;
        cout << "Final Amount: ₹" << finalAmount << endl;
        cout << "--------------------------------------\n";
        cout << "Thank you for visiting A2B!\n";
    }
};

int main() {
    Bill b;
    b.getCustomerDetails();
    b.showMenu();
    b.takeOrder();
    b.generateBill();
    return 0;
}

