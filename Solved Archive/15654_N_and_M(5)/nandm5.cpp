#include <iostream>
using namespace std;

/***************************************************************
PSEUDO-CODE

resultArr[8]

printResult():
    FOR i = 0 to M-1
        PRINT resultArr[i]
    RETURN

formatResultArray(int begin, int end):
    FOR i = begin to end
        SET resultArr[i] to -1

printCombinations(int N, int M, int level, int target):
    IF not (level < M), THEN
        printResult()
        RETURN

    IF target is already in resultArr AND level is not -1, THEN
        RETURN

    IF level is not -1, THEN
        SET resultArr[level] to target

    FOR i = 1 to N
        formatResultArray(level+1, M)
        printCombinations(N, M, level+1, i)
    
    RETURN

main():
    GET user input of N and then M
    printCombinations(N, M, -1, -1)
    RETURN

***************************************************************/
int resultArr[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

void printResult(int M) {
    for (int i = 0; i < M; ++i) {
        cout << resultArr[i];
        if (i < (M-1))
            cout << ' ';
    }
    cout << '\n';
}

void formatResultArray(int begin, int end) {
    for (int i = begin; i < end; ++i)
        resultArr[i] = -1;
}

bool isAlreadyInResult(int M, int target) {
    for (int i = 0; i < M; ++i) {
        if (resultArr[i] == target)
            return true;
    }
    return false;
}

void printCombinations(int N, int M, int level, int target, int* referenceArr) {

    if (level != -1) {
        if (isAlreadyInResult(M, referenceArr[target]))
            return;

        resultArr[level] = referenceArr[target];
    }

    if (level == (M-1)) {
        printResult(M);
        return;
    }

    for (int i = 0; i < N; ++i) {
        formatResultArray(level+1, N);
        printCombinations(N, M, level+1, i, referenceArr);
    }
}
void BubbleSort(int* array, int length) {
    for (int i = 0; i < length-1; ++i)
        for (int j = i+1; j < length; ++j)
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int* referenceArr = new int[N];
    for (int i = 0; i < N; ++i)
        cin >> referenceArr[i];
    BubbleSort(referenceArr, N);


    printCombinations(N, M, -1, -1, referenceArr);

    delete [] referenceArr;
    return 0;
}