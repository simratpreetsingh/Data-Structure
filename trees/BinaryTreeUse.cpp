#include <iostream>
#include "BinaryTreeNode.h"
#include "Queue.h"
#include "Stack.h"
#include "BinarySearchTree.h"
using namespace std;

void print(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data;
	if (root->left) {
		cout << " l:" << root->left->data;
	}

	if (root->right) {
		cout << " r:" << root->right->data;
	}
	cout << endl;
	print(root->left);
	print(root->right);
}

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = takeInput();
	root->right = takeInput();
	return root;
}

int maximumValue(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int maximum=root->data;
    int left=maximumValue(root->left);
    int right=maximumValue(root->right);
    if(left>right && left>maximum )
    {
        maximum=left;
    }
    else if(right>left && right>maximum)
    {
        maximum=right;
    }

    return maximum;

}
int sumOfNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}

bool checkIdentical(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1->data!=root2->data)
    {
            return false;
    }
        checkIdentical(root1->left,root2->left);
        checkIdentical(root1->right,root2->right);

}
int maximum(int a,int b)
{
return (a >= b)? a: b;
}

int height(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+maximum(height(root->left),height(root->right));
}

bool balanced(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return false;
    }
    int left=height(root->left);
    int right=height(root->right);
    if(left-right<=1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FindNode(BinaryTreeNode<int>* root,int node)
{
    if(root!=NULL)
    {
    if(root->data==node)
    {
        return true;
    }
    else
    {
        FindNode(root->left,node);
        FindNode(root->right,node);
    }
    }
    else
    {
        return false;
    }

}

void mirror(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        BinaryTreeNode<int>* temp;
        mirror(root->left);
        mirror(root->right);

        temp=root->left;
        root->left=root->right;
        root->right=temp;


    }
}
void printLeaf(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return ;
    }
    if(root->left==NULL && root->right==NULL)
    {
       root=NULL;
    }
    if(root->left!=NULL)
    {
    printLeaf(root->left);
    }
    if(root->right!=NULL)
    {
    printLeaf(root->right);
    }
}

void LevelWisePrint(BinaryTreeNode<int> * root) {
	Queue<BinaryTreeNode<int>*> q;
    cout<<root->data<<endl;
	q.enqueue(root);
	while (root!=NULL) {
            BinaryTreeNode<int> * temp=q.dequeue();
            if(temp->left)
            {
                q.enqueue(temp->left);
            }
            if(temp->right)
            {
                q.enqueue(temp->right);
            }

			}


}



void printLevel(BinaryTreeNode<int>* root,int level,bool ltr)
{
    if(root==NULL)
    {
        return ;
    }
    if(level==1)
    {
        cout<<root->data<<endl;
    }
    else if(level>1)
    {
        if(ltr)
        {
        printLevel(root->left,level-1,ltr);
        printLevel(root->right,level-1,ltr);
        }
        else
        {
        printLevel(root->right,level-1,ltr);
        printLevel(root->left,level-1,ltr);

        }
    }
}

void printSpiral(BinaryTreeNode<int>* root)
{
    int h=height(root);
    int i;
    bool ltr=false;
    for(int i=0;i<=h;i++)
    {
        printLevel(root,i,ltr);
        ltr=!ltr;
    }
}

void preOrder(BinaryTreeNode<int>* root)
{
    if(root)
    {
        cout<<root->data<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void InOrder(BinaryTreeNode<int>* root)
{
    if(root)
    {
        InOrder(root->left);
        cout<<root->data;
        InOrder(root->right);
    }
}

void PostOrder(BinaryTreeNode<int>* root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data;
    }
}

void PreOrderNonRecursive(BinaryTreeNode<int>* root)
{
Stack<BinaryTreeNode<int>*> s;
while(1)
{
    while(root)
    {
        cout<<root->data;
       // s.push(root->data);
        root=root->left;
    }
    if(s.isEmpty())
        break;
    root=s.pop();
    root=root->right;
}
}

int FindMax(BinaryTreeNode<int>* root)
{
    Queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int> * temp;
    int maximum=0;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        temp=q.dequeue();
        if(maximum<temp->data)
        {
            maximum=temp->data;
        }
        if(temp->left)
        {
            q.enqueue(root->left);
        }
        if(temp->right)
        {
            q.enqueue(root->right);
        }
    }
return maximum;

}

