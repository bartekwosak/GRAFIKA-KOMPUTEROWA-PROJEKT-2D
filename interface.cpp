#include "interface.hpp"
#include <iostream>
#include <exception>
using namespace std;

void wczytaj(BITMAP *bmp)
{

    if(mouse_b&1&&(mouse_x>0&&mouse_x<32&&mouse_y>25&&mouse_y<50))
    {
        BITMAP* tmp = load_bitmap("obrazek1.bmp",NULL);
        cout<<"Wczytano obrazek1.bmp"<<endl;
        blit(tmp,bmp,0,0,0,0,bmp->w,bmp->h);
    }
    if(mouse_b&1&&(mouse_x>34&&mouse_x<64&&mouse_y>25&&mouse_y<50))
    {
        BITMAP* tmp = load_bitmap("obrazek2.bmp",NULL);
        cout<<"Wczytano obrazek2.bmp"<<endl;
        blit(tmp,bmp,0,0,0,0,bmp->w,bmp->h);
    }
    if(mouse_b&1&&(mouse_x>64&&mouse_x<100&&mouse_y>25&&mouse_y<50))
    {
        try
        {
            char name[20];
            cout<<"Podaj sciezke do pliku: "<<endl;
            cin>>name;
            if(strlen(name)==0)
            {
                BITMAP* tmp = load_bitmap("obrazek1.bmp",NULL);
                blit(tmp,bmp,0,0,0,0,bmp->w,bmp->h);
                cin.clear();
                cin.sync();
            }
            else
            {
                BITMAP* tmp = load_bitmap(name,NULL);
                cout<<"Wczytano"<<endl;
                blit(tmp,bmp,0,0,0,0,bmp->w,bmp->h);
                cin.clear();
                cin.sync();
            }
        }
        catch(exception& e)
        {
            cout<<"Podano niewlasciwa sciezke!"<<endl;
        }

    }
}

void zapisz(BITMAP *bmp)
{

    if(mouse_b&1&&(mouse_x>0&&mouse_x<100&&mouse_y>52&&mouse_y<75))
    {
        save_bitmap("obrazek_po.bmp",bmp,NULL);
        cout<<"Zapisano obraz"<<endl;
    }

}

void zaznacz_kursorem(BITMAP *bmp,int tab[800][600])
{

    if(mouse_b&1&&(mouse_x>0&&mouse_x<50&&mouse_y>77&&mouse_y<100))
    {
        cout<<"start"<<endl;
        int px = 0;
        int py = 0;
        int kx = 0;
        int ky = 0;
        select_mouse_cursor(MOUSE_CURSOR_ALLEGRO);
        show_mouse(screen);

        while(px==0)
        {
            cout<<mouse_x<<"+"<<mouse_y<<endl;
            if(mouse_b&2)
            {
                px = mouse_x-100;
                py = mouse_y;
            }
        }
        while(kx==0)
        {
            if(mouse_b&1)
            {
                kx = mouse_x-100;
                ky = mouse_y;
            }
        }
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                tab[i][j] = 0;
            }
        }
        for(int i=px; i<kx; i++)
        {
            for(int j=py; j<ky; j++)
            {
                tab[i][j] = 1;
            }
        }
    }
}

void zaznacz_rozdzka(BITMAP *buffor,int tab[800][600],int zakres, int czulosc)
{
    if(mouse_b&1&&(mouse_x>0&&mouse_x<100&&mouse_y>100&&mouse_y<133))
    {

        int px = 0;
        int py = 0;
        int kx = 0;
        int ky = 0;
        while(px == 0)
        {
            if(mouse_b&2)
            {
                px = mouse_x-100;
                py = mouse_y;
            }
        }

        px = px - zakres;
        py = py - zakres;
        kx = px + zakres + zakres;
        ky = py + zakres + zakres;

        if(px  < 0 )
            px = 0;
        if(kx > 800 )
            kx = 800;
        if(py < 0 )
            py =  0;
        if(ky > 600 )
            ky =  600;

        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                tab[i][j] = 0;
            }
        }
        int rm = getr(getpixel(buffor,mouse_x-100,mouse_y));
        int gm = getg(getpixel(buffor,mouse_x-100,mouse_y));
        int bm = getb(getpixel(buffor,mouse_x-100,mouse_y));

        for(int i=px; i<kx; i++)
        {
            cout<<px<<"+"<<kx<<endl;
            for(int j=py; j<ky; j++)
            {
                int r = getr(getpixel(buffor,i,j));
                int g = getg(getpixel(buffor,i,j));
                int b = getb(getpixel(buffor,i,j));
                if(abs(rm-r)<czulosc)
                    tab[i][j] = 1;
                if(abs(gm-g)<czulosc)
                    tab[i][j] = 1;
                if(abs(bm-b)<czulosc)
                    tab[i][j] = 1;
            }
        }
    }
}

