#include <iostream>
#include <exception>

class NegativeStockException : public std::exception {};
class OverCapacityException : public std::exception {};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxStock;
public:
    InventoryItem(T max) : stock(0), maxStock(max) {}

    void setStock(T value) {
        if (value < 0) {
            throw NegativeStockException();
        }
        if (value > maxStock) {
            throw OverCapacityException();
        }
        stock = value;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        std::cout << "Attempting to set stock to -5...\n";
        item.setStock(-5);
    } catch (const NegativeStockException&) {
        std::cout << "Caught NegativeStockException - what(): std::exception\n";
    }

    try {
        std::cout << "Attempting to set stock to 120 (max 100)...\n";
        item.setStock(120);
    } catch (const OverCapacityException&) {
        std::cout << "Caught OverCapacityException - what(): std::exception\n";
    }

    return 0;
}
