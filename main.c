#include <allegro.h>
#include <math.h>

DATAFILE* data;
BITMAP *bmp;
BITMAP* islem;

void save();
void olustur();
void ekran();
void ciz();
void boya();
void sekil();
void dosya();
void faredenetim();
void farearac();
void farerenk();
void farearacd();

int lastx = -1, lasty = -1;

void pen(BITMAP *bmp, int lastx, int lasty, int mouse_x, int mouse_y, int ilkrenk){
    int i,j;
    for (i = -1; i < 3; i++)
        for(j = -1; j < 3; j++)
            line(bmp,lastx+i, lasty+j, mouse_x+i,mouse_y+j,ilkrenk);
}

int x,sec,ilkrenk,ikincirenk,gorunturenk;///cerceverenk verme icin

int main()
{
    olustur();
    show_mouse(screen);
    bmp=create_bitmap(1000,600);
    islem=create_bitmap(930,530);
    show_mouse(screen);
    sec=1;
    ekran();
    ilkrenk=makecol(0,0,0);
    ikincirenk=makecol(255,255,255);

    while (!key[KEY_ESC])
    {

        acquire_screen();
        blit(bmp, screen, 0, 0, 0, 0, 1000, 600);
        release_screen();
        rectfill(bmp,0,569,67,600,makecol(255, 255, 255));
        textprintf_centre_ex(bmp, font,35, 575, makecol(0, 0, 0),-1,"X = %d",mouse_x);
        textprintf_centre_ex(bmp, font,35, 588, makecol(0, 0, 0),-1,"Y = %d",mouse_y);
        if((mouse_x>70)&&(mouse_y>70)&&(mouse_y<600))
            faredenetim();
        else if(mouse_x>70&& mouse_y<630)
            farearac();
        else if(mouse_x>5 && mouse_x<60&& mouse_y>360 && mouse_y<562)
            farerenk();
        else if(mouse_x<69&& mouse_y>3)
            farearacd();

    }

    clear_keybuf();
}
END_OF_MAIN();


void save()
{
    blit(bmp,islem,70,70,0,0,930,530);
    save_bitmap("islem.bmp",islem,NULL);
}

