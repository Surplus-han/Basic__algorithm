#include <bits/stdc++.h>

using namespace std;

/* �������ڵ�ṹ�� */
struct TreeNode {
    int val;          // �ڵ�ֵ
    TreeNode *left;   // ���ӽڵ�ָ��
    TreeNode *right;  // ���ӽڵ�ָ��
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/* ��ʼ�������� */
// ��ʼ���ڵ�
TreeNode* n1 = new TreeNode(1);
TreeNode* n2 = new TreeNode(2);
TreeNode* n3 = new TreeNode(3);
TreeNode* n4 = new TreeNode(4);
TreeNode* n5 = new TreeNode(5);

n1->left = n2;
n1->right = n3;
n2->left = n4;
n2->right = n5;

/* ������ɾ���ڵ� */
TreeNode* P = new TreeNode(0);
// �� n1 -> n2 �м����ڵ� P
n1->left = P;
P->left = n2;
// ɾ���ڵ� P
n1->left = n2;

/* ������� */
vector<int> levelOrder(TreeNode *root) {
    // ��ʼ�����У�������ڵ�
    queue<TreeNode *> queue;
    queue.push(root);
    // ��ʼ��һ���б����ڱ����������
    vector<int> vec;
    while (!queue.empty()) {
        TreeNode *node = queue.front();
        queue.pop();              // ���г���
        vec.push_back(node->val); // ����ڵ�ֵ
        if (node->left != nullptr)
            queue.push(node->left); // ���ӽڵ����
        if (node->right != nullptr)
            queue.push(node->right); // ���ӽڵ����
    }
    return vec;
}

/* ǰ����� */
void preOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    // �������ȼ������ڵ� -> ������ -> ������
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

/* ������� */
void inOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    // �������ȼ��������� -> ���ڵ� -> ������
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

/* ������� */
void postOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    // �������ȼ��������� -> ������ -> ���ڵ�
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

