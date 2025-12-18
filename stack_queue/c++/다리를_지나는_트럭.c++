#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    int total_weight = 0;
    queue<pair<int, int>> bridge;
    queue<int> weights;
    
    for (int i: truck_weights) weights.push(i);
    
    while (!bridge.empty() || !weights.empty()) {
        time += 1;
        
        if (!bridge.empty()) {
            auto [w, a] = bridge.front();
            if (a == time) {
                total_weight -= w;
                bridge.pop();
            }
        }
        
        if (!weights.empty()) {
            int f = weights.front();
            if (total_weight + f <= weight && bridge.size() < bridge_length) {
                bridge.push({f, time + bridge_length});
                total_weight += f;
                weights.pop();
            }
        }
    }
    return time;
}

/*
1. 현재 시간, 현재 다리의 무게를 셀 수 있어야 한다.
2. 큐에 넣을 수 있을 때 넣기
*/