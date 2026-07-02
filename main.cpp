#include <iostream>
#include <map>
#include <string>
using namespace std;

// Struct representing a product inside the vending machine
struct Product {
    string name;
    double price;
    int quantity;
};

// Class representing the Vending Machine
class VendingMachine {
private:
    map<int, Product> products; // Map storing products with their unique IDs
    double totalRevenue; // Total revenue accumulated from purchases

public:
    VendingMachine() {
        totalRevenue = 0.0;
    }

    // Method to add a new product to the machine
    void addProduct(int id, string name, double price, int quantity) {
        Product product;
        product.name = name;
        product.price = price;
        product.quantity = quantity;
        products[id] = product;
    }

    // Method to display all available products in the machine
    void displayProducts() {
        cout << "\n--- Available Products ---" << endl;
        for (const auto& pair : products) {
            int id = pair.first;
            const Product& product = pair.second;
            cout << "ID: " << id 
                 << " | Name: " << product.name 
                 << " | Price: $" << product.price 
                 << " | Stock: " << product.quantity << endl;
        }
    }

    // Method to handle a product purchase
    void purchaseProduct(int id, double amountInserted) {
        if (products.find(id) != products.end()) {
            Product& product = products[id];
            if (product.quantity > 0) {
                if (amountInserted >= product.price) {
                    cout << "\n>>> Product '" << product.name << "' successfully purchased!" << endl;
                    double change = amountInserted - product.price;
                    cout << ">>> Change returned: $" << change << endl;
                    product.quantity--;
                    totalRevenue += product.price;
                } else {
                    cout << "\n[ERROR] Insufficient funds to purchase this product." << endl;
                }
            } else {
                cout << "\n[ERROR] This product is out of stock." << endl;
            }
        } else {
            cout << "\n[ERROR] Product not found." << endl;
        }
    }

    // Method to display financial metrics (Admin only)
    void displayRevenue() {
        double potentialRevenue = 0.0;
        for (const auto& pair : products) {
            const Product& product = pair.second;
            potentialRevenue += product.price * product.quantity;
        }

        cout << "\n--- Financial Summary ---" << endl;
        cout << "Total Revenue: $" << totalRevenue << endl;
        cout << "Remaining Stock Value: $" << potentialRevenue << endl;
    }

    // Method to restock products (Admin only)
    void restockProduct() {
        cout << "\n--- Restock Menu ---" << endl;
        displayProducts();
        cout << "Enter the ID of the product you wish to restock: ";
        int id;
        cin >> id;

        if (products.find(id) != products.end()) {
            Product& product = products[id];
            cout << "Enter the quantity to add: ";
            int quantityToAdd;
            cin >> quantityToAdd;
            if (quantityToAdd > 0) {
                product.quantity += quantityToAdd;
                cout << "\n>>> Product '" << product.name << "' successfully restocked!" << endl;
            } else {
                cout << "\n[ERROR] Quantity must be greater than zero." << endl;
            }
        } else {
            cout << "\n[ERROR] Product not found." << endl;
        }
    }
};

int main() {
    VendingMachine machine;

    // Seeding initial inventory
    machine.addProduct(1, "Water", 2.50, 3);
    machine.addProduct(2, "Soda", 4.00, 5);
    machine.addProduct(3, "Juice", 3.00, 6);
    machine.addProduct(4, "Tea", 2.00, 2);
    machine.addProduct(5, "Cookies", 1.50, 9);
    machine.addProduct(6, "Chips", 3.50, 1);
    machine.addProduct(7, "Cake", 5.00, 9);
    machine.addProduct(8, "Chocolate", 3.00, 4);
    machine.addProduct(9, "Pie", 6.00, 7);

    int mode = -1;
    while (mode != 0) {
        cout << "=== Vending Machine System ===" << endl;
        cout << "1. User Mode" << endl;
        cout << "2. Administrator Mode" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> mode;

        if (mode == 1) {
            cout << "\n=== User Mode ===" << endl;
            machine.displayProducts();
            cout << "Enter the ID of the product you wish to purchase: ";
            int id;
            cin >> id;
            cout << "Enter payment amount ($): ";
            double payment;
            cin >> payment;
            machine.purchaseProduct(id, payment);
        } else if (mode == 2) {
            cout << "Enter administrator password: ";
            string password;
            cin >> password;
            if (password == "123") {
                int adminOption = -1;
                while (adminOption != 0) {
                    cout << "\n=== Administrator Mode ===" << endl;
                    cout << "1. Restock Products" << endl;
                    cout << "2. Check Inventory" << endl;
                    cout << "3. Check Revenue" << endl;
                    cout << "0. Return to Main Menu" << endl;
                    cout << "Choose an option: ";
                    cin >> adminOption;

                    if (adminOption == 1) {
                        machine.restockProduct();
                    } else if (adminOption == 2) {
                        machine.displayProducts();
                    } else if (adminOption == 3) {
                        machine.displayRevenue();
                    } else if (adminOption == 0) {
                        cout << "Returning to main menu..." << endl;
                    } else {
                        cout << "[ERROR] Invalid option. Please try again." << endl;
                    }
                }
            } else {
                cout << "[ERROR] Incorrect password. Access denied." << endl;
            }
        } else if (mode == 0) {
            cout << "Exiting system. Thank you!" << endl;
        } else {
            cout << "[ERROR] Invalid option. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}