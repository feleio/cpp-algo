template <class T>
Item<T>::Item() : data(T()){
}

template <class T>
void Item<T>::SetData(T data){
    this->data = data;
}

template <class T>
T Item<T>::GetData(){
    return data;
}

template <class T>
template <class U>
void Item<T>::SetAverageFrom(U values[], int n){
    T sum = T();
    for(int i=0;i<n;++i){
        sum += values[i];
    }
    data = sum / n;
}

template <class T>
Item<T>::operator double(){
    return data;
}

template <class T>
template <class U>
void Item<T>::operator= (const U& other){
    data = other.GetData();
}
