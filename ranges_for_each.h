#include <ranges>
#include <iostream>
template<class Range,class Function>
Function for_each(Range& r, Function f){
    auto first = std::ranges::begin(r);
    auto last = std::ranges::end(r);
    for(;start!=end;++start){  //equallivent of comparing while (∗p!=0)
        f(*start);
    }
    return f;    

};  