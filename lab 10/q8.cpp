#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ofstream outFile("config.txt");
    outFile << "AAAAABBBBCCCCC";
    outFile.close();

   
    fstream file("config.txt", ios::in | ios::out);
    file.seekp(5, ios::beg);
    file << "XXXXX";
    file.close();

    
    ifstream inFile("config.txt");
    string content;
    getline(inFile, content);
    cout << "Updated content: " << content << endl;
    inFile.close();

    return 0;
}