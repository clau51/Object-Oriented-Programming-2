#include <iostream>
#include <iomanip>
#include "TimedTask.h"

using namespace std;
namespace sdds
{
	void TimedTask::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* taskName)
	{
		if (taskName && taskName[0])
		{
			string s_taskName(taskName);
			task[m_records].m_taskName = s_taskName;
			task[m_records].m_timeUnit = "nanoseconds";
			task[m_records].m_taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
			m_records++;
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const TimedTask& timedTask)
	{
		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;
		for (int i = 0; i < timedTask.m_records; i++)
		{
			ostr << setw(21) << left << timedTask.task[i].m_taskName
					<< setw(13) << right << timedTask.task[i].m_taskDuration.count() << " " 
					<< timedTask.task[i].m_timeUnit << endl;
		}
		ostr << "--------------------------" << endl;
		return ostr;
	}
}