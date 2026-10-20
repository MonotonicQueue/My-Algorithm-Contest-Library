mp = [['*'] * 16 for _ in range(8)]
for _ in range(3):
    x = int(input())
    mp[(x-1)//16][(x-1)%16] = chr(x)

for i in range(8):
    for j in range(16):
        print(mp[i][j],end="")
    print()