#include <iostream>

using namespace std;

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

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }

    void insertNode(TreeNode *newNode)
    {
        if (root == NULL)
        {
            root = newNode;
            cout << "Inserted as root node" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (newNode->value == temp->value)
                {
                    cout << "Value already exists";
                    return;
                }
                else if ((newNode->value < temp->value) && (temp->left == NULL))
                {
                    temp->left = newNode;
                    cout << "Value inserted" << endl;
                    break;
                }
                else if (newNode->value < temp->value)
                {
                    temp = temp->left;
                }
                else if ((newNode->value > temp->value) && (temp->right == NULL))
                {
                    temp->right = newNode;
                    cout << "Value inserted" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

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

    TreeNode *iterativeSearch(int v)
    {
        if (root == NULL || root->value == v)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (v == temp->value)
                {
                    return temp;
                }
                else if (v < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    TreeNode *recursiveSearch(TreeNode *r, int val)
    {
        if (r == NULL || r->value == val)
            return r;
        else if (val < root->value)
            return recursiveSearch(r->left, val);
        else
            return recursiveSearch(r->right, val);
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *maxValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current->right != NULL)
        {
            current = current->right;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *r, int v)
    {
        if (r == NULL)
            return NULL;
        else if (v < r->value)
            r->left = deleteNode(r->left, v);
        else if (v > r->value)
            r->right = deleteNode(r->right, v);
        else
        {
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                TreeNode *temp = minValueNode(r->right);
                r->value = temp->value;
                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }
};

int main()
{
    BST obj;
    int option, val;
    do
    {
        cout << "\n0. EXIT" << endl;
        cout << "1. insert node" << endl;
        cout << "2. Traverse Node" << endl;
        cout << "3. Search Node" << endl;
        cin >> option;
        TreeNode *newNode = new TreeNode();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the value to insert in Tree: ";
            cin >> val;
            newNode->value = val;
            obj.insertNode(newNode);
            break;
        case 2:
            cout << "\n1. BFS/LevelOrder Traverse" << endl;
            obj.levelOrderTraverse(obj.root);
            cout << "\n2. DFS, PreOrder Traverse" << endl;
            obj.preorderTraverse(obj.root);
            cout << "\n3. DFS, InOrder Traverse" << endl;
            obj.inorderTraverse(obj.root);
            cout << "\n4. DFS, PostOrder Traverse" << endl;
            obj.postorderTraverse(obj.root);
            break;
        case 3:
            cout << "Enter the value to be searched";
            cin >> val;
            if (obj.iterativeSearch(val) != NULL)
            {
                cout << "Value Found" << endl;
            }
            else
            {
                cout << "Value not found" << endl;
            }
            break;
        default:
            cout << "Please Enter correct Option";
        }
    } while (option != 0);
    return 0;
}