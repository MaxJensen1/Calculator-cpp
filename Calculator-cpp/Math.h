#pragma once
#include <iostream>
#include <string>
#include <cstdint>

class Math
{
public:
	double Calculate(double value1, double value2, char operation);
	double Power(double value, uint8_t exponent);
};