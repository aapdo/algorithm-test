'''
https://www.acmicpc.net/problem/2346
'''

# -N <= k <= N 인 정수 k가 풍선 안 종이에 적혀 있음.
# 처음엔 1번 풍선 터뜨리고, 종이에 적힌 값만큼 이동하여 다음 풍선을 터뜨림.
# 양수가 적혀있으면 오른쪽, 음수면 왼쪽.
# 이미 터진 풍선은 빼고 이동함.

n = int(input())
numbers = list(map(int, input().split()))
from collections import deque
d = deque()
number = 0
for i in range(n):
    d.append(i+1)

idx = d.popleft()    
print(str(idx), end=" ")
for i in range(n-1):
    number = numbers[idx-1]
    if number < 0:
        number = -1 * number
        for _ in range(number):
            d.appendleft(d.pop())
    else: 
        for _ in range(number-1):
            d.append(d.popleft())
    idx = d.popleft()
    print(str(idx), end=" ")
    

