def solution(triangle):
    answer = 0
    h = len(triangle)
    DP = [[0 for _ in range(h)] for _ in range(h)]
    
    DP[0][0] = triangle[0][0]
    
    for i in range(1, h):
        for j in range(i+1):
            if j == 0:
                DP[i][j] = DP[i-1][j] + triangle[i][j]
            elif j == i:
                DP[i][j] = DP[i-1][j-1] + triangle[i][j]
            else:
                DP[i][j] = max(DP[i][j], DP[i-1][j-1] + triangle[i][j])
                DP[i][j] = max(DP[i][j], DP[i-1][j] + triangle[i][j])
    
    answer = max(DP[h-1])
    return answer

'''
i층의 j번째까지의 최대 값
DP[i][j] = DP[i][j], DP[i-1][j-1], DP[i-1][j]

'''