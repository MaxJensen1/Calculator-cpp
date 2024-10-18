#pragma once
#include "Math.h"
#include <Windows.h>
#include <string>
#include <sstream>
#include <algorithm> // For std::any_of
#include <cctype>    // For std::isalpha
#include <vector>
#include <chrono>

class UI: public Math
{
public:
	void Run();

private:
	void HandleInput();
	void PrintResult();
	bool SplitString(std::string input);

private:
	Math calculator;
	bool running = true;
	char operator_;
	double value1;
	double value2;
	double ans;
};