#include "Vehicles.h"

using namespace std;
using namespace vehicles;

int main(int argc, char**argv){
	Car sedan;
	Truck bigRig;
	sedan.SetMileage(25);
	sedan.SetPassengers(5);
	sedan.display();
	cout << endl;
	bigRig.SetMileage(15);
	bigRig.SetPayload(200);
	bigRig.display();
	cout << "Press any key to exit..." << endl;
	getchar();
	return 0;
}