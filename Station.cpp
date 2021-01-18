/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Station.h"



    size_t Station::id_generator = 0;
    size_t Station::m_widthField = 0;
    
  
    Station::Station()
    {
        setSafeState();

    }

    Station::Station(const std::string& record)
    {
        
        setSafeState();
        
        ++id_generator;
        m_stationID = id_generator;
        
        
        size_t next_pos = 0;
        bool more = true;
        Utilities utl;
        

        while (more)
        {
            m_itemName = utl.extractToken(record, next_pos, more);
            m_serialNumb = std::stoi(utl.extractToken(record, next_pos, more));
            m_stockQty = std::stoi(utl.extractToken(record, next_pos, more));
            m_stationDesc = utl.extractToken(record, next_pos, more);

            if (this->m_widthField < utl.getFieldWidth())
            {
                this->m_widthField = utl.getFieldWidth();
            }

        }

        if (this->m_widthField < utl.getFieldWidth())
            m_widthField = utl.getFieldWidth();
        
        

        }

    const std::string& Station::getItemName() const
    {
        return this->m_itemName;
    }

    unsigned int Station::getNextSerialNumber()
    {
        return this->m_serialNumb++;
    }

    unsigned int Station::getQuantity() const
    {
        return this->m_stockQty;
    }

    void Station::updateQuantity()
    {
        if (m_stockQty > 0)
            --m_stockQty;
    }

    void Station::display(std::ostream& os, bool full) const
    {
        if (full)
        {
            os << "[" << std::setw(3) << std::setfill('0') << std::right << this->m_stationID << "]" << std::setfill(' ');

            os << " Item: " << std::setw(m_widthField) << std::left << getItemName();

            os << " [" << std::setw(6) << std::setfill('0') << std::right << this->m_serialNumb << "]" << std::setfill(' ');

            os << " Quantity: " << std::setw(m_widthField) << std::left << getQuantity();

            os << " Description: " << this->m_stationDesc << std::endl;

        }

        else 
        {
            os << "[" << std::setw(3) << std::setfill('0') << std::right << this->m_stationID << "]" << std::setfill(' ');

            os << " Item: " << std::setw(m_widthField) << std::left << getItemName();

            os << " [" << std::setw(6) << std::setfill('0') << std::right << this->m_serialNumb << "]" << std::setfill(' ') << std::endl;
           
       
            
   
            
            
            
            
            //os << std::setfill('0') << this->m_stationID << std::unse
            //os << "]";
            //os << std::setw(m_widthField) << " Item: " << getItemName();
            //os << std::setw(6) << "[" << this->m_serialNumb << "]" << std::endl;
        }

        
    }

    void Station::setSafeState()
    {
        m_itemName = "";
        m_serialNumb = 0u;
        m_stationDesc = "";
        m_stockQty = 0u;
    }



    