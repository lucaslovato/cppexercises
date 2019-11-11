#include <iostream>
#include <vector>

using namespace std;

// Create the struct for the sensors
struct Sensor {
	string name;
	int quantity;
	int number_of_cables;
	double response_time;
	bool we_have;
};

// Set the data for each sensor
Sensor magnetic = {"magnetic", 1, 3, .15, true};
Sensor water = {"water", 1, 3, .05, true};
Sensor accelerometer = {"accelerometer", 5, 4, .8, true};
Sensor temperature = {"temperature", 20, 3, .8, false};
Sensor microphone = {"microphone", 5, 6, 1, true};

// Set the vector of sensors
vector<Sensor> sensors {magnetic, water, accelerometer, temperature, microphone};

// This function receives one argument struct Sensor and print its information
void info(Sensor s) {
	cout << "Sensor: " << s.name << endl;
	cout << "Quantity: " << s.quantity << endl;
	cout << "Number of cables: " << s.number_of_cables << endl;
	cout << "We have?: " << ((s.we_have) ? "Yes" : "No") << endl << endl;
}

int main() {
	// loop in each sensor
	for (int s = 0; s < sensors.size(); s++) {
		info(sensors[s]);
	}
}