#include <iostream>
using namespace std;

class Duck{
    public:
        virtual ~Duck() = default;
        
        virtual void quack() const{ cout << "\nQuack Quack"; };
        virtual void fly() const{ cout << "\nIm flying"; };
};

class Turkey{
    public:
        virtual void gobble() const { cout << "\nTurkey goes Gobble Gobble"; };
        virtual void fly() const { cout << "\nTurkeys fly slowly"; };
};

class MallarDuck : public Duck{
    public:
        MallarDuck() = default;
        
        void quack() const override { cout << "\nQuack  QUAKC Quack"; };
        void fly() const override { cout << "\nIm flying FAST"; };
};

class WildTurkey : public Turkey{
    private:
    public:
        void gobble() const { cout << "\nZZZZZZZZZ"; };
        void fly() const { cout << "\nTAHHHHHHHHHHHHHH"; };
        
};

class TurkeyAdapter : public Duck{
    private:
        Turkey *t;
    public:
        TurkeyAdapter() = default;
        TurkeyAdapter(Turkey *turkey): t(turkey){}
        
        virtual void quack() const override { this->t->gobble(); };
        virtual void fly() const override { 
            for(int i = 0; i < 5; i++){
                this->t->fly();
            }
        };
};

void testDuck(const Duck *duck){
    duck->quack();
    duck->fly();
}

int main() {
    MallarDuck *md = new MallarDuck;
    testDuck(md);
    
    WildTurkey *wt = new WildTurkey;
    TurkeyAdapter *wtadapter = new TurkeyAdapter(wt);
    testDuck(wtadapter);
    
    delete md;
    delete wt;
    delete wtadapter;
    
    return 0;
}
