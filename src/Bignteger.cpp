#include "Bignteger.h"

/* --------- Methods --------- */

std::string Bignteger::intReturn() const{
    std::string aux = value;
    if(negative == 1){
        aux = aux.insert(0,"-");
    }
    return aux;
}

inline bool Bignteger::symbolReturn() const{
    return negative;
}

inline std::string Bignteger::valueReturn() const{
    return value;
}

inline size_t Bignteger::lengthReturn() const{
        return value.length();
}

std::string Bignteger::normalize(std::string number) const{
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

bool Bignteger::greaterThan(const Bignteger& other) const{
    bool thisSym = this->symbolReturn();
    bool otherSym = other.symbolReturn();
    if(thisSym == 0 && otherSym == 1){
        return 1;
    } else if(thisSym == 1 && otherSym == 0){
        return 0;
    } else if((this->lengthReturn() == other.lengthReturn()) && (thisSym == 1) && (this->value.compare(other.value) < 0)){
        return 1;
    } else if((this->lengthReturn() == other.lengthReturn()) && (thisSym == 0) && (this->value.compare(other.value) > 0)){
        return 1;
    } else if((this->lengthReturn() > other.lengthReturn()) && (thisSym == 0)){
        return 1;
    } else if((this->lengthReturn() < other.lengthReturn()) && (thisSym == 1)){
        return 1;
    } else
    return 0;
}

bool Bignteger::equalTo(const Bignteger& other) const{
    bool thisSym = this->symbolReturn();
    bool otherSym = other.symbolReturn();
    if((thisSym == otherSym) & (this->value.compare(other.value) == 0)){
        return 1;
    } else
    return 0;
}

bool Bignteger::lessThan(const Bignteger& other) const{
    if((this->equalTo(other) == 0) & (this->greaterThan(other) == 0)){
        return 1;
    } else
    return 0;
}

std::string Bignteger::valueSum(const Bignteger &other) const{
    std::string a = this->valueReturn();
    std::string b = other.valueReturn();
    int diff = a.length() - b.length();

    if(diff > 0){
        b.insert(0, diff, '0');
    } else if (diff < 0){
        diff *= -1;
        a.insert(0, diff, '0');
    }

    char carry = '0';
    std::string sum = a;

    for(int i = a.length() -1 ; i>=0 ; i--){
        sum[i] = (a[i] - '0') + (b[i] - '0') + (carry - '0') + '0';
        if(sum[i] > '9'){
            sum[i] -= 10;
            carry = '1';
        } else{
            carry = '0';
        }
    }

    if(carry == '1'){
        sum.insert(0,"1");
    }
    return sum;
}

std::string Bignteger::valueSubtraction(const Bignteger &other) const{
    std::string a;
    std::string b;
    int diff = a.length() - b.length();

        if(diff > 0){
        a = this->valueReturn();
        b = other.valueReturn();
            b.insert(0, diff, '0');
        } else if (diff < 0){
            a = other.value;
        b = this->value;
            diff *= -1;
            b.insert(0, diff, '0');
        }   else{
        int comp = this->value.compare(other.valueReturn());
        if(comp == 0){
        return "0";
        } else if(comp > 0){
        a = this->valueReturn();
        b = other.valueReturn();
        } else{
        a = other.valueReturn();
        b = this->valueReturn();
        }
    }

    int carry = '0';
    std::string sub = a;
    for(int i = a.length() - 1; i >= 0; i--){
        if(a[i] < b[i]){
            sub[i] = (a[i] - '0' + 10) - (carry - '0') - (b[i] - '0') + '0';
            carry = '1';
        } else if((a[i] == b[i]) && (carry == '1')){
            sub[i] = (a[i] - '0' + 10) - (carry - '0') - (b[i] - '0') + '0';
            carry = '1';
        } else{
            sub[i] = (a[i] - '0') - (b[i] - '0') - (carry - '0') + '0';
            carry = '0';
        }
    }
    return normalize(sub);
}

std::string Bignteger::valueMultiplication(const Bignteger &other) const{
    std::string a = this->valueReturn();
    std::string b = other.valueReturn();
    int lengthA = a.length();
    int lengthB = b.length();
    int l = lengthA + lengthB;
    std::string mult;
    mult.resize(l, 0);
    int carry;
    int it = l-1;

    for(int i = lengthB - 1; i >= 0; i--){
        carry = 0;
        for(int j = lengthA - 1; j >= 0; j--){
            mult[it] = mult[it] + carry + (a[j]-'0')*(b[i]-'0');
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
        mult[i] += '0';
    }
    return normalize(mult);
}

std::string Bignteger::valueDivision(Bignteger B) const{
    Bignteger A = intReturn();
        A.negative = 0;
        B.negative = 0;
        if(B.valueReturn() == "0"){
                throw "undefined division";
        }
        if(A.valueReturn() == "0"){
                return A.valueReturn();
        }
        if(B.valueReturn() == "1"){
                return A.valueReturn();
        }
        if(B > A){
        return "0";
        }

    int lengthA = A.lengthReturn();
    int lengthB = B.lengthReturn();
    int diff = lengthA - lengthB;

    Bignteger support = "1";
    support.value.insert(1, diff, '0');

    bool status = 1;
    Bignteger division = "0";
    Bignteger result = "0"; //B * division result

    while(diff >= 0){
        if(status == 1){
        while(A > result){
            division = division.valueSum(support);
            result = B.valueMultiplication(division);
        }
        if(A == result){
            return division.valueReturn();
        } else{
        status = 0;
        support.value.pop_back();
        diff--;
        }
        } else{
          while(result > A){
            division = division.valueSubtraction(support);
            result = B.valueMultiplication(division);
        }
        if(A == result){
            return division.valueReturn();
        } else{
        status = 1;
        support.value.pop_back();
        diff--;
        }
        }
    }

    if((diff < 0) && (A != result) && (status == 0)){
       support.value = "1";
       division = division.valueSubtraction(support);
       }
    return division.valueReturn();
}

std::string Bignteger::valueModulo(const Bignteger& other) const{
    Bignteger division = this->valueDivision(other);
    Bignteger support = other.valueMultiplication(division);
    Bignteger result = this->valueSubtraction(support);
    return result.valueReturn();
}

/* --------- Constructors --------- */

Bignteger::Bignteger(){
    value = "0";
}

Bignteger::Bignteger(const char* v){
    value = v;
    if(value[0] == '-'){
        negative = 1;
        value = normalize(value.substr(1,value.length()));
    } else{
        value = normalize(value);
    }
}

Bignteger::Bignteger(const std::string&& v){
    if(v[0] == '-'){
        negative = 1;
        value = normalize(v.substr(1,v.length()));
    } else{
        value = normalize(v);
    }
}

Bignteger::Bignteger(const Bignteger& v)
    : value(v.value), negative(v.negative){}

Bignteger::Bignteger(const Bignteger&& v)
    : value(v.value), negative(v.negative){}

/* --------- Operators --------- */

Bignteger& Bignteger::operator = (const Bignteger& other){
    value = other.value;
    negative = other.negative;
    return *this;
}

Bignteger& Bignteger::operator = (const Bignteger&& other){
    value = other.value;
    negative = other.negative;
    return *this;
}

Bignteger& Bignteger::operator = (const char*&& other){
    value = other;
    if(value[0] == '-'){
        negative = 1;
        value = normalize(value.substr(1,value.length()));
        return *this;
    } else{
        value = normalize(other);
        negative = 0;
        return *this;
    }
}

Bignteger& Bignteger::operator = (std::string&& other){
    if(other[0] == '-'){
        value = other.substr(1, other.length());
        negative = 1;
        return *this;
    } else{
        value = other;
        negative = 0;
        return *this;
    }
}

bool Bignteger::operator > (const Bignteger& y) const{
    return greaterThan(y);
}

bool Bignteger::operator >= (const Bignteger& y) const{
    if(this->greaterThan(y) || this->equalTo(y)){
        return 1;
    } else return 0;
}

bool Bignteger::operator < (const Bignteger& y) const{
    return lessThan(y);
}

bool Bignteger::operator <= (const Bignteger& y) const{
    if(this->lessThan(y) || this->equalTo(y)){
        return 1;
    } else return 0;
}

bool Bignteger::operator == (const Bignteger& y) const{
    return equalTo(y);
}

bool Bignteger::operator != (const Bignteger& y) const{
    return !(equalTo(y));
}

std::string Bignteger::operator + (Bignteger& y){
    bool xSym = this->symbolReturn();
    bool ySym = y.symbolReturn();
    Bignteger sum;

    if(xSym == ySym){
        sum = this->valueSum(y);
        if(xSym == 1){
        sum.value.insert(0, "-");
        return sum.valueReturn();
        } else return sum.valueReturn();
    } else{
        sum = this->valueSubtraction(y);
        this->negative = 0;
        y.negative = 0;
        if((xSym == 1 && *this>y) || (ySym == 1 && y>*this)){
        sum.value.insert(0, "-");
        this->negative = xSym;
        y.negative = ySym;
        return sum.valueReturn();
        } else{
        this->negative = xSym;
        y.negative = ySym;
        return sum.valueReturn();
        }
    }
}

std::string Bignteger::operator - (Bignteger& y){
    bool xSym = this->symbolReturn();
    bool ySym = y.symbolReturn();
    Bignteger subtraction;

    if(xSym != ySym){
        subtraction = this->valueSum(y);
        if(xSym == 1){
        subtraction.value.insert(0, "-");
        return subtraction.valueReturn();
        } else return subtraction.valueReturn();
    } else{
        subtraction = this->valueSubtraction(y);
        this->negative = 0;
        y.negative = 0;
        if((xSym == 0 && *this<y)||(xSym == 1 && *this>y)){
        subtraction.value.insert(0, "-");
        this->negative = xSym;
        y.negative = ySym;
        return subtraction.valueReturn();
        } else{
        this->negative = xSym;
        y.negative = ySym;
        return subtraction.valueReturn();
        }
    }
}

std::string Bignteger::operator * (const Bignteger& y) const{
    Bignteger multiplication = this->valueMultiplication(y);
    if(this->symbolReturn() == y.symbolReturn()){
        return multiplication.valueReturn();
    } else{
        return multiplication.value.insert(0, "-");
    }
}

std::string Bignteger::operator / (const Bignteger& y) const{
    Bignteger division = this->valueDivision(y);
    if(this->symbolReturn() == y.symbolReturn()){
        return division.valueReturn();
    } else{
        return division.value.insert(0, "-");
    }
}

std::string Bignteger::operator % (const Bignteger& y) const{
    Bignteger modulo = this->valueModulo(y);
    if(this->symbolReturn() == 0){
        return modulo.valueReturn();
    } else{
        return modulo.value.insert(0, "-");
    }
}

std::ostream& operator << (std::ostream& output, const Bignteger& x){
	output << x.intReturn();
	return output;
}
