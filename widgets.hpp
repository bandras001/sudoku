#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <string>

using namespace genv;
using namespace std;

class Widget {
    protected:
        int x, y, size_x, size_y;
        bool checked, inFocus,asd;

    public:
        Widget( );
        Widget( int _x, int _y );
        Widget( int _x, int _y, int _size_x, int _size_y );

        virtual bool is_selected( event ev ) const;
        virtual void unfocus(event ev);
        virtual void draw( event ev );
        virtual void handle( event ev );
        void set_focus( bool focus );
        void set_checked(bool _checked);


        bool is_focused() const { return inFocus;   }               // Fókuszban van-e még a widget
        int positionX() const   { return x;         }
        int positionY() const   { return y;         }
        int width() const       { return size_x;    }
        int height() const      { return size_y;    }

        };

#endif // WIDGETS_HPP_INCLUDED
