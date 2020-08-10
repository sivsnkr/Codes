import math
n = int(input())
res = math.factorial(n)/(math.factorial(3)*math.factorial(n-3))
res = res*math.factorial(n-2);
res = res*2;
res = res%1000000007;
print(int(res))

