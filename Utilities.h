/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef UTILITIES_H
#define UTILITIES_H
#include<iostream>
#include<string>
#include <iomanip>
#include <utility>



	class Utilities 
	{
		size_t m_widthField = 1;
		static char m_delimiter;

	public:
		
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();

	};


#endif // !SDDS_UTILITIES_H
