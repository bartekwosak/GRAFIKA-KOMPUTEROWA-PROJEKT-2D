//#include <iostream>
#include <allegro.h>
#include "interface.hpp"
#include "jasnosc.hpp"
#include "zmiana.kolorow.hpp"

using namespace std;

void negatyw(BITMAP* buffor, int tab[800][600])
{
    if(mouse_b&1&&(mouse_x>0&&mouse_x<100&&mouse_y>300&&mouse_y<350))
    {
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                if(tab[i][j] == 1)
                {
                    int r = 255-getr(getpixel(buffor,i,j));
                    int g = 255-getg(getpixel(buffor,i,j));
                    int b = 255-getb(getpixel(buffor,i,j));
                    if(r<0)
                        r = 0;
                    if(g<0)
                        g = 0;
                    if(b<0)
                        b = 0;
                    putpixel(buffor,i,j,makecol(r,g,b));
                }
            }
        }
    }
}

void rozmycie(BITMAP *buffor, int tab[800][600])
{
    if(key[KEY_Q])
    {
        int maska[3][3] = {{1,1,1},
            {1,1,1},
            {1,1,1}
        };
        for(int i=1; i<799; i++)
        {
            for(int j=1; j<599; j++)
            {
                if(i-1>0    &&  i+1<800    &&  j-1>0 &&   j+1<600)
                {
                    if(tab[i][j] == 1)
                    {
                        int r11= getr(getpixel(buffor,i-1,j-1));
                        int g11 = getg(getpixel(buffor,i-1,j-1));
                        int b11 = getb(getpixel(buffor,i-1,j-1));

                        int r12= getr(getpixel(buffor,i,j-1));
                        int g12 = getg(getpixel(buffor,i,j-1));
                        int b12 = getb(getpixel(buffor,i,j-1));

                        int r13= getr(getpixel(buffor,i+1,j-1));
                        int g13 = getg(getpixel(buffor,i+1,j-1));
                        int b13 = getb(getpixel(buffor,i+1,j-1));

                        int r21= getr(getpixel(buffor,i-1,j));
                        int g21 = getg(getpixel(buffor,i-1,j));
                        int b21 = getb(getpixel(buffor,i-1,j));

                        int r22= getr(getpixel(buffor,i,j));
                        int g22 = getg(getpixel(buffor,i,j));
                        int b22 = getb(getpixel(buffor,i,j));

                        int r23= getr(getpixel(buffor,i+1,j));
                        int g23 = getg(getpixel(buffor,i+1,j));
                        int b23 = getb(getpixel(buffor,i+1,j));

                        int r31= getr(getpixel(buffor,i-1,j+1));
                        int g31 = getg(getpixel(buffor,i-1,j+1));
                        int b31 = getb(getpixel(buffor,i-1,j+1));

                        int r32= getr(getpixel(buffor,i,j+1));
                        int g32 = getg(getpixel(buffor,i,j+1));
                        int b32 = getb(getpixel(buffor,i,j+1));

                        int r33= getr(getpixel(buffor,i+1,j+1));
                        int g33 = getg(getpixel(buffor,i+1,j+1));
                        int b33 = getb(getpixel(buffor,i+1,j+1));

                        int sr = r11*maska[0][0]+r12*maska[0][1]+r13*maska[0][2]+
                                 r21*maska[1][0]+r22*maska[1][1]+r23*maska[1][2]+
                                 r31*maska[2][0]+r32*maska[2][1]+r33*maska[2][2];
                        int sg = g11*maska[0][0]+g12*maska[0][1]+g13*maska[0][2]+
                                 g21*maska[1][0]+g22*maska[1][1]+g23*maska[1][2]+
                                 g31*maska[2][0]+g32*maska[2][1]+g33*maska[2][2];
                        int sb = b11*maska[0][0]+b12*maska[0][1]+b13*maska[0][2]+
                                 b21*maska[1][0]+b22*maska[1][1]+b23*maska[1][2]+
                                 b31*maska[2][0]+b32*maska[2][1]+b33*maska[2][2];
                        int sm = maska[0][0]+maska[0][1]+maska[0][2]+
                                 maska[1][0]+maska[1][1]+maska[1][2]+
                                 maska[2][0]+maska[2][1]+maska[2][2];
                        if(sm!=0)
                        {
                            sr = sr/sm;
                            sg = sg/sm;
                            sb = sb/sm;
                            if(sr>255)
                                sr = 255;
                            else if(sr<0)
                                sr = 0;
                            if(sg>255)
                                sg = 255;
                            else if(sg<0)
                                sg = 0;
                            if(sb>255)
                                sb = 255;
                            else if(sb<0)
                                sb = 0;
                        }
                        putpixel(buffor,i,j,makecol(sr,sg,sb));
                    }
                }
            }
        }
    }
}

int main()
{
    allegro_init();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    install_keyboard();

    BITMAP * bmp = load_bitmap("obrazek1.bmp",NULL);

    int tab[800][600];

    for(int i=0; i<bmp->w; i++)
        for(int j=0; j<bmp->w; j++)
            tab[i][j] = 1;

    install_mouse();
    enable_hardware_cursor();
    select_mouse_cursor(MOUSE_CURSOR_ARROW);
    show_mouse(screen);
    BITMAP* buffor = create_bitmap(800,600);
    int czulosc = 5;
    int zakres = 20;

    while(1)
    {
        clear_to_color(buffor,makecol(127,127,127));

        interface(buffor,bmp,czulosc,zakres);

        blit(bmp,buffor,0,0,101,0,bmp->w,bmp->h);

        rysuj_zaznaczenie(buffor,bmp,tab);

        blit(buffor,screen,0,0,0,0,buffor->w,buffor->h);

        negatyw(bmp,tab);

        jasnosc(bmp,tab);

        zmiana_kolorow(bmp,tab);

        rozmycie(bmp,tab);
        zaznacz_kursorem(bmp,tab);
        zaznacz_wszystko(tab);
        zaznacz_rozdzka(bmp,tab,zakres,czulosc);

        if(key[KEY_ESC])
            break;

        rest(50);
    }
    return 0;
}
END_OF_MAIN();
