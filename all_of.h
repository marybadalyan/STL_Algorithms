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

//the stl implementation uses find_if_not for all_of to minimize code 
//repetition so we will implement it here 