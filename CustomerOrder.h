/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include"Station.h"
#include <vector>


struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};




class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	size_t m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;

public:

	CustomerOrder();
	CustomerOrder(const std::string& inpt);
	
	//Move and Copy Constructors
	CustomerOrder(const CustomerOrder& src);      // Copy throws and exception if called
	CustomerOrder(CustomerOrder&& src) noexcept;  // Move
	
	//Move and Copy assigment operators
	CustomerOrder& operator=(const CustomerOrder& src) = delete;  //Copy
	CustomerOrder& operator=(CustomerOrder&& src) noexcept;       //Move

	~CustomerOrder();
	
	

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
	void ResizeArray(size_t size);
	void setSafeState();
	


};

#endif // !CUSTOMERORDER_H
