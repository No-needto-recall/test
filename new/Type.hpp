#ifndef _CTL_TYPE_HPP_
#define _CTL_TYPE_HPP_

#include "GroupCards.hpp"
#include <map>
#include <functional>

using std::map;
using std::function;


using TypeType=unsigned int;
enum TypeCards:TypeType{
    HIGH_CARD=1,ONE_PAIR,TWO_PAIRS,THREE_OF_A_KIND,STRAIGHT,
    FLUSH,FULL_HOUSE,FOUR_OF_A_KIND,STRAIGHT_FLUSH,ROYAL_FLUSH
};

class Type;
using Compare =function<bool(const Type &,const Type&)>;
namespace GREADER{
    bool KindCard(const Type&,const Type &);
    bool HighCard(const Type&,const Type &);
    bool RoyalFlush(const Type&,const Type &);
}//end of GREADER

namespace EQUA{
    bool Equa(const Type&,const Type &);
}//end of EQUA

namespace TYPE{
    bool IsStraight(const Cards &cards);
    bool IsRoyalFlush(const Cards &cards);
    TypeType GetType(const Cards&cards5);
    void PrintType(TypeType type);

    Compare SetGreadter(const TypeType type);
}//end of TYPE



class Type
:public GroupCards
{
public:
    Type(Cards cards5);
    ~Type() {}
    bool operator >(const Type &)const ;
    bool operator <(const Type &)const;
    bool operator ==(const Type &)const;
    bool operator >=(const Type &)const;
    bool operator <=(const Type &)const;
private:
    TypeType  _type;
    Compare _greadter;
};


#endif
