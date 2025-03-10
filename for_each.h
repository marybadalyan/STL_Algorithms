

template<class StartIterator,class EndIterator,class Function>
Function for_each(StartIteratorstart,EndIterator end, Function f){
    while(start!=end){
        f(*start);
        ++start;
    }
    return f;    //returning f in case it is a lambda function
}