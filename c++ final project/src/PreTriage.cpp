//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 5
// Date:		   Apr 6, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "Menu.h"
#include "Patient.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	void PreTriage::reg() {
		int sel = -1;
		Patient* patient;
		if (m_lineupSize >= maxNoOfPatients) cout << "Line up full!\n";
		else {
			m_pMenu.operator>>(sel);
			switch (sel) {
			case 0:
				break;
			case 1:
				patient = new CovidPatient;
				break;
			case 2:
				patient = new TriagePatient;
				break;
			}
			if (sel == 1 || sel == 2) {
				patient->setArrivalTime();
				patient->fileIO(false);
				cout << "Please enter patient information: \n";
				cin >> *patient;
				cout << "\n******************************************\n" << *patient
					<< "Estimated Wait Time: " << getWaitTime(*patient)
					<< "\n******************************************\n\n";
				m_lineup[m_lineupSize++] = patient;
			}
		}
	}
	void PreTriage::admit() {
		int sel = -1, idx = 0;
		char type[]{ 'C', 'T' };
		m_pMenu.operator>>(sel);
		if (sel == 1 || sel == 2) {
			idx = indexOfFirstInLine(type[sel - 1]);
			m_lineup[idx]->fileIO(false);
			cout << "\n******************************************\nCalling for " 
				<< *m_lineup[idx]
				<< "******************************************\n\n";
			setAverageWaitTime(*m_lineup[idx]);
			removePatientFromLineup(idx);
		}
	}
	const Time PreTriage::getWaitTime(const Patient& p) const {
		unsigned int cnt = 0;
		for (unsigned i = 0; i < static_cast<unsigned>(m_lineupSize); ++i)
			if (m_lineup[i]->type() == p.type()) ++cnt;
		return (p.type() == 'C') ? m_averCovidWait * cnt : m_averTriageWait * cnt;
	}
	void PreTriage::setAverageWaitTime(const Patient& p) {
		if (p.type() == 'C')
			m_averCovidWait = ((getTime() - static_cast<int>(p.operator Time()))
				+ static_cast<int>(m_averCovidWait * static_cast<unsigned>(p.number() - 1))) 
				/ p.number();
		else if (p.type() ==  'T')
			m_averTriageWait = ((getTime() - static_cast<int>(p.operator Time()))
				+ static_cast<int>(m_averTriageWait * static_cast<unsigned>(p.number() - 1)))
				/ p.number();
	}
	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	int PreTriage::indexOfFirstInLine(char type) const {
		int idx = -1;
		for (auto i = 0; i < m_lineupSize; ++i)
			if (type == m_lineup[i]->type()) { idx = i; break; }
		return idx;
	}
	void PreTriage::load() {
		char type = 0;
		cout << "Loading data...\n";
		ifstream fptr(m_dataFilename);
		Patient* patient;
		if (fptr) {
			fptr >> m_averCovidWait >> type >> m_averTriageWait;
			fptr.ignore();
			while(m_lineupSize < maxNoOfPatients && !fptr.eof()) {
				fptr.get(type);
				fptr.ignore();
				switch (type) {
					case 'C': patient = new CovidPatient;
						break;
					case 'T': patient = new TriagePatient;
						break;
				}
				if (type == 'C' || type == 'T') {
					patient->fileIO(true);
					patient->csvRead(fptr);
					patient->fileIO(false);
					m_lineup[m_lineupSize++] = patient;
					type = 0;
				}
			}
			if (m_lineupSize == 100) cout << "Warning: number of records exceeded 100\n";
			if (m_lineupSize == 0) cout << "No data or bad data file!\n\n";
			else cout << m_lineupSize << " Records imported...\n\n";
		}
	}
	PreTriage::PreTriage(const char* dataFilename)
		: m_averCovidWait(15), m_averTriageWait(5),
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		if (dataFilename) {
			m_dataFilename = new char[strlen(dataFilename) + 1];
			strcpy(m_dataFilename, dataFilename);
		}
		else m_dataFilename = nullptr;
		load();
	}
	PreTriage::~PreTriage() {
		ofstream file(m_dataFilename);
		file << m_averCovidWait << "," << m_averTriageWait << endl;
		cout << "Saving Average Wait Times,\n   COVID Test: " << m_averCovidWait
			<< "\n   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup...\n";
		for (auto i = 0; i < m_lineupSize; ++i) {
			m_lineup[i]->csvWrite(file);
			file << endl;
			cout << i + 1 << "- ";
			m_lineup[i]->csvWrite(cout);
			cout << endl;
			delete m_lineup[i];
			m_lineup[i] = nullptr;
		}
		file.close();
		delete[] m_dataFilename;
		m_dataFilename = nullptr;
		cout << "done!\n";
	}
	void PreTriage::run(void) {
		int sel = -1;
		while (sel != 0) {
			m_appMenu.operator>>(sel);
			switch (sel)
			{
			case 0:
				break;
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			}
		}
	}
}
