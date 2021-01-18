/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Utilities.h"

	

	void Utilities::setFieldWidth(size_t newWidth)
	{
		this->m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string token(str); 
		more = false;

		if (next_pos < token.length()) // if string is smaller than next_pos
		{
			token = token.substr(next_pos);

			if (token.find(m_delimiter) != std::string::npos)
			{
				more = true;
				token = token.substr(0, token.find(m_delimiter));
				
				if (m_widthField < token.length())
					this->m_widthField = token.length();
			
			}
		}

		else
		{
			token = token.substr(0, token.length());
		}


		if (token.empty())
		{
			throw std::string("No Data Detected!");
		}

		next_pos = next_pos + token.length() + 1;

		return token;


	}
	
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

	
	
	char Utilities::m_delimiter = ','; // define static variable
