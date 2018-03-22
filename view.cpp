void sTree::view(yzel* cur, int level){//рекурсивная распечатка с графическим представлением
		if(cur){
			view(cur->right , level+1);//вывод правого поддерева
			for(int i = 0; i<level; i++){
				std::cout<<"                     ";
			} 	
		
			std::cout<<"tip: "<<cur->type<<" znachenie: "<<cur->value<<std::endl;

			view(cur->left , level+1);//вывод левого поддерева
		}
}
