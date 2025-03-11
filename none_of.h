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