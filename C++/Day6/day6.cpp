#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main()
{
    std::ifstream inputFile("input.txt");
    std::string line;
    std::string substr;
    std::unordered_set<char> charSet;
    int sequenceAmount = 4;

    getline(inputFile, line);

    for (size_t i = 0; i < line.length(); i++)
    {
        substr = line.substr(i, sequenceAmount);
        int length = substr.length();
        for (size_t i = 0; i < length; i++)
        {
            charSet.insert(substr[i]);
        }

        if (charSet.size() == sequenceAmount)
        {
            std::cout << i + sequenceAmount << std::endl;
            break;
        }
        charSet.clear();
    }
}