#include<iostream>

using namespace std;

struct Tree {
	int value;
	Tree* left;
	Tree* right;

	Tree(int v) : value(v), left(nullptr), right(nullptr) {}
};


Tree* insert(Tree* tree, int n){
	if(tree == nullptr){
		return new Tree(n);
	}else if(tree->value < n){
		tree->right = insert(tree->right, n);
	}else{
		tree->left = insert(tree->left, n);
	}

	return tree;
}

void preorder(Tree* tree){
	if(tree == nullptr) return;
	cout << tree->value << "\n";
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(Tree* tree){
	if(tree == nullptr) return;
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->value << "\n";
}

void deleteTree(Tree* tree){
	if(tree == nullptr) return;
	deleteTree(tree->left);
	deleteTree(tree->right);
	delete tree;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	Tree* root = nullptr;
    while(cin >> n){
		root = insert(root, n);
	}



//	preorder(root);
	postorder(root);

    deleteTree(root);


}
