#include <iomanip>
#include <string>
#include "HugeInt.h"
using namespace std;


HugeInt::HugeInt(long num){
		for(int i=0;i<digit;i++)
				integer[i]=0;
		for(int j=digit-1;num!=0 && j>=0;j--){
				integer[j]=num%10;
				num/=10;
		}
}
HugeInt::HugeInt(const string &value){
		for(int i=0;i<digit;i++)
					integer[i]=0;
		int size=value.size();
		for(int j=digit-size,k=0;j<digit;j++,k++){
				if(isdigit(value[k]))
						integer[j]=value[k]-'0';
		}
}
HugeInt HugeInt::operator+(const HugeInt &op) const {
		HugeInt temp;
		int c=0;
		for(int i=digit-1;i>=0;i--){
				temp.integer[i]=integer[i]+op.integer[i]+c;
				if(temp.integer[i]>9){
						temp.integer[i]%=10;
						c=1;
				}
				else
						c=0;
		}
		return temp;
}
HugeInt HugeInt::operator-(const HugeInt &op) const {
	    HugeInt temp;
		int c=0;
		for(int i=digit-1;i>=0;i--){
		        temp.integer[i]=integer[i]-op.integer[i]+c;
		        if(temp.integer[i]<0){
				        temp.integer[i]+=10;
				        c=-1;
				}
				else
				        c=0;
		}
		return temp;
}
ostream &operator<<(ostream &output,const HugeInt &number){
		int i=0;
		for(i=0;(number.integer[i]==0) &&(i<=HugeInt::digit);i++)
		;
		if(i==HugeInt::digit)
				output<<0;
		else{
				for(;i<HugeInt::digit;i++)
						output<<number.integer[i];
		}
		return output;
}
istream &operator>>(istream &input,HugeInt &number){
		string temp;
		input >> temp;
		number=HugeInt(temp);
		return input;
}
