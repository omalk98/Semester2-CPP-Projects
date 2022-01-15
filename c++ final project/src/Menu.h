#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds {
	class Menu {
		char* m_text;
		int m_noOfSel;
		void display()const;
	public:
		Menu();
		Menu(const char* MenuContent, int NoOfSelections);
		virtual ~Menu();
		int& operator>>(int& Selection);
		Menu(const Menu& copy);
		Menu& operator=(const Menu& copy) = delete;
	};
}
#endif //!SDDS_MENU_H