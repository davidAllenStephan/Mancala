int getArrayTotal(int array[], int length)
{

    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += array[i];
        array[i] = 0;
    }

    return total;
}