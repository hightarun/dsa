#include <iostream>
using namespace std;

//structure for tree node
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

//BFS level order traversal
void givenLevel(TreeNode *node, int level)
{
    if (node == NULL)
        return;
    if (level == 1)
        cout << node->value << " ";
    else if (level > 1)
    {
        givenLevel(node->left, level - 1);
        givenLevel(node->right, level - 1);
    }
}
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void levelOrderTraverse(TreeNode *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        givenLevel(root, i);
    }
}

//DFS
void preorderTraverse(TreeNode *node) //root , left , right
{
    if (node == NULL)
    {
        return;
    }
    cout << node->value << " ";
    preorderTraverse(node->left);
    preorderTraverse(node->right);
}

void postorderTraverse(TreeNode *node) //left , right , root
{
    if (node == NULL)
    {
        return;
    }
    postorderTraverse(node->left);
    postorderTraverse(node->right);
    cout << node->value << " ";
}

void inorderTraverse(TreeNode *node) //left ,root ,right
{
    if (node == NULL)
    {
        return;
    }
    inorderTraverse(node->left);
    cout << node->value << " ";
    inorderTraverse(node->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "\n\t BFS";
    cout << "\nLevel Order : \n";
    levelOrderTraverse(root);

    cout << "\n\n\t DFS ";
    cout << "\nPreorder : \n";
    preorderTraverse(root);
    cout << "\nPostorder : \n";
    postorderTraverse(root);
    cout << "\nInorder : \n";
    inorderTraverse(root);
    return 0;
}