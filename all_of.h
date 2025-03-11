template <class StartIt,class EndIt, class Predicate>
constexpr bool all_of(StartIt begin,EndIt end ,Predicate p){
    for(;*begin!=end;++begin){
        if(!p(*begin)){
            return false;
        }
    }
    return true;
}