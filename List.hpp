#pragma once

  
template<typename T>
struct Element{//элемент списка
  	T _data; // значенеи элемента
	Element *_next;	//ссылка на следущий элемент
	Element *_prev;	//ссылка на предыдущий элемент
};

template<typename T>
class List {
private:
    Element<T> *_head; //начало списка
	Element<T> *_tail; //начало списка
    int _size; //размер
public:
   List();//конструктор
   void add(const T &_data);//заносим элемент в конец списка
   T remove(int index);//удаляем i-ый элемент
   int size(); //размер
   T operator[](int index)const;//получение i-го элемента
   T & operator[](int index);//получение i-го элемента
   void clear();
   ~List(); //деструктор
};

template<typename T>
void List<T>::clear(){
   for(int i = 0; i < _size; --_size){//проходим по каждому элементу
		   Element<T> *buf = _head;
		   _head = _head->_next;//переходим к следующему
		   delete buf;//удаляем предыдущий
		}
}

template<typename T>
List<T>::List<T>():_head(nullptr), _tail(nullptr), _size(0){
   }

template<typename T>
void List<T>::add(const T &_data){
	    Element<T> *buf = new Element<T>;
		buf->_data = _data;
		buf->_next = nullptr;
		buf->_prev = _tail;
		if (_tail) {
			_tail->_next = buf;
		}
		if (_head == nullptr) {
			_head = buf;
		}
		_tail = buf;
		++_size;
}

template<typename T>
T List<T>::remove(int index){
	   if(index < 0 || index >= _size){//если неверный  индекс
			return T(0);
	   }
		Element<T> *temp = _head;
		for(int i = 0; i < _size && i < index; ++i) {	// получаем нужный элемент
			temp = temp->_next;
		}

		if (temp == nullptr) {// если не нашли
			return T(0); 
		}
		if (temp->_prev) {
			temp->_prev->_next = temp->_next;
		}
		if (temp->_next) {
			temp->_next->_prev = temp->_prev;
		}
		T _data = temp->_data;
 
		if (temp->_prev == nullptr) {
			_head = temp->_next;
		}
		if (temp->_next == nullptr) {
			_tail = temp->_prev;
		}
		delete temp;
		--_size;
		return _data;
}

template<typename T>
int List<T>::size(){ 
	return _size; 
}

template<typename T>
T & List<T>::operator[](int index){
	    Element<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //ищем нужный элемент
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
T List<T>::operator[](int index)const{
	    Element<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //ищем нужный элемент
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
List<T>::~List(){ //деструктор
		for(int i = 0; i < _size; --_size){//проходим по каждому элементу
		   Element<T> *buf = _head;
		   _head = _head->_next;//переходим к следующему
		   delete buf;//удаляем предыдущий
		}
}


