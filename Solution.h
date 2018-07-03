#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	void push(int value) {
		if (length==0)
		{
			arr = new int[1]();
			length = 1;
			index = 0;
			arr[0] = value;
			index++;
		}
		else if (length == index)
		{
			length = 2 * length;
			int *temp = new int[length];
			for (int i = 0; i < length; i++)
			{
				temp[i] = arr[i];
			}
			delete arr;
			arr = temp;
			arr[index] = value;
			index++;
		}
		else
		{
			arr[index] = value;
			index++;
		}
	}
	void pop() {
		if (length == 0 || index == -1)
		{
			return;
		}
		else
		{
			index--;
		}
	}
	int top() {
		if (length == 0 || index == -1)
		{
			return -1;
		}
		else
		{
			return arr[index-1];
		}
	}
	int min() {
		int min = 0;
		for (int i = 0; i < index; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
		}
		return arr[min];
	}

	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() < 0)
		{
			return true;
		}
		bool isPossible = false;
		stack<int> seq;
		int i = 0,j=0,targetIndex=0;
		while (j < popV.size())
		{
			while (seq.empty() || seq.top() != popV[j])
			{
				if (j == popV.size()||i==pushV.size())
					break;
				seq.push(pushV[i]);
				i++;
			}
			if (seq.top() == popV[j])
			{
				seq.pop();
				j++;
			}
			else
			{
				break;
			}
		}
		if (j == popV.size())
		{
			isPossible = true;
		}
		return isPossible;
	}

	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> q;
		if (root == NULL)
		{
			return q;
		}
		vector<TreeNode*> treeq;
		treeq.push_back(root);
		while (!treeq.empty())
		{
			TreeNode *temp = treeq.front();
			q.push_back(temp->val);
			treeq.erase(treeq.begin());
			if (temp->left != NULL)
			{
				treeq.push_back(temp->left);
			}
			if (temp->right != NULL)
			{
				treeq.push_back(temp->right);
			}
		}
		return q;
	}

	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
		{
			return false;
		}
		int firstMin=-1, firstMax=-1;
		int size = sequence.size();
		bool left=true, right = true;
		for (int i = size-1; i >= 0; i--)
		{
			if (sequence[i] > sequence[size-1])
			{
				firstMax = i;
			}
			if (sequence[i] < sequence[size-1])
			{
				firstMin = i;
				break;
			}
		}
		for (int i = 0; i <= firstMin; i++)
		{
			if (sequence[i] > sequence[size - 1])
			{
				return false;
			}
		}
		for (int i = firstMin + 1; i <= firstMax; i++)
		{
			if (sequence[i] < sequence[size - 1])
			{
				return false;
			}
		}
		if (firstMax != -1)
		{
			left = VerifySquenceOfBST(vector<int>(sequence.begin() + firstMin + 1, sequence.begin()+firstMax+1));
		}
		if (firstMin != -1)
		{
			right = VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin() + firstMin + 1));
		}
		return left&&right;
	}

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		vector<int> path;
		FindPath(root, expectNumber, 0, path,res);
		return res;
	}

	void FindPath(TreeNode* root, int expectNum, int currentSum, vector<int>& path, vector<vector<int>>& res)
	{
		if (root == NULL)
		{
			return;
		}
		currentSum += root->val;
		path.push_back(root->val);
		if (currentSum == expectNum&&root->right==NULL&&root->left==NULL)
		{
			res.push_back(path);
		}
		else if(currentSum<expectNum)
		{
			FindPath(root->left, expectNum, currentSum, path, res);
			FindPath(root->right, expectNum, currentSum, path, res);
		}
		path.pop_back();
		return;
	}

	RandomListNode* Clone(RandomListNode* pHead)
	{
		RandomListNode *tempHead = pHead;
		while (tempHead != NULL)
		{
			RandomListNode *tempNode = new RandomListNode(tempHead->label);
			RandomListNode *temp = tempHead->next;
			tempHead->next = tempNode;
			tempNode->next = temp;
			tempHead = temp;
		}

		tempHead = pHead;
		while (tempHead != NULL)
		{
			if(tempHead->random!=NULL)
				tempHead->next->random = tempHead->random->next;
			tempHead = tempHead->next->next;
		}

		RandomListNode *newHead = new RandomListNode(0),*tempNewHead;
		tempHead = pHead;
		tempNewHead = newHead;
		while (tempHead != NULL)
		{
			tempNewHead->next = tempHead->next;
			tempNewHead = tempNewHead->next;
			tempHead->next = tempHead->next->next;
			tempHead = tempHead->next;
		}
		return newHead->next;
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode *res = ConvertToList(pRootOfTree);
		while (res!=NULL&&res->left != NULL)
		{
			res = res->left;
		}
		return res;
	}

	TreeNode* ConvertToList(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
		{
			return NULL;
		}
		else if (pRootOfTree->right == NULL&&pRootOfTree->left == NULL)
		{
			return pRootOfTree;
		}
		else
		{
			TreeNode *left = ConvertToList(pRootOfTree->left);
			while (left!=NULL&&left->right != NULL)
			{
				left = left->right;
			}
			pRootOfTree->left = left;
			if(left!=NULL) left->right = pRootOfTree;
			TreeNode *right = ConvertToList(pRootOfTree->right);
			while (right!=NULL&&right->left != NULL)
			{
				right = right->left;
			}
			pRootOfTree->right = right;
			if(right!=NULL) right->left = pRootOfTree;
			return pRootOfTree;
		}
	}
private:
	int *arr;
	int length=0;
	int index=-1;
};