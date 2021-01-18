/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include"Workstation.h"
#include<deque>
#include<fstream>


class LineManager 
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> toBeFilled;
	std::deque<CustomerOrder> Completed;
	size_t m_cntCustomerOrder;
	size_t m_linemanagercnt;
	Workstation* m_firstWorkstation;
	std::vector<Workstation*> sorted;

public:
	LineManager();
	LineManager(const std::string& filename, std::vector<Workstation*> workstations, std::vector<CustomerOrder>& customerorders);
	~LineManager();
	
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted();

};

#endif // !LINEMANAGER_H
