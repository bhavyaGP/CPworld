#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    int arr[r][c];

    // Reading the matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    int maxCount = 0;
    int maxRow = -1;
    for (int i = 0; i < r; i++)
    {
        int cnt = 0;
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                cnt++;
            }
        }
        if (cnt > maxCount)
        {
            maxCount = cnt;
            maxRow = i;
        }
    }
    if (maxRow != -1)
    {
        cout << maxRow + 1 << endl;
    }

    return 0;
}

// string str;
//     cin>>str;
//     int startcnt=0;
//     int hashcnt=0;
//     for(int i=0;i<str.length();i++){
//         if(str[i]=='*'){
//             startcnt++;
//         }
//         if(str[i]=='#'){
//             hashcnt++;
//         }
//     }
//     cout<<startcnt-hashcnt;