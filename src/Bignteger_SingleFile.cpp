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
			value = normalize(v.substr(1,v.length()));
		} else{
			value = normalize(v);
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
	
	bool symbolReturn(){
		return negative;
	}
	
	std::string valueReturn(){
		return value;
	}
	
	std::string normalize(std::string number){
		
		if(number[0] != '-'){
			while(number.length() > 1 && number[0] == '0'){
				number.erase(0,1);
			}
		} else if(number[0] == '-'){
			while(number.length() > 2 && number[1] == '0'){
				number.erase(1,1);
			}
		}
	
		return number;
	
	}
	
	bool greaterThan(Bignteger b){
		
		bool aSym = this->symbolReturn();
		bool bSym = b.symbolReturn();
		
		if(aSym == 0 & bSym == 1){
			return 1;
		} else
		
		if(aSym == 1 & bSym == 0){
			return 0;
		} else
		
		if((this->value.length() > b.value.length()) & (aSym == 1)){
			return 0;
		} else
		
		if((this->value.length() < b.value.length()) & (aSym == 0)){
			return 0;
		} else
		
		if(this->value.compare(b.value) == 0){
			return 0;
		} else
		
		if((this->value.compare(b.value) < 0) & (aSym == 0)){
			return 0;
		} else
		
		if((this->value.compare(b.value) < 0) & (aSym == 1)){
			return 1;
		} else
		
		if((this->value.compare(b.value) > 0) & (aSym == 1)){
			return 0;
		} else
		
		return 1;
	}
	
	bool equalTo(Bignteger b){
		
		bool aSym = this->symbolReturn();
		bool bSym = b.symbolReturn();
		
		if((aSym == bSym) & (this->value.compare(b.value) == 0)){
			return 1;
		} else
		
		return 0;
	}
	
	bool lessThan(Bignteger b){
		if((this->equalTo(b) == 0) & (this->greaterThan(b) == 0)){
			return 1;
		} else
		
		return 0;
	}
	
	std::string valueSum(Bignteger B){

		std::string a = this->value;
		std::string b = B.value;
		
		int diff = a.length() - b.length();
		
		if(diff > 0){
			b.insert(0, diff, '0');
		} else if (diff < 0){
			diff *= -1;
			a.insert(0, diff, '0');
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
