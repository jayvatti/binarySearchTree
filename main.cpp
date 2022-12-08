#include "TreeNode.h"

unsigned int TreeNode::kLeastCount = 0;
TreeNode* createBalacedTree(std::vector<int>& sortArray){
    std::sort(sortArray.begin(),sortArray.end())//sorting using std::sort
    ;
    TreeNode* head = TreeNode::buildBalancedTree(sortArray);//creating a balanced tree
    return head;//returning the head of that tree
}
void kthSmallestData(TreeNode* head, int k){
    TreeNode::kLeastCount = k;//updating the value of k
    TreeNode::kthSmallest(head);//getting the kth smallest element
}

int main(int argc, char** argv)
{
   int kthSmallest;//kth smallest
   std::cout<<std::endl;
   std::vector<int> sortArray{6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};//input vector
   TreeNode* head = createBalacedTree(sortArray);//creates a balanced tree

   //printing the vector
   std::cout<<"Vector: "; for(int i: sortArray){std::cout<<i<<' ';} std::cout<<std::endl;
   std::cout<<"Enter K: "; std::cin>>kthSmallest;//input : k
   kthSmallestData(head,kthSmallest);//printing the kth-smallest element

   std::cout<<std::endl<<std::endl;
   std::cout<<"InOrder Traversal:";
   TreeNode::inOrder(head);
   std::cout<<std::endl;
   TreeNode::PostOrderDestroy(head);//destroying from the heap
   std::cout<<std::endl<<std::endl;


}

