#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

void moveFromTo(std::list<char> *from, std::list<char> *to, int amount)
{
    for (size_t i = 0; i < amount; i++)
    {
        to->push_back(from->back());
        from->pop_back();
    }
}

void moveMultipleFromTo(std::list<char> *from, std::list<char> *to, int amount)
{

    std::list<char> temp;

    for (size_t i = 0; i < amount; i++)
    {
        temp.push_back(from->back());
        from->pop_back();
    }
    for (size_t i = 0; i < amount; i++)
    {
        to->push_back(temp.back());
        temp.pop_back();
    }
}

int main()
{
    std::ifstream inputFile("input2.txt");
    std::string line;
    std::vector<std::list<char>> stacks;

    int state = 0;
    int columnSize = 4;
    while (getline(inputFile, line))
    {
        int lineLength = line.length();
        if (line.find('[') == std::string::npos)
        {
            state = 2;
        }
        if (state == 0)
        {
            for (size_t i = 0; i < (lineLength + 1) / columnSize; i++)
            {
                stacks.push_back(std::list<char>());
            }
            state++;
        }
        if (state <= 1)
        {
            for (size_t i = 0; i * columnSize < lineLength; i++)
            {
                char letter = line[1 + (i * columnSize)];
                if (letter != ' ')
                {
                    stacks.at(i).push_front(letter);
                }
            }
        }
        else if (state > 1)
        {
            if (line.length() > 0 && line[0] != ' ')
            {
                std::stringstream text(line);
                std::string segment;
                std::vector<std::string> segments;

                while (getline(text, segment, ' '))
                {
                    segments.push_back(segment);
                }

                int from = stoi(segments[3]);
                int to = stoi(segments[5]);
                int amount = stoi(segments[1]);

                moveMultipleFromTo(&stacks[from - 1], &stacks[to - 1], amount);
            }
        }

        // std::cout << line << std::endl;
    }

    std::string output;

    for (size_t i = 0; i < stacks.size(); i++)
    {
        output += stacks[i].back();
        for (std::list<char>::iterator it = stacks[i].begin(); it != stacks[i].end(); ++it)
        {
            // std::cout << *it;
        }
        // std::cout << std::endl;
    }

    std::cout << output << std::endl;
}
