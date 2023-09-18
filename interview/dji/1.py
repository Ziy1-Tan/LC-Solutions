# /**
#  * 题目描述：
#  * 假设你需要编写一个文件系统搜索程序，该程序可以在给定的文件系统中搜索包含指定关键字的路径。假设文件系统结构如下：
#  *
#  * root/
#  * -folder1/
#  * --file1.txt
#  * --file2.txt
#  * -folder2/
#  * --file3.txt
#  * --file4.txt
#  * -folder3/
#  * --file5.txt
#  * -folder4/
#  * --file6.txt
#  * 每个文件或文件夹的路径占据一行，文件夹的层级关系通过"-"的缩进表示。文件夹之间的关系可以看作是一个树结构，其中根文件夹为顶层文件夹。
#  *
#  * 示例数据表示在root文件夹下有 folder1
#  * ，folder2,folder3跟folder4文件夹，folder1里面有file1.txt和file1.txt等。
#  *
#  * 假如我这里搜索关键词为“4”,则应该输出
#  *
#  * /root/folder2/file4.txt
#  * /root/folder4
#  *
#  *
#  * 输入描述
#  * 第一行为要搜索的关键词
#  *
#  * 第二行为文件系统数据的行数总数
#  *
#  * 第三行开始为文件系统结构，每个文件或文件夹的路径占据一行，文件夹的层级关系通过"-"的缩进表示。
#  *
#  * 输出描述
#  * 输出为包含关键词的全路径。一行一个匹配路径
#  *
#  *
#  * 补充说明：
#  *
#  * 输出的文件路径必须以根路径“/”开头，并以斜杠 / 分隔各级文件夹和文件。
#  *
#  * 文件夹或者文件的名字包含该关键字均认为是命中,若文件夹和文件名均包含关键词，则需要分别输出
#  *
#  * 如果找不到包含关键词的文件或者关键词为空，则输出 "No Files Found"。
#  *
#  * 匹配的数据输出顺序需要保持输入的顺序
#  * 样例输入
#  * 4
#  * 11
#  * root/
#  * -folder1/
#  * --file1.txt
#  * --file2.txt
#  * -folder2/
#  * --file3.txt
#  * --file4.txt
#  * -folder3/
#  * --file5.txt
#  * -folder4/
#  * --file6.txt
#  * 样例输出
#  * /root/folder2/file4.txt
#  * /root/folder4/
#  *
#  * 提示
#  * 先把输入构造成一棵树，再进行搜索
#  */
class TreeNode:
    def __init__(self, name):
        self.name = name
        self.children = []


def construct(fileList):
    root = TreeNode("root")
    curr = [root]

    fileList = fileList[1:]
    for line in fileList:
        depth = line.count("-")
        name = line.strip().replace("-", "")
        node = TreeNode(name)

        parent = curr[depth - 1]
        parent.children.append(node)
        if depth > len(curr) - 1:
            curr.append(node)
        else:
            curr[depth] = node

    return root


res = []


def search(root, keyword, current):
    if keyword in root.name:
        res.append("/root/" + "".join(current))

    for child in root.children:
        current.append(child.name)
        search(child, keyword, current)
        current.pop()


keyword = "file"
num = 11
fileList = [
    "root/",
    "-folder1/",
    "--file1.txt",
    "--file2.txt",
    "-folder2/",
    "--file3.txt",
    "--file4.txt",
    "-folder3/",
    "--file5.txt",
    "-folder4/",
    "--file6.txt",
]

# keyword = input()
# num = input()
# fileList = []
# for i in range(int(num)):
#     file = input()
#     fileList.append(file)

root = construct(fileList)
search(root, keyword, [])

if len(res) == 0:
    print("No Files Found")
else:
    for file in res:
        print(file)
