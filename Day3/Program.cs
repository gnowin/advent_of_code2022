
using Microsoft.VisualBasic.CompilerServices;
string inputPath = Environment.CurrentDirectory + "/input.txt";
string[] rucksacks = File.ReadAllLines(inputPath);


int sum = 0, sumPart2 = 0;
foreach (var rucksack in rucksacks)
{
    int halfStringLength = rucksack.Length / 2;
    string compartmentOne = rucksack.Substring(0, halfStringLength);
    string compartmentTwo = rucksack.Substring(halfStringLength, halfStringLength);

    foreach (var c in compartmentOne)
    {
        if (compartmentTwo.Contains(c))
        {
            sum += getPriority(c);
            break;
        }
    }
}

for (int i = 0; i < rucksacks.Count(); i += 3)
{
    HashSet<char> set1 = rucksacks[i].ToHashSet<char>();
    HashSet<char> set2 = rucksacks[i + 1].ToHashSet<char>();
    HashSet<char> set3 = rucksacks[i + 2].ToHashSet<char>();

    set1.IntersectWith(set2);
    set1.IntersectWith(set3);

    sumPart2 += getPriority(set1.First());
}

Console.WriteLine(sum);
Console.WriteLine(sumPart2);


static int getPriority(char letter)
{
    if (letter == char.ToLower(letter))
    {
        return (int)letter % (int)'a' + 1;
    }
    else
    {
        return (int)letter % (int)'A' + 27;
    }
}
