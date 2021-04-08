#include<iostream>
#include "heap.h"
#include<queue>

using namespace std;

int main(){
	
	vector<int> v;
	v.push_back(100);
	v.push_back(50);
	v.push_back(120);
	v.push_back(60);
	v.push_back(100);
	
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<'\t';
	cout<<endl;
	
	heapsort(v);
	
	for(int i=0;i<v.size();i++)
		cout<<endl<<v[i]<<'\t';
	
	return 0;
}
