n, m = map(int, input().split())
t = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]


f = [[0] * (m+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, m+1):
        if j >= t[i-1]:
            f[i][j] = max(f[i-1][j], f[i-1][j-t[i-1]] + (b[i-1]-a[i-1]))
        else:
            f[i][j] = f[i-1][j]

print(max(f[n]))
