#include <bits/stdc++.h>
using namespace std;
int main()
{

    int N, M, K;
    cin >> N >> M >> K;
    int arr[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[N][M];
        }
    }
    vector<vector<int>> query(K);
    for (int i = 0; i < K; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 4; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        query.push_back(temp);
    }


    

}