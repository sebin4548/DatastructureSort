//#include<iostream>
//// #include "BinarySearchTree.hpp"
//using namespace std;
//
//template<class ItemType>
//struct TreeNode{
//    ItemType info;
//    TreeNode<ItemType>* left;
//    TreeNode<ItemType>* right;
//};
//
//template<class ItemType>
//class TreeType{
//public:
//    TreeType();
//    ~TreeType();
//    TreeType(const TreeType<ItemType>& originalTree);
//    void operator=(const TreeType<ItemType>& originalTree);
//    void MakeEmpty();
//    bool IsEmpty() const;
//    bool IsFull() const;
//    int GetLength() const;
//    ItemType GetItem(ItemType item, bool& found);
//    void PutItem(ItemType item);
//    void DeleteItem(ItemType item);
//
//
//    void Print() const;
//private:
//    TreeNode<ItemType>* root;
//};
//
//template<class ItemType>
//void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree){
//    if(originalTree == NULL)
//        copy = NULL;
//    else{
//        copy = new TreeNode<ItemType>;
//        copy -> info = originalTree -> info;
//        CopyTree(copy -> left, originalTree -> left);
//        CopyTree(copy -> right, originalTree -> right);
//    }
//}
//template<class ItemType>
//TreeType<ItemType>::TreeType(const TreeType<ItemType>& originalTree){
//    CopyTree(root, originalTree.root);
//}
//
//template<class ItemType>
//void Insert(TreeNode<ItemType>*& ptr, ItemType item){
//    if(ptr == NULL){
//        ptr = new TreeNode<ItemType>;
//        ptr->right = NULL;
//        ptr -> left = NULL;
//        ptr->info = item;
//    }
//    else if(item < ptr ->info)
//        Insert(ptr->left, item);
//    else if(item > ptr-> info)
//        Insert(ptr->right, item);
//}
//
//template<class ItemType>
//void TreeType<ItemType>::PutItem(ItemType item){
//    Insert(root, item);
//}
//int main(){
//    TreeType<int> tree;
//    tree.PutItem(5);
//    tree.PutItem(3);
//    tree.PutItem(4);
//    tree.PutItem(2);
//    tree.PutItem(7);
//    tree.PutItem(6);
//    tree.PutItem(8);
//    tree.Print();
//    return 0;
//}
