/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef STATION_H
#define STATION_H



#include "Utilities.h"


	class Station
	{
		int m_stationID;
		std::string m_itemName;
		std::string m_stationDesc;
		size_t m_serialNumb;
		size_t m_stockQty;
		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station();
		Station(const std::string& record);
		const std::string& getItemName() const;
		unsigned int getNextSerialNumber();
		unsigned int getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
		void setSafeState();

	};
	


#endif // !SDDS_STATION_H
