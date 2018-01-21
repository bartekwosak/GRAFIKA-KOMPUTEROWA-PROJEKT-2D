#include "jasnosc.hpp"

void jasnosc(BITMAP* buffor, int tab[800][600])
{
    if(mouse_b&1&&(mouse_x>0&&mouse_x<100&&mouse_y>250&&mouse_y<275))
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
                    if(mouse_x>0&&mouse_x<33)
                        r+=5;
                    if(mouse_x>34&&mouse_x<66)
                        g+=5;
                    if(mouse_x>67&&mouse_x<100)
                        b+=5;
                    if(r>255)
                        r = 255;
                    if(g>255)
                        g = 255;
                    if(b>255)
                        b = 255;
                    putpixel(buffor,i,j,makecol(r,g,b));
                }
            }
        }
    }
    if(mouse_b&1&&(mouse_x>0&&mouse_x<100&&mouse_y>275&&mouse_y<300))
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
                    if(mouse_x>0&&mouse_x<33)
                        r-=5;
                    if(mouse_x>34&&mouse_x<66)
                        g-=5;
                    if(mouse_x>67&&mouse_x<100)
                        b-=5;
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
