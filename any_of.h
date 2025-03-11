template <class StartIt,class EndIt, class Predicate>
constexpr bool any_of(StartIt begin,EndIt end ,Predicate p){
    for(;*begin!=end;++begin){
        if(p(*begin)){
            return begin;
        }
    }
    return end;
}



template <class StartIt,class EndIt, class Predicate>
constexpr bool any_of(StartIt begin,EndIt end ,Predicate p){
    return any_of(begin,end,p) != end;
}
