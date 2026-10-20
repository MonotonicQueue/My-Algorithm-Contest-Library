t = float(input())
v = float(input())
sleep_t = float(input())
rabbit_t = 1000/v+sleep_t
if t < rabbit_t:
    print("turtle")
elif t > rabbit_t:
    print("rabbit")
else:
    print("tie")
print("%.2f"%rabbit_t)