void olustur()
{
    int derinlik;
    allegro_init();
    derinlik = desktop_color_depth();
    if (derinlik== 0) derinlik= 32;
    set_color_depth(derinlik);
    set_gfx_mode( GFX_AUTODETECT_WINDOWED,900,600,0,0);
    install_timer();
    install_keyboard();
    install_mouse();
    set_window_title("MUHAMMED ÞARA");

}
void faredenetim()
{
    int x_1,y_1,x_2,y_2,x_3,y_3,R=0;
    x_1=mouse_x;
    y_1=mouse_y;

    if(mouse_b!=1)
    {
        lastx = -1;
        lasty = -1;
    }
    else if (mouse_b==1)
    {
        if(sec==1)/// serbest çizim
        {

           if (lastx != -1 || lasty != -1){
                pen(bmp,lastx, lasty, mouse_x,mouse_y,ilkrenk);
            }
            lastx = mouse_x;
            lasty = mouse_y;
        }

        else if(sec==2)///silgi
            rectfill(bmp,mouse_x,mouse_y,mouse_x+5,mouse_y+5,ikincirenk);
        else if(sec==3)///düz çizgi
        {
            while(1)
            {
                if(mouse_b!=1)
                {
                    x_2=mouse_x;
                    y_2=mouse_y;
                   break;
                }
            }
            line(bmp,x_1,y_1,x_2,y_2,ilkrenk);

        }
        else if(sec==4)  ///dikdörtgen çizme -içi boþ
        {
            while(1)
            {
                if(mouse_b!=1)
                {
                    x_2=mouse_x;
                    y_2=mouse_y;
                    break;
                }
            }
            rect(bmp,x_1,y_1,x_2,y_2,ilkrenk);
        }
        else if(sec==5)///dikdörtgen çizme -içi dolu
        {
            while(1)
            {
                if(mouse_b!=1)
                {
                    x_2=mouse_x;
                    y_2=mouse_y;
                    break;
                }
            }
            rectfill(bmp,x_1,y_1,x_2,y_2,ilkrenk);
        }
        else if(sec==6)  ///üçgen çizme -içi boþ
        {
        while(1)
            {
                if(mouse_b!=1)
                {
                    x_2=mouse_x;
                    y_2=mouse_y;
                    break;
                }
            }

             int b=0;
           b= x_1+((x_2-x_1)/2);
           line(bmp,x_1,y_2,b,y_1,ilkrenk);
                line(bmp,b,y_1,x_2,y_2,ilkrenk);
                line(bmp,x_2,y_2,x_1,y_2,ilkrenk);
        }
        else if(sec==7)///üçgen cizme -içi dolu
        {
            while(1)
            {
                if(mouse_b!=1)
                {
                    x_2=mouse_x;
                    y_2=mouse_y;
                    break;
                }
            }
            int a=0;
           a= x_1+((x_2-x_1)/2);
            triangle(bmp,x_1, y_2,a,y_1, x_2, y_2, ilkrenk);
        }

        else if(sec==8)///  çember cizme-boþ
        {
            while(1)
            {
                if(mouse_b!=1)
                {
                    x_2=mouse_x;
                    y_2=mouse_y;
                    break;
                }
            }
            R=sqrt((pow((x_2-x_1),2)+pow((y_2-y_1),2)));
            circle(bmp,x_1,y_1,R,ilkrenk);
        }
        else if(sec==9)///çember çizme-dolu
        {
            while(1)
            {
                if(mouse_b!=1)
                {
                    x_2=mouse_x;
                    y_2=mouse_y;
                    break;
                }
            }
            R=sqrt((pow((x_2-x_1),2)+pow((y_2-y_1),2)));
            circlefill(bmp,x_1,y_1,R,ilkrenk);
        }
        else if(sec==12)
        {
            floodfill(bmp,mouse_x,mouse_y,ilkrenk);
        }
    }
         ciz();
         boya();
        rectfill(bmp,0,569,67,600,makecol(255, 255, 255));
        textprintf_centre_ex(bmp, font,35, 575, makecol(0, 0, 0),-1,"X = %d",mouse_x);
        textprintf_centre_ex(bmp, font,35, 588, makecol(0, 0, 0),-1,"Y = %d",mouse_y);

}
void farerenk()
{
    if(getpixel(screen,mouse_x,mouse_y)!=gorunturenk)
        if(mouse_b==1)
            ilkrenk=getpixel(screen,mouse_x,mouse_y);
        else if(mouse_b==2)
            ikincirenk=getpixel(screen,mouse_x,mouse_y);
        rectfill(bmp,12,290,40,320,ikincirenk);
        rectfill(bmp,27,305,55,335,ilkrenk);
}

