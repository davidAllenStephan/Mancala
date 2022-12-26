int getAllTotal(int playerBoard[][6], int playerStore[]) {
    int total = 0;
    for (int i = 0; i < 6; i++) {
        total += playerBoard[0][i];
    }
    for (int i = 0; i < 6; i++) {
        total += playerBoard[1][i];
    }
    for (int i = 0; i < 2; i++) {
        total += playerStore[i];
    }

    return total;
}