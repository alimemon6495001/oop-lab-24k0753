#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("large_log.txt");
    char buffer[11];
    
    inFile.read(buffer, 10);
    buffer[10] = '\0';
    cout << "First 10 chars: " << buffer << endl;
    cout << "Position after read: " << inFile.tellg() << endl;
    
    inFile.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Next 10 chars: " << buffer << endl;
    cout << "Position after read: " << inFile.tellg() << endl;
    
    inFile.close();
    return 0;
}