void ekran()
{
    x=makecol(255,255,255);
    clear_to_color(bmp,makecol(250, 211, 155));/// olusan ekranyn arkasyndaki renk
    ciz();
    boya();
    rectfill(bmp,70,70,1000,600,x);///ekran üzerindeki her kýsmý beyaz yapar(ikincibir renk olarak)
}
void boya()
{
    rect(bmp,11,289,39,319,(0,0,0));
    rect(bmp,26,304,54,334,(0,0,0));
    rectfill(bmp,12,290,40,320,ikincirenk);
    rectfill(bmp,27,305,55,335,ilkrenk);

    circlefill(bmp,19,370,11,makecol(255,255,255));
    circlefill(bmp,48,370,11,makecol(1,0,0));

    circlefill(bmp,19,400,11,makecol(0,255,0));
    circlefill(bmp,48,400,11,makecol(255,0,0));

    circlefill(bmp,19,430,11,makecol(240,240,0));
    circlefill(bmp,48,430,11,makecol(255,0,255));

    circlefill(bmp,19,460,11,makecol(0, 255, 255));
    circlefill(bmp,48,460,11,makecol(105,20,123));

    circlefill(bmp,19,490,11,makecol(205,25,160));
    circlefill(bmp,48,490,11,makecol(238,221,130));

    circlefill(bmp,19,520,11,makecol(200,200,200));
    circlefill(bmp,48,520,11,makecol(15,20,123));

    circlefill(bmp,19,550,11,makecol(0, 25, 255));
    circlefill(bmp,48,550,11,makecol(50,205,50));
}
void farearac()
{
    if(mouse_b==1)
    {
        if(mouse_x>70 && mouse_x<139)
            sec=1;
        else if(mouse_x>141 && mouse_x<209)
            sec=2;
        else if(mouse_x>211 && mouse_x<280)
            sec=3;
        else if(mouse_x>281 && mouse_x<350)
            sec=4;
        else if(mouse_x>351 && mouse_x<420)
            sec=5;
        else if(mouse_x>421 && mouse_x<490)
            sec=6;
        else if(mouse_x>491 && mouse_x<560)
            sec=7;
        else if(mouse_x>561 && mouse_x<630)
            sec=8;
        else if(mouse_x>631 && mouse_x<700)
            sec=9;
        else if(mouse_x>701 && mouse_x<770)
            sec=10;
        else if(mouse_x>771 && mouse_x<840)
            sec=11;
        else if(mouse_x>841 && mouse_x<900)
            exit(-1);


    }

}
void farearacd()
{
    if(mouse_b==1)
    {
        if(mouse_y<69 && mouse_y>3)
            save();
        else if(mouse_y<139 && mouse_y>70)
        {
            BITMAP *ac=load_bitmap("islem.bmp",NULL);
            blit(ac,bmp,0,0,70,70,930,530);
        }
        else if(mouse_y<209 && mouse_y>141)
            rectfill(bmp,70,71,1000,600,x);
        else if(mouse_y<280 && mouse_y>212)
            sec=12;
    }
}
void ciz()
{
    rectfill(bmp,0,0,69,570,makecol(250, 211, 155));
    rectfill(bmp,0,0,1000,68,makecol(250, 211, 155));

    hline(bmp,0,70,68,makecol(0,0,0));
    hline(bmp,0,69,1000,makecol(255,255,255));
    hline(bmp,0,68,1000,makecol(0,0,0));

    vline(bmp,68,0,600,makecol(0,0,0));
    vline(bmp,69,0,600,makecol(255,255,255));
    vline(bmp,70,0,68,makecol(0,0,0));

///ust menunun araclarý
    BITMAP *kaydet= load_bitmap( "s.bmp", NULL);
    blit(kaydet,bmp,-15,-15,0,0,1000,600);

    BITMAP *kalem= load_bitmap( "pen.bmp", NULL);
    blit(kalem,bmp,-85,-15,0,0,1000,600);

    BITMAP *sil= load_bitmap( "sil.bmp", NULL);
    blit(sil,bmp,-155,-15,0,0,1000,600);
    vline(bmp,141,0,68,makecol(0,0,0));
    vline(bmp,140,0,68,makecol(255,255,255));
    vline(bmp,139,0,68,makecol(0,0,0));

    BITMAP *ciz= load_bitmap( "line.bmp", NULL);
    blit(ciz,bmp,-225,-15,0,0,1000,600);
    vline(bmp,211,0,68,makecol(0,0,0));
    vline(bmp,210,0,68,makecol(255,255,255));
    vline(bmp,209,0,68,makecol(0,0,0));

    BITMAP *dik= load_bitmap( "dik.bmp", NULL);
    blit(dik,bmp,-295,-15,0,0,1000,600);
    vline(bmp,281,0,68,makecol(0,0,0));
    vline(bmp,280,0,68,makecol(255,255,255));
    vline(bmp,279,0,68,makecol(0,0,0));

    BITMAP *dikk= load_bitmap( "dikk.bmp", NULL);
    blit(dikk,bmp,-365,-15,0,0,1000,600);
    vline(bmp,351,0,68,makecol(0,0,0));
    vline(bmp,350,0,68,makecol(255,255,255));
    vline(bmp,349,0,68,makecol(0,0,0));

    BITMAP *uc= load_bitmap( "uc.bmp", NULL);
    blit(uc,bmp,-435,-15,0,0,1000,600);
    vline(bmp,421,0,68,makecol(0,0,0));
    vline(bmp,420,0,68,makecol(255,255,255));
    vline(bmp,419,0,68,makecol(0,0,0));

    BITMAP *uck =load_bitmap( "uckk.bmp", NULL);
    blit(uck,bmp,-505,-15,0,0,1000,600);
    vline(bmp,491,0,68,makecol(0,0,0));
    vline(bmp,490,0,68,makecol(255,255,255));
    vline(bmp,489,0,68,makecol(0,0,0));

    BITMAP *cem= load_bitmap( "cember.bmp", NULL);
    blit(cem,bmp,-575,-15,0,0,1000,600);
    vline(bmp,561,0,68,makecol(0,0,0));
    vline(bmp,560,0,68,makecol(255,255,255));
    vline(bmp,559,0,68,makecol(0,0,0));

    BITMAP *cemk= load_bitmap( "cemberk.bmp", NULL);
    blit(cemk,bmp,-645,-15,0,0,1000,600);
    vline(bmp,631,0,68,makecol(0,0,0));
    vline(bmp,630,0,68,makecol(255,255,255));
    vline(bmp,629,0,68,makecol(0,0,0));

    vline(bmp,701,0,68,makecol(0,0,0));
    vline(bmp,700,0,68,makecol(255,255,255));
    vline(bmp,699,0,68,makecol(0,0,0));

    textprintf_centre_ex(bmp, font,770, 10, makecol(0, 0, 0),-1,"HAZIRLAYANLAR");

    textprintf_centre_ex(bmp, font,770, 35, makecol(0, 0, 0),-1,"MUHAMMED ÞARA");
    textprintf_centre_ex(bmp, font,770, 50, makecol(0, 0, 0),-1,"M.FURKAN TUFAN");

    vline(bmp,841,0,68,makecol(0,0,0));
    vline(bmp,840,0,68,makecol(255,255,255));
    vline(bmp,839,0,68,makecol(0,0,0));

    BITMAP *cik= load_bitmap( "kapat.bmp", NULL);
    blit(cik,bmp,-853,-15,0,0,1000,600);

    vline(bmp,898,0,68,makecol(0,0,0));
    vline(bmp,899,0,68,makecol(255,255,255));

    /// sol menunu araclarý

    BITMAP *yeni= load_bitmap( "dos.bmp", NULL);
    blit(yeni,bmp,-15,-85,0,0,1000,600);

    BITMAP *dosya= load_bitmap( "yeni.bmp", NULL);
    blit(dosya,bmp,-15,-155,0,0,1000,600);
    hline(bmp,0,139,69,makecol(255,255,255));
    hline(bmp,0,138,67,makecol(0,0,0));
    hline(bmp,0,140,67,makecol(0,0,0));

    BITMAP *kapat= load_bitmap( "boya.bmp", NULL);
    blit(kapat,bmp,-15,-225,0,0,1000,600);
    hline(bmp,0,209,68,makecol(255,255,255));
    hline(bmp,0,210,67,makecol(0,0,0));
    hline(bmp,0,208,67,makecol(0,0,0));

    hline(bmp,0,279,68,makecol(255,255,255));
    hline(bmp,0,280,67,makecol(0,0,0));
    hline(bmp,0,278,67,makecol(0,0,0));

    hline(bmp,0,280,68,makecol(0,0,0));
    hline(bmp,0,279,67,makecol(255,255,255));
    hline(bmp,0,278,67,makecol(0,0,0));

    hline(bmp,0,350,68,makecol(0,0,0));
    hline(bmp,0,349,67,makecol(255,255,255));
    hline(bmp,0,348,67,makecol(0,0,0));

    int i;
    for(i=0; i<218; i++)
        hline(bmp,0,351+i,67,makecol(103,109,118));
    int a;
    for(a=0; a<80; a++)
        hline(bmp,0,569+a,67,makecol(100,0,100));
}
