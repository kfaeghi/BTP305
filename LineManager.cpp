/*
Name: Khashayar Faeghi
Senca Email: kfaeghi@myseneca.ca
Seneca Id: 125630186
Date:  11/28/2020

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#include "LineManager.h"



LineManager::LineManager()
{
	m_linemanagercnt = 0u;
	m_cntCustomerOrder = 0u;
	m_firstWorkstation = nullptr;
}

LineManager::LineManager(const std::string& filename, std::vector<Workstation*> workstations, std::vector<CustomerOrder>& customerorders)
{
	m_linemanagercnt = 0u;
	m_cntCustomerOrder = 0u;
	m_firstWorkstation = nullptr;
	try
	{
		
		Utilities utl;
		bool first = false;
		bool more = false;
		size_t next_pos = 0u;

		std::move(customerorders.begin(), customerorders.end(), std::back_inserter(toBeFilled));
		std::copy(workstations.begin(), workstations.end(), std::back_inserter(AssemblyLine));

		m_cntCustomerOrder = toBeFilled.size();

		std::ifstream file(filename);
		if(!file)
			throw std::string("Error In Opening [") + filename + "] file.";

		
		auto find_work = [&](std::string itemname)
		{
			Workstation* tmp = nullptr;
			for (auto& i : as_const(AssemblyLine))
			{
				if (i->getItemName().compare(itemname) == 0)
				{
					tmp = i;
					break;
				}

			}
			return tmp;
		};
		
		
		while (!file.eof())
		{
			more = true;
			next_pos = 0u;
			std::string record;

			std::getline(file, record);
			std::string name = utl.extractToken(record, next_pos, more);

			while (more)
			{
				Workstation* wrk = find_work(name);
				if (first == false)
				{
					
					m_firstWorkstation = wrk;
					sorted.push_back(wrk);
					first = true;
				}
				
				else if(more)
				{
					std::string temp = utl.extractToken(record, next_pos, more);
					Workstation* next_wrk = find_work(temp);

					wrk->setNextStation(*next_wrk);
					sorted.push_back(next_wrk);
					name = temp;
					wrk = next_wrk;
				}

				
			}
			
		}

		file.close();




		
	}

	catch (std::string error)
	{
		std::cerr << error << std::endl;
	}
}

LineManager::~LineManager()
{
	m_firstWorkstation = nullptr;
}



bool LineManager::run(std::ostream& os)
{
	m_linemanagercnt++;
	os << "Line Manager Iteration: " << m_linemanagercnt << std::endl;


	CustomerOrder ordertoFill{};
	bool flag = false;

	if (!toBeFilled.empty())
	{
		*m_firstWorkstation += std::move(toBeFilled.front());
		toBeFilled.pop_front();
	}

	for (auto i : AssemblyLine)
		i->runProcess(os);

	for (auto i : sorted)
		i->moveOrder();

	for (auto i : AssemblyLine)
	{
		if (i->getIfCompleted(ordertoFill))
		{
			Completed.push_back(std::move(ordertoFill));
		}
	}

	if (Completed.size() == m_cntCustomerOrder)
		flag = true;
	
	return flag;
}

void LineManager::displayCompletedOrders(std::ostream& os) const
{
	for (const auto& i : as_const(Completed))
	{
		i.display(os);
	}
}

void LineManager::displayStations() const
{
	for (const auto& i : as_const(AssemblyLine))
	{
		i->display(std::cout);
	}
}

void LineManager::displayStationsSorted()
{
	



	for (const auto& i : as_const(sorted))
	{
		i->display(std::cout);
	}
}
