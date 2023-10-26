#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 	Node<T>* first;
	int n;
        // ...

    public:
	ListLinked(){
		first= nullptr;
		n=0;
	}
	~ListLinked(){
		while(first!=nullptr){
		Node<T> *aux = first->next;
		delete first;
		first = aux;
		}

	}
	T operator[](int pos){
		if(pos>=0 && pos < n){
			 Node<T>*aux = first;
			 for(int i =1; i < pos; i ++){
				 aux= aux->next;
		}
			 return aux->data;
		}	 
		else{
			throw std::out_of_range("posicion no valida");
		}
		


	}
	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		out << "List ->[";

		Node<T>*aux = list.first;

		while(aux){
			out<< aux->data;
			if(aux->next != nullptr)
				out<<",";

			aux = aux->next;
		}
		out << "]";
		return out;



	}
	 virtual void insert(int pos, T e) override{
		 if( pos >  n || pos< 0){
			 throw std::out_of_range("Posición no válida, fuera del array");
		 }
		if(pos==0){
			prepend(e);
		}
		else if( pos== n){
		append(e);
		}
		 else{
			 Node<T>*prev = first;
			for(int i =1; i<pos; i ++){
				prev = prev-> next;

			}
			Node<T>*aux = new Node<T>(e,prev->next);
                        prev->next = aux;

			n++;
		}
	 }
      virtual  void append( T e) override{
       		if(first== nullptr){
			prepend(e);
		}
		else{
			Node<T>*prev= first;
			for(int i =1; i < size();i ++){
				prev= prev-> next;
			}
			Node<T>*aux = new Node<T>(e,prev->next);
			prev->next = aux;
		}
		n++;
	
       }
      virtual  void prepend(T e) override{
	     Node<T>*aux = new Node<T>(e,first);
	     first= aux;
	     n++;
       }
      virtual  T remove(int pos) override{
	       Node <T>* aux = first;
	       Node<T>* del;
	       int delet;
	       if( pos> size()-1 || pos< 0){
		       throw std::out_of_range ("Posición no válida, fuera del array");
	       }
	       else{
		       if(pos==0){
			       first= aux->next;
			       del=aux;
			       delet = del->data;
			 }
		     else{

		       for(int i =1 ; i < pos ; i ++){
			       aux = aux->next;

		       }
		       del= aux->next;
		       delet = del->data;
		       aux->next= del->next;
		     }
		  n--;
		  delete del;
		  return delet;
		}
       }
       virtual T get (int pos) override{
		if( pos> size()-1 || pos< 0){
                       throw std::out_of_range ("Posición no válida, fuera del array");
               }
               else{
		       Node<T>*aux= first;
		       for(int i =0;i <=pos; i ++){
			       aux = aux->next;
		       }
		   	return aux->data;
	    	}
	}
       virtual  int search( T e) override{
		Node <T>*aux= first;
	for(int i =0; i <= n ; i ++){
		if(aux->data=e){
			return i;
		}
		aux=aux->next;
	}
		 
			return -1;

	
	}
       virtual  bool empty() override{
		if(n ==0)//lista vacía
			return true;
		else 
			return false;
	}
       virtual  int size() override{
		return n ;
	}
   };
        
