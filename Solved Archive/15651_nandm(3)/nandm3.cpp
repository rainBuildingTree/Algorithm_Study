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

void printCombinations(int N, int M, int level, int target) {

    if (level != -1) {
        /*if (isAlreadyInResult(M, target))
            return;*/

        resultArr[level] = target;
    }

    if (level == (M-1)) {
        printResult(M);
        return;
    }

    for (int i = 1; i <= N; ++i) {
        formatResultArray(level+1, N);
        printCombinations(N, M, level+1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    printCombinations(N, M, -1, -1);

    return 0;
}