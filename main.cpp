#include "application.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include "counter.hpp"

#include <iostream>

using namespace genv;
using namespace std;

int main()
{
    Application app(800,800, "MyApp v1.2"); // példányosítjuk az alkamazást

    // létrehozzuk a vezérlõket
    int terkozi = -3;
    for(int i=0; i<9;i++){
        int terkozj = -3;
        if(i%3==0) terkozi+=3;
        for(int j=0; j<9;j++){
            if( j%3 == 0 ) terkozj += 3;
            Counter* c = new Counter((j+1)*60 + j+1 + terkozj,(i+1)*60 + terkozi + i+1, 60, 60); {
            app.addCounter(c);
            }
        }
    }
    app.run(); // futtatjuk az alkalmazást

    return 0;
}


