#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string ticketID, passengerName, date, destination;
    double price;

public:
    Ticket(string id, string name, double p, string d, string dest) : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << endl;
    }

    virtual void cancel() {
        cout << "Ticket cancelled for " << passengerName << endl;
    }

    virtual void displayTicketInfo() const {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
    string airlineName, flightNumber, seatClass;

public:
    FlightTicket(string id, string name, double p, string d, string dest, string airline, string flight, string seat): Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight No: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
    string trainNumber, coachType, departureTime;

public:
    TrainTicket(string id, string name, double p, string d, string dest, string train, string coach, string time): Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        cout << "Seat auto-assigned for " << passengerName << " on train " << trainNumber << endl;
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Train No: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
    string busCompany, seatNumber;

public:
    BusTicket(string id, string name, double p, string d, string dest, string company, string seat): Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout << "Ticket cancelled. Full refund issued for " << passengerName << endl;
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat No: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
    string artistName, venue, seatType;

public:
    ConcertTicket(string id, string name, double p, string d, string dest, string artist, string loc, string seat): Ticket(id, name, p, d, dest), artistName(artist), venue(loc), seatType(seat) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket ft("FT001", "Ali", 250.0, "2025-04-05", "Dubai", "Emirates", "EK202", "Economy");
    TrainTicket tt("TR101", "Sara", 90.0, "2025-04-06", "Lahore", "GreenLine", "AC", "09:00 AM");
    BusTicket bt("BS201", "Zain", 45.0, "2025-04-07", "Islamabad", "Skyways", "B12");
    ConcertTicket ct("CN301", "Hira", 150.0, "2025-04-08", "Karachi", "Ali Zafar", "Expo Center", "VIP");

    ft.reserve();
    ft.displayTicketInfo();
    cout << endl;

    tt.reserve();
    tt.displayTicketInfo();
    cout << endl;

    bt.cancel();
    bt.displayTicketInfo();
    cout << endl;

    ct.reserve();
    ct.displayTicketInfo();

    return 0;
}
