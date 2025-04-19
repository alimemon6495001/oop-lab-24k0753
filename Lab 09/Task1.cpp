#include <iostream>
#include <string>
using namespace std;

// Abstract base class for Patient
class Patient {
protected:
    string name;
    string id;
    
public:
    // Constructor to initialize common patient data
    Patient(const string& n, const string& i) : name(n), id(i) {}
    
    // Pure virtual functions to be implemented by derived classes
    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;
    
    // Virtual destructor for proper cleanup
    virtual ~Patient() {}
};

// Derived class for InPatient
class InPatient : public Patient {
private:
    int daysAdmitted;
    double dailyRate;
    
public:
    // Constructor for InPatient
    InPatient(const string& n, const string& i, int days, double rate)
        : Patient(n, i), daysAdmitted(days), dailyRate(rate) {}
    
    // Implementation of displayTreatment for InPatient
    void displayTreatment() const override {
        cout << "InPatient Treatment Details:\n";
        cout << "Name: " << name << "\nID: " << id << "\n";
        cout << "Days Admitted: " << daysAdmitted << "\n";
        cout << "Daily Rate: $" << dailyRate << "\n";
    }
    
    // Implementation of calculateCost for InPatient
    double calculateCost() const override {
        return daysAdmitted * dailyRate;
    }
};

// Derived class for OutPatient
class OutPatient : public Patient {
private:
    int numberOfVisits;
    double visitCharge;
    
public:
    // Constructor for OutPatient
    OutPatient(const string& n, const string& i, int visits, double charge)
        : Patient(n, i), numberOfVisits(visits), visitCharge(charge) {}
    
    // Implementation of displayTreatment for OutPatient
    void displayTreatment() const override {
        cout << "OutPatient Treatment Details:\n";
        cout << "Name: " << name << "\nID: " << id << "\n";
        cout << "Number of Visits: " << numberOfVisits << "\n";
        cout << "Charge per Visit: $" << visitCharge << "\n";
    }
    
    // Implementation of calculateCost for OutPatient
    double calculateCost() const override {
        return numberOfVisits * visitCharge;
    }
};

int main() {
    // Create InPatient and OutPatient objects
    InPatient ip("John Doe", "IP123", 5, 250.0);
    OutPatient op("Jane Smith", "OP456", 3, 150.0);
    
    // Use base class pointers for polymorphism
    Patient* patients[] = {&ip, &op};
    
    // Display treatment details and calculate costs for each patient
    for (Patient* p : patients) {
        p->displayTreatment();
        cout << "Total Cost: $" << p->calculateCost() << "\n\n";
    }
    
    return 0;
}