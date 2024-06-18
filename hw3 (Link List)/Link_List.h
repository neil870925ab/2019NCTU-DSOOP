#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template <typename T>
struct Int_Node
{
	T value;
	Int_Node<T> *pre, *next;
};

template <typename T>
class Link_List
{
	
	template <typename U>
	friend ostream &operator<<(ostream &o, const Link_List<U> &a){	// print all integers in the list
		
		Int_Node<T> *S=a.head->next;
		for(int i=0;i<a.size;i++){
			o<<S->value<<" ";
			S=S->next;
		}
		return o;
	}  	
	
	template <typename U>
	friend istream &operator>>(istream &o, Link_List<U> &a){			// input a value at the back of the list, like insert_node(val);
	
		U input;
		o>>input;
		a.insert_node(input);
		
		return o;
	}
	
	
public:
	Link_List(){										// default constructor
	
		head=new Int_Node<T>;
		tail=new Int_Node<T>;
		tail->pre=head;
		head->pre=0;
		head->next =tail;
		tail->next=0;
		size=0;
	}	
										
	Link_List(const Link_List &a){						// copy constructor
	
		head=new Int_Node<T>;
		tail=new Int_Node<T>;
		head->pre=0;
		tail->next=0;
		size=a.getSize();
		
		
		Int_Node<T> *S=head;
		
		for(int i=0;i<size;i++){
			
			S->next=new Int_Node<T>;
			S->next->pre=S;
			S->next->value=a[i];
			S=S->next;
			
		}
		
		S->next=tail;
		tail->pre=S;
		for(int i=0;i<size;i++){
			1;
		}
	}
	
	~Link_List(){
		
		Int_Node<T> *S=head;
		while(S!=0){
			Int_Node<T> *N=S->next;
			delete S;
			S=N;
		}
	}											
	
	
	int getSize() const{
		return size;	
	}
	
	const Link_List &operator=(const Link_List &a){;		// assignment operator
	
		Int_Node<T> *S=head->next;
		while(S->next!=0){
			Int_Node<T> *N=S->next;
			delete S;
			S=N;
		}
		size=a.getSize();
		
		if(size==0){
			return *this;
		}
		 
		S=this->head;
		
		for(int i = 0;i<size;i++){
			S=S->next;
			S->next=new Int_Node<T>;
			S->next->pre=S;
			S->next->value=a[i];

		}
		
		return *this;
		
	}
	
	
	bool operator==(const Link_List &a) const{			// equality operator
	
		if(this->size!= a.size){
			return false;
		}
		
		Int_Node<T> *x=head->next;
		Int_Node<T> *y=a.head->next;
		 
		for(int i=0;i<this->size;i++){
			if(x->value!=y->value){
                return false;
			}
			else{
				x=x->next;
                y=y->next;
			}
		}
		
		return true;

	}
	
	
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this==right);
	}
	
	

	T &operator[](int index){							// subscript operator for non-const objects
	
		Int_Node<T> *S=head->next;
		
		for(int i=0;i<index;i++){
			S=S->next;
		}
		
		return S->value;
	}
	
	
	T operator[](int index) const{						// subscript operator for const objects
		
		Int_Node<T> *S=head->next;
		
		for(int i=0;i<index;i++){
			S=S->next;
		}
		
		return S->value;
	}	

	bool insert_node(T value){							// insert an integer at the back of link list
	
		Int_Node<T> *S=new Int_Node<T>;
		S->pre=tail->pre;
		S->pre->next=S;
		S->next=tail;
		tail->pre=S;
		S->value=value;
		size++;
		
		return true;

	}
	
	bool delete_node(){									// delete the last node
	
		Int_Node<T> *S=tail->pre;
		if(S!=0){
			S->pre->next=tail;
			tail->pre=S->pre;
			delete S;
			size --;
		}
		
		return true;
	
	}
	
	bool insert_node(int index, T value){				// insert an integer after the i_th position
	
		Int_Node<T> *S=new Int_Node<T>;
		Int_Node<T> *X=head->next;
		for(int i=0;i<index-1;i++){ 
			X=X->next;
		} 
		
		size ++;	
		
		S->pre=X->pre;
		S->next=X;
		X->pre->next=S;
		X->pre=S;
		
		
		S->value=value;

		return true;

	}
	
	bool delete_node(int index){						// delete the i_th node
	
		Int_Node<T> *S=head->next;
		
		for(int i=0;i<index-1;i++){
			S=S->next;
		}
		
		Int_Node<T> *tmp=S->next;
		Int_Node<T> *tmp_2=S->pre;
		delete S;
		tmp_2->next=tmp;
		
		if(tmp!=NULL){
			tmp->pre=tmp_2;
		}
		
		size--;

		return true;
	
	}

private:
	int size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};


#endif // LINK_LIST
