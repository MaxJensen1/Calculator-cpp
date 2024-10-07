#include "Math.h"

double Math::Calculate(double value1, double value2, char operation)
{
    switch (operation)
    {
    case '+':
        return value1 + value2;
        break;

    case '-':
        return value1 - value2;
        break;

    case '*':
        return value1 * value2;
        break;

    case '/':
        return value1 / value2;
        break;

    default:
        return 0;
    }
}

double Math::Power(double value, uint8_t exponent)
{
    double result = value;
    for (int i = 0; i < exponent; i++)
    {
        result *= value;
    }

    return result;
}