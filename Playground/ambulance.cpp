#include<bits/stdc++.h>
using namespace std;

struct ambulance {
    int deadline;
    int score;
};
bool camparator(ambulance a,ambulance b){
    return (a.score>b.score);
}
int checkSlot(int n, vector<int>& assigned) {
    int slot = -1;
    int i = 0;
    if(assigned[i] == -1) {
        slot = 1;
        assigned[i] = 1;
    }
    else {
        while(i <= n) {
            if(assigned[i] == -1) {
                slot = 1;
                assigned[i] = 1;
                break;
            }
            i++;
        }
    }
    return slot;
}

int solve(vector<ambulance>& arr) {
    sort(arr.begin(), arr.end(),camparator );

    int maxDeadline = 0;
    for(const auto& x : arr) {
        maxDeadline = max(maxDeadline, x.deadline);
    }

    vector<int> assigned(maxDeadline, -1);
    int totalScore = 0;
    for(int i = 0; i < arr.size(); i++) {
        int slot = checkSlot(arr[i].deadline - 1, assigned);
        if(slot > 0) {
            totalScore += arr[i].score;
        }
    }
    
    return totalScore;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int size;
        cin >> size;
        vector<ambulance> arr(size);
        for(int i = 0; i < size; i++) {
            cin >> arr[i].deadline >> arr[i].score;
        }
        int ans = solve(arr);
        cout << ans << endl;
    }
    return 0;
}
