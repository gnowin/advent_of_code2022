
string inputPath = Environment.CurrentDirectory + "/input.txt";
string[] rucksacks = File.ReadAllLines(inputPath);


int sum = 0;
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

Console.WriteLine(sum);


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
