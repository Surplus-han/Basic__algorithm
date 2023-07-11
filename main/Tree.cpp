/*
 *
 * 对称性递归问题--->二叉树的递归问题
 */
#include <bits/stdc++.h>
using namespace std;
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
//1.相同的的树
//如果两棵树都是空树那么必然相同；如果两棵树其中只有一棵树为空树那么必不相同 返回值：两棵树都非空+根节点值相同+左子树相同+右子树相同
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
	{
		return false;
	}
	return p && q && p->val == q->val && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
}

/*
 * 二叉树的最大深度，空树的深度为0，树非空，返回左右子树最深的加一
 *
 */
int height(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}

/*
 * 平衡二叉树--
 *  判断一棵树是不是平衡二叉树 平衡二叉树定义：左右子树最大高度差<=1 特殊判断：空树是平衡树 返回值：
 *  根节点的左右子树高度差<=1 + 左子树是平衡二叉树 +右子树是平衡二叉树
 */
bool isBalanced(TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return (abs(height(root->left) - height(root->right))) <= 1 && isBalanced(root->left)
			&& isBalanced(root->right);
	}
}

/*
 * 单值二叉树
 *  单值二叉树：所有节点值均相等 特殊判断：
 *  1、空树是单值二叉树
 *  2、如果左子树非空且根节点的值异与左子节点值(即根节点与左子节点不同)，返回false,
 *  右子树同理 返回值：左子树是单值二叉树+右子树是单值二叉树
 */

bool isUnivalTree(TreeNode* root)
{
	if (!root)
	{
		return true;
	}
	if ((root->left && root->left->val != root->val) || (root->right && root->right->val != root->val))
	{
		return false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

/*
 * 另一个树的子树
 *
 *  判断一个数是不是另一颗树的子树
 *  特殊判断：有一颗树为空就不成立 这道题的思路比较特殊
 *  ，先判断两棵树是否是相同，如果相同那么就是满足题意的，
 *  然后判断一棵树的左子树是否是另一颗树的子树/一棵树的右子树是否是另一颗树的子树
 */

bool isSubTree(TreeNode* root1, TreeNode* root2)
{
	if (!root1 || !root2)
		return false;
	if (isSameTree(root1, root2))
		return true;
	return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
}

/*
 *
 * 翻转二叉树
 *  将一棵二叉树镜像翻转 特殊判断：空树的镜像翻转树仍然是本身 思路：翻转左子树后替换右子树，翻转右子树后替换左子树
 */
TreeNode* invertTree(TreeNode* root)
{
	if (!root)
		return nullptr;
	TreeNode* left = invertTree(root->left);
	TreeNode* right = invertTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}

/*
 * 合并二叉树
 * 将两个二叉树合并 思路：
 * 1、都是空树返回nullptr
 * 2、其中有一个空返回另一个树的根节点
 * 3、都不空的话先把两棵树根节点值相加，然后递归合并左右子树(以第一棵树为合并后的树) 代码如下：
 */
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
{
	if (!root1)
		return root2;
	if (!root2)
		return root1;
	if (root1 && root2)
		root1->val += root2->val;
	root1->left = mergeTrees(root1->left, root2->left);    //递归合并左子树
	root1->right = mergeTrees(root1->right, root2->right); //递归合并右子树
	return root1;
}

/*
 * 对称的二叉树
 * 判断一棵树是否为对称二叉树
 * 思路：构造一个辅助函数判断两棵树是否是镜像对称的，
 * 然后题目只要判断两棵这个树是否镜像对称 而比较两棵树是否镜像对称，
 * 即一棵树的左子树和另一棵树的右子树，
 * 以及一棵树的右子树和另一棵树的左子树是否镜像对称
 * 特殊判断：都是空树满足条件；其中有一棵空树不满足条件 代

 */


bool isMirror(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;
	return (p->val == q->val) && (isMirror(p->left, q->right)) && (isMirror(p->right, q->left));
}
bool isSymmetric(TreeNode* root)
{
	return isMirror(root, root);
}


/*
 * 树的子结构
 *  判断一棵树是否是另一棵树的子结构，
 *  注意子结构与子树的区别 子结构不能只利用根节点进行对称性递归，
 *  需要构造辅助函数，判断当两棵树根节点值相同时一棵树是否为另一棵树子结构
 */

// hasSubStructure函数是判断如果A,B根节点相同，B是不是A的子结构
bool hasSubStructure(TreeNode* A, TreeNode* B)
{
	if (!B)        //递归结束条件1：A的一个节点B的对应位置没有,可以认为是子结构
		return true;
	if (!A || A->val != B->val)  //递归结束条件2：B的一个节点A的对应位置没有 / A,B对应位置节点值不同，此时必然不可能是子结构
		return false;
	return hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right); //返回值：继续在对应位置递归判断
}

bool isSubStructure1(TreeNode<T>* A, TreeNode<T>* B)
{
	if (!A || !B)   //特殊判断
		return false;
	// 根节点相同的话直接进入比较，根节点不相同看B是不是A的左/右子树的子结构
	return hasSubStructure(A, B) || isSubStructure1(A->left, B) || isSubStructure1(A->right, B);
}


