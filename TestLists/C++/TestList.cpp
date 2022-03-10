//TestList.cpp
//10/03/2022

#include <iostream>
#include <vector>

using namespace std;

class list_element{
	public:
	    list_element(int n=0, list_element* ptr=0):d(n), next(ptr){}
		int d;
		list_element* next;
};


class list{
	public:
	    list():head(0), cursor(0){}
		list(const int* arr, int n);
		list(const list& lst);
		void prepend(int n);
		int get_element(){return cursor->d;}
		void advance(){cursor = cursor->next;}
		void print();
        ~list();
	private:
        list_element* head;
        list_element* cursor;
};


void list::prepend(int n){
	if(head == 0)
		cursor = head = new list_element(n, head);
	else
		head = new list_element(n, head);
}

void list::print(){
	list_element* h = head;
	while(h != 0){
	    cout << h->d <<",";
        h = h->next;		
	}
}

list::list(const list& lst){
	if(lst.head == 0){
		head = 0;
		cursor = 0;
	}
	else{
		list_element* h = new list_element();
	    list_element* previous;
		cursor = lst.head;
		head = h;
		h->d = lst.head->d;
		previous = h;
	
	    for(cursor = lst.head->next; cursor != 0;){
		   h = new list_element();
		   h->d = cursor->d;
		   previous->next = h;
		   cursor = cursor->next;
		   previous = h;
	    }
	}
	cursor = head;
}

list::list(const int* arr, int n){
    
	if(head == 0){
	    cursor = 0; 
		head = 0;
	}
	else{
		list_element* h = new list_element();
		cursor = head;
		head = h;
		for (int i=n-1; i>=0; --i){
		   head = new list_element(arr[i], head);
	    }
	}	
}

list::~list(){
	for(cursor=head; cursor !=0;){
		cursor = head->next;
		delete head;
		head = cursor;
	}
}

int main(){
    list a, b;
    a.prepend(9);
	a.prepend(8);
    
	cout << "list a " << endl;
    a.print();
	cout << "\n";
   
    for(int i=0; i < 40; ++i)
         b.prepend(i*i);
   	cout << "list b " << endl;
	b.print();
	cout << "\n";	
	
	list c(b);
	cout << "list c " << endl;
	c.print();
	cout << "\n";
	
	int data[10] = {3,4,6,7,-3,5};
	
	list d(data, 6);
	cout << "list d " << endl;
	d.print();
	cout << "\n";
	
    list e(data,10);
	cout << "list e " << endl;
	e.print();
	cout << "\n";
	
    return 0;
}