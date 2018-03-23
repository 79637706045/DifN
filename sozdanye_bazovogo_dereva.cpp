void sTree::sozdanye_bazovogo_dereva(){
	
/*
Строит дерево:
 $((ln(2))*x)+(sin(x))/48))$
 */
 /*this имеет type 1; value 0;*/
	
	this->root->type = 1;
	this->root->value = 0;
	
	this->root->left = new yzel(1,2);
	this->root->left->left = new yzel(3,0);
	this->root->left->right = new yzel(2,0);
	this->root->left->left->left = new yzel(0,2);
	this->root->left->left->right = NULL;
	
	this->root->right = new yzel(1,3);
	this->root->right->left = new yzel(3,1);
	this->root->right->right = new yzel(0,48);
	this->root->right->left->left = new yzel(2,0);
	this->root->left->left->right = NULL;
}
