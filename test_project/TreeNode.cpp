#include<iostream>
using namespace std;
template<class ItemType>
class TreeNode{
public:
    ItemType info;
    TreeNode<ItemType>* left;
    TreeNode<ItemType>* right;
};

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree){
    if(tree == NULL) return 0;
    else return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}
template <class ItemType>
void Retrieve(TreeNode<ItemType>* ptr, ItemType& item, bool& found){
    if(ptr == NULL) found = false;
    else if(item < ptr->info)
        Retrieve(ptr->left, item, found);
    else if(item > ptr-> info)
        Retrieve(ptr->right, item, found);
    else{
        item = ptr -> info;
        found = true;
    }
}
template <class ItemType>
void Insert(TreeNode<ItemType>*& ptr, ItemType item){
    if(ptr == NULL){
        ptr = new TreeNode<ItemType>;
        ptr->right = NULL;
        ptr -> left = NULL;
        ptr->info = item;
    }
    else if(item < ptr ->info)
        Insert(ptr->left, item);
    else if(item > ptr-> info)
        Insert(ptr->right, item);
}
template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data){
    while(tree->right != NULL)
        tree = tree->right;
    data = tree -> info;
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item);

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree){
    ItemType data;
    TreeNode<ItemType>* tempPtr;
    tempPtr = tree;
    
    if(tree->left == NULL){
        tree = tree -> right;
        delete tempPtr;
    }
    else if(tree->right == NULL){
        tree = tree -> left;
        delete tempPtr;
    }
    else{
        GetPredecessor(tree->left, data);
        tree -> info = data;
        Delete(tree->left, data);
    }
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item){
    if(item < tree -> info)
        Delete(tree->left, item);
    else if(item > tree -> info)
        Delete(tree->right, item);
    else
        DeleteNode(tree);
}

template <class ItemType>
class TreeType{
    TreeNode<ItemType>* root;
public:
    int LengthIs() const{
        return CountNodes(root);
    }
    void RetrieveItem(ItemType& item, bool& found){
        Retrieve(root, item, found);
    }
    void InsertItem(ItemType item){
        Insert(root, item);
    }
    TreeType();
    ~TreeType();
    bool IsFull();
    void RetrieveITem(ItemType& item, bool& found) const;
    void DeleteItem(ItemType item){
        Delete(root, item);
    }
//    void GetNextItem(ItemType& item, OrderType order, bool& finished);
    void Print(std::ofstream& outfile) const;
};

