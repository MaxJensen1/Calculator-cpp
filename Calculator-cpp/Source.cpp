#pragma once
#include "Math.h"
#include <chrono>
#include <cstdint>

int main()
{
	Math math;
	std::chrono::high_resolution_clock::time_point start;
	start = std::chrono::high_resolution_clock::now();

	std::cout << math.Power(math.Calculate(18446744073709551615, 18446744073709551615, '*'), 6);

	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = now - start;
	std::cout << "\nOperation took: " << elapsed.count() << " seconds.";
}