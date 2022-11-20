/*
@ Rat in a Maze Problem - I

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1).
Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is
blocked.
Your Task:
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order.
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1

*/

// CODE LINK : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &board)
{
    // Cheching whether rat should be placed on current block.
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (board[x][y] == 1))
    {
        return true;
    }
    return false;
}

void solve(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &board, string path, vector<string> &ans)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // mark visited
    visited[x][y] = 1;

    // 4 choices - D  L  R  U

    // DOWN
    int newX = x + 1;
    int newy = y;
    if (isSafe(newX, newy, n, visited, board))
    {
        path.push_back('D');
        solve(newX, newy, n, visited, board, path, ans);
        path.pop_back();
    }

    // LEFT
    newX = x;
    newy = y - 1;
    if (isSafe(newX, newy, n, visited, board))
    {
        path.push_back('L');
        solve(newX, newy, n, visited, board, path, ans);
        path.pop_back();
    }

    // RIGHT
    newX = x;
    newy = y + 1;
    if (isSafe(newX, newy, n, visited, board))
    {
        path.push_back('R');
        solve(newX, newy, n, visited, board, path, ans);
        path.pop_back();
    }

    // UP
    newX = x - 1;
    newy = y;
    if (isSafe(newX, newy, n, visited, board))
    {
        path.push_back('U');
        solve(newX, newy, n, visited, board, path, ans);
        path.pop_back();
    }

    // unmark visited
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &board, int n)
{
    // answer vector of string
    vector<string> ans;

    // if rat can't place at starting
    if (board[0][0] == 0)
    {
        return ans;
    }

    // current position of rat
    int srcX = 0;
    int srcY = 0;

    // making visited board with all path unvisited
    vector<vector<int>> visited = board;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    // will store the path from source to destination
    string path = "";

    // Solve the problem
    solve(srcX, srcY, n, visited, board, path, ans);

    // After Solving the problem sort alphabhatically
    sort(ans.begin(), ans.end());

    // return ans
    return ans;
}

int main()
{
    vector<vector<int>> board = {{1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1}};

    int n = 4;

    vector<string> result = findPath(board, n);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}