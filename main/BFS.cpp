#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <set>
#include <string>
/*
 * BFS常见场景 ---求最短距离--在⼀幅「图」中找到从起点 start 到终点 target 的最近距离，
 *
 *
 *
 */
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
	{
	}
};
//基本框架
int BFS(TreeNode* Start, TreeNode* End)
{
	queue<TreeNode*> q;
	set<TreeNode*> visited;
	q.push(Start);//将起点加入队列
	int step = 0;
	while (!q.empty())
	{
		int sz = q.size();
		for (int i = 0; i < sz; i++)//遍历当前队列
		{
			TreeNode* node = q.back();
			//判断是否到达终点
			if (node == End)
			{
				return step;
			}
			/*
			 * 遍历相邻节点，更改visited
			 */
		}
		step++;//更新步数
	}
}
//二叉树的最小深度

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
				q.pop();//出队列
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

/*
 *
 *
 *
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
 */
//BFS 可以找到最短距离，但是空间复杂度⾼，⽽ DFS 的空间复杂度较低。

//解开密码锁的最少次数

//你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
// 每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
//
//锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
//
//列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
//
//字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。


//https://leetcode.cn/problems/open-the-lock/
/*
 *
 * 题⽬中描述的就是我们⽣活中常⻅的那种密码锁，若果没有任何约束，最少
的拨动次数很好算，就像我们平时开密码锁那样直奔密码拨就⾏了。
但现在的难点就在于，不能出现 deadends ，应该如何计算出最少的转动次
数呢？

如果你只转⼀下锁，有⼏种可能？总共有 4 个位置，
每个位置可以向上转，也可以向下转，也就是有 8 种可能对吧。
⽐如说从 "0000" 开始，转⼀次，可以穷举出 "1000", "9000", "0100",
"0900"... 共 8 种密码。然后，再以这 8 种密码作为基础，对每个密码再转
⼀下，穷举出所有可能...
仔细想想，这就可以抽象成⼀幅图，每个节点有 8 个相邻的节点，⼜让你求
最短距离，这是典型的 BFS
 */
class Solution1 {
 public:
	//将s[i]向上拨动一次
	string up(string s,int i)
	{
		if(s[i] == '9')
		{
			s[i] = '0';
		}
		else{
			s[i] += 1;
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
			return step;
	}
};





