

int getFarthestIndex(int array[], int size) {

    int farthest = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] != 0) {
            farthest = i;
            break;
        }
    }

    return farthest;


}