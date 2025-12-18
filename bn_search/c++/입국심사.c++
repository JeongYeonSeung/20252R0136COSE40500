#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long max_time = *max_element(times.begin(), times.end());
    long long answer = LLONG_MAX;
    
    long long left = 1;
    long long right = n * max_time;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long curr = 0;
        for (int t: times) curr += (mid / t);
        
        if (n <= curr) {
            answer = min(answer, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}