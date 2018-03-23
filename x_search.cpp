void sTree::x_search(yzel* tempr, int* counter){
	if(tempr){
		if(tempr->type == 2){
			(*counter)++;
		}
	x_search(tempr->left, counter);
	x_search(tempr->right, counter);
	}
}
