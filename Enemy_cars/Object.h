#pragma once
class MyObject{
    public:
        void set_x(int X) {x=X;}
        void set_y(int Y) {y=Y;}
        int get_x() {return x;}
        int get_y() {return y;}
    private:
        int x,y;
};