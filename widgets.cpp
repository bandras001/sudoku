/// Ebben a cpp f�jlban lesz a Widget oszt�ly implement�l�sa
#include "widgets.hpp"
#include <iostream>

using namespace genv;
using namespace std;

// A Widget oszt�ly konstruktorainak kifejt�se
Widget::Widget( ) {}                                            // Param�ter n�lk�li konstruktor
Widget::Widget( int _x, int _y ) : x(_x), y(_y) {checked=false;}              // K�t param�teres konstruktor
Widget::Widget( int _x, int _y, int _size_x, int _size_y )      // N�gy param�teres konstruktor
: x(_x), y(_y), size_x(_size_x), size_y(_size_y) {
    inFocus = false;
    asd = true;
    checked = false;

}

// A Widget oszt�ly is_selected f�ggv�ny�nek kifejt�se
bool Widget::is_selected( event ev ) const {
    return ev.pos_x>x && ev.pos_x<x+size_x && ev.pos_y>y && ev.pos_y<y+size_y;
}
void Widget::unfocus( event ev ){
    if(ev.button == btn_left) {//inFocus=false;
    checked=false;
    //cout << checked<< endl;
    }
}

void Widget::draw(event ev) {}

void Widget::handle(event ev) {}

void Widget::set_focus( bool focus ){
    inFocus = focus;
}
void Widget::set_checked(bool _checked){
    checked =_checked;
}
