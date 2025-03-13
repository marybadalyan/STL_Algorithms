#include <iostream>
#include <utility>


namespace stlAlg{

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
 
    
    template <class InputIt1,class InputIt2>
    constexpr InputIt1 search(InputIt1 begin1,InputIt1 end1,InputIt2 begin2,InputIt2 end2){
        while(true){
            InputIt1 start = begin1;
            for(InputIt2 it = begin2;++it,++start){
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

    //implementing find_end with search
    template <class InputIt1,class InputIt2>
    constexpr InputIt1 find_end(InputIt1 begin1,InputIt1 end1,InputIt2 begin2,InputIt2 end2){
        if(begin2 == end2){
            return end1;
        }

        InputIt1 end = end1;
        while(true){
            InputIt1 new_end = stlAlg::search(begin1,end1,begin2,end2);
            if(new_end == end){
                break;
            }
            else{
                end = new_end;
                begin1 = end;
                ++begin1;
            }
        }
        return end;
    }

    template <class InputIt1,class InputIt2,class Pred>
    constexpr InputIt1 search(InputIt1 begin1,InputIt1 end1,InputIt2 begin2,InputIt2 end2,Pred p){
        while(true){
            InputIt1 start = begin1;
            for(InputIt2 it = begin2;++it,++start){
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

    template <class InputIt1,class InputIt2,class Pred>
    constexpr InputIt1 find_end(InputIt1 begin1,InputIt1 end1,InputIt2 begin2,InputIt2 end2,Pred p){
        if(begin2 == end2){
            return end1;
        }

        InputIt1 end = end1;
        while(true){
            InputIt1 new_end = stlAlg::search(begin1,end1,begin2,end2,p);
            if(new_end == end){
                break;
            }
            else{
                end = new_end;
                begin1 = end;
                ++begin1;
            }
        }
        return end;
    }
}