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
	
	bool greaterThan(Bignteger a, Bignteger b){
		
		bool aSym = a.symbolReturn();
		bool bSym = b.symbolReturn();
		
		if(aSym == 0 && bSym == 1){
			return 1;
		} else

		if(aSym == 1 && bSym == 0){
			return 0;
		} else

		if((a.value.length() == b.value.length()) && (aSym == 1) && (a.value.compare(b.value) < 0)){
			return 1;
		} else

		if((a.value.length() == b.value.length()) && (aSym == 0) && (a.value.compare(b.value) > 0)){
			return 1;
		} else

		if((a.value.length() > b.value.length()) && (aSym == 0)){
			return 1;
		} else

		if((a.value.length() < b.value.length()) && (aSym == 1)){
			return 1;
		} else

		return 0;
	}
	
	bool equalTo(Bignteger a, Bignteger b){
		
		bool aSym = a.symbolReturn();
		bool bSym = b.symbolReturn();
		
		if((aSym == bSym) & (a.value.compare(b.value) == 0)){
			return 1;
		} else
		
		return 0;
	}
	
	bool lessThan(Bignteger a, Bignteger b){
		if((a.equalTo(a,b) == 0) & (a.greaterThan(a,b) == 0)){
			return 1;
		} else
		
		return 0;
	}
	
	std::string valueSum(Bignteger &A, Bignteger &B){

		std::string a = A.value;
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
	
	std::string valueSubtraction(Bignteger &A, Bignteger &B){ 

        std::string a;
        std::string b;

        int diff = A.value.length() - B.value.length();

		if(diff > 0){
            a = A.value;
            b = B.value;
			b.insert(0, diff, '0');
		} else if (diff < 0){
		    a = B.value;
            b = A.value;
			diff *= -1;
			b.insert(0, diff, '0');
		}   else{
            int comp = A.value.compare(B.value);
            if(comp == 0){
                return "0";
            } else if(comp > 0){
                a = A.value;
                b = B.value;
            } else{
                a = B.value;
                b = A.value;
            }
		}

        int carry = 48;

		std::string sub = a;

		for(int i = a.length() -1 ; i>=0 ; i--){

			if(a[i] < b[i]){

                sub[i] = (a[i] - 48 + 10) - (carry - 48) - (b[i] - 48) + 48;
                carry = 49;

			} else if((a[i] == b[i]) && (carry == 49)){

                sub[i] = (a[i] - 48 + 10) - (carry - 48) - (b[i] - 48) + 48;
                carry = 49;

			} else{

                sub[i] = (a[i] - 48) - (b[i] - 48) - (carry - 48) + 48;
                carry = 48;

			}
		}

        sub = normalize(sub);

		return sub;

	}
	
	std::string valueMultiplication(Bignteger &A, Bignteger &B){

        std::string a = A.value;
        std::string b = B.value;

        int lengthA = a.length();
        int lengthB = b.length();

        int l = lengthA + lengthB;
        std::string mult;
        mult.resize(l, 0);

        int carry;

        int it = l-1;
        for(int i = lengthB - 1; i>=0; i--){
            carry = 0;
            for(int j = lengthA - 1; j>=0; j--){
                    mult[it] = mult[it] + carry + (a[j]-48)*(b[i]-48);
                    if(mult[it] > 9){
                        carry = mult[it] / 10;
                        mult[it] = mult[it] - (carry*10);
                    } else carry = 0;
                    it--;
            }
            mult[it] = mult[it] + carry;
            it = it + lengthA - 1;
        }

        for(int i = 0; i < l; i++){
            mult[i] += 48;
        }

        return normalize(mult);

	}
	
	std::string valueDivision(Bignteger A, Bignteger B){

	    A.negative = 0;
	    B.negative = 0;

	    if(B.value == "0"){
            throw "undefined division";
	    }

	    if(A.value == "0"){
            return A.value;
	    }

	    if(B.value == "1"){
            return A.value;
	    }

	    if(B > A){
            return "0";
	    }

	    if(A == B){
            return "1";
	    }

        int lengthA = A.value.length();
        int lengthB = B.value.length();
        int diff = lengthA - lengthB;

        Bignteger support("1");
        support.value.insert(1, diff, '0');

        bool status = 1;
        Bignteger division("0");
        Bignteger result("0");

        while(diff >= 0){
            if(status == 1){
                while(A > result){
                    division = division.valueSum(division, support);
                    result = B.valueMultiplication(B, division);
                }
                if(A == result){
                    return division.value;
                } else{
                status = 0;
                support.value.pop_back();
                diff--;

                }
            } else{
              while(result > A){
                    division = division.valueSubtraction(division, support);
                    result = B.valueMultiplication(B, division);
                }
                if(A == result){
                    return division.value;
                } else{
                status = 1;
                support.value.pop_back();
                diff--;
                }
            }
        }

        if((diff < 0) && (A != result) && (status == 0)){
           support.value = "1";
           division = division.valueSubtraction(division, support);
           }

        return division.value;

	}
	
	std::string valueModulo(Bignteger& A, Bignteger& B){

        Bignteger division = A.valueDivision(A,B);
        Bignteger support = B.valueMultiplication(B, division);
        Bignteger result = A.valueSubtraction(A, support);

        return result.value;

	}
	
	/* --------- Operators --------- */

	bool operator > (Bignteger& y){
		Bignteger x = intReturn();
		return x.greaterThan(x,y);
	}

	bool operator >= (Bignteger& y){
		Bignteger x = intReturn();
		if(x.greaterThan(x,y) || x.equalTo(x,y)){
            return 1;
		} else return 0;
	}

	bool operator < (Bignteger& y){
		Bignteger x = intReturn();
		return x.lessThan(x,y);
	}

	bool operator <= (Bignteger& y){
		Bignteger x = intReturn();
		if(x.lessThan(x,y) || x.equalTo(x,y)){
            return 1;
		} else return 0;
	}

	bool operator == (Bignteger& y){
		Bignteger x = intReturn();
		return x.equalTo(x,y);
	}
	
	bool operator != (Bignteger& y){
		Bignteger x = intReturn();
		return !(x.equalTo(x,y));
	}

	std::string operator + (Bignteger& y){
		Bignteger x = intReturn();
		bool xSym = x.negative;
		bool ySym = y.negative;
		Bignteger sum;

		if(xSym == ySym){
		    sum = x.valueSum(x,y);
		    if(xSym == 1){
			sum.value.insert(0, "-");
			return sum.value;
		    } else return sum.value;
		} else{
		    sum = x.valueSubtraction(x,y);
		    x.negative = 0;
		    y.negative = 0;
		    if((xSym == 1 && x>y) || (ySym == 1 && y>x)){
			sum.value.insert(0, "-");
			x.negative = xSym;
			y.negative = ySym;
			return sum.value;
		    } else{
			x.negative = xSym;
			y.negative = ySym;
			return sum.value;
		    }
		}
	}
	
	std::string operator - (Bignteger& y){
		Bignteger x = intReturn();
		bool xSym = x.negative;
		bool ySym = y.negative;
		Bignteger subtraction;

		if(xSym != ySym){
		    subtraction = x.valueSum(x,y);
		    if(xSym == 1){
			subtraction.value.insert(0, "-");
			return subtraction.value;
		    } else return subtraction.value;
		} else{
		    subtraction = x.valueSubtraction(x,y);
		    x.negative = 0;
		    y.negative = 0;
		    if((xSym == 0 && x<y)||(xSym == 1 && x>y)){
			subtraction.value.insert(0, "-");
			x.negative = xSym;
			y.negative = ySym;
			return subtraction.value;
		    } else{
			x.negative = xSym;
			y.negative = ySym;
			return subtraction.value;
			}
		}
	}

};

int main(){
	
	return 0;
	
}
