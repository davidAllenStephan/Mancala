int getArrayHighestIndex(int array[], int size) {
    int index = 0;
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            index = i;
        }
    }
    return index;
}