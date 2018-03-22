void delete_tree(yzel* cur){
	if(cur){
		delete_tree(cur->left);
		delete_tree(cur->right);
		delete(cur);
	}
}
