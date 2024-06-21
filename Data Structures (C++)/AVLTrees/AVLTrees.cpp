#include <iostream>
using namespace std;

struct Node {
	int value;
	int h = 0;
	Node* left;
	Node* right;
};

//function for setting height

int GetHeight(Node* node, int h) {
	if (node != NULL) {
		h = GetHeight(node->left, h);
		node->h = h;
		h = 0;
		h = GetHeight(node->right, h);
		if (h >= node->h) {
			node->h = h;
			h++;
			return(h);
		}
		return(node->h + 1);
	}
	return(h);
}

void InOrder(Node* node) {
	if (node != NULL) {
		InOrder(node->left);
		cout << node->value << "   ";
		InOrder(node->right);
	}
}

void PreOrder(Node* node) {
	if (node != NULL) {
		cout << node->value << "   ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void PostOrder(Node* node) {
	if (node != NULL) {
		PostOrder(node->left);
		PostOrder(node->right);
		cout << node->value << "   ";
	}
}

int Checkleft(Node* node) { // sub function for checking if node's left is NULL or not and giving height of left 
	if (node->left == NULL) {
		return(-1);
    }
	return(node->left->h);
}

int Checkright(Node* node) {
	if (node->right == NULL) {
		return(-1);
	}
	return(node->right->h);
}

Node* Balance(Node* node) {
	
	//shift left
	if (Checkleft(node) + 1 < Checkright(node)) {// || node->left->h + 1 < node->right->h
		if (Checkleft(node->right) > Checkright(node->right)) {// double shift left
			Node* curr = node->right;//100
			Node* n = curr->left;//90
			Node* temp = n->right;
			n->right = curr;
			curr->left = temp;
			node->right = n;
		}
		Node* n = node->right;
		Node* temp = n->left;
		n->left = node;
		node->right = temp;
		return(n);
	}
	//shift right
	if (Checkleft(node) > Checkright(node)+1) {// || node->left->h > node->right->h +1
		if (Checkleft(node->left)<Checkright(node->left)){// double shift right
			Node* curr = node->left;
			Node* n = curr->right;
			Node* temp = n->left;
			n->left = curr;
			curr->right = temp;
			node->left = n;
		}
		Node* n = node->left;
		Node* temp = n->right;
		n->right = node;
		node->left = temp;
		return(n);
	}

	return(node);
}

Node* ADD(Node* node, int value,Node* Root) {
	if (node == NULL) {
		Node* temp = new Node;
		temp->value = value;
		temp->left = NULL;
		temp->right = NULL;
		
		return(temp);
	}
	if (value > node->value) {
		node->right = ADD(node->right, value,Root);
		int b = 0;
		GetHeight(Root, b);
		node=Balance(node);
		return(node);
	}
	else {
		node->left = ADD(node->left, value,Root);
		int b = 0;
		GetHeight(Root, b);
		node = Balance(node);
        return(node);
	}
}

void print(Node* node) {
	Node* temp = node;
	cout << node->value << endl;
	int a = 0;
	while (a != 4) {
		cout << "1 for left, 2 for right, 3 for root node, 4 for exit: ";
		cin >> a;
		if (a == 1) {
			if (node->left == NULL) {
				cout << "NULL" << endl;
				continue;
			}
			node = node->left;
			cout << node->value << endl;
		}
		if (a == 2) {
			if (node->right == NULL) {
				cout << "NULL" << endl;
				continue;
			}
			node = node->right;
			cout << node->value << endl;
		}
		if (a == 3) {
			node = temp;
		}
	}

}

void printheight(Node* node) {
	Node* temp = node;
	cout << node->h << endl;
	int a = 0;
	while (a != 4) {
		cout << "1 for left, 2 for right, 3 for root node, 4 for exit: ";
		cin >> a;
		if (a == 1) {
			if (node->left == NULL) {
				cout << "NULL" << endl;
				continue;
			}
			node = node->left;
			cout << node->h << endl;
		}
		if (a == 2) {
			if (node->right == NULL) {
				cout << "NULL" << endl;
				continue;
			}
			node = node->right;
			cout << node->h << endl;
		}
		if (a == 3) {
			node = temp;
		}
	}

}
void Search(Node* node, int value) {
	if (node->value == value) {
		cout << "value found" << endl;
		return;
	}
	if (value > node->value) {
		if (node->right == NULL) {
			cout << "Search NULL" << endl;
			return;
		}
		Search(node->right, value);
		return;
	}
	else {
		if (node->left == NULL) {
			cout << "Search NULL" << endl;
			return;
		}
		Search(node->left, value);
		return;
	}
}

Node* Delete(Node* node, int value) {
	if (node == NULL) {
		cout << "Tree is NULL" << endl;
		return(node);
	}
	if (node->value == value) {
		cout << "value found" << endl;
	}
	else {
		if (value > node->value) {
			if (node->right == NULL) {
				cout << "Search NULL" << endl;
				return(node);
			}
			node->right = Delete(node->right, value);
			return(node);
		}
		else {
			if (node->left == NULL) {
				cout << "Search NULL" << endl;
				return(node);
			}
			node->left = Delete(node->left, value);
			return(node);
		}
	}
	if (node->left == NULL) {
		Node* temp = node->right;
		free(node);
		return (temp);
	}
	if (node->right == NULL) {
		Node* temp = node->left;
		free(node);
		return (temp);
	}

	Node* temp = node->left;
	while (temp->right != NULL) {
		temp = temp->right;
	}
	node->value = temp->value;
	node->left = Delete(node->left, node->value);
	return(node);
}

int main() {
	Node* Root = NULL;
	int a = 0;
	int  b;
	while (a != 10) {
		cout << "1 for Add, 2 for print, 3 for searching, 4 for delete, 5 for GetHeight, 6 for Print Height, 7 for In order, 8 for Pre order, 9 for post order, 10 for exit: ";
		cin >> a;
		if (a == 1) {
			cout << "Enter value you want to add: ";
			cin >> b;
			Root = ADD(Root, b,Root);
		}
		else if (a == 2) {
			print(Root);
		}
		else if (a == 3) {
			cout << "Enter value you want to Search: ";
			cin >> b;
			Search(Root, b);
		}
		else if (a == 4) {
			cout << "Enter value you want to delete: ";
			cin >> b;
			Delete(Root, b);
		}
		else if (a == 5) {
			b = 0;
			GetHeight(Root, b);

		}
		else if (a == 6) {
			printheight(Root);
		}
		else if (a == 7) {
			InOrder(Root);
			cout << endl;
		}
		else if (a == 8) {
			PreOrder(Root);
			cout << endl;
		}
		else if (a == 9) {
			PostOrder(Root);
			cout << endl;
		}
	}
}