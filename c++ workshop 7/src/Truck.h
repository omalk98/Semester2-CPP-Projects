#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"
#include <iostream>
namespace sdds {
	class Truck : public MotorVehicle {
		double m_MAX_KG_CAPACITY;
		double m_currentCapacity;
		void setMaxCargo(double maxCargo);
		void setCurrentCargo(double cargo = 0);
	public:
		Truck();
		Truck(const char* lp, unsigned int year, double capacity, const char* loc = "Factory");
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator <<(std::ostream& os, const Truck& vehicle);
	std::istream& operator >>(std::istream& in, Truck& vehicle);
}
#endif //!SDDS_TRUCK_H