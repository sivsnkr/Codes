import math
t = input()
t = t.split(" ")
n = int(t[0])
k = int(t[1])

total = 0
mod = 998244353
for i in range(1,n+1):
    num = int(n/i)
    if(num >= k):
        total+=(math.factorial(num-1)/(math.factorial(k-1)*math.factorial(num-1-(k-1))))
        total%=mod

print(int(total))
