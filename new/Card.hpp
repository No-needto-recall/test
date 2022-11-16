#ifndef _CTL_CARD_HPP_
#define _CTL_CARD_HPP_

#include <iostream>

using std::cout;
using std::endl;
using NumType=int;
using ColourType=int;
using CardType=char;
//0,1,2,3
//♠,♥,♣,♦
enum Suits:ColourType{
    SUITS_SPADE,//♠
    SUITS_HEARTS,//♥
    SUITS_DIAMONDS,//♣
    SUITS_CLUBS//♦
};
//点数2,3,4,5,6,7,8,9,10,J ,Q ,K ,A
//对应2,3,4,5,6,7,8,9,10,11,12,13,14
enum Nums : NumType
{
    NUM_2 = 2,
    NUM_3,
    NUM_4,
    NUM_5,
    NUM_6,
    NUM_7,
    NUM_8,
    NUM_9,
    NUM_10,
    NUM_J,
    NUM_Q,
    NUM_K,
    NUM_A
};

class Card
{
    
public:
    Card()
    :_card(0)
    {}

    Card(NumType num,ColourType colour) 
    :_card(colour*13+(num-2))
    {}
    
    ~Card() {}
    Card &operator=(const Card &card){
        if(this!=&card){
            this->_card = card._card;
         }
            return *this;
   }
    Card &operator=(Card &&card){
        if(this!=&card){
            this->_card = card._card;
         }
            return *this;
    }
    Card(Card&& card)
    :_card(card.GetColour()*13+(card.GetNum()-2))
    {}
    Card(const Card& card)
    :_card(card.GetColour()*13+(card.GetNum()-2))
    {}

    NumType GetNum()const{return (_card%13)+2;}
    ColourType GetColour()const{return _card/13;}
protected:
    //用char一个字节来表示卡牌的点数和花色
    CardType _card;
    //0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11,12,
    //13,14,15,16,17,18,19,20,21,22,23,24,25,
    //_card%13+2=点数
    //_card/13=花色
};

//公共函数
namespace CARD{

inline void PrintNum(const NumType&);
inline void PrintColour(const ColourType&);

}//end of CARD

namespace CARD{

inline void PrintColour(const ColourType&colour){
        if(colour==SUITS_SPADE){
            cout<<"\033[34m♠\033[0m";
        }else if(colour==SUITS_CLUBS){
            cout<<"\033[31m♦\033[0m";
        }else if(colour==SUITS_HEARTS){
            cout<<"\033[31m♥\033[0m";
        }else if(colour==SUITS_DIAMONDS){
            cout<<"\033[34m♣\033[0m";
        }
    }

inline void PrintNum(const NumType&num){
     if(num==NUM_J){cout<<"J";}
    else if(num==NUM_Q){cout<<"Q";}
    else if(num==NUM_K){cout<<"K";}
    else if(num==NUM_A){cout<<"A";}
    else {cout<<static_cast<int>(num);}
}    

}//end of CARD





#endif
