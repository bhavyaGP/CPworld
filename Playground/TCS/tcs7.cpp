#include <bits/stdc++.h>
using namespace std;

// Function to check if coordinates are within bounds
bool isValid(int ly, int y, int x, int s) {
    return ly >= 0 && ly < s && y >= 0 && y < s && x >= 0 && x < s;
}

// Function to trace band path and mark in cube
vector<vector<vector<int>>> tracePath(int startLy, int startY, int startX, 
                                    const string& moves, int bandNum, int s) {
    vector<vector<vector<int>>> path(s, vector<vector<int>>(s, vector<int>(s, 0)));
    int ly = startLy, y = startY, x = startX;
    
    // Mark starting position
    path[ly][y][x] = bandNum;
    
    // Follow movement sequence
    for (char move : moves) {
        switch (move) {
            case 'u': y--; break;
            case 'd': y++; break;
            case 'f': ly++; break;
            case 'b': ly--; break;
            case 'r': x++; break;
            case 'l': x--; break;
        }
        
        if (!isValid(ly, y, x, s)) {
            // Invalid path - out of bounds
            return vector<vector<vector<int>>>();
        }
        path[ly][y][x] = bandNum;
    }
    
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s;
    cin >> s;
    
    int ly1, y1, x1;
    cin >> ly1 >> y1 >> x1;
    
    string band1;
    cin >> band1;
    
    int ly2, y2, x2;
    cin >> ly2 >> y2 >> x2;
    
    string band2;
    cin >> band2;
    
    // Trace paths for both bands
    auto path1 = tracePath(ly1, y1, x1, band1, 1, s);
    auto path2 = tracePath(ly2, y2, x2, band2, 2, s);
    
    // Check if either path is invalid
    if (path1.empty() || path2.empty()) {
        cout << "Impossible\n";
        return 0;
    }
    
    // Combine paths and check for intersections
    vector<vector<vector<int>>> cube(s, vector<vector<int>>(s, vector<int>(s, 0)));
    bool hasOverlap = false;
    int maxHeight = 0;
    
    // First, check for direct overlaps
    for (int ly = 0; ly < s; ly++) {
        for (int y = 0; y < s; y++) {
            for (int x = 0; x < s; x++) {
                if (path1[ly][y][x] && path2[ly][y][x]) {
                    cout << "Impossible\n";
                    return 0;
                }
                cube[ly][y][x] = path1[ly][y][x] + path2[ly][y][x];
            }
        }
    }
    
    // Check vertical alignments for height differences
    for (int ly = 0; ly < s; ly++) {
        for (int x = 0; x < s; x++) {
            vector<pair<int, int>> band1Points, band2Points;
            
            // Collect points for both bands in this vertical line
            for (int y = 0; y < s; y++) {
                if (path1[ly][y][x]) band1Points.push_back({y, 1});
                if (path2[ly][y][x]) band2Points.push_back({y, 2});
            }
            
            // If both bands exist in this vertical line
            if (!band1Points.empty() && !band2Points.empty()) {
                hasOverlap = true;
                for (auto &p1 : band1Points) {
                    int y1 = p1.first;
                    int band1 = p1.second;
                    for (auto &p2 : band2Points) {
                        int y2 = p2.first;
                        int band2 = p2.second;
                        maxHeight = max(maxHeight, abs(y1 - y2));
                    }
                }
            }
        }
    }
    
    if (!hasOverlap) {
        cout << "Impossible\n";
    } else {
        cout << maxHeight << "\n";
    }
    
    return 0;
}