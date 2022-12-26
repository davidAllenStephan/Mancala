void determineWinnerStats(int winner, int value[])
{

    if (winner == 0)
    {
        value[0] += 1;
    }
    else if (winner == 1)
    {
        value[1] += 1;
    }
    else if (winner == 2)
    {
        value[2] += 1;
    }
}
