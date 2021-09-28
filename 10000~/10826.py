n = int(input())
pri = 0
sec = 1

for i in range(n):
    pri, sec = sec, pri+sec
print(pri)
