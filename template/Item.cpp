template <class T>
Item<T>::Item() : data(T()){
}

template <class T>
void Item<T>::SetData(T& data){
    this.data = data;
}

template <class T>
T Item<T>::GetData(){
    return data;
}