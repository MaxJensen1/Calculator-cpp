#include "UI.h"

void UI::Run()
{
    while (running)
    {
        HandleInput();
        PrintResult();
    }
}

void UI::HandleInput()
{
    std::cout << "Enter calcualtion with the format\nvalue1 { + | - | * | / } value2.\n";

    std::string input;
    std::getline(std::cin, input);

    bool containsLetter = std::any_of(input.begin(), input.end(), [](char c)
    {
         return std::isalpha(c);
    });
    
    if (containsLetter) // If it contains a letter, restart
    {
        system("CLS");
        std::cout << "Invalid input: Input contains letters. Please enter numbers and operators only.\n";
        HandleInput();
    }
    else if (input.find(' ') == std::string::npos) // If it doesn't have a space, restart
    {
        system("CLS");
        std::cout << "Invalid input: Must contain spaces between the operator and numbers.\n";
        HandleInput();
    }
    else if (input.find('+') != std::string::npos || input.find('-') != std::string::npos ||
             input.find('*') != std::string::npos || input.find('/') != std::string::npos)
    {
        if (!SplitString(input))
        {
            system("CLS");
            std::cout << "Parsing falied because of wrong format.\n";
            HandleInput();
        }
    }
    else
    {
        system("CLS");
        std::cout << "Invalid input.\n";
        HandleInput();
    }
}

bool UI::SplitString(std::string input)
{
    std::istringstream iss(input);
    std::string word;
    std::vector<std::string> parts;

    while (iss >> word) // Take one word at a time from the string stream and add to the array, it's splitting on spaces
    {
        parts.push_back(word);
    }

    if (parts.size() != 3 || parts[1].length() != 1) // Makes sure that there are three parts before trying to parse
    {
        return false;
    }

    try
    {
        value1 = std::stod(parts[0]);
        operator_ = (parts[1])[0];
        value2 = std::stod(parts[2]);

        return true;
    }
    catch (const std::invalid_argument& e)
    {
        return false;
    }
}

void UI::PrintResult()
{
    if (operator_ == '/' && value2 == 0)
    {
        std::cout << "Error: Can't divide by zero.\n";
    }
    else
    {
        double totalTime = 0;

        for (int i = 0; i < timesToCalculate; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            ans = calculator.Calculate(value1, value2, operator_);
            auto now = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = now - start;

            totalTime += elapsed.count();
        }
        
        double averageTime = totalTime / timesToCalculate;
        std::cout << value1 << " " << operator_ << " " << value2 << " = " << ans << "\n";
        std::cout << "\Performed operation " << timesToCalculate << " times. Average time: " << averageTime << " seconds (" << averageTime * 1000 << " milliseconds).";
    }

    std::cin.get();
    system("CLS");
}