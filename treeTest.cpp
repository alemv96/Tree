#include <iostream>
#include <queue>
#include "binaryTree.h"
using namespace std;

void printInOrder(BinaryTree<char>::Position p){
	if (!p.isPresent()) return;
	
	//inorder traversal.
	printInOrder(p.left());	
	//print the node;
	cout << *p << " ";
	printInOrder(p.right());
}

void printPreOrder(BinaryTree<char>::Position p){
	
	if (!p.isPresent()) return;	
	
	cout << *p << " ";
	printPreOrder(p.left());
	printPreOrder(p.right());
	
}

void printPostOrder(BinaryTree<char>::Position p){
	if (!p.isPresent()) return;

	printPostOrder(p.left());
	printPostOrder(p.right());
	cout << *p <<" ";
}

void printBreadthFirst(BinaryTree<char>::Position p){
   BinaryTree<char>::Position node;
   queue<BinaryTree<char>::Position> q;
	
	//if (!p.isPresent())
		q.push(p);
	        
	while(!q.empty()){
		node = q.front();
		cout << *node << " ";	
		
		if (node.left().isPresent())  
			q.push(node.left());
		if (node.right().isPresent())
			q.push(node.right());
		
		q.pop();
	}
}

int main(){
	BinaryTree<char> t;
	/*
	 *
 	 *  Build the following tree
 	 *	      A
 	 *	    /   \
         *	   B     C
         *        / \   / \
   	 *       D   E F   G
         */
	 t.insertRootLeft('A');
	 BinaryTree<char>::Position p = t.rootPosition();
	 t.insertLeft(p , 'B');
	 t.insertRight(p , 'C');	
	 p = p.left();
	 t.insertLeft(p , 'D');
	 t.insertRight(p, 'E');
	 p = p.parent().right();
	 t.insertLeft(p , 'F');
	 t.insertRight(p , 'G');
		
	 //In order traversal
	 cout << "In order: " ;
	 printInOrder(t.rootPosition()); 
	 cout << endl; 
	
	 //Pre order traversal	
	 cout << "Pre - Order: ";
	 printPreOrder(t.rootPosition());
	 cout << endl;

	 //Post order traversal;
	 cout << "Post-Order: ";
	 printPostOrder(t.rootPosition());
	 cout << endl;

	 //Breadth-first trversal
	 cout << "Breadth-First:" ;
	 printBreadthFirst(t.rootPosition());
         cout << endl;
   
	return 0;
}
