#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find(vector<int>& parents, int x) {
    if (parents[x] != x) {
        parents[x] = find(parents, parents[x]);
    }
    return parents[x];
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> parents(n);
    for (int i = 0; i < n; i++) parents[i] = i;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                int pi = find(parents, i);
                int pj = find(parents, j);
                if (pi == pj) continue;
                parents[pj] = pi;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i == parents[i]) answer++;
    }
     
    return answer;
}