

int getClosestIndex(int array[], int size) {
    
    int closest = size;
    
    for (int i = size-1 ; i >= 0; i--) {
        if (array[i] != 0) {
            closest = i;
            break;
        }
    }

    return closest;
}