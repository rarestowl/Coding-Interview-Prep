/************  BST deletion ******************************/
        if (!root) return root;
        
        if (val < root->val) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->val) {
            root->right = deleteNode(root->right, val);
        } else {
            /* Leaf node case */
            if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            /* 1 child case */
            if (!root->left || !root->right) {
                TreeNode *ret = root->left ? root->left : root->right;
                delete(root);
                return ret;
            }
            /* 2 child case */
            if (root->left && root->right) {
                TreeNode *tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
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
/************** (Binary Tree/ Array) to BST ******************/
void inorder(Node *root, vector<int> &v){
    if(root==NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
void put_inorder(Node *root, int *i, vector<int> v){
    if(root==NULL)
        return;
    put_inorder(root->left, i, v);
    root->data = v[*i];
    (*i)++;
    put_inorder(root->right, i, v);
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> v;
    inorder(root, v);
    sort(v.begin(), v.end());
    int i=0;
    put_inorder(root, &i, v);
    return root;
}
/**************  sorted array to bst tree  ****************/
Node* form(vector<int> v, int start, int end){
    if(start<=end){
        int middle = (start+end)/2;
        Node* root = new Node(v[middle]);
        root->left = form(v, start, middle-1);
        root->right = form(v, middle+1, end);
        return root;
    }
    return NULL;
}
/************************************************************/
