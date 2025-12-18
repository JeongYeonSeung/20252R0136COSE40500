from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    time = 0
    curr_w = 0
    
    bridge = deque([])
    trucks = deque(truck_weights)
    
    time = 0
    first = trucks.popleft()
    bridge.append((1, first))
    curr_w += first
    
    while bridge:
        time += 1
        if time - bridge[0][0] >= bridge_length:
            curr_w -= bridge.popleft()[1]
        
        if len(bridge) == bridge_length:
            continue
        
        if trucks and curr_w + trucks[0] <= weight:
            truck = trucks.popleft()
            bridge.append((time, truck))
            curr_w += truck
    
    return time