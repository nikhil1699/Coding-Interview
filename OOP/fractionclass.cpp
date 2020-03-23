#include <bits/stdc++.h>
using namespace std;
class Fraction{
private:
	int numerator;int denominator;
public:
	Fraction(int numerator, int denominator){
		this->numerator=numerator;
		this->denominator=denominator;
	}
	void print(){
		cout<< this->numerator<<" / "<<denominator<<endl;

	}
	void simplify(){
		int gcd=1;
		int j=min(this->numerator, this->denominator);
		for(int i=1; i<=j;i++){
			if(this->numerator%i==0 && this->denominator%i==0){
				gcd=i;
			}
		}
		this->numerator=this->numerator/gcd;
		this->denominator=this->denominator/gcd;
	}

	Fraction operator+(Fraction const &f2){
		int lcm=denominator*f2.denominator;
		int x=lcm/denominator;
		int y=lcm/f2.denominator;
		int num=x*numerator+(y*f2.numerator);
		Fraction fNew(num, lcm);
		 // numerator=num;
		 // denominator=lcm;
		fNew.simplify();
		return fNew;
	}

	// void multiply(Fraction const &f2){
	// 	numerator=numerator*f2.numerator;
	// 	denominator=denominator*f2.denominator;
	// 	simplify();
	// }

	Fraction operator*(Fraction const &f2){
		int n=numerator*f2.numerator;
		int d=denominator*f2.denominator;
		Fraction fNew(n,d);
		fNew.simplify();
		return fNew;
	}
	bool operator==(Fraction const &f2){
		return (numerator==f2.numerator && denominator==f2.denominator);
	}

};

int main(){
	Fraction f1(10,2);
	Fraction f2(15,4);
	Fraction f3=f1+f2;
	Fraction f4=f1*f2;

	f1.print();
	f2.print();
	f3.print();
	f4.print();
	if(f1==f2){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}
	return 0;
}