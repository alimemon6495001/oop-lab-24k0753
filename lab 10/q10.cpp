#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("data_records.txt");
    
    
    inFile.seekg(16, ios::beg);
    
    string record;
    getline(inFile, record);
    cout << "Third record: " << record << endl;
    
    inFile.close();
    return 0;
}