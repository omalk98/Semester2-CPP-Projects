#ifndef SDDS_MARK_H
#define SDDS_MARK_H
namespace sdds {
	class Mark {
		int m_value;
	public:
		Mark();
		Mark(int);
		operator int()const;
		operator double()const;
		operator char()const;
		Mark& operator +=(int);
		Mark& operator =(int);

	};
	int operator +=(int&, Mark&);
}
#endif