#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    outFile << "Sensor 1: 25.5 C\n";
    cout << "position after line 1: " << outFile.tellp() << endl;
    
    outFile << "Sensor 2: 98.1 %RH\n";
    cout << "position after line 2: " << outFile.tellp() << endl;
    
    outFile.close();
    return 0;
}