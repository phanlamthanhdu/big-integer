#include <bits/stdc++.h>
using namespace std;
//MAX_LONG_LONG = 9 223 372 036 854 775 807

int lower_fence = 100'000'000'000'000'000;
struct big_integer{
    vector <long long> data;

    big_integer(){}
    big_integer(int x){
        data.push_back(x);
    }
    void operator=(big_integer x){
        data.clear();
        for(auto v : x.data) data.push_back(v);
    }
    big_integer operator+(const big_integer x) const{
        big_integer ans;
        int carry{0},i{0};

        while(i < x.data.size()){
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
        if(carry) ans.data.push_back(carry);
        return ans;
    }
    void output(){
        for(int i(data.size()-1); i >= 0; i--){
            if(data[i] < lower_fence && i != data.size()-1)
                for(int j{0}; j < 16-(int)log10(data[i]); j++) 
                    cout << 0;
            cout << data[i];
        }
    }
};

int main(){
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
