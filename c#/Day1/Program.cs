// See https://aka.ms/new-console-template for more information

string path = Environment.CurrentDirectory + "/input.txt";

String input = File.ReadAllText(path);

String[] caloriesList = input.Split('\n');

LinkedList<UInt32> elvesCalories = new LinkedList<UInt32>();
UInt32 tempCalories = 0;
foreach (var line in caloriesList)
{

    if (line.Any(char.IsDigit))
    {
        tempCalories += Convert.ToUInt32(line);
    }
    else
    {
        if (elvesCalories.First != null)
        {
            LinkedListNode<UInt32> node = elvesCalories.First!;
            bool run = true;
            while (run)
            {
                if (node.Value < tempCalories)
                {
                    elvesCalories.AddBefore(node, tempCalories);
                    run = false;
                }
                else if (node.Next == null)
                {
                    elvesCalories.AddBefore(node, tempCalories);
                    run = false;
                }
                else if (node == null)
                {
                    run = false;
                }
                else
                {
                    node = node.Next!;
                }
            }
        }
        else
        {
            elvesCalories.AddFirst(tempCalories);
        }
        tempCalories = 0;
    }
}

UInt64 temp = 0;
for (int i = 0; i < 3; i++)
{
    temp += elvesCalories.ElementAt(i);
}
Console.WriteLine(temp);
