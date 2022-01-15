#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>

namespace sdds {
	class MotorVehicle {
		char m_licensePlate[9];
		char m_currentAddress[64];
		unsigned int m_yearManufactured;
	protected:
		void setaddress(const char* address = "Factory");
		void setlp(const char* lp);
		void setyear(unsigned int year);
	public: 
		MotorVehicle();
		MotorVehicle(const char* lp, unsigned int year, const char* loc = "Factory");
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);
}
#endif //!SDDS_MOTORVEHICLE_H