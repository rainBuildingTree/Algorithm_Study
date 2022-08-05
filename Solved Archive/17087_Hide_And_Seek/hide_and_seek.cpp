#include <iostream>
using namespace std;

/*
    1. CALCULATE the distances between Sujin and her bros
    2. FIND GCD for distances
    3. PRINT it
    4. SUCCESS
*/

int get_gcd(int a, int b) {
    if (b == 0)
        return a;
    return get_gcd(b, a%b);
}

int get_max(int a, int b) {
    return ((a >= b) ? a : b);
}
int get_min(int a, int b) {
    return ((a <= b) ? a : b);
}

int main() {

    int bro_count, sujin_loc;
    cin >> bro_count >> sujin_loc;

    int* bro_dists = new int[bro_count];
    for (int i = 0; i < bro_count; ++i) {
        cin >> bro_dists[i];
        bro_dists[i] = bro_dists[i] - sujin_loc;
        if (bro_dists[i] < 0)
            bro_dists[i] *= -1;
    }

    if (bro_count == 1) {
        cout << bro_dists[0];
        return 0;
    }

    int larger = get_max(bro_dists[0], bro_dists[1]);
    int smaller = get_min(bro_dists[0], bro_dists[1]);
    int current_gcd = get_gcd(larger, smaller);

    for (int i = 2; i < bro_count; ++i) {
        int larger = get_max(bro_dists[i], current_gcd);
        int smaller = get_min(bro_dists[i], current_gcd);
        current_gcd = get_gcd(larger, smaller);
    }   
    cout << current_gcd;


    return 0;
}