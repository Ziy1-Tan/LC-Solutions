n, k = map(int, input().split())
a = list(map(int, input().split()))

# 计算所有题目数量之和，以及每个题目数量对k取模的结果
total = sum(a)
mod = [num % k for num in a]

# 创建二维状态矩阵dp，dp[i][j]表示前i个题目，除以k余数为j的最少天数
dp = [[float("inf")] * k for _ in range(total + 1)]
dp[0][0] = 0  # 边界条件：前0个题目，除以k余数为0的最少天数为0

for i in range(1, n + 1):  # 从第1个题目开始，依次处理每个题目
    for j in range(k):  # 遍历所有的余数
        mod_add = (j + mod[i - 1]) % k  # 第i个题目的余数加上上一轮的余数
        mod_subtract = (j - mod[i - 1] + k) % k  # 第i个题目的余数减去上一轮的余数
        for t in range(a[i - 1], total + 1):  # 遍历总题目数量，计算dp[i][j]的值
            dp[t][j] = min(dp[t][j], dp[t - a[i - 1]][mod_add] + (t - a[i - 1]) // k)
            dp[t][j] = min(
                dp[t][j], dp[t - a[i - 1]][mod_subtract] + (t - a[i - 1]) // k
            )

# 找到最大的天数天数，满足dp[total][0] == dp[total][k] == dp[total][2k] == ...
ans = float("inf")
for t in range(k):
    if dp[total][t] < ans:
        ans = dp[total][t]

if ans == float("inf"):
    print(0)
else:
    print(ans)

# sort a list
l = [5,5,6,1,4,2,3]
l.sort()
print(l)
