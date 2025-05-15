#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream inputFile("VEHICLE.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') continue;

        istringstream iss(line);
        string type, id, name, yearStr, extraData, certification;
        
        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, yearStr, ',');
        getline(iss, extraData, ',');
        getline(iss, certification);

        if (type == "hybridCar") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string versionStr = extraData.substr(colonPos + 1);
                float version = stof(versionStr);
                cout << "hybridCar " << id << " - Software Version: " << version << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string capacityStr = extraData.substr(colonPos + 1);
                int capacity = stoi(capacityStr);
                cout << "ElectricVehicle " << id << " - Battery Capacity: " << capacity << endl;
            }
        }
    }

    inputFile.close();
    return 0;
}