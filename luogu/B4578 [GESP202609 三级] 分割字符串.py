s = input()
i = 1
lst = 0
while s.find(' '*i,lst) != -1:
    now = s.find(' '*i,lst)
    print(s[lst:now])
    lst = now+i
    i += 1
print(s[lst:])