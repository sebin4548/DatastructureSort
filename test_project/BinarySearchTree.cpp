#include<iostream>
template <class ItemType>
struct TreeNode {
    ItemType info;
    TreeNode<ItemType> *left;
    TreeNode<ItemType> *right;
};
template <class ItemType>
void Insert(TreeNode<ItemType> *&tree, ItemType item){
    if(tree == NULL){
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if(item < tree->info){
        Insert(tree->left, item);
    }
    else{
        Insert(tree->right, item);
    }
}
template <class ItemType>
void PrintTree(TreeNode<ItemType> *tree){
    if(tree != NULL){
        PrintTree(tree->left);
        std::cout << tree->info << std::endl;
        PrintTree(tree->right);
    }
}
template <class ItemType>
void Destroy(TreeNode<ItemType> *&tree){
    if(tree != NULL){
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}
template <class ItemType>
class TreeType{
    public:
        TreeType(){
            root = NULL;
        }
        ~TreeType(){
            Destroy(root);
        }
        
        // bool IsEmpty();
        // bool IsFull();
        // int GetLength();
        // ItemType GetItem(ItemType item, bool &found);
        void PutItem(ItemType item){
            Insert(root, item);
        }
        // void DeleteItem(ItemType item);

        void Print(){
            PrintTree(root);
        }
    private:
        TreeNode<ItemType> *root;
};
int main(){
    TreeType<int> tree;
    tree.PutItem(5);
    tree.PutItem(3);
    tree.PutItem(4);
    tree.PutItem(2);
    tree.Print();
    return 0;
}