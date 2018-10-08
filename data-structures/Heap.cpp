#include<iostream>
#include<vector>
using namespace std;

class Heap{
	private: 
	int TYPE; // MIN => 0, MAX => 1
	vector<int> vec;

	public:
	Heap(int TYPE){
		this->TYPE = TYPE;
	}

	void insert(int num){
		this->vec.push_back(num);
		int i = this->vec.size() - 1;
		if(this->TYPE == 0){
			while(i>0 && num < this->vec[(i-1)/2]){
				this->vec[i] = this->vec[(i-1)/2];
				i = (i-1)/2;
			}
		}
		else{
			while(i>0 && num > this->vec[(i-1)/2]){
				this->vec[i] = this->vec[(i-1)/2];
				i = (i-1)/2;
			}
		}
		this->vec[i] = num;
		this->view();
	}

	int remove(){
		if(this->vec.size() == 0){
			cout<<"Heap is empty"<<endl;
			return -1;
		}
		int num = this->vec[0];
		this->vec.erase(this->vec.begin());
		return num;
	}

	void view(){
		cout<<"Heap => ";
		for(int i : vec)
			cout<<i<<" ";
		cout<<endl;
	}

};


int main(){
	int heap_type,option,n;
	do{
		cout<<"Choose heap type\n0.Min heap\n1.Max heap"<<endl;
		cin>>heap_type;
	}while(heap_type != 0 && heap_type != 1);

	Heap heap(heap_type);

	while(1){
		cout<<"Enter choice\n1.Insert\t2.Delete Top\t3.View Heap\t4.Exit"<<endl;
		cin>>option;
		switch(option){
			case 1:
				cout<<"Enter the element to be inserted"<<endl;
				cin>>n;
				heap.insert(n);
				break;
			case 2:
				heap.remove();
				break;
			case 3:
				heap.view();
				break;
			case 4:
				return 0;
			default : cout<<"Wrong choice entered"<<endl;
		}
	}
	return 0;
}