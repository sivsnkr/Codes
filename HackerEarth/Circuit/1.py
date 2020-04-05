import math
n = input()
n = int(n)

notShake = []
for i in range(0, 10):
    st = input()
    st = st.split(" ")
    src = int(st[0])
    for j in range(1,10):
        se = set([src,int(st[j])])
        if(se not in notShake):
            notShake.append(se)

# n -= len(notShake)
# print(len(notShake))

res = int((math.factorial(n))/(2*math.factorial(n-2)))
res-=len(notShake)
print(res)

# s1 = set([2,3]);
# s2 = set([4,2]);

# if (s1 == s2):
#     print("Yes")
# else:
#     print("No")

# s3 = [s1]

# print(s2 in s3)
# print(len(s3))
# s2 = set();
# s2.add(3);