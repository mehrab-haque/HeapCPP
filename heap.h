/*
	Developed by : Md. Mehrab Haque
	mehrab.haque.0001@gmail.com
*/

#ifndef HEAP_H
#define HEAP_H
 
//Dependencies
#include<iostream>
#include<queue>
using namespace std;

//Class Signatures
class Heap{
	int *array;
	int maxSize;
	int currentSize;
	void swap(int &a,int &b);
	int &max(int &a,int &b);
	public:
		Heap(int maxSize);
		void insert(int element);
		int getMax();
		int size();
		void deleteKey();
		void print();
};
//Global function declaration
void heapsort(vector<int> &v);




//Function Definitions
void Heap :: swap(int &a,int &b){
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}

int &Heap :: max(int &a, int &b){
	if(a>b) return a;
	return b;
}

Heap :: Heap(int maxSize){
	this->maxSize=maxSize;
	this->currentSize=0;
	array=new int[maxSize+1];
}

void Heap :: insert(int element){
	int currentIndex=++currentSize;
	array[currentIndex]=element;
	while(currentIndex>1 && array[currentIndex]>array[currentIndex/2]){
		swap(array[currentIndex],array[currentIndex/2]);
		currentIndex/=2;
	}
}

int Heap :: getMax(){
	return array[1];
}

int Heap :: size(){
	return currentSize;
}

void Heap :: deleteKey(){
	array[1]=array[currentSize--];
	int currentIndex=1;
	while((currentIndex*2<currentSize && array[currentIndex]<max(array[currentIndex*2],array[currentIndex*2+1])) || (currentIndex*2==currentSize && array[currentIndex]<array[currentIndex*2])){
		int newIndex=currentIndex*2<currentSize?(array[currentIndex*2]>array[currentIndex*2+1]?currentIndex*2:currentIndex*2+1):currentIndex*2;
		swap(array[currentIndex],array[newIndex]);
		currentIndex=newIndex;
	}
}

void Heap :: print(){
	cout<<endl<<"################################"<<endl;
	for(int i=1;i<=currentSize;i++)
		cout<<array[i]<<'\t';
	cout<<endl<<"################################"<<endl;
}

void heapsort(vector<int> &v){
	Heap h(v.size());
	while(!v.empty()){
		h.insert(v[v.size()-1]);
		v.pop_back();	
	}
	while(h.size()>0){
		v.push_back(h.getMax());
		h.deleteKey();	
	}
}


#endif





