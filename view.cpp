void sTree::view(yzel* cur, int level){//����������� ���������� � ����������� ��������������
		if(cur){
			view(cur->right , level+1);//����� ������� ���������
			for(int i = 0; i<level; i++){
				std::cout<<"                     ";
			} 	
		
			std::cout<<"tip: "<<cur->type<<" znachenie: "<<cur->value<<std::endl;

			view(cur->left , level+1);//����� ������ ���������
		}
}
