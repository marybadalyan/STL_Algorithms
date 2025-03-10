

template<class StartIterator,class EndIterator,class Function>
Function for_each(StartIteratorstart,EndIterator end, Function f){
    for(;start!=end;++start){  //equallivent of comparing while (∗p!=0)
        f(*start);
    }
    return f;    

};

//returning f in case it is a lambda function or a functor or those could contain a value that shouldnt be lost 


/*
2: changed it to for loop for better readability
1 :used a while loop at try1
while(start!=end){  
        f(*start);
        ++start;
    } Tour of C++, pg14
*/