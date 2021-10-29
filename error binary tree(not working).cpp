#include<iostream>
using namespace std;
/*this procedure is different from udemy dsa course procedure. here we use recursion.
  here we frist create entire left side then right side.
*/
class Binary_Tree{
typedef struct Node{
   int val;
   Node* left;
   Node* right;
   }Node;
    Node* t=NULL;
        //pointing to root node of tree.
    int* arr=NULL;      //array of binary tree; for no node we assign array value=-1.
    int size=0;         //this array is filled in level-order method of tree.
public:
   Node* Root;
   Binary_Tree(int array[],int n){
     size=n;
    arr=new int[n+1];
    arr[0]=-1;
    for(int j=0;j<n;j++){arr[j+1]=array[j];}
    //Root=new Node;
    }

    void treeCreate(Node* root,int i=1){
      if(arr[i]==-1||i>size){root=NULL; }
      else{
        //t=new Node;
        //if(i==1){Root=t;}
        root=new Node;
        root->val=arr[i];
        treeCreate(root->left,2*i); //for left child of any node
        treeCreate(root->right,2*i+1);} //for right child of any node
    }

    ~Binary_Tree(){}

  void preOrder_treversal(Node* ptr){
    if(ptr!=NULL){
      cout<<ptr->val<<" ";

      preOrder_treversal(ptr->left);
      preOrder_treversal(ptr->right);}
  }



};


int main(){
int list[7]={3,5,7,8,9,10,11};
Binary_Tree b(list,7);
b.treeCreate(b.Root);
b.preOrder_treversal(b.Root);
  return 0;
}
