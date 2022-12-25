int getArrayLowestIndex(int array[], int size) {
    int index = 0;
    int min = 100;
    for (int i = 0; i < size; i++) {
        if (array[i] < min && array[i] != 0) {
            min = array[i];
            index = i;
        }
    }
    return index;
}