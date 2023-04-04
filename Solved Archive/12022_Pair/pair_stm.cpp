#include <iostream>
#include <stack>
using namespace std;

int main()
{
    //==================================================
    /* CONFIG */

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /* CONFIG END */
    //==================================================



    //==================================================
    /* INPUT */

    int peopleCount;
    cin >> peopleCount;
    
    int** menPref = new int*[peopleCount];
    for (int i = 0; i < peopleCount; ++i)
        menPref[i] = new int[peopleCount];

    for (int i = 0; i < peopleCount; ++i)
        for (int j = 0; j < peopleCount; ++j)
            cin >> menPref[i][j];

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

    /* INPUT END */
    //==================================================



    //==================================================
    /* DATA */

    int* prefIndex = new int[peopleCount];
    for (int i = 0; i < peopleCount; ++i)
        prefIndex[i]= 0;

    int* wife = new int[peopleCount];
    int* husband = new int[peopleCount];
    for (int i = 0; i < peopleCount; ++i)
    {
        wife[i] = 0;
        husband[i] = 0;
    }

    stack<int> unpairedMen;
    for (int i = 1; i <= peopleCount; ++i)
        unpairedMen.push(i);

    /* DATA END */
    //==================================================



    //==================================================
    /* PROCESS */

    while (!unpairedMen.empty())
    {
        int man = unpairedMen.top();
        int manIndex = man - 1;
        unpairedMen.pop();
        
        while (wife[manIndex] == 0)
        {
            int woman = menPref[manIndex][prefIndex[manIndex]];
            int womanIndex = woman - 1;
            ++prefIndex[manIndex];

            if (husband[womanIndex] == 0)
            {
                wife[manIndex] = woman;
                husband[womanIndex] = man;
            }
            else
            {
                int victim = husband[womanIndex];
                int victimIndex = victim - 1;

                if (inverseWomenPref[womanIndex][manIndex] < inverseWomenPref[womanIndex][victimIndex])
                {
                    wife[victimIndex] = 0;
                    unpairedMen.push(victim);

                    wife[manIndex] = woman;
                    husband[womanIndex] = man;
                }
            }
        }
    }

    /* PROCESS END */
    //==================================================



    //==================================================
    /* OUTPUT */

    for (int i = 0; i < peopleCount; ++i)
        cout << wife[i] << '\n';

    /* OUTPUT END*/
    //==================================================



    //==================================================
    /* MEMORY DEALLOCATION */

    delete [] wife;
    delete [] husband;
    for (int i = 0; i < peopleCount; ++i)
    {
        delete [] menPref[i];
        delete [] inverseWomenPref[i];
    }
    delete [] menPref;
    delete [] inverseWomenPref;
    delete [] prefIndex;

    /* MEMORY DEALLOCATION END */
    //==================================================



    //==================================================
    /* RETURN */
    return 0;
}