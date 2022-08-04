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
    //0
    int M, N;
    cin >> M >> N;

    if (N == 1)
        return 0;

    //1
    bool* prime_array = new bool[N+1];
    
    //2
    prime_array[0] = false;
    prime_array[1] = false;
    for (int i = 2; i <= N; ++i)
        prime_array[i] = true;
    
    //3
    for (int i = 2; i <= N; ++i) {
        if (prime_array[i] == true) {
            bool there_is_something_to_delete = (i*2 <= N);
            bool something_deleted = false;
            if (there_is_something_to_delete)
                for (int j = 2; j*i <= N; ++j)
                    if (prime_array[j*i] == true) {
                        something_deleted = true;
                        prime_array[j*i] = false;
                    }
            if (!something_deleted)
                break; 
        }
    }

    for (int i = M; i <= N; ++i) {
        if (prime_array[i] == true)
            cout << i << '\n';
    }

    return 0;
}