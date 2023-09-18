def dfs(adj, p, cnt, curr, prev):
    for v in adj[curr]:
        if v != prev:
            dfs(adj, p, cnt, v, curr)
            p[v] = curr
            cnt[curr] += cnt[v]


def solve(adj, str):
    n = len(adj)
    p = [-1] * n
    cnt = [1] * n
    dfs(adj, p, cnt, 0, -1)

    res = 0
    for u in range(n):
        for v in adj[u]:
            for w in adj[v]:
                if w == u:
                    continue
                if str[u] == "m" and str[v] == "h" and str[w] == "y":
                    if p[u] == v and p[v] == w:
                        res += cnt[u] * (n - cnt[v])
                    elif p[u] == v and p[w] == v:
                        res += cnt[u] * cnt[w]
                    elif p[v] == u and p[w] == v:
                        res += cnt[w] * (n - cnt[v])

    return res


def main():
    n = int(input())
    s = input()
    adj = [[] for _ in range(n)]

    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)

    result = solve(adj, s)
    print(result)


if __name__ == "__main__":
    main()

