//
// Created by Jay Vatti on 10/9/22.
//

#include "TreeNode.h"

TreeNode::~TreeNode(){delete data;}//destructor

TreeNode* TreeNode::buildBalancedTree(std::vector<int>& sortArray){//building a Balanced Tree
    //recursive function

    if(sortArray.empty()){return nullptr;}//returns nullptr if the array is empty
    unsigned int middle = sortArray.size()/2;//middle index
    auto* root = new TreeNode(new int(sortArray[middle]));//assigning the middle index

    //creating 2 vectors for left and right int
    std::vector<int> rightV(sortArray.begin() + (middle + 1), sortArray.end());
    std::vector<int> leftV;
    sortArray.size()%2 == 0? leftV.assign(sortArray.begin(), sortArray.end() - middle):
                             leftV.assign(sortArray.begin(), sortArray.end() - (middle + 1));

    //passing the vectors for left and right respectively
    root->right = buildBalancedTree(rightV);
    root->left = buildBalancedTree(leftV);
    return root;

}
void TreeNode::kthSmallest(TreeNode* root){
    //in-order traversal //kLeastCount is static
    if(root == nullptr){return;}
    kthSmallest(root->left);
    kLeastCount--;
    //returns root->data if kLeastCount == 0;
    if(kLeastCount == 0){std::cout<<"Kth Smallest Element: "<< *(root->data);return;}
    kthSmallest(root->right);
}
void TreeNode::PostOrderDestroy(TreeNode* root){
    //postOrder Destroy from the heap
    if(root == nullptr){return;}
    PostOrderDestroy(root->left);
    PostOrderDestroy(root->right);
    delete root;
}

void TreeNode::inOrder(TreeNode *root) {
    //inOrder Printing //DEBUG TEST
    if(root == nullptr){return;}
    inOrder(root->left);
    std::cout<<*(root->data)<<" ";
    inOrder(root->right);
};



