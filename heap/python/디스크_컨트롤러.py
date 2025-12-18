import heapq

def solution(jobs):
    answer = 0
    
    wq = []
    jobs = sorted([(j[0], j[1], i) for i, j in enumerate(jobs)])
    
    time = 0
    job_idx = 0
    able = 0
    r_times = []
        
    while job_idx < len(jobs) or wq:
        # 대기 큐에 작업 등록
        while job_idx < len(jobs) and jobs[job_idx][0] <= time:
            s, l, idx = jobs[job_idx]
            heapq.heappush(wq, (l, s, idx))
            job_idx += 1
        
        if wq:
            l, s, idx = heapq.heappop(wq)
            time = max(s, time) + l # 작업이 끝나는 시간으로 점프
            r_times.append(time - s)
        else:
            if job_idx < len(jobs):
                time = jobs[job_idx][0] # 다음 작업이 들어오는 시간으로 점프
    
    answer = sum(r_times) // len(jobs)
    return answer

'''
대기 큐 : 작업의 번호, 요청 시각, 소요 시간 저장
우선 순위 : 소요 시간 짧은 것, 요청 시각이 빠른 것, 번호가 작은 것.
'''