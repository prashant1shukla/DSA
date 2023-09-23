#include <bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
void iterativePreorder(node* root)
{
	if (root == NULL)
		return;
	stack<node*> st;
	st.push(root);
	while (st.empty() == false) {
		struct node* node = st.top();
		cout<<node->data<<" ";
		st.pop();
		if (node->right)
			st.push(node->right);
		if (node->left)
			st.push(node->left);
	}
}
int main()
{
	struct node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);
	iterativePreorder(root);
	return 0;
}
