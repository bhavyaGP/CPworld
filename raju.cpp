#include <iostream>
#include <vector>
using namespace std;

int findMaximumZeroes(vector<int> &arr)
{
    int n = arr.size();
    int maxZeroes = 0;
    for (int i = 0; i < n; ++i)
    {
        int minValue = arr[0];
        for (int j = 1; j <= i; ++j)
        {
            minValue = min(minValue, arr[j]);
        }
        for (int j = 0; j <= i; ++j)
        {
            arr[j] -= minValue;
        }
        int currentZeroes = 0;
        for (int j = 0; j < n; ++j)
        {
            if (arr[j] == 0)
            {
                currentZeroes++;
            }
        }
        maxZeroes = max(maxZeroes, currentZeroes);
    }

    return maxZeroes;
}

int main()
{
    vector<int> arr;
    int size;
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }
    int result = findMaximumZeroes(arr);
    cout << result << endl;

    return 0;
}
