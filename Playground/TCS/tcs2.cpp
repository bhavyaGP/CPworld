#include <bits/stdc++.h>
using namespace std;

int calculateWorth(const string &str)
{
    int worth = 0;
    for (char c : str)
    {
        worth += (c - 'a' + 1);
    }
    return worth;
}
bool isValidCombination(vector<int> &combination, vector<string> &strings,unordered_map<string, unordered_set<string>> &contradictoryPairs)
{
    for (size_t i = 0; i < combination.size(); i++)
    {
        if (combination[i] == 0)
            continue;

        for (size_t j = i + 1; j < combination.size(); j++)
        {
            if (combination[j] == 0)
                continue;

            if (contradictoryPairs.count(strings[i]) &&
                contradictoryPairs.at(strings[i]).count(strings[j]))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> strings(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> strings[i];
    }

    vector<int> costs(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> costs[i];
    }

    unordered_map<string, unordered_set<string>> contradictoryPairs;
    for (int i = 0; i < M; ++i)
    {
        string str1, str2;
        cin >> str1 >> str2;
        contradictoryPairs[str1].insert(str2);
        contradictoryPairs[str2].insert(str1);
    }

    int budget;
    cin >> budget;

    vector<int> worths(N);
    for (int i = 0; i < N; i++)
    {
        worths[i] = calculateWorth(strings[i]);
    }
    int maxWorth = 0;
    int totalCombinations = 1 << N;

    for (int mask = 0; mask < totalCombinations; mask++)
    {
        vector<int> currentCombination(N);
        int totalCost = 0;
        int totalWorth = 0;

        // Convert mask to combination
        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            {
                currentCombination[i] = 1;
                totalCost += costs[i];
                totalWorth += worths[i];
            }
        }

        if (totalCost <= budget &&
            isValidCombination(currentCombination, strings, contradictoryPairs))
        {
            maxWorth = max(maxWorth, totalWorth);
        }
    }

    cout << maxWorth << endl;
    return 0;
}