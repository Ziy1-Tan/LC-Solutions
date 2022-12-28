# Leetcode
## 二叉树的前中后序遍历（144、94、145）
注意结果打印位置即可
- 前序
```c++
while (root || !stack.empty())
{
    while (root)
    {
        res.push_back(root->val);
        stack.push(root);
        root = root->left;
    }

    root = stack.top();
    stack.pop();
    root = root->right;
}
```
- 中序
```c++
while (root || !stack.empty())
{
    while (root)
    {
        stack.push(root);
        root = root->left;
    }

    root = stack.top();
    stack.pop();
    res.push_back(root->val);
    root = root->right;
}
```
- 后序
```c++
while (root || !stack.empty())
{
    while (root)
    {
        res.push_back(root->val);
        stack.push(root);
        root = root->right;
    }

    root = stack.top();
    stack.pop();
    root = root->left;
}

reverse(res.begin(), res.end());
```
