#include <iostream>
#include <string>
using namespace std;

// Abstract base class for MenuItem
class MenuItem {
protected:
    string dishName;
    double price;
    
public:
    // Constructor to initialize common menu item data
    MenuItem(const string& name, double p) : dishName(name), price(p) {}
    
    // Pure virtual functions to be implemented by derived classes
    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;
    
    // Virtual destructor for proper cleanup
    virtual ~MenuItem() {}
};

// Derived class for Appetizer
class Appetizer : public MenuItem {
private:
    string dipType;
    
public:
    // Constructor for Appetizer
    Appetizer(const string& name, double p, const string& dip)
        : MenuItem(name, p), dipType(dip) {}
    
    // Implementation of showDetails for Appetizer
    void showDetails() const override {
        cout << "Appetizer Details:\n";
        cout << "Dish Name: " << dishName << "\n";
        cout << "Price: $" << price << "\n";
        cout << "Comes with " << dipType << " dip\n";
    }
    
    // Implementation of prepare for Appetizer
    void prepare() const override {
        cout << "Preparing " << dishName << ":\n";
        cout << "1. Plate the appetizer\n";
        cout << "2. Add " << dipType << " dip on the side\n";
        cout << "3. Garnish and serve\n";
    }
};

// Derived class for MainCourse
class MainCourse : public MenuItem {
private:
    string sideDish;
    
public:
    // Constructor for MainCourse
    MainCourse(const string& name, double p, const string& side)
        : MenuItem(name, p), sideDish(side) {}
    
    // Implementation of showDetails for MainCourse
    void showDetails() const override {
        cout << "Main Course Details:\n";
        cout << "Dish Name: " << dishName << "\n";
        cout << "Price: $" << price << "\n";
        cout << "Comes with " << sideDish << " as side dish\n";
    }
    
    // Implementation of prepare for MainCourse
    void prepare() const override {
        cout << "Preparing " << dishName << ":\n";
        cout << "1. Cook the main dish\n";
        cout << "2. Prepare " << sideDish << "\n";
        cout << "3. Plate together and serve\n";
    }
};

int main() {
    // Create Appetizer and MainCourse objects
    Appetizer app("Bruschetta", 8.99, "tomato basil");
    MainCourse main("Grilled Salmon", 22.99, "mashed potatoes");
    
    // Use base class pointers for polymorphism
    MenuItem* items[] = {&app, &main};
    
    // Display details and preparation for each menu item
    for (MenuItem* item : items) {
        item->showDetails();
        item->prepare();
        cout << "\n";
    }
    
    return 0;
}