#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// Directions for Queen, Rook, and Bishop
const vector<pair<int, int>> QUEEN_DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
const vector<pair<int, int>> ROOK_DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> BISHOP_DIRS = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

struct Piece {
    char type;
    int x, y;
};

// Helper to encode board state
string encodeState(const vector<Piece>& pieces) {
    // Sort pieces to ensure consistent encoding regardless of piece order
    vector<Piece> sortedPieces = pieces;
    sort(sortedPieces.begin(), sortedPieces.end(), 
         [](const Piece& a, const Piece& b) {
             return a.type < b.type || (a.type == b.type && (a.x < b.x || (a.x == b.x && a.y < b.y)));
         });
    
    string state;
    for (const auto& piece : sortedPieces) {
        state += piece.type;
        state += (char)('A' + piece.x);
        state += (char)('1' + piece.y);
    }
    return state;
}

// Helper to check if a position is within the board
bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// Helper to check if a position is occupied by another piece
bool isOccupied(const vector<Piece>& pieces, int x, int y, int excludePieceIdx) {
    for (int i = 0; i < pieces.size(); i++) {
        if (i != excludePieceIdx && pieces[i].x == x && pieces[i].y == y) {
            return true;
        }
    }
    return false;
}

// BFS to calculate unique positions
int calculateUniquePositions(vector<Piece> pieces, int depth) {
    unordered_set<string> visited;
    queue<pair<vector<Piece>, int>> q;

    string initialState = encodeState(pieces);
    visited.insert(initialState);
    q.push({pieces, 0});

    while (!q.empty()) {
        auto [currentPieces, currentDepth] = q.front();
        q.pop();

        if (currentDepth == depth) continue;

        // Try moving each piece
        for (int i = 0; i < currentPieces.size(); ++i) {
            const vector<pair<int, int>>* directions;
            
            // Select appropriate directions based on piece type
            switch (currentPieces[i].type) {
                case 'Q': directions = &QUEEN_DIRS; break;
                case 'R': directions = &ROOK_DIRS; break;
                case 'B': directions = &BISHOP_DIRS; break;
                default: continue;
            }

            // Try each direction
            for (const auto& [dx, dy] : *directions) {
                int nx = currentPieces[i].x;
                int ny = currentPieces[i].y;

                // Move in the current direction until hitting board edge or another piece
                while (true) {
                    nx += dx;
                    ny += dy;

                    if (!isValid(nx, ny) || isOccupied(currentPieces, nx, ny, i)) break;

                    vector<Piece> newPieces = currentPieces;
                    newPieces[i].x = nx;
                    newPieces[i].y = ny;

                    string newState = encodeState(newPieces);
                    if (!visited.count(newState)) {
                        visited.insert(newState);
                        q.push({newPieces, currentDepth + 1});
                    }
                }
            }
        }
    }

    return visited.size();
}

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);

    vector<Piece> pieces;
    string pieceInfo;
    while (ss >> pieceInfo) {
        char type = pieceInfo[0];
        int x = pieceInfo[1] - 'A';
        int y = pieceInfo[2] - '1';
        pieces.push_back({type, x, y});
    }

    int depth;
    cin >> depth;

    cout << calculateUniquePositions(pieces, depth) << endl;

    return 0;
}