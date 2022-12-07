#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class directory
{
private:
    int recursiveLeastEnough(int size, directory *curDir, int *leastEnough, int totalSize)
    {
        int sum = curDir->sizeOfFiles;
        for (size_t i = 0; i < curDir->subDirs.size(); i++)
        {
            sum += recursiveLeastEnough(curDir->sizeOfFiles, curDir->subDirs[i], leastEnough, totalSize);
        }
        if (sum >= 30000000 - (70000000 - totalSize))
        {
            if ((sum <= *leastEnough) || (*leastEnough == 0))
            {
                *leastEnough = sum;
            }
        }

        return sum;
    }

    int recursiveLessThan(int size, directory *curDir, int *lessThanSum)
    {
        int sum = curDir->sizeOfFiles;
        for (size_t i = 0; i < curDir->subDirs.size(); i++)
        {
            sum += recursiveLessThan(curDir->sizeOfFiles, curDir->subDirs[i], lessThanSum);
        }
        if (sum <= 100000)
        {
            *lessThanSum += sum;
        }

        return sum;
    }
    int recursiveSize(int size, directory *curDir)
    {
        int sum = curDir->sizeOfFiles;
        for (size_t i = 0; i < curDir->subDirs.size(); i++)
        {
            sum += recursiveSize(curDir->sizeOfFiles, curDir->subDirs[i]);
        }
        return sum;
    }

public:
    std::string name;
    int sizeOfFiles;
    directory *parentDir;
    std::vector<directory *> subDirs;
    directory(std::string name)
    {
        directory::name = name;
        directory::sizeOfFiles = 0;
        directory::parentDir = nullptr;
    }

    int getDirSize()
    {
        return recursiveSize(0, this);
    }

    int getDirLessThanSum()
    {
        int sum = 0;
        recursiveLessThan(0, this, &sum);
        return sum;
    }

    int getDirLeastEnough()
    {
        int totalSize = getDirSize();
        int sum = 0;
        recursiveLeastEnough(0, this, &sum, totalSize);
        return sum;
    }
};

int main()
{
    std::ifstream inputFile("input.txt");
    std::string line;

    directory *curDir;

    while (getline(inputFile, line))
    {
        // std::cout << line << std::endl;

        if (line.substr(0, 4) == "$ cd")
        {
            std::string name = line.substr(5);

            if (name == "..")
            {
                curDir = curDir->parentDir;
            }
            else
            {
                if (curDir != nullptr)
                {
                    for (size_t i = 0; i < curDir->subDirs.size(); i++)
                    {
                        if (curDir->subDirs[i]->name == name)
                        {
                            curDir = curDir->subDirs[i];
                        }
                    }
                }
                else
                {
                    directory *temp = new directory(name);
                    curDir = temp;
                }
                // std::cout << curDir->name << std::endl;
            }
        }
        else if (line.substr(0, 4) != "$ ls")
        {
            if (line.substr(0, 3) == "dir")
            {
                directory *temp = new directory(line.substr(4));
                temp->parentDir = curDir;
                curDir->subDirs.push_back(temp);
            }
            else
            {
                // std::cout << line.substr(0, line.find(' ')) << std::endl;
                int fileSize = std::stoi(line.substr(0, line.find(' ')));
                curDir->sizeOfFiles += fileSize;
            }
        }
    }

    while (curDir->parentDir != nullptr)
    {
        curDir = curDir->parentDir;
    }

    std::cout << curDir->getDirSize() << std::endl;
    std::cout << curDir->getDirLessThanSum() << std::endl;
    std::cout << curDir->getDirLeastEnough() << std::endl;
    std::cout << "hello???" << std::endl;
}
