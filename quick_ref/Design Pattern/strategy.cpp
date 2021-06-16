// Change the strategy at run time for an algorithm lets say

class Strategy {
public:
    virtual void phase1();
    virtual void do_this();
};

class Str1 : public Strategy {};
class Application
{
public:
    void setStrategy(Strategy *s) {
        cs = s;
    }


private:
    Stategy* cs;
};

client()
{
    APplication *ap;
    ap->setStrategy(new Str1);
    ap->start();
}