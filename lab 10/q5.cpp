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

        if (type == "AutonomousCar") {
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                string versionStr = extraData.substr(colonPos + 1);
                float version = stof(versionStr);
                cout << "AutonomousCar " << id << " - Software Version: " << version << endl;
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
        else if (type == "HybridTruck") {
            size_t colonPos = extraData.find(':');
            size_t pipePos = extraData.find('|');
            
            if (colonPos != string::npos && pipePos != string::npos) {
               
                string cargoStr = extraData.substr(colonPos + 1, pipePos - colonPos - 1);
                int cargo = stoi(cargoStr);
                
               
                size_t batteryPos = extraData.find("Battery:");
                if (batteryPos != string::npos) {
                    string batteryStr = extraData.substr(batteryPos + 8);
                    int battery = stoi(batteryStr);
                    cout << "HybridTruck " << id << " - Cargo: " << cargo 
                         << ", Battery: " << battery << endl;
                }
            }
        }
        else {
            cerr << "Unknown vehicle type: " << type << endl;
        }
    }

    inputFile.close();
    return 0;
}