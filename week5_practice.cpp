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

template <typename T>
T largerValue(const T &first, const T &second) {
    return (first > second) ? first : second;
}

int main() {
    CampusEvent openEvent("Coding Club Meeting");

    cout << "--- Base event ---" << endl;
    openEvent.printDetails(); // This call uses CampusEvent::printDetails directly.

    LimitedEvent limitedEvent("Robotics Workshop", 18);

    CampusEvent *eventPtr1 = &openEvent;
    CampusEvent *eventPtr2 = &limitedEvent;

    cout << "--- Polymorphism ---" << endl;
    eventPtr1->printDetails();
    eventPtr2->printDetails();

    int attendanceA = 45;
    int attendanceB = 80;
    double ratingA = 4.2;
    double ratingB = 4.7;

    cout << "--- Function template ---" << endl;
    cout << "Higher attendance estimate: " << largerValue(attendanceA, attendanceB) << endl;
    cout << "Higher event rating: " << largerValue(ratingA, ratingB) << endl;

    return 0;

}