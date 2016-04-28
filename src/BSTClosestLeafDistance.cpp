/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int getMin(int x, int y)
{
	return (x < y) ? x : y;
}
int nearnodes(struct node *root)
{
	if (root == NULL)
		return INT_MAX;
	if (root->left == NULL && root->right == NULL)
		return 0;
	int cd1 = nearnodes(root->left);
	int cd2 = nearnodes(root->right);
	return 1 + getMin(cd1, cd2);
}
int closest(struct node *root, char k, struct node *prev[], int index)
{
	if (root == NULL)
		return INT_MAX;
	if (root->data == k)
	{
		int res = nearnodes(root);
		for (int i = index - 1; i >= 0; i--)
			res = getMin(res, index - i + nearnodes(prev[i]));
		return res;
	}
	prev[index] = root;
	int r1 = closest(root->left, k, prev, index + 1);
	int r2 = closest(root->right, k, prev, index + 1);
	return getMin(r1, r2);

}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	struct node *prev[100];
	int result = closest(root, temp->data, prev, 0);
	return result;
}