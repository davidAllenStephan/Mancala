int determineSideEmpty(int player_board[])
{
    int isActive = 0;
    for (int i = 0; i < 6; i++)
    {
        if (player_board[i] != 0)
        {
            isActive = 1;
        }
    }
    return isActive;
}