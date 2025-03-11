#include <utility>
#include <iostream>
template<class StartIterator,class Size,class Function>
std::pair<StartIterator,Function> for_each_n(StartIterator start,Size n, Function f){
    for(Size i = 0;i < n;++i,++start){  //equallivent of comparing while (∗p!=0)
        f(*start);
    }
    return {start,f};    

};

