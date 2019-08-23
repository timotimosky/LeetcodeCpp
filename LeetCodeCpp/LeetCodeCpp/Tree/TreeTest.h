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
	int tvalue;
	//判断是否是单值二叉树
	bool isUnivalTree(TreeNode* root) {

		if (root == NULL)
			return false;
		tvalue = root->val;
		return ifEqals(root);
	}

	bool ifEqals(TreeNode* root)
	{
		if (root == NULL)
			return true;
		if (root->val == tvalue)
		{
			return ifEqals(root->left) && ifEqals(root->right);
		}
		else
			return false;
	}

	/*给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。
	如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
	给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 - 1 */

	int findSecondMinimumValue(TreeNode* root) {

	}

};