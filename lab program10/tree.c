#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *NODE;

NODE getnode(int item)
 {
    NODE x = (NODE)malloc(sizeof(struct node));
    if(x!=NULL){
	x->data=item;
	x->left = NULL;
     	x->right = NULL;
    	return x;
	}
    else {
        printf("Memory allocation failed!\n");
        exit(0);
    }
}
NODE insert(NODE root,int item)
{
	if(root ==NULL)
		return getnode(item);
	if(item<root->data)
		root->left = insert(root->left,item);
	else if(item>root->data)
		root->right = insert(root->right,item);
	return root;
}
void inorder(NODE root)
{
	if(root == NULL)
	return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void preorder(NODE root)
{
	if(root == NULL)
	return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(NODE root)
{
	if(root == NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}
int main()
{
	NODE root = NULL;
	int item,ch;
	for(;;)
	{
	printf("1.Insert.\n2.Inorder Traversal.\n3.Preorder Traversal.\n4.Postorder Traversal.\n5.Exit:\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: printf("\nEnter the element:\n");
			scanf("%d",&item);
			root = insert(root,item);
			break;
		case 2: inorder(root);
			break;
		case 3: preorder(root);
			break;
		case 4: postorder(root);
			break;
		case 5: exit(1);
		default :printf("Invalid Choice");
		}
	}
}
