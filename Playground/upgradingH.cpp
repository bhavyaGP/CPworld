#include <bits/stdc++.h>
using namespace std;

vector<int> gradingStudents(vector<int> grades)
{
    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i] >= 38)
        {
            int remainder = grades[i] % 5;
            if (remainder >= 3)
            {
                grades[i] += 5 - remainder;
            }
        }
    }
    return grades;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> result = gradingStudents(v);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}