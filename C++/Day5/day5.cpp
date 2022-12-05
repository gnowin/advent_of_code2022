#include <iostream>
#include <fstream>
#include <vector>
#include <list>

int main()
{
    std::ifstream inputFile("input.txt");
    std::string line;
    std::vector<std::vector<int>> stacks;

    for (size_t i = 0; i < 5; i++)
    {
        std::vector<int> stack;
        stack.push_back(i);
        stacks.push_back(stack);
    }
    for (size_t row = stacks.begin(); row != stacks.end(); row++)
    {
        std::vector<int> temp = stacks.at(row);
        for (size_t col = temp.begin(); col != temp.end(); col++)
        {
            /* code */
        }
        }

    while (getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }
}

void moveTopOfStack()
{
}