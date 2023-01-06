#include <iostream>
using namespace std;

/*****************************************************
PSUEDO-CODE


*******************************************************/

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
        if (isAlreadyInResult(M, target))
            return;

        resultArr[level] = target;
    }

    if (level == (M-1)) {
        printResult(M);
        return;
    }

    for (int i = ((target == -1) ? 1 : (target+1)); i <= N; ++i) {
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