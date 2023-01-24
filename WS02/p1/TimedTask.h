#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

#include <chrono>
#include <string>

namespace sdds
{
	struct Task
	{
		std::string m_taskName{};
		std::string m_timeUnit{};
		std::chrono::steady_clock::duration m_taskDuration{};
	};

	class TimedTask
	{
		static int m_records;
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		Task* task{};

	public:
		TimedTask() = default;
		void startClock();
		void stopClock();
		void addTask(const char* taskName);
		friend std::ostream& operator<<(std::ostream& ostr, TimedTask& timedtask);
	};

}

#endif