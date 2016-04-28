/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void Add(struct node *root, int arr[], int *i){
	if (root == NULL)
		return;
	Add(root->left, arr, i);
	arr[*i] = root->data;
	++*i;
	Add(root->right, arr, i);

}
int count1(struct node *p)
{
	if (p == NULL)
		return(0);
	else
		if (p->left == NULL && p->right == NULL)
			return(1);
		else
			return(1 + (count1(p->left) + count1(p->right)));
}
void sortarray(int *x, int first, int last){
	int i, j, temp;
	for (i = 0; i<last; i++){
		for (j = i + 1; j<last; j++){
			if (x[i]>x[j]){
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}
void check(struct node *root, int *arr, int *i){
	if (root == NULL)
		return;
	check(root->left, arr, i);
	if (root->data != arr[*i])
		root->data = arr[*i];
	++*i;
	check(root->right, arr, i);

}
void fix_bst(struct node *root){
	if (root == NULL)
		return;
	else
	{
		int i = 0;
		int n = count1(root);
		int *arr = (int*)malloc(sizeof(int)*n);
		Add(root, arr, &i);
		sortarray(arr, 0, n);
		i = 0;
		check(root, arr, &i);
	}
}
