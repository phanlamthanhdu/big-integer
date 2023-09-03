#include <bits/stdc++.h>
using namespace std;
// MAX_LONG_LONG = 9 223 372 036 854 775 807

long long lower_fence = (long long) 1e17;
struct big_integer{
    /* 
        Using a vector as a big_integer data structure
        Fast and Easy storage
        Each slot in the vector stores 17 digits
        Ex:     13 40004323342315782 
            When storing in my big_integer, it'll be reversed:
                40004323342315782 13
                
    */ 
    vector <long long> data;

    // Default Constructor
    big_integer(){}
    // Parameterized Constructor
    big_integer(int x){
        data.push_back(x);
    }

    // Operator Overloading
    // Opertor =
    void operator=(big_integer x){
        data.clear();                                   // Removing all the digits before assigning 
        for(auto v : x.data) data.push_back(v);    // Push each slot from x into a new big_integer
    }

    // Operator +
    big_integer operator+(const big_integer x) const{
        big_integer ans;
        int carry{0},i{0};

        while(i < x.data.size() && i < data.size()){
            long long res = data[i] + x.data[i] + carry;
            ans.data.push_back(res % lower_fence);
            carry = res / lower_fence;
            i++;
        }
        while(i < data.size()){
            long long res = data[i] + carry;
            ans.data.push_back(res % lower_fence);
            carry = res / lower_fence;
            i++;
        }
        while(i < x.data.size()){
            long long res = x.data[i] + carry;
            ans.data.push_back(res % lower_fence);
            carry = res / lower_fence;
            i++;
        }
        if(carry) ans.data.push_back(carry);
        return ans;
    }

    // Print the big_integer
    void output(){
        for(int i(data.size()-1); i >= 0; i--){
            if(i != data.size()-1) cout << setw(17) << setfill('0') << data[i]; // Printing without digit-losing issue
            else cout << data[i];
        }
    }
};

int main(){

    // Implement big_integer with Fibonacci
	big_integer f1 = 1, f2 = 1;
	int n;
	cin >> n;
	while(n >= 3){
		n--;
		auto temp = f2;
		f2 = f2+f1;
		f1 = temp;
	}
	f2.output();
    return 0;
}
