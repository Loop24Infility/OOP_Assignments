#include <iostream>
#include <string>
using namespace std;

class Performance {
    string time;
    int totalSeats;
    int bookedSeats;
public:
    Performance(string t, int seats) : time(t), totalSeats(seats), bookedSeats(0) {}

    bool bookSeat(int numSeats) {
        if (bookedSeats + numSeats <= totalSeats) {
            bookedSeats += numSeats;
            return true;
        }
        return false;
    }

    int seatsRemaining() {
        return totalSeats - bookedSeats;
    }

    void displayStatus() {
        cout << "Performance at " << time << ": " << seatsRemaining() << " seats remaining\n";
    }

    string getTime() {
        return time;
    }
};

int main() {
    Performance p1("1:00 PM", 100);
    Performance p2("5:00 PM", 100);
    Performance p3("8:30 PM", 100);

    int choice, seats;
    while (true) {
        cout << "\nCinema Booking System\n";
        cout << "1. Book seats\n";
        cout << "2. View remaining seats\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Select performance:\n1. 1:00 PM\n2. 5:00 PM\n3. 8:30 PM\nEnter choice: ";
            cin >> choice;
            cout << "Enter number of seats to book: ";
            cin >> seats;

            bool success = false;
            if (choice == 1) success = p1.bookSeat(seats);
            else if (choice == 2) success = p2.bookSeat(seats);
            else if (choice == 3) success = p3.bookSeat(seats);

            if (success) cout << "Booking successful!\n";
            else cout << "Booking failed. Not enough seats.\n";
        }
        else if (choice == 2) {
            p1.displayStatus();
            p2.displayStatus();
            p3.displayStatus();
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    cout << "CODE BY KSHITIJ JADHAV";
    return 0;
}
