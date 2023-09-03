#include <bits/stdc++.h>
using namespace std;

long long lower_fence = (long long) 1e17;
struct big_integer{
    vector <long long> data;

    big_integer(){}
    big_integer(string &s){

        int n(s.length()-1), cnt{0};
        string res;
        for(int i{n}; i >= 0; i--){
            res += s[i];
            cnt++;
            if(cnt == 17 || i == 0){
                reverse(res.begin(),res.end());
                data.push_back(strtoll(res.c_str(), nullptr, 10));
                res.clear();
                cnt = 0;
            }
        }
    }

    big_integer get_reverse(){        
        //Convert big_integer to string
        string s;

        for(int i(data.size()-1); i >= 0; i--){
            if(data[i] < lower_fence && i != data.size()-1)
                for(int j{0}; j < 16-(int)log10(data[i]+0.9); j++) 
                    s += '0';
            s += to_string(data[i]);
        }
        
        //Store reverse to big_integer
        reverse(s.begin(),s.end());
        big_integer ans(s);
        return ans;
    }
    int length(){
        int n(data.size());
        int count = to_string(data[n-1]).length();
        if(n > 1) count += (n-1) * 18;
        return count;
    }
    big_integer& operator=(const big_integer &x){
        data.clear();
        for(auto v : x.data) data.push_back(v);
        return *this;
    }
    bool operator==(const big_integer &x) const{
        int i(data.size()-1),
            j(x.data.size()-1);
        if(i != j) return 0;
        while(i >= 0){
            if(data[i] != x.data[j]) return 0;
            i--;
        }
        return 1;
    }
    big_integer operator+(const big_integer &x) const{
        big_integer ans;
        long long carry{0};
        int i{0};

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
    void output(){
        for(int i(data.size()-1); i >= 0; i--){
            if(i != data.size()-1) cout << setw(17) << setfill('0') << data[i];
            else cout << data[i];
        }
    }
};

int main(){
	int n, i = 0;
    int limit_rep = 1e4, limit_len = 1.5e4;

    string input;
    cin >> input;

    big_integer s = big_integer(input);
    big_integer rs = s.get_reverse();

    vector<big_integer> results;
    while(i <= limit_rep and s.length() <= limit_len){   
        s = s + rs;
        rs = s.get_reverse();

        results.push_back(s);
        if (s == rs){
            cout << "NO" << endl; 
            for(big_integer i : results){
                i.output();
                cout << endl;
            }
            return 0;
        }
        i = i + 1;
    }
    cout << "YES" << endl;

    cout << i << " "; s.output();
    return 0;
}