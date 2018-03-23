void sTree::copy(yzel* stemp, yzel* ftemp){
		if(ftemp){
			
			stemp->type = ftemp->type;
			stemp->value = ftemp->value;
			
			if(ftemp->left != NULL){
				stemp->left = new yzel(-1,-1);
			}
			
			if(ftemp->right != NULL){
				stemp->right = new yzel(-1,-1);
			}
			
			copy(stemp->left, ftemp->left);
			copy(stemp->right, ftemp->right);
		}
}
