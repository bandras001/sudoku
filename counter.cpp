#include "counter.hpp"
#include <sstream>
#include <string.h>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace genv;
using namespace std;

Counter::Counter( int _x, int _y, int _size_x, int _size_y )
    : Widget( _x, _y, _size_x, _size_y), kek(200,240,244)
{
    w_text = " ";
    szam = 0;
    checked = false;
    u_limit = 9;
    l_limit = 0;
}

void Counter::draw(event ev)
{
    gout << move_to(x,y) << color(200, 200, 200) << box(size_x,size_y);
    gout << move_to(x, y+size_y) << color(250,250,250) << line_to(x,y) << line(size_x,0);
    gout << color(100,100,100) << line(0,size_y) << line_to(x, y+size_y);

    if(checked){
        gout << move_to(x,y) << color(120,240,190) << box(size_x, size_y);
        gout << move_to(x, y+size_y) << color(250,250,250) << line_to(x,y) << line(size_x,0);
        gout << color(50,130,100) << line(0,size_y) << line_to(x, y+size_y);
    }
    //gout << move_to(x-2,y-2) << color(0,255,0)<< box(size_x+4, size_y+4); ///elsõ verzió
    gout << move_to(x+2,y+2);

    if( is_selected(ev) ) gout << kek;
    else gout << color(200,200,200);
    if(checked) gout << color(120,240,190);

    gout << box(size_x-4,size_y-4);
    gout << move_to(x + size_x/2 - gout.twidth(" ")/2, y+ size_y/2 + gout.cdescent());
    gout << color(0,0,0) << text(w_text);
}

void Counter::handle(event ev){

    if( (ev.type == ev_key || ev.type == ev_mouse) && (checked == true) ){

        if( (ev.keycode == key_down || ev.button == btn_wheeldown )&& szam != l_limit ) szam-=1; convert(szam,w_text);

        if( (ev.keycode == key_up || ev.button == btn_wheelup ) && szam!= u_limit ) szam+=1; convert(szam,w_text);

        if( ev.keycode >= 49 && ev.keycode <= 57 ) {w_text = ev.keycode; szam = atoi(w_text.c_str());checked=false;}

    }

    if( (ev.type == ev_mouse && ev.button==btn_left) || (ev.type == ev_key && ev.keycode == key_enter) ) checked = !checked;
    //cout << checked<< endl;

}

bool Counter::is_checked() const{
    return checked;
}

int Counter::get_szam(){
    return szam;
}

void Counter::set_szam(int _szam){
    szam =_szam;
}

void Counter::convert(int _szam, string _w_text){
    stringstream ss;
    ss << _szam;
    w_text = ss.str();
    if(szam == 0) w_text = " ";
}

