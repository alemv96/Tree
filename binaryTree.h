//File: binaryTree.h
//Purpose:  Template for a binary tree class.

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

template <class E>
class BinaryTree{

	public:
		//constructor 
		BinaryTree() {root = 0x00;}
		
		//destructor
		~BinaryTree() {if(root) delete root;}
			//tree node type
			struct Node{
					
					//Constuctor.
					Node(E data){
						this -> data = data;
						left = 0x00;
						right = 0x00;
						parent = 0x00;
					}

	    	  			//this is a destructor.
					~Node(){
						if (left) delete left;
						if (right) delete right;
					}
				Node *left;		//left child 
				Node *right;	//right child
				Node *parent;	//parent
				E data;
			};
		
		//position node type 
		class Position {

				private :
					Node *v;   	//The node we are pointed at;
				public:
				 	Position(Node * _v = NULL) : v(_v){}
		
						//deference operator.
						E& operator*() {return v -> data;}
						//traversal function.
						Position left() const { return Position(v->left);}	
						Position right() const {return Position(v->right);}
						Position parent() const {return Position(v->parent);}					
			
						//status functions.			
						bool isRoot() const {return v -> parent == 0x00;}
						bool isExternal() const {return v->left == 0x00 && v->right == 0x00;}
						bool isPresent() const {return v != 0x00;}
				
						//make our outer class our friend 
						friend class BinaryTree<E>;
		};
				
			//insertion operations.
			void insertRootLeft(const E& data){

					Node *node = new Node(data);
					node -> left = root;
					root = node;	
			}

			void insertRootRight(const E& data){

				Node *node = new Node(data);
				node -> right = root;
				root = node;	

			}
			
			void insertLeft(const Position &p, const E& data){
				Node *node = new Node(data);
				node -> parent = p.v;
                  		node -> left = p.v ->	left;			
				p.v -> left = node;	
			}

			void insertRight(const Position &p , const E& data){
					Node *node = new Node(data);
					node -> parent = p.v;
					node -> right = p.v -> right;
					p.v -> right = node;			
			}
			
			// access the root of the tree.
			Position rootPosition() const {
					return Position (root);
			}		

	private:
		Node *root;

	};

#endif
