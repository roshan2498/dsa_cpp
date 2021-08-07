#include"tree.h"

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


Node *lca(Node *root,int a,int b){
	
	if(root == NULL) return NULL;

	if(root->data == a or root->data == b) return root;

	Node *left_lca = lca(root->left,a,b);
	Node *right_lca= lca(root->right,a,b);

	if(left_lca != NULL and right_lca != NULL) return root;
	return(left_lca != NULL)?left_lca:right_lca;
}

void preorder(Node *root){
	// root left right
	if(root != NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}

}


int main(int argc, char const *argv[]) {
    file_i_o();
    Node*root = NULL;
    root = buildTree();
    preorder(root);
    cout<<lca(root,4,9)->data<<endl;
    return 0;
}