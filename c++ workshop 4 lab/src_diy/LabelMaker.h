#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"
namespace sdds {
	class LabelMaker {
		Label* m_labels;
		int m_labelCount;
	public:
		LabelMaker();
		LabelMaker(int);
		~LabelMaker();
		void readLabels();
		void printLabels()const;
	};
}
#endif