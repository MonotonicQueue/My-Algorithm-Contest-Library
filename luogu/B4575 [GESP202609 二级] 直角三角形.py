import math
a = [0.0]*1000000
a[1] = float(input())
a[2] = float(input())
d = float(input())
i = 1
while True:
    if i >= 3:
        a[i] = math.sqrt(a[i-1]*a[i-1]+a[i-2]*a[i-2])
    if a[i] > d:
        print(i)
        break
    i += 1