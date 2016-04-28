/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include <stddef.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
void Addpre(struct node *root, int arr[], int *i){
	if (root == NULL)
		return;

	arr[*i] = root->data;
	++*i;
	Addpre(root->left, arr, i);
	Addpre(root->right, arr, i);
}
void Addpos(struct node *root, int arr[], int *i){
	if (root == NULL)
		return;
	Addpos(root->left, arr, i);
	Addpos(root->right, arr, i);
	arr[*i] = root->data;
	++*i;
}
void Addin(struct node *root, int arr[], int *i){
	if (root == NULL)
		return;
	Addin(root->left, arr, i);
	arr[*i] = root->data;
	++*i;
	Addin(root->right, arr, i);

}
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	else
	{
		int x = 0;
		Addin(root, arr, &x);
	}
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	else
	{
		int x = 0;
		Addpre(root, arr, &x);
	}
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	else
	{
		int x = 0;
		Addpos(root, arr, &x);
	}
}


