/************  BST from preorder traversals **************/ 
Node* constructTree ( int pre[], int size ){ 
	stack<Node *> st; 
	Node* root = newNode( pre[0] ); 
	st.push(root);
	for(int i = 1; i < size; ++i ){ 
		Node* temp = NULL; 
		while(!st.empty() && pre[i] > st.top()->data ){ 
			temp = st.top();
     	st.pop();
    }
		if( temp != NULL){ 
			temp->right = newNode( pre[i] ); 
			st.push(temp->right); 
		}  
		else{ 
			st.top()->left = newNode( pre[i] ); 
			st.push(st.top()->left); 
		} 
	} 
	return root; 
} 
/***********************************************************/
