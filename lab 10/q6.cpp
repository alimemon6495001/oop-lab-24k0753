#include <iostream>
#include <fstream>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
   
    InventoryItem item1 = {123, "Sample Item"};
    ofstream outFile("inventory.dat", ios::binary);
    outFile.write(reinterpret_cast<char*>(&item1), sizeof(item1));
    outFile.close();

    
    InventoryItem item2;
    ifstream inFile("inventory.dat", ios::binary);
    inFile.read(reinterpret_cast<char*>(&item2), sizeof(item2));
    inFile.close();

    cout << "Loaded Item ID: " << item2.itemID << endl;
    cout << "Loaded Item Name: " << item2.itemName << endl;

    return 0;
}