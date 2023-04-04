#include <iostream>
using namespace std;

bool IsAllPaired(int* wife, int peopleCount)
{
    bool isAllPaired = true;

    for (int i = 0; i < peopleCount; ++i)
        if (wife[i] < 0)
            isAllPaired = false;

    return isAllPaired; 
}

int FindUnpairedMan(int* wife, int peopleCount)
{
    for (int i = 0; i < peopleCount; ++i)
        if (wife[i] < 0)
            return i;
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Get number of men/women
    int peopleCount;
    cin >> peopleCount;
    
    // Make a men preference table
    int** menPref = new int*[peopleCount];
    for (int i = 0; i < peopleCount; ++i)
        menPref[i] = new int[peopleCount+1];
    
    for (int i = 0; i < peopleCount; ++i)
    {
        menPref[i][0] = 1;
        for (int j = 1; j <= peopleCount; ++j)
            cin >> menPref[i][j];
    }

    // Make a inversed women preference table
    int** inverseWomenPref = new int*[peopleCount];
    for (int i = 0; i < peopleCount; ++i)
        inverseWomenPref[i] = new int[peopleCount];
    
    for (int i = 0; i < peopleCount; ++i)
        for (int j = 0; j < peopleCount; ++j)
        {
            int temp;
            cin >> temp;
            inverseWomenPref[i][temp-1] = j;
        }

    // Make wife / husband arrays
    int* wife = new int[peopleCount];
    int* husband = new int[peopleCount];

    // Initialize with -1
    for (int i = 0; i < peopleCount; ++i)
    {
        wife[i] = -1;
        husband[i] = -1;
    }

    // Stable Marriage Algorithm
    while (!IsAllPaired(wife, peopleCount))
    {
        int man = FindUnpairedMan(wife, peopleCount);
        
        while (wife[man] < 0)
        {
            if (menPref[man][0] > peopleCount)
            {
                cout << "\n\nERROR: perfection broken\n\n";
                break;
            }

            int woman = menPref[man][menPref[man][0]] - 1;
            ++menPref[man][0];

            if (husband[woman] < 0)
            {
                wife[man] = woman;
                husband[woman] = man;
            }
            else if (inverseWomenPref[woman][man] < inverseWomenPref[woman][husband[woman]])
            {
                wife[man] = woman;
                wife[husband[woman]] = -1;
                husband[woman] = man;
            }
        }
    }

    for (int i = 0; i < peopleCount; ++i)
        cout << wife[i]+1 << '\n';


    // Deallocation of memory
    delete [] wife;
    delete [] husband;

    for (int i = 0; i < peopleCount; ++i)
    {
        delete [] menPref[i];
        delete [] inverseWomenPref[i];
    }
    delete [] menPref;
    delete [] inverseWomenPref;




    return 0;
}