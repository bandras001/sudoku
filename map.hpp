/*#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include "widgets.hpp"

using namespace std;
using namespace genv;

class Counter:public Widget{
protected:
    bool checked;
    int szam;
    string w_text;
    int l_limit, u_limit;
    color kek;
public:
    Counter( int _x, int _y, int size_x,int _size_y );
    virtual void draw(genv::event ev);
    virtual void handle( genv::event ev );
    virtual bool is_checked() const;

    virtual int get_szam();
    virtual void set_szam(int _szam);
    virtual void convert(int _szam, string _w_text);
};

#endif // MAP_HPP_INCLUDED


