#include "zmiana.kolorow.hpp"
void zmiana_kolorow(BITMAP *buffor,int tab[800][600])
{
    if(mouse_b&1&&(mouse_x>80&&mouse_x<100&&mouse_y>350&&mouse_y<375)) // RGB
    {
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                if(tab[i][j] == 1)
                {
                    int r = getr(getpixel(buffor,i,j));
                    int g = getg(getpixel(buffor,i,j));
                    int b = getb(getpixel(buffor,i,j));
                    putpixel(buffor,i,j,makecol(r,g,b));
                }
            }
        }
    }
    if(mouse_b&1&&(mouse_x>80&&mouse_x<100&&mouse_y>375&&mouse_y<400)) // RBG
    {
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                if(tab[i][j] == 1)
                {
                    int r = getr(getpixel(buffor,i,j));
                    int g = getg(getpixel(buffor,i,j));
                    int b = getb(getpixel(buffor,i,j));
                    putpixel(buffor,i,j,makecol(r,b,g));
                }
            }
        }
    }
    if(mouse_b&1&&(mouse_x>80&&mouse_x<100&&mouse_y>400&&mouse_y<425)) //GRB
    {
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                if(tab[i][j] == 1)
                {
                    int r = getr(getpixel(buffor,i,j));
                    int g = getg(getpixel(buffor,i,j));
                    int b = getb(getpixel(buffor,i,j));
                    putpixel(buffor,i,j,makecol(g,r,b));
                }
            }
        }
    }
    if(mouse_b&1&&(mouse_x>80&&mouse_x<100&&mouse_y>425&&mouse_y<450)) // GBR
    {
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                if(tab[i][j] == 1)
                {
                    int r = getr(getpixel(buffor,i,j));
                    int g = getg(getpixel(buffor,i,j));
                    int b = getb(getpixel(buffor,i,j));
                    putpixel(buffor,i,j,makecol(g,b,r));
                }
            }
        }
    }
    if(mouse_b&1&&(mouse_x>80&&mouse_x<100&&mouse_y>450&&mouse_y<475)) // BRG
    {
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                if(tab[i][j] == 1)
                {
                    int r = getr(getpixel(buffor,i,j));
                    int g = getg(getpixel(buffor,i,j));
                    int b = getb(getpixel(buffor,i,j));
                    putpixel(buffor,i,j,makecol(b,r,g));
                }
            }
        }
    }
    if(mouse_b&1&&(mouse_x>80&&mouse_x<100&&mouse_y>475&&mouse_y<500)) // BGR
    {
        for(int i=0; i<800; i++)
        {
            for(int j=0; j<600; j++)
            {
                if(tab[i][j] == 1)
                {
                    int r = getr(getpixel(buffor,i,j));
                    int g = getg(getpixel(buffor,i,j));
                    int b = getb(getpixel(buffor,i,j));
                    putpixel(buffor,i,j,makecol(b,g,r));
                }
            }
        }
    }
}

