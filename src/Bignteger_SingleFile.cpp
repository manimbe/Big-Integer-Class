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

	std::string intReturn(){
		std::string aux = value;
		
		if(negative == 1){
			aux = aux.insert(0,"-");
		}
		
		return aux;
	}
	
	void display(){
		if(negative == 1){
			std::cout << "-";
		}
		std::cout << value << std::endl;
	}
	
	bool symbol(Bignteger a){
		return a.negative;
	}
	
	bool greaterThan(Bignteger a, Bignteger b){
		bool aSym = symbol(a);
		bool bSym = symbol(b);
		
		if(aSym == 0 & bSym == 1){
			return 1;
		} else
		
		if(aSym == 1 & bSym == 0){
			return 0;
		} else
		
		if((a.value.length() > b.value.length()) & (aSym == 1)){
			return 0;
		} else
		
		if((a.value.length() < b.value.length()) & (aSym == 0)){
			return 0;
		} else
		
		if(a.value.compare(b.value) == 0){
			return 0;
		} else
		
		if((a.value.compare(b.value) < 0) & (aSym == 0)){
			return 0;
		} else
		
		if((a.value.compare(b.value) < 0) & (aSym == 1)){
			return 1;
		} else
		
		if((a.value.compare(b.value) > 0) & (aSym == 1)){
			return 0;
		} else
		
		return 1;
	}
	
	bool equalTo(Bignteger a, Bignteger b){
		
		bool aSym = symbol(a);
		bool bSym = symbol(b);
		
		if((aSym == bSym) & (a.value.compare(b.value) == 0)){
			return 1;
		} else
		
		return 0;
	}
	
	bool lessThan(Bignteger a, Bignteger b){
		if((equalTo(a,b) == 0) & (greaterThan(a,b) == 0)){
			return 1;
		} else
		
		return 0;
	}
	
};

int main(){
	
	return 0;
	
}
