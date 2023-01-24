#include "TimedTask.h"

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
	}
	std::ostream& operator<<(std::ostream& ostr, TimedTask& timedtask)
	{
		return ostr;
	}
}