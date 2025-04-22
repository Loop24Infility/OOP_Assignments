#include <bits/stdc++.h>
using namespace std;

class AddAmount {
public:
    double amount;
    AddAmount() {
        amount = 50.0;
    }

    AddAmount(double amount_to_add) {
        amount = 50.0 + amount_to_add;
    }

    void displayAmount() {
        cout << "Final amount in Piggie Bank: $" << amount << endl;
    }
};

int main() {
    AddAmount piggieBank1;
    cout << "Piggie Bank 1 (no additional amount):" << endl;
    piggieBank1.displayAmount();

    double amount_to_add = 25.0;
    AddAmount piggieBank2(amount_to_add);
    cout << "\nPiggie Bank 2 (with additional $" << amount_to_add << "):" << endl;
    piggieBank2.displayAmount();
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
