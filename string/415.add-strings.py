class Solution(object):
    def addStrings(self, num1, num2):
        ans = ""
        i, j, carry = len(num1) - 1, len(num2) - 1, 0
        while i >= 0 or j >= 0 or carry != 0:
            n1 = int(num1[i]) if i >= 0 else 0
            n2 = int(num2[j]) if j >= 0 else 0
            sum = n1+n2+carry
            carry = sum//10
            ans = str(sum % 10)+ans
            i, j = i-1, j-1
        return ans


print(Solution().addStrings("11", "123"))
