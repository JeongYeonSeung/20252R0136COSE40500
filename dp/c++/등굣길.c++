#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// DP[i][j] = DP[i][j-1] + DP[i-1][j]

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<bool>> is_puddle(n+1, vector<bool>(m+1, false));
    vector<vector<int>> DP(n+1, vector<int>(m+1, 0));
    
    for (auto& p: puddles) {
        is_puddle[p[1]][p[0]] = true;
    }
    
    for (int i = 1; i <= m; i++) {
        if (is_puddle[1][i]) break;
        DP[1][i] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (is_puddle[i][1]) break;
        DP[i][1] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (is_puddle[i][j]) continue;
            DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % 1000000007;
         }
    }
    
    return DP[n][m] % 1000000007;
}