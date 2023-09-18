n, H = map(int, input().split())
x1, y1, h1, a1, b1 = map(int, input().split())
x2, y2, h2, a2, b2 = map(int, input().split())

# 1 -> 2
tmp1 = h1
tmp2 = h2
tmpH = H
step2 = abs(x2 - 1) + abs(y2 - 1)
tmp2 += b2 * (step2 // a2)
tmpH -= tmp2
step1 = 1 + step2 + abs(x2 - x1) + abs(y2 - y1)
tmp1 += b1 * (step1 // a1)
tmpH -= tmp1
result1 = tmpH

# 2->1
tmp1 = h1
tmp2 = h2
tmpH = H
step1 = abs(x1 - 1) + abs(y1 - 1)
tmp1 += b1 * (step1 // a1)
tmpH -= tmp1
step2 = 1 + step1 + abs(x2 - x1) + abs(y2 - y1)
tmp2 += b2 * (step2 // a2)
tmpH -= tmp2
result2 = tmpH



r = max(result1, result2)
if r >= 0:
    print(r)
else:
    print("yingyingying")
