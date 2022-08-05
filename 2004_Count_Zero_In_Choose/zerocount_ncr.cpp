#include <iostream>
using namespace std;

int main() {
    long long input_m, input_n;
    // F: factorial, M: minus.
    long long five_count_nF = 0, five_count_mF = 0, five_count_nMmF = 0;
    long long two_count_nF = 0, two_count_mF = 0, two_count_nMmF = 0;
    cin >> input_n >> input_m;

    for (long long i = 5; i <= input_n; i = i*5)
        five_count_nF += (input_n / i);
    for (long long i = 2; i <= input_n; i = i*2)
        two_count_nF += input_n / i;

    for (long long i = 5; i <= input_m; i = i*5)
        five_count_mF += input_m / i;
    for (long long i = 2; i <= input_m; i = i*2)
        two_count_mF += input_m / i;
    
    for (long long i = 5; i <= input_n - input_m; i = i*5)
        five_count_nMmF += (input_n-input_m) / i;
    for (long long i = 2; i <= input_n - input_m; i = i*2)
        two_count_nMmF += (input_n-input_m) / i;
    
    long long total_five_count = five_count_nF - five_count_mF - five_count_nMmF;
    long long total_two_count = two_count_nF - two_count_mF - two_count_nMmF;
    cout << (((total_five_count) <= (total_two_count)) ? (total_five_count) : (total_two_count));

    return 0;
}