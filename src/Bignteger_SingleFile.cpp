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
	
	std::string valueSum(Bignteger A, Bignteger B){

		std::string a = A.value;
		std::string b = B.value;
		
		int diff = a.length() - b.length();
		
		if(diff > 0){
			while(diff > 0){
				b.insert(0,"0");
				diff--;	
			}
		} else if (diff < 0){
			diff *= -1;
			while(diff > 0){
				a.insert(0,"0");
				diff--;
			}
		}
		
		char carry = 48;
		std::string sum = a;
		
		for(int i = a.length() -1 ; i>=0 ; i--){
			sum[i] = (a[i] - 48) + (b[i] - 48) + (carry - 48) + 48;
			if(sum[i] > 57){
				sum[i] -= 10;
				carry = 49;	
			} else{
				carry = 48;	
			}
		}
	
		if(carry == 49){
			sum.insert(0,"1");
		}
	
		return sum;	

	}
	
};

int main(){
	
	return 0;
	
}
