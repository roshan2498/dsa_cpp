#include<bits/stdc++.h>
using namespace std;



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

class node{
	public:	
		int val;
		node *left,*right;

		node(int val){
			this->val=  val;
			left = NULL;
			right = NULL;
		}	
};

// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
vector<int> input = {1, 2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1};
int idx = 0;

node *buildTree(){
	int d = input[idx++];
	if(d == -1){
		return NULL;
	}
	
	node *n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void levelOrder(node *root){
	queue<node*> q;
	
	q.push(root);
	q.push(NULL); //push NULL to the queue

	while(!q.empty()){
		auto x = q.front(); //pop the front node

		if(x == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){  
				q.push(NULL); // this step is important to mark end of the level
			}
		}

		else{
			q.pop();
			cout<<x->val<<" ";
			if(x->left) q.push(x->left);
			if(x->right) q.push(x->right);
		}
	}
}

// level order traversal when we need to return a vector of vector
map<int,vector<int>> mp;
void traverse(node *root, int d){
	if(root == NULL) return;

	mp[d].push_back(root->val);
	traverse(root->left, d+1);
	traverse(root->right,d+1);
}

vector<vector<int>> levelorderfast(node *root){
	mp.clear();
	traverse(root,0);
	vector<vector<int>> ret;
	for(auto x : mp){
		ret.push_back(x.second);
	}

	return ret;
}

// Input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
node* buildLevelOrder(){
	int d;
	cin>>d;

	node *root = new node(d);

	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node *current = q.front();
		q.pop();

		int c1,c2;
		cin>>c1>>c2;

		if(c1 != -1){
			current->left = new node(c1);
			q.push(current->left);
		}
		if(c2 != -1){
			current->right = new node(c2);
			q.push(current->right);
		}
	}

	return root;
}

int main(int argc, char const *argv[]) {
    // file_i_o();
	node *root = buildLevelOrder();
	// levelOrder(root);
	vector<vector<int>> ret = levelorderfast(root);
	for(auto lvl : ret){
		for(auto x : lvl){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}