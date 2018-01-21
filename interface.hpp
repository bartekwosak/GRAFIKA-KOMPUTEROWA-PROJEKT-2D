#include <allegro.h>

void interface(BITMAP* buffor,BITMAP* bmp,int &czulosc, int &zakres);

void rysuj_zaznaczenie(BITMAP* buffor,BITMAP* bmp,int tab[800][600]);

void zaznacz_kursorem(BITMAP* bmp, int tab[800][600]);

void zaznacz_rozdzka(BITMAP *buffor,int tab[800][600], int zakres, int czulosc);

void zaznacz_wszystko(int tab[800][600]);
