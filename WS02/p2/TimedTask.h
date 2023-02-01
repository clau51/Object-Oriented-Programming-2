//Name: Carmen Lau
//Student ID: 166689216
//Email: clau51@myseneca.ca
//Date: January 21, 2023
//Section: NDD
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

#include <chrono>
#include <string>

namespace sdds
{
	const int MAX_TASK = 10;

	struct Task
	{
		std::string m_taskName{};
		std::string m_timeUnit{};
		std::chrono::steady_clock::duration m_taskDuration{};
	};

	class TimedTask
	{
		int m_records{};
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		Task m_task[MAX_TASK]{};

	public:
		TimedTask() = default;
		TimedTask& startClock();
		TimedTask& stopClock();
		TimedTask& addTask(const char* taskName);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& timedTask);
	};

}

#endif