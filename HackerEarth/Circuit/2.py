import math
n = input()
n = n.split(" ")
x = []
for j in n:
    x.append(int(j))

b1 = int(x[1]*x[2])
b2 = int(x[0]*x[3])
b3 = int((b2*x[1])/x[3])

g = math.gcd(b1,math.gcd(b2,b3))
b1=int(b1/g)
b2=int(b2/g)
b3=int(b3/g)

print("{} {} {}".format(b1,b2,b3))