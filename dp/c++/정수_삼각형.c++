#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int DP[n+1][n+1];
    
    DP[0][0] = triangle[0][0];
    
    for (int i = 1; i < n; i++) {
        DP[i][0] = triangle[i][0] + DP[i-1][0];
        DP[i][i] = triangle[i][i] + DP[i-1][i-1];
    }
    
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            DP[i][j] = triangle[i][j] + max(DP[i-1][j-1], DP[i-1][j]);
        }
    }
    
    return *max_element(DP[n-1], DP[n-1]+n);
}