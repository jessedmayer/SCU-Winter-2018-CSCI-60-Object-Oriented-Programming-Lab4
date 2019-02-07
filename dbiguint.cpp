#include "dbiguint.h"

dbiguint::dbiguint(){
    data_=NULL;
    capacity_=0;
}

dbiguint::dbiguint(const std::string & temp){
    capacity_=temp.length();
    data_=new short unsigned int[capacity_];
    int j = temp.length()-1;
    for (int i = 0; i < temp.length(); i++){
        if (temp[j]=='0')
            data_[i]= 0;
        else if (temp[j]=='1')
            data_[i]= 1;
        else if (temp[j]=='2')
            data_[i]= 2;
        else if (temp[j]=='3')
            data_[i]= 3;
        else if (temp[j]=='4')
            data_[i]= 4;
        else if (temp[j]=='5')
            data_[i]= 5;
        else if (temp[j]=='6')
            data_[i]= 6;
        else if (temp[j]=='7')
            data_[i]= 7;
        else if (temp[j]=='8')
            data_[i]= 8;
        else if (temp[j]=='9')
            data_[i]= 9;
        else 
            assert(temp[j]>='0' && temp[j]<='9');
        j--;
    }
}

std::size_t dbiguint::size() const{
    return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const{
    if(pos >= capacity_ || pos < 0){
        return 0;
    }else{
        return data_[pos];
    }
}    

std::ostream & operator << (std::ostream &out, const dbiguint &a){
    for (int i = a.size()-1; i >= 0 ; i--)
        out << a[i];
    out << std::endl;
    return out;
}
void dbiguint::reserve(std::size_t newcapacity_){
    if(newcapacity_>capacity_){
        unsigned short* newptr = new unsigned short[newcapacity_];
        for(int i=0; i<capacity_; i++){
            newptr[i]=data_[i];
        }
        for (int j=capacity_; j < newcapacity_; j++){
            newptr[j]=0;
        }
        delete [] data_;
        data_=newptr;
        capacity_ = newcapacity_;
    }
}
void dbiguint::operator +=(const dbiguint &b){
    if (b.size()>capacity_){
        reserve(b.size());
    }
    for (int i = 0; i <capacity_; i++){
        data_[i] += b[i];
        if (data_[i] > 9) { //i only did nine because no two numbers in data added should be in the 20s
            data_[i] -= 10;
            if ((i+1)>=capacity_){
                reserve(i+2);
                data_[i+1] +=1;
            } else {
            data_[i+1] +=1; //since no two numbers added together should be in their twenties you only add 1 to the next number space
            }
        }
    }
}


/*
unsigned short operator [](std::size_t pos) const{
    assert((pos<CAPACITY) && (pos>=0));
    return data_[pos];
}

int biguint::compare(const biguint & b) const{
    for (int i = CAPACITY-1; i >= 0; i--){
        if (data_[i] > b.data_[i]){
            return 1;
        } else if (data_[i] < b.data_[i]){
            return -1;
        } else if (i = 0){
            return 0;
        }
    }
}

bool operator < (const biguint &a, const biguint &b){
    if (a.compare(b) == -1)
        return true;
    else 
        return false;
}

bool operator <= (const biguint &a, const biguint &b){
    if (a.compare(b) == -1 || a.compare(b) == 0)
        return true;
    else 
        return false;
}

bool operator != (const biguint &a, const biguint &b){
    if (a.compare(b) == 1 || a.compare(b) == -1)
        return true;
    else 
        return false;
}

bool operator == (const biguint &a, const biguint &b){
    if (a.compare(b) == 0)
        return true;
    else 
        return false;
}

bool operator >= (const biguint &a, const biguint &b){
    if (a.compare(b) == 1 || a.compare(b) == 0)
        return true;
    else 
        return false;
}

bool operator > (const biguint &a, const biguint &b){
    if (a.compare(b) == 1)
        return true;
    else 
        return false;
}

ostream& operator <<(ostream& out, const biguint& a){
    for (int i = a.CAPACITY-1; i >= 0 ; i--)
        out << a.data_[i];
    out << endl;
    return out;
}

void operator += (const biguint & b){
    
}

*/


