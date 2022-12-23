
int determineAddToPlayerStore(int playerStore[2], int playerTurn, int originalPlayerTurn, int extra)
{
    if (playerTurn == originalPlayerTurn)
    {
        playerStore[originalPlayerTurn] += 1;
    }
    else if (playerTurn != originalPlayerTurn)
    {
        extra++;
    }
    return extra;
}
