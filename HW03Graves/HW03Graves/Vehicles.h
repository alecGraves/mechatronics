/**
Vehicles.h
homework 3 for mechatronics 2610

@author Alec Graves
*/
#include <iostream>

namespace vehicles {
	class Car {
	private:
		int _mileage;
		int _passengers;
	public:
		void SetMileage(int mileage) {
			_mileage = mileage;
		}
		int GetMileage() {
			return _mileage;
		}
		void SetPassengers(int passengers) {
			_passengers = passengers;
		}
		virtual void display() {
			using namespace std;
			cout << "This car seats " << _passengers
				<< " passengers" << endl << "Gas mileage is "
				<< GetMileage() << " MPG" << endl;
		}
	Car() {;}
	};
	class Truck : public Car {
	private:
		int _payload;
	public:
		void SetPayload(int payload) {
			_payload = payload;
		}
		void display() {
			using namespace std;
			cout << "This truck has a payload of " << _payload
				<< " tons" << endl << "Gas mileage is "
				<< GetMileage() << " MPG" << endl;
		}
	Truck() : Car() {;}
	};
}