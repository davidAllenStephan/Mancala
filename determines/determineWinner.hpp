
int determineWinner(int player_1_store, int player_2_store)
{
    if (player_1_store > player_2_store)
    {
        return 0;
    }
    if (player_1_store < player_2_store)
    {
        return 1;
    }
    return 2;
}
