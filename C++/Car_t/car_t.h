#pragma once
# include <iostream>
# include <string>
using namespace std;
class car_t{
    
    public:
        car_t():id(idAll++){
            
            cap=defCap;

        };
        car_t(size_t capacity):id(idAll++){
            
            cap=capacity;
        };
        car_t(const car_t & car):id(idAll++){
            cap=car.cap;

         };
        car_t& operator= (const  car_t& car){cap=car.cap;};
        bool operator< (const  car_t& car)const;
        bool compareStrings(const  car_t& car);
        const string getName()const{return name;}; 
        const string getType() const{return type;};
        const size_t getCap() const{return cap;};
        const int getId() const{return id;};

        
        
        

    
    protected:
         ~car_t(){};
         void  setType(string t){ type=t;};
         void  setName(string t){name=t;};


        
       
        
    private:
        const int id;
        static int idAll;   
        string type;
        string name;
        size_t cap;
        static size_t defCap;

};

class private_t: public car_t{
   public:

    ~private_t(){};
    private_t(){
        speed=0;
        setType("auto");
        setName("car");
    };
     private_t(size_t capacity):car_t(capacity){
        speed=0;
        setType("auto");
        setName("car");
        
    };
    size_t getSpeed()const{return speed;};
    void acc(){speed+=10;};
    void red(){
        if(speed!=0)
        speed-=10;
        };

   private:
     size_t speed;
     

};

class bus_t: public car_t{
   public:

    ~bus_t(){};
    bus_t(){
        setType("gear");
        setName("bus");
        seats=0;
        line=0;
    };
     bus_t(size_t capacity,size_t se,size_t le):car_t(capacity){
        setType("gear");
        setName("bus");
        seats=se;
        line=le;
        
    };
    size_t getSeats()const{return seats;};
    size_t getLine()const{return line;};
    size_t setSeats(size_t se){seats=se;};
    size_t setLine(size_t le){line=le;};
    

   private:
     size_t seats;
     size_t line;
     



};
