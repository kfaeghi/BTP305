/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"



class Workstation : public Station
{
	std::deque<CustomerOrder> m_orders; 
	Workstation* m_pNextStation;

public:
	Workstation();
	Workstation(const std::string& str);

	//All copy and move must be deleted
	Workstation(const Workstation&) = delete;
	Workstation& operator = (const Workstation&) = delete;
	Workstation(Workstation&&) noexcept = delete;
	Workstation& operator = (Workstation&&) noexcept = delete;


	void runProcess(std::ostream& os);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream& os);
	Workstation& operator+=(CustomerOrder&&);
};
#endif // WORKSTATION_H