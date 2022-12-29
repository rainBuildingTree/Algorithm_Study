#include <iostream>
using namespace std;
/*
Check all paper
    Use recursion
    Get the largest sum
    if earned sum is larger than global biggest then replace the biggest
    printout biggest
    return

    Type: Bar, Cube, L, S, T
    Direction: Right, Down, Left, Up
    RRR DDD LLL UUU
    RDL DLU LUR URD
    RRU DDR LLD UUL
    RUR DRD LDL ULU
    R(RD) D(DL) L(LU) U(UR)
*/
enum TetrominoType {BAR=0, CUBE, L, S, T};
enum TetrominoDire {RIGHT=0, DOWN, LEFT, UP};
const int PAPER_DIMENSION = 2;

int checkAndReturn(int** paper, int N, int M, int row, int col) {
    if ((row < 0) || (row >= N) || (col < 0) || (col >= M))
        return -1;
    return paper[row][col];
}

int findSum(int** paper, int N, int M, int row, int col, TetrominoType type, TetrominoDire dire) {
    int sum = paper[row][col];
    int add1, add2, add3;
    int add4 = -1; int add5 = -1; int add6 = -1;

    if (type == BAR) {
        if (dire == RIGHT) {
            add1 = checkAndReturn(paper, N, M, row, col+1);
            add2 = checkAndReturn(paper, N, M, row, col+2);
            add3 = checkAndReturn(paper, N, M, row, col+3);
        }
        else if (dire == DOWN) {
            add1 = checkAndReturn(paper, N, M, row+1, col);
            add2 = checkAndReturn(paper, N, M, row+2, col);
            add3 = checkAndReturn(paper, N, M, row+3, col);
        }
        else if (dire == LEFT) {
            add1 = checkAndReturn(paper, N, M, row, col-1);
            add2 = checkAndReturn(paper, N, M, row, col-2);
            add3 = checkAndReturn(paper, N, M, row, col-3);
        }
        else if (dire == UP) {
            add1 = checkAndReturn(paper, N, M, row-1, col);
            add2 = checkAndReturn(paper, N, M, row-2, col);
            add3 = checkAndReturn(paper, N, M, row-3, col);
        }
    }
    else if (type == CUBE) { // RDL DLU LUR URD
        if (dire == RIGHT) {
            add1 = checkAndReturn(paper, N, M, row, col+1);
            add2 = checkAndReturn(paper, N, M, row+1, col+1);
            add3 = checkAndReturn(paper, N, M, row+1, col);
        }
        else if (dire == DOWN) {
            add1 = checkAndReturn(paper, N, M, row+1, col);
            add2 = checkAndReturn(paper, N, M, row+1, col-1);
            add3 = checkAndReturn(paper, N, M, row, col-1);
        }
        else if (dire == LEFT) {
            add1 = checkAndReturn(paper, N, M, row, col-1);
            add2 = checkAndReturn(paper, N, M, row-1, col-1);
            add3 = checkAndReturn(paper, N, M, row-1, col);
        }
        else if (dire == UP) {
            add1 = checkAndReturn(paper, N, M, row-1, col);
            add2 = checkAndReturn(paper, N, M, row-1, col+1);
            add3 = checkAndReturn(paper, N, M, row, col+1);
        }
    }
    else if (type == L) { // RRU DDR LLD UUL
        if (dire == RIGHT) {
            add1 = checkAndReturn(paper, N, M, row, col+1);
            add2 = checkAndReturn(paper, N, M, row, col+2);
            add3 = checkAndReturn(paper, N, M, row-1, col+2);
            add4 = add1;
            add5 = add2;
            add6 = checkAndReturn(paper, N, M, row+1, col+2);
        }
        else if (dire == DOWN) {
            add1 = checkAndReturn(paper, N, M, row+1, col);
            add2 = checkAndReturn(paper, N, M, row+2, col);
            add3 = checkAndReturn(paper, N, M, row+2, col+1);
            add4 = add1;
            add5 = add2;
            add6 = checkAndReturn(paper, N, M, row+2, col-1);
        }
        else if (dire == LEFT) {
            add1 = checkAndReturn(paper, N, M, row, col-1);
            add2 = checkAndReturn(paper, N, M, row, col-2);
            add3 = checkAndReturn(paper, N, M, row+1, col-2);
            add4 = add1;
            add5 = add2;
            add6 = checkAndReturn(paper, N, M, row-1, col-2);
        }
        else if (dire == UP) {
            add1 = checkAndReturn(paper, N, M, row-1, col);
            add2 = checkAndReturn(paper, N, M, row-2, col);
            add3 = checkAndReturn(paper, N, M, row-2, col-1);
            add4 = add1;
            add5 = add2;
            add6 = checkAndReturn(paper, N, M, row-2, col+1);
        }
    }
    else if (type == S) { // RUR DRD LDL ULU
        if (dire == RIGHT) {
            add1 = checkAndReturn(paper, N, M, row, col+1);
            add2 = checkAndReturn(paper, N, M, row-1, col+1);
            add3 = checkAndReturn(paper, N, M, row-1, col+2);
            add4 = add1;
            add5 = checkAndReturn(paper, N, M, row+1, col+1);
            add6 = checkAndReturn(paper, N, M, row+1, col+2);
        }
        else if (dire == DOWN) {
            add1 = checkAndReturn(paper, N, M, row+1, col);
            add2 = checkAndReturn(paper, N, M, row+1, col+1);
            add3 = checkAndReturn(paper, N, M, row+2, col+1);
            add4 = add1;
            add5 = checkAndReturn(paper, N, M, row+1, col-1);
            add6 = checkAndReturn(paper, N, M, row+2, col-1);
        }
        else if (dire == LEFT) {
            add1 = checkAndReturn(paper, N, M, row, col-1);
            add2 = checkAndReturn(paper, N, M, row+1, col-1);
            add3 = checkAndReturn(paper, N, M, row+1, col-2);
            add4 = add1;
            add5 = checkAndReturn(paper, N, M, row-1, col-1);
            add6 = checkAndReturn(paper, N, M, row-1, col-2);
        }
        else if (dire == UP) {
            add1 = checkAndReturn(paper, N, M, row-1, col);
            add2 = checkAndReturn(paper, N, M, row-1, col-1);
            add3 = checkAndReturn(paper, N, M, row-2, col-1);
            add4 = add1;
            add5 = checkAndReturn(paper, N, M, row-1, col+1);
            add6 = checkAndReturn(paper, N, M, row-2, col+1);
        }
    }
    else if (type == T) { //R(RD) D(DL) L(LU) U(UR)
        if (dire == RIGHT) {
            add1 = checkAndReturn(paper, N, M, row, col+1);
            add2 = checkAndReturn(paper, N, M, row, col+2);
            add3 = checkAndReturn(paper, N, M, row+1, col+1);
            add4 = add1;
            add5 = add2;
            add6 = checkAndReturn(paper, N, M, row-1, col+1);
        }
        else if (dire == DOWN) {
            add1 = checkAndReturn(paper, N, M, row+1, col);
            add2 = checkAndReturn(paper, N, M, row+2, col);
            add3 = checkAndReturn(paper, N, M, row+1, col-1);
            add4 = add1;
            add5 = add2;
            add3 = checkAndReturn(paper, N, M, row+1, col+1);
        }
        else if (dire == LEFT) {
            add1 = checkAndReturn(paper, N, M, row, col-1);
            add2 = checkAndReturn(paper, N, M, row, col-2);
            add3 = checkAndReturn(paper, N, M, row-1, col-1);
            add4 = add1;
            add5 = add2;
            add3 = checkAndReturn(paper, N, M, row+1, col-1);
        }
        else if (dire == UP) {
            add1 = checkAndReturn(paper, N, M, row-1, col);
            add2 = checkAndReturn(paper, N, M, row-2, col);
            add3 = checkAndReturn(paper, N, M, row-1, col+1);
            add4 = add1;
            add5 = add2;
            add3 = checkAndReturn(paper, N, M, row-1, col-1);
        }
    }
    if (((add1 < 0) || (add2 < 0) || (add3 < 0)) && ((add4 < 0) || (add5 < 0) || (add6 < 0)))
        return 0;
    int candidateA = add1 + add2 + add3;
    int candidateB = add4 + add5 + add6;
    sum += (candidateA < candidateB) ? candidateB : candidateA;
    return sum;
}

int findBiggestSum(int** paper, int N, int M, int row, int col) {
    int biggest = 0;

    for (int type = 0; type < 5; ++type)
        for (int dire = 0; dire < 4; ++dire) {
            int temp = findSum(paper, N, M, row, col, static_cast<TetrominoType>(type), static_cast<TetrominoDire>(dire));
            biggest = (biggest < temp) ? temp : biggest;
        }

    return biggest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, biggest = 0;
    cin >> N >> M;
    int** paper = new int*[N];
    for (int i = 0; i < N; ++i) {
        paper[i] = new int[M];
        for (int j = 0; j < M; ++j)
            cin >> paper[i][j];
    }

    for (int row = 0; row < N; ++row)
        for (int col = 0; col < M; ++col) {
            int temp = findBiggestSum(paper, N, M, row, col);
            biggest = (biggest < temp) ? temp : biggest;
        }

    cout << biggest << '\n';

    for (int i = 0; i < N; ++i) {
        delete [] paper[i];
        paper[i] = nullptr;
    }
    delete [] paper;

    return 0;
}