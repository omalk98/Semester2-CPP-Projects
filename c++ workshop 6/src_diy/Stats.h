#include <iostream>
namespace sdds {
	class Stats {
		char* m_filename;
		double* m_numberList;
		unsigned m_noOfNumbers;
		unsigned m_columnWidth;
		unsigned m_noOfColumns;
		unsigned m_precision;
		double m_dummy;
		unsigned getSize();
		void setFilename(const char*, bool = false);
		void loadNumbers();
		void saveAs(const char*)const;
	public:
		Stats(unsigned columnWidth = 15,
			unsigned noOfColumns = 4,
			unsigned precision = 2);
		Stats(const char* filename,
			unsigned columnWidth = 15,
			unsigned noOfColumns = 4,
			unsigned precision = 2);
		Stats(const Stats&);
		Stats& operator=(const Stats&);
		~Stats();
		double& operator[](unsigned);
		double operator[](unsigned)const;
		operator bool()const;
		std::istream& getFile(std::istream&);
		std::ostream& display(std::ostream&)const;
		void sort(bool);
		unsigned size()const;
		const char* name()const;
		unsigned occurrence(double, double, std::ostream& ostr = std::cout);
	};
	std::ostream& operator<<(std::ostream&, const Stats&);
	std::istream& operator>>(std::istream&, Stats&);
}
