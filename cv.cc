// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2024 Steffen A. Mork

#include <cstdlib>
#include <cstdio>
#include <thread>
#include <mutex>
#include <condition_variable>

#include <unistd.h>

int main()
{
	std::mutex              mutex;
	std::condition_variable cv;
	std::thread             thread([&]()
	{
		printf("T> Thread start with locking.\n");
		std::unique_lock<std::mutex> lock(mutex);

		printf("T> Waiting for notification...\n");
		cv.wait(lock);
		printf("T> End.\n");
	});

	printf("M> Waiting...\n");
	sleep(2);
	printf("M> Notifying...\n");
	cv.notify_all();
	printf("M> Joining...\n");
	thread.join();
	printf("M> End.\n");

	return EXIT_SUCCESS;
}
