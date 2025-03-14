#include <iostream>
#include <utility>


namespace stlAlg{

    template <class InputIt,class Predicate>
    constexpr InputIt find_if_not(InputIt begin,InputIt end,Predicate p){
        for(;begin!=end;++begin){
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
    
    
    template <class InputIt,class Value>
    constexpr InputIt find(InputIt begin,InputIt end, const Value& val){
        for(;begin!=end;++begin){
            if(*begin == val){
                return begin;
            }
        }
        return end;
    }

    template <class InputIt,class Predicate>
    constexpr InputIt find_if(InputIt begin,InputIt end, Predicate p){
        for(;begin!=end;++begin){
            if(p(*begin)){
                return begin;
            }
        }
        return end;
    }
    template <class InputIt,class Predicate>
    constexpr bool any_of(InputIt begin,InputIt end, Predicate p){
        return stlAlg::find_if(begin,end,p) != end;
    }
    
    template<class StartIterator,class Size,class Function>
    std::pair<StartIterator,Function> for_each_n(StartIterator start,Size n, Function f){
        for(Size i = 0;i < n;++i,++start){  //equallivent of comparing while (∗p!=0)
            f(*start);
        }
        return {start,f};    

    }


    template<class StartIterator,class EndIterator,class Function>
    Function for_each(StartIterator start,EndIterator end, Function f){
        for(;start!=end;++start){  //equallivent of comparing while (∗p!=0)
            f(*start);
        }
        return f;    

    }
    //returning f in case it is a lambda function or a functor or those could contain a value that shouldnt be lost 

    template <class InputIt,class Predicate>
    constexpr bool none_of(InputIt begin,InputIt end,Predicate p){
        return find_if(begin,end,p) == end;
    }
 
    
    template <class InputIt1,class InputIt2>
    constexpr InputIt1 search(InputIt1 begin1,InputIt1 end1,InputIt2 begin2,InputIt2 end2){
        while(true){
            InputIt1 start = begin1;
            for(InputIt2 it = begin2;;++it,++start){
                if(it == end2){
                    return start;
                }
                if(start == end1){
                    return end1;
                }
                if(*it != *start)
                {
                    break;
                }
            }
            ++begin1;
        }
    }

    template <class InputIt1,class InputIt2,class Pred>
    constexpr InputIt1 search(InputIt1 begin1,InputIt1 end1,InputIt2 begin2,InputIt2 end2,Pred p){
        while(true){
            InputIt1 start = begin1;
            for(InputIt2 it = begin2;;++it,++start){
                if(it == end2){
                    return start;
                }
                if(start == end1){
                    return end1;
                }
                if(!p(*it,*start))
                {
                    break;
                }
            }
            ++begin1;
        }
    }

    template <class InputIt1, class InputIt2>
    constexpr InputIt1 find_end(InputIt1 begin1, InputIt1 end1, InputIt2 begin2, InputIt2 end2) {
        if (begin2 == end2) {
            return end1;
        }

        InputIt1 result = end1;  // Last known match, initially "not found"
        while (true) {
            InputIt1 new_result = stlAlg::search(begin1, end1, begin2, end2);
            if (new_result == end1) {
                break;  // No more matches
            } else {
                result = new_result;  // Update last match
                begin1 = new_result;  // Move start to current position
                ++begin1;  // Advance by one
            }
        }
        return result;
    }

    template <class InputIt1, class InputIt2, class Pred>
    constexpr InputIt1 find_end(InputIt1 begin1, InputIt1 end1, InputIt2 begin2, InputIt2 end2, Pred p) {
        if (begin2 == end2) {
            return end1;
        }

        InputIt1 result = end1;
        while (true) {
            InputIt1 new_result = stlAlg::search(begin1, end1, begin2, end2, p);
            if (new_result == end1) {
                break;
            } else {
                result = new_result;
                begin1 = new_result;
                ++begin1;
            }
        }
        return result;
    }
    template <class InputIt1, class InputIt2>
    constexpr InputIt1 find_first_of_find(InputIt1 start1, InputIt1 end1,InputIt2 start2,InputIt2 end2){
        for(InputIt1 it = start1;it != end1;++it){
            if(stlAlg::find(start2,end2,*it) != end2){
                return it;
            }
        }
        return end1;
    }
    template <class InputIt1, class InputIt2>
    constexpr InputIt1 find_first_of(InputIt1 start1, InputIt1 end1,InputIt2 start2,InputIt2 end2){
        for(;start1!=end1;++start1){
            for(InputIt1 it = start2;it != end2;++it){
                if(*it == *start1){
                    return start1;
                }
            }
        }
        return end1;
    }

}