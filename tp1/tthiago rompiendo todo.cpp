#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> v = {3,1,5,2,1}; //lo recibe x cin
// int w = pow(pow(3,5), 2) + 6;
// int w = 33;
// int w = 17;
// int w = 9;
int w = 400;

vector<vector<bool>> cache(v.size()+1, vector<bool>(w+1, false)); //row: |v|, colum: w
/*
bool opant(int i, int acum){    


	if(i == v.size()){
		return (w == acum);
	}

    return opant(i+1, acum + v[i]) or opant(i+1, acum * v[i]) or opant(i+1,  pow(acum, v[i])) or opant(i+1,acum - v[i]) ;

}
*/

bool op(int i, int acum){    


	if(i == v.size() && acum >= 0){
		return cache[i][acum] = (w == acum);
	}
	if(i == v.size() && acum < 0 ){
		return false;//(w == acum);
	}

	if(acum > w){
		return false;
	}

	if(acum >= 0 ){
		if(cache[i][acum] != false){
			return cache[i][acum];
		}	
    	
		return cache[i][acum] = op(i+1, acum + v[i]) or op(i+1, acum * v[i]) or op(i+1,  pow(acum, v[i])) or op(i+1,acum - v[i]);

	}else {
		return 	op(i+1, acum + v[i]) or op(i+1, acum * v[i]) or op(i+1,  pow(acum, v[i])) or op(i+1,acum - v[i]); 
	}




}


int main() {

	// cout << opant(1, v[0]) << endl;

	bool res = op(1, v[0]);

	if(res){
		cout << "se puede calcular! :-)" << endl;
	}else{
		cout << "noooooooooo" << endl;
	}
  return 0;
}