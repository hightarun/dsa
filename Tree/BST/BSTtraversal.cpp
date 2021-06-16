#include <iostream>
using namespace std;

//Class TreeNode represent each node
class TreeNode
{
public:
    int data;
    TreeNode *leftNode{nullptr};
    TreeNode *rightNode{nullptr};

    TreeNode();
    TreeNode(int d);
    void insertData(int d);
    void inorderTraverse();
    void preorderTraverse();
    void postorderTraverse();
    void levelOrderTraverse();
};

//Implementing TreeNode class prototypes function.
TreeNode::TreeNode(int d)
{
    data = d;
}

//Inserting node as a left child if it is smaller than the current node
//else it will be inserted as the right child
// Assuming no two numbers/nodes are same
void TreeNode::insertData(int d)
{
    if (d < data)
    {
        if (leftNode == nullptr)
        {
            leftNode = new TreeNode(d);
        }
        else
        {
            leftNode->insertData(d);
        }
    }
    else
    {
        if (rightNode == nullptr)
        {
            rightNode = new TreeNode(d);
        }
        else
        {
            rightNode->insertData(d);
        }
    }
}

// Inorder traversal algorithm
void TreeNode::inorderTraverse()
{
    //1.Left subtree
    if (leftNode != nullptr)
    {
        leftNode->inorderTraverse();
    }
    //2. Root
    cout << data << " ";
    //3. Right subtree
    if (rightNode != nullptr)
    {
        rightNode->inorderTraverse();
    }
}

// Preorder traversal algorithm
void TreeNode::preorderTraverse()
{
    //1. Root
    cout << data << " ";
    //2.Left subtree
    if (leftNode != nullptr)
    {
        leftNode->preorderTraverse();
    }
    //3. Right subtree
    if (rightNode != nullptr)
    {
        rightNode->preorderTraverse();
    }
}

// Postorder Traversal Algorithm
void TreeNode::postorderTraverse()
{
    //1.Left subtree
    if (leftNode != nullptr)
    {
        leftNode->postorderTraverse();
    }
    //2. Right subtree
    if (rightNode != nullptr)
    {
        rightNode->postorderTraverse();
    }
    //3. Root
    cout << data << " ";
}

int main()
{
    //Taking root node as 25
    TreeNode *root = new TreeNode(25);

    //inserting data into the binary tree
    root->insertData(20);
    root->insertData(31);
    root->insertData(19);
    root->insertData(23);
    root->insertData(26);
    root->insertData(36);

    //Calling inorder traversal function from root object
    cout << "\n Inorder: ";
    root->inorderTraverse();

    cout << "\n Preorder: ";
    root->preorderTraverse();

    cout << "\n Postorder: ";
    root->postorderTraverse();

    return 0;
}