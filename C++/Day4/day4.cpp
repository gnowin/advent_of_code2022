#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inputFile("input.txt");
    std::string line;

    int times = 0;

    while (getline(inputFile, line))
    {
        int seperator = line.find(',');

        std::string lineLeft = line.substr(0, seperator);
        std::string lineRight = line.substr(seperator + 1, line.length() - seperator - 1);

        seperator = lineLeft.find('-');
        int taskOneStart = stoi(lineLeft.substr(0, seperator));
        int taskOneEnd = stoi(lineLeft.substr(seperator + 1, lineLeft.length() - seperator - 1));

        seperator = lineRight.find('-');
        int taskTwoStart = stoi(lineRight.substr(0, seperator));
        int taskTwoEnd = stoi(lineRight.substr(seperator + 1, lineRight.length() - seperator - 1));

        if (taskOneStart <= taskTwoStart && taskTwoEnd <= taskOneEnd)
        {
            times++;
        }
        else if (taskTwoStart <= taskOneStart && taskOneEnd <= taskTwoEnd)
        {
            times++;
        }
        else if (taskOneStart >= taskTwoStart && taskOneStart <= taskTwoEnd)
        {
            times++;
        }
        else if (taskTwoStart >= taskOneStart && taskTwoStart <= taskOneEnd)
        {
            times++;
        }
    }

    std::cout << times << std::endl;
}