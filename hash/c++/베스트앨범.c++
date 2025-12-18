#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> per_genres;
    unordered_map<string, vector<pair<int, int>>> per_song;
    
    for (int i = 0; i < plays.size(); i++) {
        per_genres[genres[i]] += plays[i];
        per_song[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> vec_pg(per_genres.begin(), per_genres.end());
    
    sort(vec_pg.begin(), vec_pg.end(), [](pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second;
    });
    
    for (auto& gen: vec_pg) {
        vector<pair<int, int>> ps = per_song[gen.first];
        sort(ps.begin(), ps.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        answer.push_back(ps[0].first);
        if (ps.size() > 1) {
            answer.push_back(ps[1].first);
        }
    }
    
    return answer;
}