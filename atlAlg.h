#include <iostream>


namespace stlAlg{
//the stl implementation uses find_if_not for all_of to minimize code 
//repetition so we will implement it here 
    template <class InputIt,class Predicate>
    constexpr InputIt find_if_not(InputIt begin,InputIt end,Predicate p){
        for(;*begin!=end;++begin){
            if(!p(*begin)){
                return begin;
            }
        }
        return end;
    }
    
    
    
    template <class StartIt,class EndIt, class Predicate>
    constexpr bool all_of(StartIt begin,EndIt end ,Predicate p){
        return find_if_not(begin,end,p) == end;
    }
    
    template <class InputIt,class Predicate>
    constexpr InputIt find_if(InputIt begin,InputIt end, Predicate p){
    for(;*begin!=end;++begin){
        if(p(*begin)){
            return begin;
        }
    }
    return end;
    }

    template <class InputIt,class Predicate>
    constexpr bool any_of(InputIt begin,InputIt end, Predicate p){
        return any_of(begin,end,p) != end;
    }

    #include <utility>
    #include <iostream>
    template<class StartIterator,class Size,class Function>
    std::pair<StartIterator,Function> for_each_n(StartIterator start,Size n, Function f){
        for(Size i = 0;i < n;++i,++start){  //equallivent of comparing while (∗p!=0)
            f(*start);
        }
        return {start,f};    

    }

    

    template<class StartIterator,class EndIterator,class Function>
    Function for_each(StartIteratorstart,EndIterator end, Function f){
        for(;start!=end;++start){  //equallivent of comparing while (∗p!=0)
            f(*start);
        }
        return f;    

    };

    //returning f in case it is a lambda function or a functor or those could contain a value that shouldnt be lost 

    template <class InputIt,class Predicate>
    constexpr InputIt find_if(InputIt begin,InputIt end,Predicate p){
        for(;begin!=end;++end){
            if(p(*begin)){
                return begin;
            }
        }
        return end;
    }

    template <class InputIt,class Predicate>
    constexpr bool none_of(InputIt begin,InputIt end,Predicate p){
        return find_if(begin,end,p) == end;
    }

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
    
    }
}


