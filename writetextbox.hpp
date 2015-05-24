#ifndef WRITETEXTBOX_HPP_INCLUDED
#define WRITETEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string>

using namespace std;

class WriteTextBox : public Widget{
protected:
    char w_text;
    bool checked;
    int szam;
public:
    WriteTextBox( int _x, int _y, int size_x,int _size_y, char _w_text );
    virtual void draw(genv::event ev);
    virtual void handle( genv::event ev );
    virtual bool is_checked() const;
};

#endif // WRITETEXTBOX_HPP_INCLUDED
