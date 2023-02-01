//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: January 21, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include "TimedTask.h"

using namespace std;
namespace sdds
{
	TimedTask& TimedTask::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();

		return *this;
	}

	TimedTask& TimedTask::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();

		return *this;
	}

	TimedTask& TimedTask::addTask(const char* taskName)
	{
		if (taskName && taskName[0])
		{
			string taskName_s(taskName);
			m_task[m_records].m_taskName = taskName_s;
			m_task[m_records].m_timeUnit = "nanoseconds";
			m_task[m_records].m_taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
			m_records++;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const TimedTask& timedTask)
	{
		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;
		for (int i{ 0 }; i < timedTask.m_records; i++)
		{
			ostr << setw(21) << left << timedTask.m_task[i].m_taskName
					<< setw(13) << right << timedTask.m_task[i].m_taskDuration.count() << " " 
					<< timedTask.m_task[i].m_timeUnit << endl;
		}
		ostr << "--------------------------" << endl;
		return ostr;
	}
}