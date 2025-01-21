#include <bits/stdc++.h>
using namespace std;

class VaishnaviGame {
private:
    // Direction arrays for movement (up, right, down, left)
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    int n, m, k;
    vector<vector<char>> grid;
    int startX, startY;

    // Helper function to check if position is valid
    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    // Helper function to check if position is stable
    bool isStable(int x, int y) {
        if (x == n - 1) return true;  // Last row is stable
        return grid[x + 1][y] == 'B'; // Check for building below
    }

    // Apply gravity to current position
    pair<int, int> applyGravity(int x, int y) {
        while (x + 1 < n && grid[x + 1][y] != 'B') {
            x++;
            if (isStable(x, y)) break;
        }
        return {x, y};
    }

    // Calculate Manhattan distance between two points
    int getManhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    // Constructor to initialize the game
    VaishnaviGame() {
        readInput();
    }

    // Read input from standard input
    void readInput() {
        cin >> n >> m;
        grid = vector<vector<char>>(n, vector<char>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'S') {
                    startX = i;
                    startY = j;
                    grid[i][j] = 'E';  // Convert S to E for consistent processing
                }
            }
        }
        cin >> k;
    }

    // Structure to represent state in BFS
    struct State {
        int x, y, moves;
        State(int _x, int _y, int _m) : x(_x), y(_y), moves(_m) {}
    };

    // Find and print solution
    void solve() {
        // BFS to find reachable positions
        queue<State> q;
        map<pair<int, int>, int> visited;
        map<pair<int, int>, int> reachable;

        // Apply gravity to starting position
        auto start = applyGravity(startX, startY);
        q.push(State(start.first, start.second, 0));
        visited[start] = 0;

        // BFS exploration
        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            // If current position is stable and not in last row
            if (isStable(curr.x, curr.y) && curr.x < n - 1) {
                if (reachable.find({curr.x, curr.y}) == reachable.end() || 
                    reachable[{curr.x, curr.y}] > curr.moves) {
                    reachable[{curr.x, curr.y}] = curr.moves;
                }
            }

            // Try all possible moves
            for (int dir = 0; dir < 4; dir++) {
                int newX = curr.x + dx[dir];
                int newY = curr.y + dy[dir];

                if (isValid(newX, newY) && grid[newX][newY] != 'B' && curr.moves + 1 <= k) {
                    auto nextPos = applyGravity(newX, newY);
                    
                    if (visited.find(nextPos) == visited.end() || 
                        visited[nextPos] > curr.moves + 1) {
                        visited[nextPos] = curr.moves + 1;
                        q.push(State(nextPos.first, nextPos.second, curr.moves + 1));
                    }
                }
            }
        }

        // Find maximum distance reachable positions
        vector<pair<int, int>> farthestCells;
        int maxDist = -1;

        for (const auto& pos : reachable) {
            if (pos.second <= k) {
                int dist = getManhattanDistance(startX, startY, 
                                             pos.first.first, pos.first.second);

                if (dist > maxDist) {
                    maxDist = dist;
                    farthestCells.clear();
                    farthestCells.push_back(pos.first);
                } else if (dist == maxDist) {
                    farthestCells.push_back(pos.first);
                }
            }
        }

        // Sort and print results
        sort(farthestCells.begin(), farthestCells.end());
        for (const auto& cell : farthestCells) {
            cout << cell.first << " " << cell.second << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    VaishnaviGame game;
    game.solve();
    
    return 0;
}