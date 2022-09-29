#include <iostream>
#include <string>
using namespace std;

/*
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.
*/

int check_longest(char** table, const int table_size) {
    int longest_len = 0;
    for (int i = 0; i < table_size; ++i) {
        int current_len = 1;
        char current_color = 0;
        for (int j = 0; j < table_size; ++j) {
            if (table[i][j] != current_color) {
                longest_len = (longest_len < current_len) ? current_len : longest_len;
                current_len = 1;
                current_color = table[i][j];
                continue;
            }
            ++current_len;
        }
        longest_len = (longest_len < current_len) ? current_len : longest_len;
    }

    for (int j = 0; j < table_size; ++j) {
        int current_len = 1;
        char current_color = 0;
        for (int i = 0; i < table_size; ++i) {
            if (table[i][j] != current_color) {
                longest_len = (longest_len < current_len) ? current_len : longest_len;
                current_len = 1;
                current_color = table[i][j];
                continue;
            }
            ++current_len;
        }
        longest_len = (longest_len < current_len) ? current_len : longest_len;
    }
    return longest_len;
}

void print_table(char** table, int table_size) {
    for (int i = 0; i < table_size; ++i) {
        for (int j = 0; j < table_size; ++j)
            cout << table[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void print_current_loc(char** table, int table_size, int i_loc, int j_loc) {
    for (int i = 0; i < table_size; ++i) {
        for (int j = 0; j < table_size; ++j)
            if ( (i == i_loc) && (j == j_loc) )
                cout << "* ";
            else
                cout << table[i][j] << ' ';
                
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, longest_len = 1;
    cin >> n;
    char** table = new char*[n];
    
    for (int i = 0; i < n; ++i) {
        table[i] = new char[n];
        string temp_input;
        cin >> temp_input;
        for (int j = 0; j < n; ++j)
            table[i][j] = temp_input[j];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != n-1)
                if (table[i][j] != table[i][j+1]) {
                    char temp = table[i][j];
                    table[i][j] = table[i][j+1];
                    table[i][j+1] = temp;
                    int max_len = check_longest(table, n);
                    longest_len = (longest_len < max_len) ? max_len : longest_len;
                    temp = table[i][j];
                    table[i][j] = table[i][j+1];
                    table[i][j+1] = temp;
                    
                }
            if (i != n-1)
                if (table[i][j] != table[i+1][j]) {
                    char temp = table[i][j];
                    table[i][j] = table[i+1][j];
                    table[i+1][j] = temp;
                    int max_len = check_longest(table, n);
                    longest_len = (longest_len < max_len) ? max_len : longest_len;
                    temp = table[i][j];
                    table[i][j] = table[i+1][j];
                    table[i+1][j] = temp;
                    
                }
        }
    }

    cout << longest_len << '\n';
    

    // deallocate memory
    for (int i = 0; i < n; ++i) {
        delete [] table[i];
        table[i] = nullptr;
    }
    delete [] table;
    table = nullptr;

    return 0;
}