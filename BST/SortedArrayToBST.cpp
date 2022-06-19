#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key =k;
        left=NULL;
        right=NULL;
    }
};
Node* sortedArrayToBST(int arr[],
						int start, int end)
{
	if(start>end)
        return NULL;
    int mid=(start+end)/2;
    Node *root=new Node(arr[mid]);;
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);
    return root;
}

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	cout << node->key << " ";
	preOrder(node->left);
	preOrder(node->right);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Convert List to BST */
    Node *root = sortedArrayToBST(arr, 0, n-1);
	cout << "PreOrder Traversal of constructed BST \n";
	preOrder(root);

	return 0;
}

// This code is contributed by rathbhupendra
