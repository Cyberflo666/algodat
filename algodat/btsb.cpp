// AlgoDat Assignement 2 Binary find

#include<fstream>
#include<iostream>
using namespace std;



//define node
struct node {
	int data; 
	node* lchild; node* rchild;
};


//create empty node
node* emptyNode(int data) {
	node* newNode = new node();
	newNode -> data = data;
	newNode -> lchild = newNode -> rchild = NULL;
	return newNode;
}

//fill nodes 
node* fill(node* root,int data) {
	if(root == NULL) { 
		root = emptyNode(data);

	}

	//sort numbers into nodes. lesser into lchild 
	else if(data <= root -> data) {
		root ->lchild = fill(root-> lchild, data);
	}

	//bigger into rchild 
	else {
		root->rchild = fill(root -> rchild,data);
	}

	return root;
}

//search algorithm 
bool find(node* root,int data) {
	if(root == NULL) {
		return false;
	}

	else if(root -> data == data) {
		return true;
	}

	else if(data <= root -> data) {
		return find(root -> lchild, data);
	}

	else {
		return find(root -> rchild, data);
	}
}




void PrintBST(){
	ofstream dotfile;
	std::remove ("Bintree.dot");
	dotfile.open ("Bintree.dot");
	dotfile << "digraph G {";
	dotfile << 
	dotfile.close();
}



//create tree an fill with hardcoded numbers
int main() {

    int n;
    int userNum;
    
    node* root = NULL;
    cout << "Binary Search Tree"<< endl;
    cout << "How many numebrs?: " << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
		cout << "Enter Number: " << endl;
        cin >> userNum;
        root=fill(root, userNum);
    }
    

	cout << "Tree created" << endl;

	/*node* root = NULL; 
	root = fill(root,1);	
	root = fill(root,8);	
	root = fill(root,5);
	root = fill(root,6);
	root = fill(root,2);
	root = fill(root,3);
	root = fill(root,7);
	root = fill(root,9);
	root = fill(root,4);*/

	/**/
	PrintBST();

	//number to be searched  
	int userSearch;
	cout << "Search Binary Tree for: ";
	cin>>userSearch;

	//confirm true/false
	if(find(root, userSearch) == true) cout << "\nin Tree\n";
	else cout <<"\nnot in Tree\n";
}