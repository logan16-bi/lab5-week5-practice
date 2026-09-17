/*
 * Course: COEN 2220 - Programming 2
 * Name: Logan N. Ramirez Rodriguez
 * Lab: Lab 5 - Week 5 Practice: OOP and Function Templates
 * Description: Inheritance, polymorphism, and function template practice
 * Due date: 9/17/2026
 */

#include <iostream>
#include <string>
using namespace std;

class CampusEvent
{
    private:
        string name; // Each CampusEvent object keeps its own name.

    public:
        CampusEvent(string eventName) {
            name = eventName; // The base class initializes shared state.
        }

        string getName() const {
            return name; // Derived classes use this public interface to read the name.
        }

        virtual void printDetails() const {
            cout << name << ": open attendance" << endl;
        }
};

class LimitedEvent : public CampusEvent
{
    private:
        int availableSeats;

    public:
        LimitedEvent(string eventName, int seats) : CampusEvent(eventName) {
            availableSeats = seats;
        }

        void printDetails() const override {
            cout << getName() << ": " << availableSeats << " seats available" << endl;
        }
};

// ===== Resolve these TODOs later (Part D) =====
// TODO (Part D): Write a function template named largerValue.
// It receives two const references of the same generic type and returns the larger value.
// Do not write separate int and double versions.

int main() {
    CampusEvent openEvent("Coding Club Meeting");

    cout << "--- Base event ---" << endl;
    openEvent.printDetails(); // This call uses CampusEvent::printDetails directly.

    // ===== Resolve these TODOs later (Part E) =====
    // TODO (Part E): Create a LimitedEvent with dummy data.
    // TODO (Part E): Store the addresses of openEvent and your LimitedEvent
    // in two CampusEvent pointers. Call printDetails() through both pointers.
    // TODO (Part E): Use largerValue with two int values and with two double values.
    // Print each result with a descriptive English label.

    return 0;
}