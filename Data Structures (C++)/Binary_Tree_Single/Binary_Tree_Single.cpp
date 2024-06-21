#include <iostream>
#include <queue>
using namespace std;

struct Node {
	string value;
	int h = 0;
	int level;
	Node* left;
	Node* right;
};

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
//umer print
void printt(const string& prefix, Node* parent, bool isLeft, bool isRoot) {
	if (parent == NULL)
		return;

	if (isRoot) {
		cout << "RT----";
	}
	else {
		cout << prefix <<
			(isLeft ? "(L)|----" : "(R)L----");
	}
	// print the value of the node
	cout << parent->value << endl;

	// enter the next tree level - left and right branch
	printt(prefix + (isLeft ? "   | " : "    "),
		parent->left, true, false);
	printt(prefix + (isLeft ? "   | " : "    "),
		parent->right, false, false);
}
// pass the root node of your binary tree
void printBT(Node* node) {
	printt("", node, false, true);
}

Node* ADD(Node* node, string value) {
	if (node == NULL) {
		Node* temp = new Node;
		temp->value = value;
		temp->left = NULL;
		temp->right = NULL;

		return(temp);
	}
	//Else, do level order traversal until we find an empty
	// place, i.e. either left child or right child of some
	// node is pointing to NULL.
		queue<Node*> q;
	q.push(node);

	while (!q.empty()) {
		Node* temp1 = q.front();
		q.pop();

		if (temp1->left != NULL)
			q.push(temp1->left);
		else {
			temp1->left = ADD(temp1->left, value);
			return node;
		}

		if (temp1->right != NULL)
			q.push(temp1->right);
		else {
			temp1->right = ADD(temp1->right, value);
			return node;
		}
	}
}

void Mirror(Node* a) {
	if (a == NULL)return;

	Mirror(a->left);
	Mirror(a->right);
	Node* temp = a->left;
	a->left = a->right;
	a->right = temp;
}

Node* height(Node* node, string d) {
	if (node == nullptr) {
		return node;
	}
	if (node->value == d) {
		cout << node->h << endl;
	}
	node->left = height(node->left, d);
	node->right = height(node->right, d);
	return node;
}

void level(Node* node, int d) {
	if (node == NULL) {
			return;  // Assuming level is 0-based. if 1 based then send 1 from main
	}



	level(node->left, d+1);
	level(node->right, d+1);

	node->level = d;

}

void LevelPrint(Node* node,string d) {
	if (node == NULL) {
		return;
	}
	if (node->value == d) {
		cout << "Level is: " << node->level<<endl;
		return;
	}
	
	LevelPrint(node->left,d);
	LevelPrint(node->right,d);

	
}


Node* PreAndSuc(Node* node, string d, Node*& pre) {

	if (node == NULL) {
		return node;
	}
	if (node->value == d) {
		if (pre != NULL) {
			cout << pre->value << endl;
		}
		else {
			cout << "no predecessor exists!" << endl;
		}
		if (node->left != NULL) {
			cout << node->left->value << endl;
		}
		else {
			cout << "no left successor exists!" << endl;
		}
		if (node->right != NULL) {
			cout << node->right->value << endl;
		}
		else {
			cout << "no right successor exists!" << endl;
		}
		return node;
	}
	pre = node;
	node->left = PreAndSuc(node->left, d, pre);
	pre = node;
	node->right = PreAndSuc(node->right, d, pre);
	return node;
}


int main() {
	Node* Root = NULL;
	int c = 0;
	int a = 0;
	string  b;
	while (a != 20) {
		cout << "1 for Add, 2 for print, 3 for searching, 4 for delete, 5 for In order, 6 for Pre order, 7 for post order, 8 for exit: ";
		cin >> a;
		if (a == 1) {
			cout << "Enter string you want to add: ";
			cin >> b;
			Root = ADD(Root, b);
		}
		else if (a == 2) {
			print(Root);
		}
		else if (a == 3) {
			Mirror(Root);
		}
		else if (a == 4) {
			c = 0;
			GetHeight(Root,c);
			cout << "Enter string: ";
			cin >> b;
			height(Root, b);
		}
		else if (a == 5) {
			c = 0;
			level(Root, c);
			cout << "Enter string: ";
			cin >> b;
			LevelPrint(Root, b);
		}
		else if (a == 9) {
			InOrder(Root);
			cout << endl;
		}
		else if (a == 10) {
			PreOrder(Root);
			cout << endl;
		}
		else if (a == 11) {
			PostOrder(Root);
			cout << endl;
		}
		else if (a == 12) {
			printBT(Root);
		}
	}
}