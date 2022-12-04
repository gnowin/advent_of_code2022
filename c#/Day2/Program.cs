using System;
using System.IO;
enum Moves
{
    None = 0,
    Rock = 1,
    Paper = 2,
    Scissors = 3
}
enum Results
{
    Lose = 0,
    Tie = 3,
    Win = 6
}

namespace Day2
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputPath = Environment.CurrentDirectory + "/input.txt";

            string input = File.ReadAllText(inputPath);

            string[] rounds = input.Split('\n');


            int scorePart1 = 0, scorePart2 = 0;
            foreach (var item in rounds)
            {
                Moves opponentMove = GetMove(item[0]);
                scorePart1 += getResult(opponentMove, GetMove(item[2]));
                scorePart2 += getResult(opponentMove, GetNewMove(opponentMove, item[2]));
            }
            Console.WriteLine("Score part 1: " + scorePart1);
            Console.WriteLine("Score part 2: " + scorePart2);
        }

        static Moves GetMove(char move)
        {
            if (move == 'A' || move == 'X')
            {
                return Moves.Rock;
            }
            else if (move == 'B' || move == 'Y')
            {
                return Moves.Paper;
            }
            else if (move == 'C' || move == 'Z')
            {
                return Moves.Scissors;
            }
            else
            {
                Console.WriteLine("Returned no move! Should not happen.");
                return Moves.None;
            }

        }

        static Moves GetNewMove(Moves opponent, char player)
        {
            if (player == 'Y')
            {
                return opponent;
            }

            if (opponent == Moves.Rock)
            {
                switch (player)
                {
                    case 'X':
                        return Moves.Scissors;
                    case 'Z':
                        return Moves.Paper;
                    default:
                        Console.WriteLine("case error");
                        return Moves.None;
                }
            }
            else if (opponent == Moves.Paper)
            {
                switch (player)
                {
                    case 'X':
                        return Moves.Rock;
                    case 'Z':
                        return Moves.Scissors;
                    default:
                        Console.WriteLine("case error");
                        return Moves.None;
                }
            }
            else if (opponent == Moves.Scissors)
            {
                switch (player)
                {
                    case 'X':
                        return Moves.Paper;
                    case 'Z':
                        return Moves.Rock;
                    default:
                        Console.WriteLine("case error");
                        return Moves.None;
                }
            }
            else
            {
                Console.WriteLine("if error");
                return Moves.None;
            }
        }


        static int getResult(Moves opponent, Moves player)
        {

            int playerPoints = (int)player;

            if (opponent == Moves.Rock)
            {
                switch (player)
                {
                    case Moves.Rock:
                        return playerPoints + (int)Results.Tie;
                    case Moves.Paper:
                        return playerPoints + (int)Results.Win;
                    case Moves.Scissors:
                        return playerPoints + (int)Results.Lose;
                    default:
                        Console.WriteLine("case error");
                        return 0;
                }
            }
            else if (opponent == Moves.Paper)
            {
                switch (player)
                {
                    case Moves.Rock:
                        return playerPoints + (int)Results.Lose;
                    case Moves.Paper:
                        return playerPoints + (int)Results.Tie;
                    case Moves.Scissors:
                        return playerPoints + (int)Results.Win;
                    default:
                        Console.WriteLine("case error");
                        return 0;
                }
            }
            else if (opponent == Moves.Scissors)
            {
                switch (player)
                {
                    case Moves.Rock:
                        return playerPoints + (int)Results.Win;
                    case Moves.Paper:
                        return playerPoints + (int)Results.Lose;
                    case Moves.Scissors:
                        return playerPoints + (int)Results.Tie;
                    default:
                        Console.WriteLine("case error");
                        return 0;
                }
            }
            else
            {
                Console.WriteLine("if error");
                return 0;
            }
        }


    }



}
