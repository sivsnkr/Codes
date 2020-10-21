import math
n = int(input())

r = math.factorial(n)/(math.factorial(2)*math.factorial(n-2))
r = r%10000009
print(r)