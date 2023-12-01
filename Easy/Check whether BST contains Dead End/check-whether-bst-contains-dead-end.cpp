//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    
//     bool ans(Node *root, int minvalue, int maxvalue)
// {

//     if (root->left == NULL && root->right == NULL) {
//         if (root->data == minvalue && root->data == maxvalue) {
//             return true;
//         } else {
//             return false;
//         }
//     }

//     int val = root->data;

//     bool x = ans(root->left, minvalue, val);
//     bool y = ans(root->right, val, maxvalue);

//     return x || y;
// }

// bool isDeadEnd(Node *root)
// {
//     if (root == NULL) {
//         return true;
//     }

//     if (root->left == NULL && root->right == NULL) {
//         return true;
//     }

//     int val = 0;
//     int minvalue = 0;
//     int maxvalue = INT_MAX;

//     return ans(root, minvalue, maxvalue);
// }

vector<int> arr, leaf;
    
    void inorder(Node* node){
        if(!node)
            return;
        
        inorder(node->left);
        arr.push_back(node->data);
        if(!node->left && !node->right)
            leaf.push_back(node->data);
        inorder(node->right);
    }
    
    bool isDeadEnd(Node *root)
    {
        arr = {0};  // Initialize with a 0 value to handle the edge case of root being 1.
        leaf = {};
        inorder(root);
        
        int j = 0;
        for(int i = 1; i < arr.size() && j < leaf.size(); ++i){
            if(arr[i] == leaf[j]){
                if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                    return true;
                ++j;
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends