from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) < 2:
            return intervals

        intervals.sort(key=lambda x: x[0])
        ans = []
        for interval in intervals:
            l, r = interval[0], interval[1]
            if not ans or ans[-1][1] < l:
                ans.append([l, r])
            else:
                ans[-1][1] = max(ans[-1][1], r)

        return ans


print(Solution().merge([[1, 8], [3, 6], [9, 11]]))
