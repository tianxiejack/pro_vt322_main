/*
 * main.cpp
 *
 *  Created on: 2019年5月8日
 *      Author: d
 */
#include "EventManager.hpp"

int main()
{
	CEventParsing parsing;
	CEventManager* eventManager = new CEventManager();
	std::thread T1(CEventParsing::thread_jsEvent);
	std::thread T2(CEventParsing::thread_comrecvEvent);
	std::thread T3(CEventParsing::thread_comsendEvent);
	std::thread T4(CEventParsing::thread_Getaccept);
	std::thread T5(CEventParsing::thread_ReclaimConnect);

	struct timeval tmp;
	while(1)
	{
		tmp.tv_sec = 1;
		tmp.tv_usec = 0;
		select(0, NULL, NULL, NULL, &tmp);
	}

	T1.join();
	T2.join();
	T3.join();
	T4.join();
	T5.join();
	return 0;
}

