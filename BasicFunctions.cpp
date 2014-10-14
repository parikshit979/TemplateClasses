#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

template <class T>
class Functions
{
    private:
        T MOD;
        double precistion_num;
        int MAX;
        long long *catalan;
    public:
        Functions(T _mod, T _precistion_num, int _maxSize)
        {
            MOD = _mod;
            precistion_num = _precistion_num;
            MAX = _maxSize;
            catalan = new long long [MAX];
        }

        T power(T, T);
        T squareRoot(T);

        void calculateCatalanNumbers(int num);
        long long getCatalanNumbers(int index){ return catalan[index]; }
};

template <class T>
T Functions<T>::power(T num, T exp)
{
    T ans = static_cast<T>(1);
    while ( exp ) {
		if ( exp & 1 ) {
			ans = (ans*num);
			if ( ans >= MOD ) ans %= MOD;
		}
		num = (num*num);
		if ( num >= MOD ) num %= MOD;
		exp >>= 1;
	}
	return ans;
}

template <class T>
T Functions<T>::squareRoot(T num)
{
    T mid, low = 0.0, high = num;
	while (low<high) {
		mid = (low+high)/2.0;
		if (mid * mid < num)
			low = mid + precistion_num;
		else
			high = mid - precistion_num;
	}
	return mid;
}


template <class T>
void Functions<T>::calculateCatalanNumbers(int num) {
    catalan[1] = static_cast<T>(1);
    for (int i = 2; i <= num; i++) {
        for (int j = 1; j <= i - 1; j++) {
            catalan[i] = (catalan[i] + ((catalan[j]) * catalan[i - j]) % MOD) % MOD;
        }
        catalan[i] = catalan[i] % MOD;
    }
}

int main()
{
    Functions<long long> func_longlong(1000000007, 0.00000001, 350);
    cout<<func_longlong.power(2,4)<<"\n";
    func_longlong.calculateCatalanNumbers(12);
    cout<<func_longlong.getCatalanNumbers(5)<<"\n";

    Functions<double> func_double(1000000007, 0.00000001, 350);
    cout<<func_double.squareRoot(17)<<"\n";


    return 0;
}
