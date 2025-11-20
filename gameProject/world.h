#include <iostream>
#include <string>
using namespace std;

struct TreeNode 
{
    string name;
    string description;
    string item;
    TreeNode* left;
    TreeNode* right;
};

// Create a new node
TreeNode* createNode(const string& name, const string& description, const string& item = "") 
{
    return new TreeNode{name, description, item, nullptr, nullptr};
}

// Build the world with ≥ 7 nodes
TreeNode* createWorld() 
{
    TreeNode* root = createNode("Forest Entrance", "You stand at the edge of a dense forest.", "torch");
    root->left = createNode("Dark Cave", "A damp cave with echoes of dripping water.", "sword");
    root->right = createNode("Sunny Meadow", "A bright meadow filled with wildflowers.", "flower");

    root->left->left = createNode("Hidden Chamber", "A secret chamber deep inside the cave.", "key");
    root->left->right = createNode("Pit", "A dangerous pit. Watch your step.");

    root->right->left = createNode("Stream", "A gentle stream flows here.", "map");
    root->right->right = createNode("Abandoned Cabin", "An old cabin with broken windows.", "shield");

    return root;
}

// Traversals
void preorder(TreeNode* root) 
{
    if (!root) return;
    cout << root->name << "\n";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) 
{
    if (!root) 
        return;
    inorder(root->left);
    cout << root->name << "\n";
    inorder(root->right);
}

void postorder(TreeNode* root) 
{
    if (!root) 
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->name << "\n";
}

// Find node by name
TreeNode* findByName(TreeNode* root, const string& name) 
{
    if (!root) 
        return nullptr;
    if (root->name == name) 
        return root;
    TreeNode* leftResult = findByName(root->left, name);
    if (leftResult) 
        return leftResult;
    return findByName(root->right, name);
}

// Delete tree
void deleteTree(TreeNode* root) 
{
    if (!root) 
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}