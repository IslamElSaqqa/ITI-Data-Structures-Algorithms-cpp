#include <iostream>
using namespace std;
struct BtNode{
        int data;
        BtNode *left, *right;
            
        BtNode (int data)
            {
                this->data = data;
                left = right = nullptr;
            }
    };

class BTree{

    BtNode *root;
    public:
        BTree() : root(nullptr) {};
    
        //^ Check that Tree isEmpty!
        bool isEmpty() { return root == nullptr; }

        //^insert Node
        void insert(int d)
        {
            root = insertNode(root, d);
        }

        //^counting Nodes
        int count() { return countNodes(root); }

        //^Pre order Tree Traversal
        void preOrderTree()
        {
            preOrder(root);
            cout << endl;
        }

        //^Post order Tree Traversal
        void postOrderTree()
        {
            postOrder(root);
            cout << endl;
        }

        //^Pre order Tree Traversal
        void inOrderTree()
        {
            inOrder(root);
            cout << endl;
        }

        //^insert Node
    private:
        BtNode *insertNode (BtNode *node, int d ){
            if(!node)
                return new BtNode(d);

            else
            {
                if (d < node->data)
                    node->left = insertNode(node->left, d);
                else
                    node->right = insertNode(node->right, d);
            }
            return node;
        }

        //^Count Nodes
        int countNodes(BtNode*node)
        {
            int count;
            if (!node)
                count = 0;
            else
            {
                int x = 1;
                x += countNodes(node->left);
                x += countNodes(node->right);
                count = x;
            }
            return count;
            }
    
        //^preOrderTree
        void preOrder(BtNode *node)
        {
            if(!node) return;

            //? 1-> process root.
            cout << node->data << " ";
            //? 2 ->Traverse Left.
            preOrder(node->left);
            //? 3-> Traverse Right
            preOrder(node->right);
            
        
        }

        //^Post Order Traversal
        void postOrder(BtNode* node)
        {
            if(!node) return;
            
            //? 1 ->Traverse Left.
            postOrder(node->left);
            //? 2-> Traverse Right
            postOrder(node->right);
            //? 3-> process root.
            cout << node->data << " ";
            
        }

        //^Inorder Traversal
        void inOrder(BtNode* node)
        {
            if(!node) return;
            
            //? 1 ->Traverse Left.
            inOrder(node->left);
            //? 2-> process root.
            cout << node->data << " ";
            //? 3-> Traverse Right
            inOrder(node->right);
                
        }

};

int main()
{
    BTree t;
    //^ Check is the Tree empty?
    cout << "Is the Tree Empty? " << t.isEmpty() << endl;
    //^inserting Nodes
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    cout << "After Insertion:\nIs the Tree Empty? " << t.isEmpty() << endl;
    
    //^counting Nodes
    cout << "Total number of nodes in BST: " << t.count() << endl;

    //^Tree Traversal
    //& Preorder
    cout << "PreOrder Tree Traversal : " << endl;
    t.preOrderTree();
    cout << "************" << endl;

    //& Inorder
    cout << "In Order Tree Traversal: " << endl;
    t.inOrderTree();
    cout << "*************" << endl;

    //& PostOrder
    cout << "Post Order Tree Traversal: " << endl;
    t.postOrderTree();

    
}