void zaznacz_wszystko(int tab[800][600])
{
    if(mouse_b&1&&(mouse_x>52&&mouse_x<100&&mouse_y>77&&mouse_y<100))
        for(int i=0; i<800; i++)
            for(int j=0; j<600; j++)
                tab[i][j] = 1;
}

void rysuj_zaznaczenie(BITMAP *buffor,BITMAP *bmp,int tab[800][600])
{
    for(int i=0; i<800; i++)
    {
        for(int j=0; j<600; j++)
        {
            if(i-1>0    &&  i+1<800    &&  j-1>0 &&   j+1<600)
            {
                if((tab[i-1][j-1] == 1 || tab[i][j-1] == 1 || tab[i+1][j-1] == 1 ||
                        tab[i-1][j] == 1  || tab[i+1][j] == 1 ||
                        tab[i-1][j+1] == 1 || tab[i][j+1] == 1 || tab[i+1][j+1] == 1 )&& tab[i][j] == 0)
                {
                    putpixel(buffor,i+100,j,makecol(255,0,0));
                }
            }
        }
    }
}

void zmiana_czulosci(int &czulosc)
{
    if(mouse_b&1&&(mouse_x>0&&mouse_x<50&&mouse_y>140&&mouse_y<170))
        czulosc++;
    if(mouse_b&1&&(mouse_x>50&&mouse_x<100&&mouse_y>140&&mouse_y<170))
        czulosc--;
}

void zmiana_zakresu(int &zakres)
{
    if(mouse_b&1&&(mouse_x>0&&mouse_x<50&&mouse_y>170&&mouse_y<200))
        zakres++;
    if(mouse_b&1&&(mouse_x>50&&mouse_x<100&&mouse_y>170&&mouse_y<200))
        zakres--;
}

