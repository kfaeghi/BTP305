/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Workstation.h"

Workstation::Workstation()
{
	this->m_pNextStation = nullptr;
}

Workstation::Workstation(const std::string& str) : Station(str)
{
	m_pNextStation = nullptr;
}

auto Workstation::runProcess(std::ostream& os) -> void
{
	if (!m_orders.empty())
		m_orders.front().fillItem(*this, os);
}

auto Workstation::moveOrder() -> bool
{
	bool valid = false;

	if (m_orders.empty())
		return valid;


	valid = m_orders.front().isItemFilled(getItemName()) && m_pNextStation;

	if (valid)
	{
		*m_pNextStation += std::move(m_orders.front());
		m_orders.pop_front();
	}


	return valid;
}

auto Workstation::setNextStation(Station& station) -> void
{
	m_pNextStation = static_cast<Workstation*>(&station); // must cast to type Workstaion*
}

auto Workstation::getNextStation() const -> const Workstation*
{
	return m_pNextStation;
}

auto Workstation::getIfCompleted(CustomerOrder& order) -> bool
{
	bool valid = false;

	if (m_orders.empty())
		return false;

	valid = m_orders.front().isOrderFilled();

	if (valid)
	{
		order = std::move(m_orders.front());
		m_orders.pop_front();
	}

	return valid;
}

auto Workstation::display(std::ostream& os) -> void
{
	os << this->getItemName();
	if (!m_pNextStation)
		os << " --> END OF LINE" << std::endl;
	else
		os  << " --> " << m_pNextStation->getItemName() << std::endl;
}

auto Workstation::operator+=(CustomerOrder&& cx) -> Workstation&
{
	m_orders.push_back(std::move(cx));
	return *this;
}
