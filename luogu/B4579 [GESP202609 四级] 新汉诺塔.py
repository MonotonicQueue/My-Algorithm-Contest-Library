f = [0]*25
n = int(input())
f[1] = 2
for i in range(2,21):
    f[i] = 2*f[i-1]+2*f[i-2]+3
print(f[n])