void interface(BITMAP *buffor,BITMAP* bmp,int &czulosc,int &zakres)
{
    rectfill(buffor,0,0,100,SCREEN_H,makecol(30,30,30));


    //*********************************
    rectfill(buffor,0,1,100,25,makecol(200,200,200));
    rectfill(buffor,0,27,32,50,makecol(150,150,150));
    rectfill(buffor,34,27,62,50,makecol(150,150,150));
    rectfill(buffor,64,27,100,50,makecol(150,150,150));
    textprintf_centre_ex(buffor, font, 50, 12, makecol(0, 0, 0), -1, "Wczytaj");
    textprintf_centre_ex(buffor, font, 20, 35, makecol(0, 0, 0), -1, "1");
    textprintf_centre_ex(buffor, font, 50, 35, makecol(0, 0, 0), -1, "2");
    textprintf_centre_ex(buffor, font, 80, 35, makecol(0, 0, 0), -1, "PLIK");
    wczytaj(bmp);

    rectfill(buffor,0,52,100,75,makecol(200,200,200));
    textprintf_centre_ex(buffor, font, 50, 63, makecol(0, 0, 0), -1, "Zapisz");
    zapisz(bmp);

    rectfill(buffor,0,77,50,100,makecol(200,200,200));                          //zaznaczanie myszka
    rect(buffor,15,80,35,97,makecol(0,0,0));


    rectfill(buffor,52,77,100,100,makecol(200,200,200));
    textprintf_centre_ex(buffor, font, 77, 85, makecol(0, 0, 0), -1, "A");      // zaznaczanie wszystkiego

    rectfill(buffor,0,102,100,198,makecol(200,200,200));
    textprintf_centre_ex(buffor, font, 50, 105, makecol(0, 0, 0), -1, "ROZDZKA");
    line(buffor,54,120,44,130,makecol(0,0,0));
    circlefill(buffor,54,120,3,makecol(255,255,0));

    textprintf_centre_ex(buffor, font, 50, 135, makecol(0, 0, 0), -1,"Czulosc: %d",czulosc);
    textprintf_centre_ex(buffor, font, 20, 155, makecol(0, 0, 0), -1, "+");
    textprintf_centre_ex(buffor, font, 80, 155, makecol(0, 0, 0), -1, "-");
    zmiana_czulosci(czulosc);

    textprintf_centre_ex(buffor, font, 50, 170, makecol(0, 0, 0), -1,"Zakres: %d",zakres);
    textprintf_centre_ex(buffor, font, 20, 185, makecol(0, 0, 0), -1, "+");
    textprintf_centre_ex(buffor, font, 80, 185, makecol(0, 0, 0), -1, "-");
    zmiana_zakresu(zakres);


    rectfill(buffor,0,200,100,225,makecol(200,200,200));
    textprintf_centre_ex(buffor, font, 50, 210, makecol(0, 0, 0), -1, "Jasnosc");

    rectfill(buffor,0,226,33,250,makecol(255,0,0));
    textprintf_centre_ex(buffor, font, 17, 235, makecol(0, 0, 0), -1, "R");

    rectfill(buffor,34,226,67,250,makecol(0,255,0));
    textprintf_centre_ex(buffor, font, 51, 235, makecol(0, 0, 0), -1, "G");

    rectfill(buffor,67,226,100,250,makecol(0,0,255));
    textprintf_centre_ex(buffor, font, 84, 235, makecol(0, 0, 0), -1, "B");

    rectfill(buffor,0,250,100,300,makecol(100,100,100));
    textprintf_centre_ex(buffor, font, 13, 260, makecol(0, 0, 0), -1, "+");
    textprintf_centre_ex(buffor, font, 50, 260, makecol(0, 0, 0), -1, "+");
    textprintf_centre_ex(buffor, font, 84, 260, makecol(0, 0, 0), -1, "+");

    textprintf_centre_ex(buffor, font, 13, 283, makecol(0, 0, 0), -1, "-");
    textprintf_centre_ex(buffor, font, 50, 283, makecol(0, 0, 0), -1, "-");
    textprintf_centre_ex(buffor, font, 84, 283, makecol(0, 0, 0), -1, "-");
    //*********************************
    rectfill(buffor,0,300,100,350,makecol(200,200,200));
    textprintf_centre_ex(buffor, font, 50, 325, makecol(0, 0, 0), -1, "Negatyw");
    rectfill(buffor,0,352,80,500,makecol(200,200,200));
    rectfill(buffor,82,352,100,500,makecol(100,100,100));

    textprintf_centre_ex(buffor, font, 40, 360, makecol(0, 0, 0), -1, "R - G - B");
    circlefill(buffor,90,363,3,makecol(20,20,20));
    circlefill(buffor,90,363,1,makecol(250,250,250));
    textprintf_centre_ex(buffor, font, 40, 385, makecol(0, 0, 0), -1, "R - B - G");
    circlefill(buffor,90,388,3,makecol(20,20,20));
    circlefill(buffor,90,388,1,makecol(250,250,250));
    textprintf_centre_ex(buffor, font, 40, 410, makecol(0, 0, 0), -1, "G - R - B");
    circlefill(buffor,90,413,3,makecol(20,20,20));
    circlefill(buffor,90,413,1,makecol(250,250,250));
    textprintf_centre_ex(buffor, font, 40, 435, makecol(0, 0, 0), -1, "G - B - R");
    circlefill(buffor,90,438,3,makecol(20,20,20));
    circlefill(buffor,90,438,1,makecol(250,250,250));
    textprintf_centre_ex(buffor, font, 40, 460, makecol(0, 0, 0), -1, "B - R - G");
    circlefill(buffor,90,463,3,makecol(20,20,20));
    circlefill(buffor,90,463,1,makecol(250,250,250));
    textprintf_centre_ex(buffor, font, 40, 485, makecol(0, 0, 0), -1, "B - G - R");
    circlefill(buffor,90,488,3,makecol(20,20,20));
    circlefill(buffor,90,488,1,makecol(250,250,250));
    //*********************************
}
