#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    priority_queue<tuple<int, int, int>> wq; // -st, t, idx 
    priority_queue<tuple<int, int, int>> jq; // -t, -st, -idx
    
    for (int i = 0; i < jobs.size(); i++) jq.push({-jobs[i][0], jobs[i][1], i});
    
    while (!jq.empty() || !wq.empty()) {
        while (!jq.empty() && -get<0>(jq.top()) <= time) {
            tuple<int, int, int> top = jq.top();
            wq.push({-get<1>(top), get<0>(top), -get<2>(top)});
            jq.pop();
        }
        
        if (!wq.empty()) {
            tuple<int, int, int> top = wq.top();
            time += -get<0>(top);
            answer += (time + get<1>(top));
            wq.pop();
        } else if (!jq.empty()){
            time = -get<0>(jq.top());
        }
    }
    
    
    return int(answer / jobs.size());
}

/*
1. 작업 소요 시간이 짧은 것.
2. 작업 요청 시각이 빠른 것.
3. 작업의 번호가 작은 것.
*/