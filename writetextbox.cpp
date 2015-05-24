#include "writetextbox.hpp"
#include "graphics.hpp"
#include <string>
#include <sstream>

using namespace genv;
using namespace std;

WriteTextBox::WriteTextBox( int _x, int _y, int _size_x, int _size_y, char _w_text )
    : Widget( _x, _y, _size_x, _size_y)
{
    w_text = _w_text;
    checked = false;
}

void WriteTextBox::draw(event ev)
{
    gout << move_to(x-2,y-2) << color(0,255,0)<< box(size_x+4, size_y+4);
    gout << move_to(x,y);
    if(is_selected(ev)){
        gout << color(200,200,200);
    } else gout << color(255,255,255);
    gout << box(size_x,size_y);
    gout << move_to(x + size_x/2 /*- gout.twidth(w_text)/2*/, y+ size_y/2 + gout.cdescent());
    gout << color(0,0,0) << text(w_text);
}

void WriteTextBox::handle(event ev)
{
    if( ev.type == ev_key && (checked == true) )
    {
            if(ev.type == ev.keycode){
                w_text = ev.keycode;
            }
    }
    if( ev.type == ev_mouse && is_selected(ev) && (ev.button==btn_left || ev.keycode == key_enter )) checked = !checked;
}

bool WriteTextBox::is_checked() const{
    return checked;
}
