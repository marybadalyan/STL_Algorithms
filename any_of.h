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
