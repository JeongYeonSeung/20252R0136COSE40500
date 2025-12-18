#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<pair<int, int>> max_pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_pq;
    unordered_set<int> valid;
    
    auto cleanup = [&](auto& pq) {
        while(!pq.empty() && !valid.count(pq.top().second)) pq.pop();
    };
    
    for (int i = 0; i < operations.size(); i++) {
        vector<string> op;
        stringstream ss(operations[i]);
        string token;
        
        while (getline(ss, token, ' ')) {
            op.push_back(token);
        }
        
        if (op[0] == "I") {
            max_pq.push({stoi(op[1]), i});
            min_pq.push({stoi(op[1]), i});
            valid.insert(i);
        } else if (!valid.empty()) {
            if (op[1] == "1") {
                auto& pq = max_pq;
                cleanup(pq);
                if (!pq.empty()) {
                    valid.erase(pq.top().second);
                    pq.pop();
                }
            } else {
                auto& pq = min_pq;
                cleanup(pq);
                if (!pq.empty()) {
                    valid.erase(pq.top().second);
                    pq.pop();
                }  
            }
        }
    }
    cleanup(max_pq);
    cleanup(min_pq);
    
    if (valid.empty()) return {0, 0};
    
    return {max_pq.top().first, min_pq.top().first};
}