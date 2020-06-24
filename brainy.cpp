#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int findClosing( int orders[], int time){
	int health = 1;
	int i = time;
	while (health != 0){
		i++;
		if (orders[i] == 91){
			health++;
		} else if(orders[i] == 93){
			health--;
		}
	}
	return i;
}




int findOpening(int orders[], int time){
	int health = 1;
	int i = time;
	while (health != 0){
		
		i--;
		if (orders[i] == 93){
			health++;
		} else if(orders[i] == 91){
			health--;
		}
	}
	return i;
}

int main(int argc, char **argv) {  	


	if (argc == 1){
		std::cout << "Need File!";
		return 1;
	}

	else {
		

		std::ifstream myfile;
    	myfile.open (argv[1]);

		std::vector<char> arr = std::vector<char>();
		


		std::cout << "Reading: " << std::endl;

 			while (!myfile.eof()) {
				char test;

				myfile >>  test ;

    			arr.push_back(test);;

 			}

			 arr.pop_back();
			std::cout << std::endl  <<  "Finished reading!" << std::endl;

			int i = 1;

			for (char x : arr){


				if (x == 62){
					i ++;
				} else if( x == 60){
					i--;
				}

				
			}



			std::vector<int>orders(arr.size());

    		std::copy(arr.begin(), arr.end() , orders.begin());
			


			std::cout << "memory size : " << i << std::endl;

			std::vector<int>mem(i * 266);
			
			i = 0;
			
			for ( int o = 0; o < arr.size(); o++ ){
				
				if (orders[o] == 62){
					

					i++;


				} else if(orders[o] == 60) {
					
					if (i == 0){
						std::cout << "Memory error";
						return 1;

					}else {
						i--;
					}


				} else if (orders[o] == 43){
				
					mem[i]++;

				} else if (orders[o] == 45){
				;
					mem[i]--;

				} else if (orders[o] == 46){
				
					std::cout << char(mem[i]) ;

				} else if (orders[o] == 44){
				
					char temp ;
					std::cout << "Input at " << i << ": ";
					std::cin >> temp;
					
					mem[i] = int(temp);

				} else if (orders[o] == 91){
					if (mem[i] == 0){
						o = findClosing(orders.data(),o);
						
					}
									

				} else if (orders[o] == 93){
					
					
					if (mem[i] != 0){
						
						o = findOpening(orders.data(),o);
						
					}
					
				}

			}
		return 0;
	}



	return 1;
}

