def min_cost(s):
    n = len(s)
    left, right = 0, n - 1
    cnt1 = s.count('1')
    cnt0 = s.count('0')
    ans = cnt1 + cnt0

    # 枚举左右边界
    while left < n and s[left] == '0':
        left += 1
        cnt0 -= 1
    ans = min(ans, cnt1 + cnt0)

    while right >= 0 and s[right] == '0':
        right -= 1
        cnt0 -= 1
    ans = min(ans, cnt1 + cnt0)

    # 枚举中间的子串
    while left <= right:
        if s[left] == '1':
            cnt1 -= 1
        else:
            cnt0 -= 1
        left += 1
        ans = min(ans, cnt1 + cnt0)

        if s[right] == '1':
            cnt1 -= 1
        else:
            cnt0 -= 1
        right -= 1
        ans = min(ans, cnt1 + cnt0)

    return ans

# 测试
s = input().strip()
print(min_cost(s))
