/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstddef>
class TreeTest {
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
public:

	//判断是否是单值二叉树
	bool isUnivalTree(TreeNode* root) {

		if (root == NULL)
			return false;

		int tvalue;

		/*if (root->)
		{

		}*/
	}



	//给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。
	//你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。


	//深度遍历
	void BST(TreeNode* root,int L,int R)
	{
		TreeNode* Left = root->left;

		//判断是否合适
		if (Left->val <L || Left->val>R)
		{
			
		}
		else
		{

		}	
	}

	bool ifDelete(TreeNode* test,int L, int R)
	{
		if (test->val <L || test->val>R)
		{
			return true;
		}
		else
		{
			return false;
		}	
	}


};