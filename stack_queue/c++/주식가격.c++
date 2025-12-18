#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> record;
    
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += 1;
        if (!record.empty()) {
            while (!record.empty() && prices[record.top()] > prices[i]) {
                int idx = record.top();
                answer[idx] = i - idx;
                record.pop();
            }
        }
        record.push(i);
    }
    
    while (!record.empty()) {
        int idx = record.top();
        answer[idx] = n - 1 - idx;
        record.pop();
    }
    return answer;
}

/*
스택으로 풀면 될 것 같다
*/