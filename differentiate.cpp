sTree* sTree::differentiate(){
		
	sTree* pS = new sTree(-1,-1);
			
	rek_d(pS->root, this->root);
	
	puts(" ");
	return pS;
}
