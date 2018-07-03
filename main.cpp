#include "Solution.h"

int main()
{
	Solution s;
	vector<int> ivec1{ 1,2,3,4,5 }, ivec2{ 4,5,3,2,1 }, ivec3{ 4,3,5,1,2 };
	TreeNode *tnode1 = new TreeNode(1),
		*tnode2 = new TreeNode(2),
		*tnode3 = new TreeNode(3),
		*tnode8=new TreeNode(8),
		*tnode6=new TreeNode(6),
		*tnode10=new TreeNode(10),
		*tnode5=new TreeNode(5),
		*tnode7=new TreeNode(7),
		*tnode9=new TreeNode(9),
		*tnode11=new TreeNode(11);
	/*
	tnode6->right = tnode7;
	tnode6->left = tnode5;
	tnode10->right = tnode11;
	tnode10->left = tnode9;
	tnode8->right = tnode10;
	tnode8->left = tnode6;
	tnode1->right = tnode3;
	tnode1->left = tnode2;
	*/

	RandomListNode *rnode1 = new RandomListNode(1),
		*rnode2 = new RandomListNode(2),
		*rnode3 = new RandomListNode(3),
		*rnode4 = new RandomListNode(4),
		*rnode5 = new RandomListNode(5);
	rnode1->next = rnode2;
	rnode2->next = rnode3;
	rnode3->next = rnode4;
	rnode4->next = rnode5;
	rnode1->random = rnode3;
	rnode2->random = rnode5;
	rnode4->random = rnode2;
	auto res = s.Convert(tnode6);
	return 0;
}