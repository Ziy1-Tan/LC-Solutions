# /**
#  *
#  * 时间限制： 3000MS
#  * 内存限制： 532480KB
#  * 题目描述：
#  * score1和score2分别为A和B两个班级的成绩单，现在需要从B班级的成绩单中，替换掉A班中部分同学成绩，确保替换后的A班成绩是保持严格增长的，需要请你选择合理的替换方法能够使得替换的次数是最小的（可能为0），并返回该替换操作次数。若无法使得替换后的score1保持严格增长，请返回值为-1。
#  *
#  *
#  *
#  * 输入描述
#  * 第一行：输入无符号uint8_t的数组，数组长度大于0；
#  *
#  * 第二行：输入无符号uint8_t的数组，数组长度大于0；
#  *
#  * 输出描述
#  * 输出一个32 位的有符号整数
#  *
#  *
#  * 样例输入
#  * score1=[81,85,83,86,87]
#  * score2=[81,83,82,84]
#  * 样例输出
#  * 1
#  *
#  * 提示
#  * 例如A班的成绩为[81,85,83,86,87], B班的成绩为
#  * [81,83,82,84]，仅需要将B班级中的82替换掉A班中的85，即可使得A班的成绩保持严格增长的，此时替换操作次数为1。
#  */
def replace_scores(score1, score2):
    replace_count = 0

    for i in range(len(score1)):
        for j in range(len(score2)):
            if score2[j] > score1[i]:
                score1[i] = score2[j]
                replace_count += 1
                break
        else:
            return -1

    return replace_count

# 样例输入
score1 = [81, 85, 83, 86, 87]
score2 = [81, 83, 82, 84]

# 调用函数并输出结果
result = replace_scores(score1, score2)
print(result)
