template <class StartIt,class EndIt, class Predicate>
constexpr bool all_of(StartIt begin,EndIt end ,Predicate p){
    for(;*begin!=end;++begin){
        if(!p(*begin)){
            return false;
        }
    }
    return true;
}

//the stl implementation uses find_if_not for all_of to minimize code 
//repetition but becouse we dont have it implemented yet well use our own 