bool FindElement(BinaryTreeNode<int>* root,int element)
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data==element)
    {
        return true;
    }
    bool left=FindElement(root->left,element);
    bool right=FindElement(root->right,element);

    return left || right;
}

int FindElementNonRecursive(BinaryTreeNode<int>* root)
{
    Queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int> * temp;
    int maximum=0;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        temp=q.dequeue();
        if(maximum<temp->data)
        {
            maximum=temp->data;
        }
        if(temp->left)
        {
            q.enqueue(root->left);
        }
        if(temp->right)
        {
            q.enqueue(root->right);

    }
return maximum;

}
}
int size(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+ size(root->left)+size(root->right);
}

int SizeNonRecursive(BinaryTreeNode<int>* root)
{
     Queue<BinaryTreeNode<int>*> q;
     int count=0;
     BinaryTreeNode<int>* temp;
     q.enqueue(root);
     while(!q.isEmpty())
     {
         temp=q.dequeue();
         count++;
         if(temp->left)
         {
             q.enqueue(temp->left);
         }
         if(temp->right)
         {
             q.enqueue(temp->right);
         }

     }
     return count;
}
void LevelReversePrint(BinaryTreeNode<int>* root)
{
 Queue<BinaryTreeNode<int>*> q;
 Stack<BinaryTreeNode<int>*> s;
 BinaryTreeNode<int> * temp;
 q.enqueue(root);
 while(!q.isEmpty())
 {
    temp=q.dequeue();
    if(temp->right)
    {
        q.enqueue(temp->right);
    }
    if(temp->left)
    {
        q.enqueue(temp->left);
    }
    s.push(temp);
 }
 while(!s.isEmpty())
 {
     cout<<s.pop()->data<<" ";
 }
}
int LevelNonRecursive(BinaryTreeNode<int>* root)
{
    int level=1;
    Queue<BinaryTreeNode<int>*> q;
    q.enqueue(root);
    q.enqueue(NULL);
    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root==NULL)
        {
            if(!q.isEmpty())
            {
                q.enqueue(NULL);
                level++;
            }
        }
            else
            {
                if(root->left)
                {
                    q.enqueue(root->left);
                }
                if(root->right)
                {
                    q.enqueue(root->right);
                }
            }

    }
return level;
}

BinaryTreeNode<int>* deepestNode(BinaryTreeNode<int>* root)
{
 Queue<BinaryTreeNode<int>*> q;
 q.enqueue(root);
 BinaryTreeNode<int>* temp;
 while(!q.isEmpty())
 {
temp=q.dequeue();
if(root->left)
{
    q.enqueue(root->left);
}
if(root->right)
{
    q.enqueue(root->right);
}
 }
 return temp;

}

int NoOfLeafNodes(BinaryTreeNode<int>* root)
{
Queue<BinaryTreeNode<int>*> q;
q.enqueue(root);
int count=0;
BinaryTreeNode<int>* temp;
while(!q.isEmpty())
{
    temp=q.dequeue();
    if(temp->left && temp->right)
    {
        count++;
    }
    else
    {
        if(temp->left)
        {
            q.enqueue(temp->left);
        }
        if(temp->right)
        {
            q.enqueue(temp->right);
        }
    }

}
return count;
}

bool StructuralIdentical(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1==NULL || root2==NULL)
    {
        return false;
    }
    return (root1->data==root2->data && StructuralIdentical(root1->left,root2->left) && StructuralIdentical(root1->right,root2->right));
}

