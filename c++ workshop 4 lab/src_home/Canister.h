#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H
#include <iostream>
namespace sdds {
   class Canister {
      char* m_contentName;
      double m_diameter; 
      double m_hieght;
      double m_contentVolume;
      bool m_usable;
      void setToDefault();
      void setName(const char*);
      bool isEmpty()const;
   public:
      Canister();
      Canister(const char*);
      Canister(double, double,
         const char* = nullptr);
      ~Canister();
      Canister& setContent(const char*);
      Canister& pour(double);
      Canister& pour(Canister&);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
}

#endif // !SDDS_BOX_H
