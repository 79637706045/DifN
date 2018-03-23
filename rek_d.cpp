void sTree::rek_d(yzel* stemp, yzel* ftemp){
		switch (ftemp->type){
/*****************************************/			
			case 0 : {//цифры
			
       		stemp->type = 0;
       		stemp->value = 0;
       		
			break;
			}
/****************************************/			
			case 1: {//операция
				
				switch(ftemp->value){
					
					case 0 : {//сложение
						
						stemp->type = 1;
						stemp->value = 0;
						
						stemp->left = new yzel(-1,-1);
						stemp->right = new yzel(-1,-1);
						
						rek_d(stemp->left, ftemp->left);
						rek_d(stemp->right, ftemp->right);
						break;
					}	
					
					case 1 : {//вычитание
						
						stemp->type = 1;
						stemp->value = 1;
						
						stemp->left = new yzel(-1,-1);
						stemp->right = new yzel(-1,-1);
						
						rek_d(stemp->left, ftemp->left);
						rek_d(stemp->right, ftemp->right);
						break;
					}
					
					case 2 : {//умножение
						
						stemp->type = 1;
						stemp->value = 0;
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 2;
						
						stemp->right = new yzel(-1,-1);
						stemp->right->type = 1;
						stemp->right->value = 2;
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->right = new yzel(-1,-1);
						rek_d(stemp->left->left, ftemp->left);
						copy(stemp->left->right, ftemp->right);
						
						stemp->right->left = new yzel(-1,-1);
						stemp->right->right = new yzel(-1,-1);
						copy(stemp->right->left, ftemp->left);
						rek_d(stemp->right->right, ftemp->right);
						
						break;
					}
					
					case 3 : {//деление
						
						stemp->type = 1;
						stemp->value = 3;
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 1;
						
						stemp->right = new yzel(-1,-1);
						stemp->right->type = 1;
						stemp->right->value = 2;
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->right = new yzel(-1,-1);
						stemp->left->left->type = 1;
						stemp->left->left->value = 2;
						stemp->left->right->type = 1;
						stemp->left->right->value = 2;
						
						stemp->right->left = new yzel(-1,-1);
						stemp->right->right = new yzel(-1,-1);
						copy(stemp->right->left, ftemp->right);
						copy(stemp->right->right, ftemp->right);
						
						stemp->left->left->left = new yzel(-1,-1);
						stemp->left->left->right = new yzel(-1,-1);
						stemp->left->right->left = new yzel(-1,-1);
						stemp->left->right->right = new yzel(-1,-1);
						rek_d(stemp->left->left->left, ftemp->left);
						copy(stemp->left->left->right, ftemp->right);
						copy(stemp->left->right->left, ftemp->left);
						rek_d(stemp->left->right->right, ftemp->right);
						
						break;
					}
					
					default: {        	
    		
       					std::cout<<"ERROR, incorrect value, of the element"<<std::endl;
       		
						break;
					}
				
				};
					
			break;
			}
/**************************************/

			case 2 : {//переменная  x1, x2, x3 ...
			
       		stemp->type = 0;
       		stemp->value = 1;
       		
			break;
			}
			
/************************************/
			case 3 : {//функция
			
					switch(ftemp->value){
					
					case 0 : {//ln
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
							
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 3;
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->left->type = 0;
						stemp->left->left->value = 1;
						
						stemp->left->right = new yzel(-1,-1);
						copy(stemp->left->right, ftemp->left);
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;
						/*
						stemp->right = new yzel(-1,-1);
						copy(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 0;
						stemp->left->value = 1;*/
						
						}
						
						break;
					}	
					
					case 1 : {//sin
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
						
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 3;
						stemp->left->value = 2;
						stemp->left->right = NULL;
						
						stemp->left->left = new yzel(-1,-1);
						
						copy(stemp->left->left, ftemp->left);
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;
						
						}
						
						break;
					}
					
					case 2 : {//cos
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
						
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 2;
						
						stemp->left->right = new yzel(-1,-1);
						stemp->left->right->type = 3;
						stemp->left->right->value = 1;
						
						stemp->left->right->right = NULL;
						
						stemp->left->right->left = new yzel(-1,-1);
						copy(stemp->left->right->left, ftemp->left);
						
						stemp->left->left = new yzel(-1,-1);
						stemp->left->left->type = 0;
						stemp->left->left->value = -1;
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;

						}
						
						break;
					}
					
					case 3 : {//exp
						
						int n = 0;
						x_search(ftemp->left, &n);
												
						if(n > 0){
							
						stemp->type = 1;
						stemp->value = 2;
						stemp->right = new yzel(-1,-1);
							
						rek_d(stemp->right, ftemp->left);
						
						stemp->left = new yzel(-1,-1);
						stemp->left->type = 1;
						stemp->left->value = 3;
						
						stemp->left->right = NULL;
						
						stemp->left->left = new yzel(-1,-1);
						copy(stemp->left->left, ftemp->left);
						}
						
						else{
						stemp->type = 0;
						stemp->value = 0;
						}
						
						break;
					}
					
					
					default: {        	
    		
       					std::cout<<"ERROR, incorrect value, of the element"<<std::endl;
       		
						break;
					};
				
					};
					
       		
			break;
			}
			
/****************************************/			
			
    		default: {        	
    		
       		std::cout<<"ERROR, incorrect type, of the element"<<std::endl;
       		
			break;
			}
				
		};
	}
