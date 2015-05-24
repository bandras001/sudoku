#include "application.hpp"
#include "graphics.hpp"
#include "game.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace genv;

Application::Application( int _SX, int _SY, std::string _name ) : SX(_SX), SY(_SY), name(_name) {
    isExiting = false;
    focused = -1;               // a program indulásakor semmi nincs fókuszban
}

void Application::addWidget( Widget *w ) {
    widgets.push_back( w );
}

void Application::addCounter( Counter *w ) {
    table.push_back( w );
}

void Application::run() {
    gout.open( SX, SY );
    gout.set_title( name );

    beolvas();

    for(int i = 0;i<9;i++) {
        for(int j = 0;j<9;j++)  {
            cout << tomb[i][j];
        }
        cout << endl;
    }

    Game game(tomb);
    vector<vector<int>> szamok = game.getNumbers();


    for(int i=0; i<table.size(); i++){

        table[i]->set_szam(szamok[i/9][i%9]);
        if(szamok[i/9][i%9] != 0) table[i]->set_active();
    }
    event ev;
    while( gin>>ev && !isExiting ) {     // amíg fogadhat eseményeket és nincs kilépési módban
        vector<vector<bool>> valid = game.getValidNumbers();

        for(int i=0; i<table.size(); i++){
            table[i]->set_valid(valid[i/9][i%9]);
        }
        if( ev.keycode == key_escape )   // esc hatására kilépünk
            isExiting = true;



        /// Fókusz kezelése
        /*if( ev.keycode == key_tab && table.size() > 0 )   // Tab hatására változik a fókusz
            focused = ( focused + 1 ) % table.size();  */   // körbe jár a már létező widgeteken

        if( ev.type == ev_mouse && ev.button==btn_left  ) { // Bal egér klikk a kiválasztás  (csak bal klikk-kor figyelnek az elemek)
            focused = -1;                                   // Ha semleges helyre történt a klikkelés (nincs ott semmi), akkor megszüntetjük a fókuszt
            for( size_t i=0; i<table.size(); i++ ) { // Minden widget-re megvizsgáljuk, hogy ő van-e választva vagy sem

                if( table[i]->is_selected(ev) ) {
                        focused = i;
                        cout << "Active widget: " << focused << endl;
                } else {
                    table[i]->unfocus( ev );
                }
            }

        }

        for( size_t i=0; i<table.size(); ++i )            // közöljük a widgetekkel, hogy melyikük van fókuszban
            table[i]->set_focus( focused == (int)i );


        /// Eseménykezelés
        if( focused != -1) {                               // csak a fókuszban lévő widget kapja meg az eseményeket
           table[focused]->handle( ev );
           table[focused]->set_checked(true);
            game.step(focused/9,focused%9, table[focused]->get_szam());
        }

        /*for( size_t i=0; i<table.size(); ++i )            // a vektorban található összes vezérlõ megkapja az eseményeket
            table[i]->handle( ev );  */                   // eseménykezelés widget szinten

        /// Vizualizálás
        gout << move_to(0, 0) << color(0,0,0) << box(SX, SY);// képernyő törlése
        for( size_t i=0; i<table.size(); ++i )
            table[i]->draw(ev);                             // képernyő újra rajzolása
        gout << refresh;                                    // képernyő frissítése
    }
}

void Application::shutdown() {
    isExiting = true;                                       // kilépés inicializálása
}

void Application::beolvas(){
    ifstream f("easy.txt");
    if (!f.good()) cerr << "HIBA a beolvasaskor!";
    string s;
    int szam;

    while (f.good())
            {
                for(int i = 0; i < 9; i++){
                    for(int j = 0; j < 9; j++){
                        getline(f,s, ' ');
                        if(s=="_") s="0";
                        stringstream ss;
                        ss << s;
                        ss >> szam;
                        ss.clear();
                        tomb[i][j] = szam;
                    }
                }
            }
            f.close();
}
