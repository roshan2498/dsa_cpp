#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *left,*right;

		Node(int data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

Node *buildTree(){
	int d;
	cin>>d;
	if(d == -1){
		return NULL;
	}

	Node *temp = new Node(d);
	temp->left = buildTree();
	temp->right = buildTree();

	return temp;
}

void preorder(Node *root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void levelOrderTraversal(Node *root){
	queue<Node*> q;

	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		auto curr = q.front();
		if(curr == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}

		else{
			q.pop();
			cout<<curr->data<<" ";
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
	}
}


// using recursive traverse
void leftViewRec(Node *root,int level,int *maxLevel){
	if(root == NULL) return;
	if(*maxLevel < level){
		cout<<root->data<<" ";
		*maxLevel = level;
	}

	leftViewRec(root->left, level+1, maxLevel);
	leftViewRec(root->right, level+1, maxLevel);
}
// Iterarive using queue
void leftView(Node *root){
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();

		for(int i=1;i<=n;i++){
			auto curr = q.front();
			q.pop();
			if(i==1){
				cout<<curr->data<<" ";
			}
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
	}
}

void leftNodes(Node *root){
	if(root->left == NULL){
		return;
	}

	cout<<root->data<<" ";
	leftNodes(root->left);
}

void rightNodes(Node *root){
	if(root->right == NULL){
		return;
	}

	cout<<root->data<<" ";
	rightNodes(root->right);
}

void leafNodes(Node *root){
	if(root == NULL) return;
	if(!root->left and !root->right){
		cout<<root->data<<" ";
	}
	leafNodes(root->left);
	leafNodes(root->right);
}


void boundaryTraversal(Node *root){
	leftNodes(root);
	leafNodes(root);
	rightNodes(root->right);
}

int main(int argc, char const *argv[])
{
	file_i_o();
	Node *root = NULL;
	root = buildTree();
	// preorder(root);
	// cout<<endl;
	// levelOrderTraversal(root);
	// cout<<endl;
	// leftView(root);
	// cout<<endl;
	// int maxLevel = 0;
	// leftViewRec(root,1,&maxLevel);
	boundaryTraversal(root);
	return 0;
}