void sTree::view_helper(yzel* cur){
		
		switch(cur->type){
			
			case 0 : {
				std::cout<<cur->value<<std::endl;
				break;
			}
			
			case 1 : {
				
				switch(cur->value){
					
					case 0 : {
						std::cout<<"+"<<std::endl;
						break;
					}
					
					case 1 : {
						std::cout<<"-"<<std::endl;
						break;
					}
					
					case 2 : {
						std::cout<<"*"<<std::endl;
						break;
					}
					
					case 3 : {
						std::cout<<"/"<<std::endl;
						break;
					}
					
					default : {
						std::cout<<"tip: "<<cur->type<<" znachenie: "<<cur->value<<std::endl;
						break;
					}
					
				}
				
				break;
			}
			
			case 2 : {
				
				std::cout<<"x_"<<cur->value<<std::endl;
				break;
			}
			
			case 3 : {
				
				switch(cur->value){
					
					case 0 : {
						std::cout<<"ln"<<std::endl;
						break;
					}
					
					case 1 : {
						std::cout<<"sin"<<std::endl;
						break;
					}
					
					case 2 : {
						std::cout<<"cos"<<std::endl;
						break;
					}
					
					case 3 : {
						std::cout<<"exp"<<std::endl;
						break;
					}
					
					default : {
						std::cout<<"tip: "<<cur->type<<" znachenie: "<<cur->value<<std::endl;
						break;
					}
					
				}
				
				break;
			}
			
			default : {
				std::cout<<"tip: "<<cur->type<<" znachenie: "<<cur->value<<std::endl;
				break;
			}
			
		}
		
		
	}
