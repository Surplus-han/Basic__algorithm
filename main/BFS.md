# BFS典型

![image-20221023124144368](C:\Users\72829\AppData\Roaming\Typora\typora-user-images\image-20221023124144368.png)

```c++
class Solution
{
 public:
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		queue<TreeNode*> q;
		q.push(root);
		int depth = 0;
		while (!q.empty())
		{
			int sz = q.size();
			for (int i = 0; i < sz; i++)
			{
				auto node = q.front();
				q.pop()//出队列
				if (node->left == nullptr && node->right == nullptr)
				{
					return depth;
				}
				//将相邻的节点加入队列
				if (node->left != nullptr)
				{
					q.push(node->left);
				}
				if (node->right != nullptr)
				{
					q.push(node->right);
				}

			}
			depth++;
		}
		return depth;
	}
};
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:return 0
        q = [root]
        depth = 1
        while q:
            for i in range(len(q)):
                node = q.pop(0)
                if  not node.left and not node.right:
                    return depth
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            depth+=1
        return depth 
```

BFS 可以找到最短距离，但是空间复杂度⾼，⽽ DFS 的空间复杂度较低。





![image-20221023144331353](C:\Users\72829\AppData\Roaming\Typora\typora-user-images\image-20221023144331353.png)

```c++
class Solution {
 public:
	//将s[i]向上拨动一次
	string up(string s,int i)
	{
		if(s[i] == '9')
		{
			s[i] = '0';
		}
		else{
			s[i]+=1;
		}
		return s;
	}
	//将s[i]向下波动一次
	string down(string s,int j)
	{
		if(s[j] == '0'){
			s[j] = '9';
		}
		else{
			s[j] -=1;
		}
		return s;
    }
	int openLock(vector<string>& deadends, string target) {
			int n = deadends.size();
			queue<string>q;
			set<string>s;//保存死亡密码
			for(auto c:deadends){
				s.insert(c);
			}
			//记录已经穷举过的密码
			set<string>visited;
			int step = 0;//步数
			q.push("0000");
			visited.insert("0000");
			while(!q.empty())
			{
				int sz = q.size();
				for(int i = 0; i < sz;i++)
				{
                    auto cur = q.front();
				    q.pop();
					if(s.count(cur)){
						continue;
					}
					if(cur == target){
						return step;
					}
					//将一个节点未遍历的节点加入队列
					for(int j = 0;j < 4;j++)
					{
						string u = up(cur,j);
						if(!visited.count(u)){
							q.push(u);
							visited.insert(u);
						}
						string d = down(cur,j);
						if(!visited.count(d)){
							q.push(d);
							visited.insert(d);
						}
					}
				}
				step++;
			}
		return -1;
	}
};

```





