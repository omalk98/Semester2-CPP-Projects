#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds {
const int MAX_LABEL_LENGTH = 70;
const int MAX_FRAME_CHARS = 8;
   class Label {
	   char m_frame[MAX_FRAME_CHARS + 1];
	   char* m_content;
   public:
	   Label();
	   Label(const char*);
	   Label(const char*, const char*);
	   ~Label();
	   void readLabel();
	   std::ostream& printLabel()const;
   };
}
#endif
