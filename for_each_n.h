template<class StartIterator,int n,class Function>
Function for_each_n(StartIterator start,int n, Function f){
    for(int i = 0;i < n;++i,++start){  //equallivent of comparing while (∗p!=0)
        f(*start);
    }
    return f;    

};
