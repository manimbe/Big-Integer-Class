#include <iostream>
#include <string>

class Bignteger{
private:
	
	bool negative = 0;
	std::string value;
	
public:
	
	Bignteger(){
		value = "0";
	}
	
	Bignteger(std::string v){
		if(v[0] == '-'){
			negative = 1;
			
			value = v.substr(1,v.length());
		} else{
			value = v;
		}
	}
	
	void Display(){
		if(negative == 1){
			std::cout << "-";
		}
		std::cout << value << std::endl;
	}
	
	std::string Return(){
		std::string aux = value;
		
		if(negative == 1){
			aux = aux.insert(0,"-");
		}
		
		return aux;
	}
	
};

int main(){
	
	std::cin.get();
	return 0;
}
