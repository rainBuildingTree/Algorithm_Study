#include <iostream>
using namespace std;

/*
MAIN:
    0. get user input to set M and N
    1. create an integer array with size of N+1
    2. put -1 into array[0] and array[1]
    2. put numbers into the array according to the index (from array[2])
    3. scan for whole array
        3-1. if a number recently scanned is not -1, then delete all numbers, which are multiples of the number, from the array
        3-2. in the case of 3-1, if all the multiples are already deleted from the array, then finish the scan.
    4. print the members of the array, which are bigger than M and not -1. (Newline should be inserted between printing each members)
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    if (N == 1)
        return 0;

    int* prime_array = new int[N+1];
    
    prime_array[0] = -1;
    prime_array[1] = -1;

    for (int i = 2; i <= N; ++i) {
        if (prime_array[i] != -1) {
            bool there_is_something_to_delete = (i*2 <= N);
            bool something_deleted = false;
            if (there_is_something_to_delete)
                for (int j = 2; j*i <= N; ++j)
                    if (prime_array[j*i] != -1) {
                        something_deleted = true;
                        prime_array[j*i] = -1;
                    }
            if (!something_deleted)
                break; 
        }
    }

    for (int i = M; i < N; ++i) {
        if (prime_array[i] != -1)
            cout << i << '\n';
    }

    return 0;
}