#include <iostream>
#include <vector>
#include <stdexcept>

/*

PS: My professor was teaching us about exceptions in software design, and I thought I could use exceptions to exit from recursion stacks instead of having a base condition. 
This is a simpler version of the kth smallest element, which is much easier to understand.
*/


//class definition
struct TreeNode{
    TreeNode * right;
    TreeNode * left;
    int data;
    explicit TreeNode(int x): right(nullptr), left(nullptr), data(x){}
};

//creating a balanced BST from a sorted array
TreeNode* sortedArrayToBST(std::vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    auto* node = new TreeNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);
    return node;
}

//printing the tree in order
void printInOrder(TreeNode * root){
    if (root == nullptr) return;
    printInOrder(root->left);
    std::cout<<root->data<<' ';
    printInOrder(root->right);
}

//deleting the tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

//finding the kth smallest element in a BST using in order traversal and throwing an exception when found
void kthSmallestElement(TreeNode* root, int& k, bool &found) {
    if (root == nullptr) return;
    kthSmallestElement(root->left, k, found);
    k--;
    if (k == 0) {
        std::cout << root->data << std::endl;
        throw std::runtime_error("Found");
    }
    kthSmallestElement(root->right,k,found);
}

int main(){
    std::vector<int> sortedArr = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
    TreeNode* sortedRoot = sortedArrayToBST(sortedArr, 0, sortedArr.size() - 1);
    int kthSmallest;
    std::cout<<"Enter k: ";
    std::cin >> kthSmallest;
    bool found = false;

    //try catch block to catch the exception thrown by kthSmallestElement function
    try {
        kthSmallestElement(sortedRoot,kthSmallest, found);
    }
    catch(...){}
    
    std::cout<<"InOrder Print: ";
    printInOrder(sortedRoot);
    deleteTree(sortedRoot);
    return 0;
}
