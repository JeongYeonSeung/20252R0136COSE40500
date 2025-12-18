def solution(n, times):
    answer = float('inf')
    
    left = 1
    right = n * max(times)
    while left <= right:
        mid = (left + right) // 2
        curr = 0
        for t in times:
            curr += mid // t
        
        if curr >= n:
            answer = min(answer, mid)
            right = mid - 1
        else:
            left = mid + 1
        
    return answer

'''
모든 사람이 심사를 받는데 걸리는 시간의 최솟값.
-> 최소를 찾는 문제.
이를 결정 문제로? K 시간에 모든 사람이 심사를 받을 수 있는가?

K시간 동안 각 심사관이 몇 명 할 수 있는지 계산 때려서 합치면 되겠네
'''