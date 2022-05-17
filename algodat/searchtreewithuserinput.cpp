// AlgoDat Assignement 2 Binary find

#include<iostream>
using namespace std;



//define node
struct node {
	int data; 
	node* left; node* right;
};


//create empty node
node* emptyNode(int data) {
	node* newNode = new node();
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}

//fill nodes 
node* fill(node* root,int data) {
	if(root == NULL) { // empty tree
		root = emptyNode(data);

	}

	//sort numbers into nodes. lesser into left 
	else if(data <= root -> data) {
		root ->left = fill(root-> left, data);
	}

	//bigger into right 
	else {
		root->right = fill(root -> right,data);
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
		return find(root -> left, data);
	}

	else {
		return find(root -> right, data);
	}
}


void PrintBTS(){
}


//create tree an fill with hardcoded numbers
int main() {

    int n;
    int userNum;
    
    node* root = NULL;
    
    cout << "How many numebrs?: " << endl;
    cin >> n;
    for(int i = 0; i < n; n++) {
        cin >> userNum;
        root=fill(root, userNum);
    }


	//node* root = NULL; 
	root = fill(root,1);	
	root = fill(root,8);	
	root = fill(root,5);
	root = fill(root,6);
	root = fill(root,2);
	root = fill(root,3);
	root = fill(root,7);
	root = fill(root,9);
	root = fill(root,4);

	//number to be searched  
	int userSearch;
	cout << "Search Binary Tree for: ";
	cin>>userSearch;

	//confirm true/false
	if(find(root, userNum) == true) cout << "\nin Tree\n";
	else cout <<"\nnot in Tree\n";
}