//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

class Solution
{
public:
// first good approch 
//   bool search_in_bst(Node* root2, int search) {
//     if (root2 == NULL) {
//         return false;
//     }

//     if (root2->data == search) {
//         return true;
//     } else if (root2->data < search) {
//         return search_in_bst(root2->right, search);
//     } else {
//         return search_in_bst(root2->left, search);
//     }
// }
//     void take_node_from_bst(Node* &root,int &val,int x,Node* root2){
//         if(root == NULL){
//             return;
//         }
        
//         if(root->data > x){
//             take_node_from_bst(root->left,val,x,root2);
//         }
        
//         int search = x - root->data;
//         bool co = search_in_bst(root2,search);
//         if(co){
//             val++;
//         }
//         take_node_from_bst(root->left,val,x,root2);
//         take_node_from_bst(root->right,val,x,root2);
//     }
//         int countPairs(Node* root1, Node* root2, int x)
//         {
//             int val = 0;
//             take_node_from_bst(root1,val,x,root2);
//             return val;
//         }

   void inorder(Node* root, vector<int>& v) {
        if (root == NULL)
            return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    int countPairs(Node* root1, Node* root2, int x) {
        vector<int> t1, t2;

        inorder(root1, t1);
        inorder(root2, t2);

        int i = 0, j = t2.size() - 1;
        int val = 0;

        while (i < t1.size() && j >= 0) {
            int sum = t1[i] + t2[j];
            if (sum > x)
                j--;
            else if (sum < x)
                i++;
            else {
                val++;i++;j--;
                
            }
        }
        return val;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends