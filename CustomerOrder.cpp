/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "CustomerOrder.h"


size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder()
{
	setSafeState();

}

CustomerOrder::CustomerOrder(const std::string& record)
{
	setSafeState();
	Utilities tmp;
	bool more = true;
	size_t next_pos = 0;
	std::vector<Item*> lstitem;



	
	m_name = tmp.extractToken(record, next_pos, more);
	m_product = tmp.extractToken(record, next_pos, more);
	


	do
	{
	

			lstitem.push_back(std::move(new Item(tmp.extractToken(record, next_pos, more))));
			m_cntItem++;
			


		
	} while (more);

	
	m_lstItem = new Item * [m_cntItem];
	
	for (auto i = 0u; i < m_cntItem; ++i)
	{
		m_lstItem[i] = lstitem[i];
	}


	if (m_widthField < tmp.getFieldWidth())
		CustomerOrder::m_widthField = tmp.getFieldWidth();



}

CustomerOrder::CustomerOrder(const CustomerOrder& src)
{
	throw std::string("ERROR: Cannot make copies.");
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
{
	setSafeState();
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
{
	if (this != &src)
	{
		if (m_lstItem)
		{

			for (auto i = 0u; i < m_cntItem; ++i)
			{

				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}

			delete[] m_lstItem;
			m_lstItem = nullptr;

		}
		m_lstItem = src.m_lstItem;

		m_cntItem = src.m_cntItem;

		m_name = src.m_name;

		m_product = src.m_product;


		src.m_lstItem = nullptr;
		src.m_cntItem = 0u;
		src.m_name = "";
		src.m_product = "";



	}

	return *this;
}

CustomerOrder::~CustomerOrder()
{
	for (auto i = 0u; i < m_cntItem; ++i)
	{
		delete m_lstItem[i];
		
	}
	
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::isOrderFilled() const
{
	bool isOrderFilled = true;

	for (auto i = 0u; i < m_cntItem; ++i)
	{
		if (m_lstItem[i]->m_isFilled == false)
		{
			isOrderFilled = false;
			break;
		}
	}


	return isOrderFilled;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const
{

	bool isFilled = true;

	for (auto i = 0u; i < m_cntItem; ++i)
		if (m_lstItem[i]->m_itemName.compare(itemName) == 0)
			isFilled = m_lstItem[i]->m_isFilled;


	return isFilled;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os)
{
	for (auto i = 0u; i < m_cntItem; ++i)
	{
		if (m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0)
		{
			if (station.getQuantity() >= 1)
			{
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;

				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}

			else
			{
				os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream& os) const
{



	os << m_name << " - " << m_product << std::endl;

	for (auto i = 0u; i < m_cntItem; ++i)
	{
		os << "[" << std::setw(6) << std::right << std::setfill('0')  << m_lstItem[i]->m_serialNumber << "] " << std::left << std::setfill(' ')
			<< std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
	}
}

void CustomerOrder::ResizeArray(size_t size)
{

	Item** resized = new Item * [size];
	for (auto i = 0u; i < size - 1; ++i)
		resized[i] = m_lstItem[i];

	delete[] m_lstItem;
	m_lstItem = nullptr;

	m_lstItem = resized;



}

void CustomerOrder::setSafeState()
{
	m_lstItem = nullptr;
	m_name = "";
	m_product = "";
	m_cntItem = 0u;
}