int diameter(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lHeight=height(root->left);
    int rHeight=height(root->right);
    int lDiameter=diameter(root->left);
    int rDiameter=diameter(root->right);
    return max(lHeight+rHeight+1,max(lDiameter,rDiameter));

}
void printArray(int path[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<path[i]<<" ";

    }
    cout<<endl;
}
void printPathRecursion(BinaryTreeNode<int> * root,int path[],int pathlength)
{
    if(root==NULL)
    {
        return ;
    }
    path[pathlength]=root->data;
    pathlength++;
    if(root->left==NULL && root->right==NULL)
    {
        printArray(path,pathlength);
    }
    else
    {
        printPathRecursion(root->left,path,pathlength);
        printPathRecursion(root->right,path,pathlength);
    }
}

bool HasSumPath(BinaryTreeNode<int> * root,int sum)
{
    if(root==NULL)
    {
        return(sum==0);
    }
    else
    {
        sum=sum-root->data;
        if(root->left && root->right || !root->left && !root->right)
            return ((HasSumPath(root->left,sum)) || HasSumPath(root->right,sum));
        else if(root->left)
            return HasSumPath(root->left,sum);
        else
            return HasSumPath(root->right,sum);

    }
}

int sumOfNodesNonRecursion(BinaryTreeNode<int>* root)
{
    Queue<BinaryTreeNode<int>*> q;
    int sum=0;
    q.enqueue(root);
    if(!q.isEmpty())
    {
        root=q.dequeue();
        if(root==NULL)
        {
            return sum;
        }
        else
        {
            sum=sum+root->data;
            if(root->left)
            {
                q.enqueue(root->left);
            }
            if(root->right)
            {
                q.enqueue(root->right);
            }
        }
    }
}
BinaryTreeNode<int>* MirrorBinaryTree(BinaryTreeNode<int> * root)
{
    BinaryTreeNode<int> * temp;
    if(root)
    {
        MirrorBinaryTree(root->left);
        MirrorBinaryTree(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;

    }
    return root;
}
bool AreMirror(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return 1;
    }
    if(root1==NULL || root2==NULL)
    {
        return 0;
    }
    if(root1->data!=root2->data)
    {
        return 0;
    }
    else
    {
        return AreMirror(root1->left,root2->right) || AreMirror(root1->right,root2->left);
    }
}
BinaryTreeNode<int>* Lca(BinaryTreeNode<int>* root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    BinaryTreeNode<int>* left=Lca(root->left,n1,n2);
    BinaryTreeNode<int>* right=Lca(root->right,n1,n2);
    if(left && right)
    {
        return root;
    }
    return (left!=NULL)?left:right;
}
int printAncestor(BinaryTreeNode<int>* root,int node)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==node)
    {
        return 1;
    }
    if( printAncestor(root->left,node) || printAncestor(root->right,node))
    {
        cout<<root->data;
        return 1;
    }
    return 0;
}
int main() {

	BinarySearchTree <int>* root=new BinarySearchTree<int>();
    printLeaf(root);
	//BinaryTreeNode<int>* root = takeInput();
	//printSpiral(root);

	//print(root);
    //BinaryTreeNode<int>* root1=MirrorBinaryTree(root);
    //print(root1);
	//int sum;
	//cin>>sum;
    //sumOfNodesNonRecursion(root);
	//int path[100];
	//printPathRecursion(root,path,0);
	//cout<<diameter(root);
	//cout<<"second tree";
	//BinaryTreeNode<int>* root2 = takeInput();
	//cout<<StructuralIdentical(root1,root2);
	/*cout<<"enter element";
	int element;
	cin>>element;
	cout<<FindElement(root,element);
	*/
	//printLeaf(root);
	//LevelWisePrint(root);
	//mirror(root);
	//cout<<endl;
	//cout<<"mirror is"<<endl;
	//print(root);
	//cout<<"next tree";
    //BinaryTreeNode<int>* root2 = takeInput();
	//print(root);
	//delete root;
	//int node;
	//cout<<"enter node";
	//cin>>node;
	//cout<<FindNode(root,node);
}

