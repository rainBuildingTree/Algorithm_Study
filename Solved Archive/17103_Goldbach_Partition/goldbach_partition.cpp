#include <iostream>
#include <vector>
using namespace std;

/*
MAIN:
    1. CREATE prime archive [0, 1 000 000]
    2. GET order_count
    3. WHILE: repeat for order_count
    4. GET input
    5. FOR: serach for range ]input/2, input[ in decending order.
        5.1. IF recently searched number is prime check whether so does (input - searched number).
            5.1.1. IF yes, partition_count++
    6. CHECK IF input/2 is prime; IF yes, partition_count++
    7. PRINT partition_count
    8. REPEAT from 3
*/

void set_nonprime_false(vector<bool>& vec, int size) {
    vec[0] = false;
    vec[1] = false;
    for (int i = 2; i < size; ++i) {
        if (vec[i]) {
            bool deleted = false;
            for (int j = 2; i*j < size; ++j) {
                if (vec[i*j]) {
                    vec[i*j] = false;
                    deleted = true;
                }
            }
            if (!deleted)
                return;
        }
    }
}

int count_goldbach_partition(const int input, const vector<bool>& database) {
    int count = 0;
    for (int i = (input-1); i >= (input/2); --i) {
            if ((database[i]) && (database[input-i]))
                ++count;
        }
    return count;
}

int main() {
    const int DATABASE_SIZE = 1000001;
    vector<bool> prime_database(DATABASE_SIZE, true);
    set_nonprime_false(prime_database, DATABASE_SIZE);

    int order_count;
    cin >> order_count;

    while (order_count--) {
        int input;
        cin >> input;
        cout << count_goldbach_partition(input, prime_database) << '\n';
    }
    return 0;
}