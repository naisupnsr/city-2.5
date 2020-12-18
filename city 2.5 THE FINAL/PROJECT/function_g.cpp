#include <iostream>
#include <fstream>
#include <windows.h>
#include <graphics.h>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "player_s.h"
#include "player.h"
#include "LL.h"
#define textcolor(txt,back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

using namespace std;
int tree1 = 600;
int tree2 = 1000;
int wintur = 1500;
int bush = 500;
int purif1 = 2000;
int purif2 = 4000;
int highpre = 200;

int player_total_money;
int player_total_pm;
int player_total_score;
int mode;
int e_score;
int episode=1;

void gotoxy(int x, int y)

{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void new_game()
{
    system("cls");
    textcolor(5,0);
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t***   ***   *********   ***  ***  ***   *********   *********   *************   ********"<<endl;
    resetcolor();
    textcolor(1,0);
    cout<<"\t\t\t\t\t\t\t****  ***   ***         ***  ***  ***   ***         ***   ***   ***  ***  ***   ***     "<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"\t\t\t\t\t\t\t*** * ***   *********   ***  ***  ***   *** *****   *********   ***  ***  ***   ********"<<endl;
    resetcolor();
    textcolor(2,0);
    cout<<"\t\t\t\t\t\t\t***  ****   ***         ***  ***  ***   ***   ***   ***   ***   ***  ***  ***   ***     "<<endl;
    resetcolor();
    textcolor(6,0);
    cout<<"\t\t\t\t\t\t\t***   ***   *********   *************   *********   ***   ***   ***  ***  ***   ********"<<endl;
    resetcolor();

}
void loadbar()
{
    textcolor(8,0);
    cout<<endl<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t  Loading...\n\n";
    char a=177, b=219;
    cout<<"\t\t\t\t\t\t\t\t\t\t  ";
    for (int i=0; i<=15; i++)
        cout<<a;
    cout<<"\r";
    cout<<"\t\t\t\t\t\t\t\t\t\t  ";
    for (int i=0; i<=15; i++)
    {
        cout<<b;
        for (int j=0; j<=1e8; j++);
    }
    resetcolor();

}

int return_money()
{
    return player_total_money;
}
int return_pm()
{
    return player_total_pm;
}
int return_score()
{
    return player_total_score;
}

void next_ep()
{
    readimagefile("next.jpg",0,0,1530,370);

    textcolor(0,2);
    cout<<endl<<"     Notification >> This episode is end. Press any key to play next episode. ";
    resetcolor();
    cout<<endl;
    system("pause");
}
void cin_fail()
{
    readimagefile("17.jpg",0,0,1530,370);
    Sleep(1000);
    textcolor(15,4);
    cout<<endl<<"     **Announce >> Please choose 1-7 ";
    resetcolor();
    cout<<endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}
void choose_tree1(int money,int pm,int score)
{
    readimagefile("t1.jpg",0,0,1530,370);
    Sleep(1000);
    if(money>0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : "<<money<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl;
    }
    else if(money<=0)
    {
        score=pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : 0"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money to buy item."<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<score;
        resetcolor();
        cout<<endl;
        episode++;
        next_ep();
    }
}
void choose_tree2(int money,int pm,int score)
{
    readimagefile("t2.jpg",0,0,1530,370);
    Sleep(1000);
    if(money>0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : "<<money<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl;
    }
    else if(money<=0)
    {
        score=pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : 0"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money to buy item."<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<score;
        resetcolor();
        cout<<endl;
        episode++;
        next_ep();
    }
}
void choose_wintur(int money,int pm,int score)
{
    readimagefile("wt.jpg",0,0,1530,370);
    Sleep(1000);
    if(money>0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : "<<money<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl;
    }
    else if(money<=0)
    {
        score=pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : 0"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money to buy item."<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<"is complete!"<<endl;
        textcolor(32,0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<score;
        resetcolor();
        cout<<endl;
        episode++;
        next_ep();
    }
}
void choose_bush(int money,int pm,int score)
{
    readimagefile("bush.jpg",0,0,1530,370);
    Sleep(1000);
    if(money>0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : "<<money<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl;
    }
    else if(money<=0)
    {
        score=pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : 0"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money to buy item."<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        episode++;
        textcolor(32,0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<score;
        resetcolor();
        cout<<endl;
        next_ep();
    }
}
void choose_purif1(int money,int pm,int score)
{
    readimagefile("p1.jpg",0,0,1530,370);
    Sleep(1000);
    if(money>0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : "<<money<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl;
    }
    else if(money<=0)
    {
        score=pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : 0"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money to buy item."<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<score;
        resetcolor();
        cout<<endl;
        episode++;
        next_ep();
    }
}
void choose_purif2(int money,int pm,int score)
{
    readimagefile("p2.jpg",0,0,1530,370);
    Sleep(1000);
    if(money>0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : "<<money<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl;
    }
    else if(money<=0)
    {
        score=pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : 0"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money to buy item."<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<score;
        resetcolor();
        cout<<endl;
        episode++;
        next_ep();
    }
}
void choose_highpre(int money,int pm,int score)
{
    readimagefile("hp.jpg",0,0,1530,370);
    Sleep(1000);
    if(money>0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : "<<money<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl;
    }
    else if(money<=0)
    {
        score=pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tpm was reduced : "<<pm<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tmoney balance : 0"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money to buy item."<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<score;
        episode++;
        resetcolor();
        cout<<endl;
        next_ep();
    }
}

void announce_enought_money()
{
    readimagefile("en.jpg",0,0,1530,370);
    Sleep(1000);
    textcolor(15,4);
    cout<<endl<<"     **Announce >> You do not have enough money. Please choose another one.";
    resetcolor();
    cout<<endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

void project_name()
{
    system("mode 213,25");
    initwindow(1530,370,"City 2.5",0,0,false,false);
    readimagefile("menu.jpg",0,0,1530,370);
    cout<<endl<<endl<<endl;
    textcolor(5,0);
    cout<<"\t\t\t\t\t\t\tCCCCCCCCCC  IIIIIIIIII  TTTTTTTTTT  YYYY    YYYY         2222222222        5555555555"<<endl;
    resetcolor();
    textcolor(1,0);
    cout<<"\t\t\t\t\t\t\tCCCCCCCCCC  IIIIIIIIII  TTTTTTTTTT  YYYY    YYYY         2222222222        5555555555"<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"\t\t\t\t\t\t\tCCCC           IIII        TTTT     YYYYYYYYYYYY               2222        5555      "<<endl;
    resetcolor();
    textcolor(2,0);
    cout<<"\t\t\t\t\t\t\tCCCC           IIII        TTTT     YYYYYYYYYYYY         2222222222        5555555555"<<endl;
    resetcolor();
    textcolor(6,0);
    cout<<"\t\t\t\t\t\t\tCCCC           IIII        TTTT         YYYY             2222222222        5555555555"<<endl;
    resetcolor();
    textcolor(12,0);
    cout<<"\t\t\t\t\t\t\tCCCC           IIII        TTTT         YYYY             2222                    5555"<<endl;
    resetcolor();
    textcolor(4,0);
    cout<<"\t\t\t\t\t\t\tCCCCCCCCCC     IIII        TTTT         YYYY             2222222222  OOOO  5555555555"<<endl;
    resetcolor();
    textcolor(8,0);
    cout<<"\t\t\t\t\t\t\tCCCCCCCCCC     IIII        TTTT         YYYY             2222222222  OOOO  5555555555"<<endl;
    resetcolor();
}
void menu()
{
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\tMENU"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t   [1] NEW GAME"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t   [2] RANK"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t   [3] HISTORY"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t   [0] EXIT_GAME"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t       Please choose mode : ";
}
void item()
{

    cout<<"\t\t\t\t\t\t\t\t\t       ITEM                          PRICE(Baht)      REDUCED PM 2.5"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [1] A small tree                       600                  10"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [2] A big tree                       1,000                  15"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [3] A wind turbine                   1,500                  24"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [4] A bush                             500                   7"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [5] A small air purifier             2,000                  30"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [6] A big air purifier               4,000                  45"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [7] A high pressure cleaner            200                   2"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [0]  Press  0 if you want to finish this episode"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t [99] Press 99 if you want to go to MENU"<<endl;
}
void rank_score()
{
    readimagefile("rank.jpg",0,0,1530,370);
    textcolor(5,0);
    cout<<"\t\t\t\t\t\t\t********* ********* ****  *** ***   *** "<<endl;
    resetcolor();
    textcolor(1,0);
    cout<<"\t\t\t\t\t\t\t***   *** ***   *** ***** *** ***  ***  "<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"\t\t\t\t\t\t\t********* ********* *** ***** *******   "<<endl;
    resetcolor();
    textcolor(2,0);
    cout<<"\t\t\t\t\t\t\t*** ***   ***   *** ***  **** ***  ***  "<<endl;
    resetcolor();
    textcolor(6,0);
    cout<<"\t\t\t\t\t\t\t***  **** ***   *** ***   *** ***   *** "<<endl;
    resetcolor();
}
void next_ep10_rank()
{
    readimagefile("total.jpg",0,0,1530,370);
    textcolor(0,2);
    cout<<endl<<"     Notification >> This episode is end. Press any key to see a total score. ";
    resetcolor();
    cout<<endl;
    system("cls");
    textcolor(0,6);
    cout<<endl<<endl<<endl<<endl<<endl<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tTOTAL SCORE : "<<player_total_score;
    resetcolor();
    cout<<endl;
    system("cls");
    //Sleep(1000);
}
int game_10()
{
    readimagefile("10.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 10"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 8,000 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition 1 : You can buy 'a wind turbine' only once. "<<endl<<endl;
    resetcolor();
    textcolor(6,0);
    cout<<"   Condition 2 : You can buy 'a small air purifier' only once. "<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition 3 : You can buy 'a big air purifier' only once. "<<endl<<endl;
    resetcolor();
    item();

    int count_con=0;
    int count_con2=0;
    int count_con3=0;
    int money=8000;
    int count_buy=0;
    int pm=0;
    int x=0;
    int en_money=0;
    en_money=money;


    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);

            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        if(count_con==0)
                        {
                            money=money-wintur;
                            pm=pm+24;
                            choose_wintur(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a wind turbine' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        if(count_con2==0)
                        {
                            money=money-purif1;
                            pm=pm+30;
                            choose_purif1(money,pm,e_score);
                            count_con2++;
                        }
                        else if(count_con2>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a small air purifier' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        if(count_con3==0)
                        {
                            money=money-purif2;
                            pm=pm+45;
                            choose_purif2(money,pm,e_score);
                            count_con3++;
                        }
                        else if(count_con3>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a big air purifier' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
                        episode++;
                        /*player_total_money+=money;
                        player_total_pm+=pm;
                        e_score=(money*2/100)+pm;
                        player_total_score+=e_score;*/
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        Sleep(1000);
                        next_ep10_rank();
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=((money*0.5)/100)+pm;
                }
            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        player_total_pm = player_total_pm + pm;
        player_total_score=player_total_score+e_score;
    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep10_rank();

    }
}
int game_9()
{
    readimagefile("9.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 9"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 8,000 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition 1 : You can buy 'a big air purifier' only once. "<<endl<<endl;
    resetcolor();
    textcolor(6,0);
    cout<<"   Condition 2 : You can buy 'a small air purifier' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int count_con2=0;
    int x=0;
    int money=10000;
    int count_buy=0;
    int pm=0;
    int en_money=0;
    en_money=money;

    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        money=money-wintur;
                        pm=pm+24;
                        choose_wintur(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        if(count_con2==0)
                        {
                            money=money-purif1;
                            pm=pm+30;
                            choose_purif1(money,pm,e_score);
                            count_con2++;
                        }
                        else if(count_con2>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a small air purifier' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        if(count_con==0)
                        {
                            money=money-purif2;
                            pm=pm+45;
                            choose_purif2(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a big air purifier' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode"<<episode<<" is complete!"<<endl;
                        episode++;
                        /*player_total_money+=money;
                        player_total_pm+=pm;
                        e_score=(money*2/100)+pm;
                        player_total_score+=e_score;*/
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=((money*0.5)/100)+pm;

                }
            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        player_total_pm = player_total_pm + pm;

        player_total_score=player_total_score+e_score;
    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tTotal score : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}
int game_8()
{
    readimagefile("8.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 8"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 8,500 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition : You can buy 'a small air purifier' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int x=0;
    int money=8500;
    int count_buy=0;
    int pm=0;
    int en_money=0;
    en_money=money;

    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        money=money-wintur;
                        pm=pm+24;
                        choose_wintur(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        if(count_con==0)
                        {
                            choose_purif1(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a small air purifier' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        money=money-purif2;
                        pm=pm+45;
                        choose_purif2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
                        episode++;
                        /*player_total_money+=money;
                        player_total_pm+=pm;
                        e_score=(money*2/100)+pm;
                        player_total_score+=e_score;*/
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tscore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=((money*0.5)/100)+pm;

                }
            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        player_total_pm = player_total_pm + pm;
        player_total_score=player_total_score+e_score;
    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tTotal score : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}
int game_7()
{
    readimagefile("7.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 7"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 9,000 baht."<<endl<<endl;
    resetcolor();
    cout<<"   Condition : You can buy 'a wind turbine' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int money=9000;
    int count_buy=0;
    int pm=0;
    int x=0;
    int en_money=0;
    en_money=money;


    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        if(count_con==0)
                        {
                            money=money-wintur;
                            pm=pm+24;
                            choose_wintur(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a wind turbine' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        choose_purif1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        money=money-purif2;
                        pm=pm+45;
                        choose_purif2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
                        episode++;
                        /*player_total_money+=money;
                        player_total_pm+=pm;
                        e_score=((money*2)/100)+pm;
                        player_total_score+=e_score;*/
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=((money*0.5)/100)+pm;
                }
            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        player_total_pm = player_total_pm + pm;

        player_total_score=player_total_score+e_score;
    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tTotal score : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}
int game_6()
{
    readimagefile("6.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 6"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 9,500 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition : You can buy 'a big tree' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int money=9500;
    int count_buy=0;
    int pm=0;
    int x=0;
    int en_money=0;
    en_money=money;


    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        if(count_con==0)
                        {
                            money=money-tree2;
                            pm=pm+15;
                            choose_tree2(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a big tree' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        money=money-wintur;
                        pm=pm+24;
                        choose_wintur(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        choose_purif1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        money=money-purif2;
                        pm=pm+45;
                        choose_purif2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
                        episode++;
                        /*player_total_money+=money;
                        player_total_pm+=pm;
                        e_score=((money*2)/100)+pm;
                        player_total_score+=e_score;*/
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=((money*0.5)/100)+pm;

                }
            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        player_total_pm = player_total_pm + pm;
        player_total_score=player_total_score+e_score;
    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou don't have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}
int game_5()
{
    readimagefile("5.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 5"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 10,000 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition : You can buy 'a big air purifier' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int money=10000;
    int count_buy=0;
    int pm=0;
    int x=0;
    int en_money=0;
    en_money=money;

    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        money=money-wintur;
                        pm=pm+24;
                        choose_wintur(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        choose_purif1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        if(count_con==0)
                        {
                            money=money-purif2;
                            pm=pm+45;
                            choose_purif2(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a big air purifier' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode  "<<episode<<" is complete!"<<endl;
                        episode++;
                        /*player_total_money+=money;
                        player_total_pm+=pm;
                        e_score=(money*2/100)+pm;
                        player_total_score+=e_score;*/
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=((money*0.5)/100)+pm;
                }
                else if(cin.fail())
                {
                    cin_fail();
                }
            }
        }
        player_total_money= player_total_money + money;
        player_total_pm = player_total_pm + pm;

        player_total_score=player_total_score+e_score;
    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tTotal score : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}
int game_4()
{
    readimagefile("4.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 4"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 10,000 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition : You can buy 'a small air purifier' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int money=10000;
    int count_buy=0;
    int pm=0;
    int x=0;
    int en_money=0;
    en_money=money;

    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        money=money-wintur;
                        pm=pm+24;
                        choose_wintur(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        ;
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        if(count_con==0)
                        {
                            money=money-purif1;
                            pm=pm+30;
                            choose_purif1(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a small air purifier' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                        break;
                    case 6 :
                        if(en_money>=purif2)
                        {
                            money=money-purif2;
                            pm=pm+45;
                            choose_purif2(money,pm,e_score);
                            count_buy++;
                        }
                        else if(en_money<purif2)
                        {
                            announce_enought_money();
                        }
                        break;
                    case 7 :
                        if(en_money>=highpre)
                        {
                            money=money-highpre;
                            pm=pm+2;
                            choose_highpre(money,pm,e_score);
                            count_buy++;
                        }
                        else if(en_money<highpre)
                        {
                            announce_enought_money();
                        }
                        break;
                    case 0 :
                        if(count_buy==0)
                        {
                            readimagefile("b1.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        else if(count_buy>=1)
                        {
                            x=1;
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode"<<episode<<" is complete!"<<endl;
                            episode++;
                            /*player_total_money+=money;
                            player_total_pm+=pm;
                            e_score=(money*2/100)+pm;
                            player_total_score+=e_score;*/
                            textcolor(32,0);
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                            resetcolor();
                            cout<<endl;
                            next_ep();
                        }
                        break;
                    case 99 :

                        loadbar();
                        closegraph();
                        x=1;
                        return 99;
                        break;
                    default :
                        cin_fail();
                    }
                    if(money>=0)
                    {
                        en_money=money;
                        e_score=((money*0.5)/100)+pm;
                    }

                }
            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        //cout<<"total :"<<player_total_pm<<"pm :"<<pm<<endl;
        player_total_pm = player_total_pm + pm;

        player_total_score=player_total_score+e_score;

    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tTotal score : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}
int game_3()
{
    readimagefile("3.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 3"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 10,000 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition : You can buy 'a wind turbine' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int money=10000;
    int count_buy=0;
    int pm=0;
    int x=0;
    int en_money=0;
    en_money=money;


    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        if(count_con==0)
                        {
                            money=money-wintur;
                            pm=pm+24;
                            choose_wintur(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a wind turbine' only once!";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        choose_purif1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        money=money-purif2;
                        pm=pm+45;
                        choose_purif2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
                        episode++;
                        /*player_total_money+=money;
                        player_total_pm+=pm;
                        e_score=(money*0.5/100)+pm;
                        player_total_score+=e_score;*/
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();
                        x=1;
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=((money*0.5)/100)+pm;
                }
            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        player_total_pm = player_total_pm + pm;

        player_total_score=player_total_score+e_score;
    }

    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tTotal score : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}
int game_2()
{
    readimagefile("2.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 2"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 10,000 baht."<<endl<<endl;
    resetcolor();
    textcolor(3,0);
    cout<<"   Condition : You can buy 'a big tree' only once. "<<endl<<endl;
    resetcolor();
    item();
    int count_con=0;
    int money=10000;
    int count_buy=0;
    int pm=0;
    int en_money=0;
    en_money=money;
    int x=0;


    if(money>0)
    {
        while(money>0 && x==0)
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        if(count_con==0)
                        {
                            money=money-tree2;
                            pm=pm+15;
                            choose_tree2(money,pm,e_score);
                            count_con++;
                        }
                        else if(count_con>=1)
                        {
                            readimagefile("once.jpg",0,0,1530,370);
                            Sleep(1000);
                            textcolor(15,4);
                            cout<<endl<<"     **Announce >> You can buy 'a big tree' only once! ";
                            resetcolor();
                            cout<<endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        money=money-wintur;
                        pm=pm+24;
                        choose_wintur(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        choose_purif1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        money=money-purif2;
                        pm=pm+45;
                        choose_purif2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
                        episode++;
                        //player_total_money=player_total_money+money;
                        //player_total_pm=player_total_pm+pm;
                        // e_score=(money*2/100)+pm;
                        // player_total_score=player_total_score+e_score;
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();
                    }
                    break;
                case 99 :

                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {

                    en_money=money;
                    e_score=(money*0.5/100)+pm;

                }

            }
            else if(cin.fail())
            {
                cin_fail();
            }
        }
        player_total_money= player_total_money + money;
        //cout<<"total :"<<player_total_pm<<"pm :"<<pm<<endl;
        player_total_pm = player_total_pm + pm;
        e_score=(money*0.5/100)+pm;
        player_total_score=player_total_score+e_score;

    }
    else if(money<=0)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tTotal score : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();

    }
}

int game_1()
{
    readimagefile("1.jpg",0,0,1530,370);
    system("CLS");
    textcolor(0,3);
    cout<<endl<<"   EPISODE 1"<<endl;
    resetcolor();
    textcolor(0,7);
    cout<<endl<<"   You have 10,000 baht."<<endl<<endl;
    resetcolor();
    item();
    int money=10000;
    int count_buy=0;
    int pm=0;
    int x=0;
    int en_money=0;
    en_money=money;
    player_total_money=money;
    player_total_pm=pm;
    if(money>0)
    {
        while(money>0&&x==0 )
        {
            readimagefile("item.jpg",0,0,1530,370);
            cout<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\tBuy item : ";
            int item=0;
            cin.clear();
            cin>>item;
            if(!cin.fail())
            {
                switch(item)
                {
                case 1 :
                    if(en_money>=tree1)
                    {
                        money=money-tree1;
                        pm=pm+10;
                        choose_tree1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 2 :
                    if(en_money>=tree2)
                    {
                        money=money-tree2;
                        pm=pm+15;
                        choose_tree2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<tree2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 3 :
                    if(en_money>=wintur)
                    {
                        money=money-wintur;
                        pm=pm+24;
                        choose_wintur(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<wintur)
                    {
                        announce_enought_money();
                    }
                    break;
                case 4 :
                    if(en_money>=bush)
                    {
                        money=money-bush;
                        pm=pm+7;
                        choose_bush(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<bush)
                    {
                        announce_enought_money();
                    }
                    break;
                case 5 :
                    if(en_money>=purif1)
                    {
                        money=money-purif1;
                        pm=pm+30;
                        choose_purif1(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif1)
                    {
                        announce_enought_money();
                    }
                    break;
                case 6 :
                    if(en_money>=purif2)
                    {
                        money=money-purif2;
                        pm=pm+45;
                        choose_purif2(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<purif2)
                    {
                        announce_enought_money();
                    }
                    break;
                case 7 :
                    if(en_money>=highpre)
                    {
                        money=money-highpre;
                        pm=pm+2;
                        choose_highpre(money,pm,e_score);
                        count_buy++;
                    }
                    else if(en_money<highpre)
                    {
                        announce_enought_money();
                    }
                    break;
                case 0 :
                    if(count_buy==0)
                    {
                        readimagefile("b1.jpg",0,0,1530,370);
                        Sleep(1000);
                        textcolor(15,4);
                        cout<<endl<<"     **Announce >> You have to buy at least 1 item.";
                        resetcolor();
                        cout<<endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                    else if(count_buy>=1)
                    {
                        x=1;
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
                        episode++;
                        player_total_money=money;
                        player_total_pm=pm;
                        e_score=(money*0.5/100)+pm;
                        player_total_score=e_score;
                        textcolor(32,0);
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
                        resetcolor();
                        cout<<endl;
                        next_ep();

                    }
                    break;
                case 99 :
                    loadbar();
                    closegraph();
                    x=1;
                    return 99;
                    break;
                default :
                    cin_fail();
                }
                if(money>=0)
                {
                    en_money=money;
                    e_score=(money*0.5/100)+pm;
                }
            }
            else if(cin.fail())
            {
                cin_fail();

            }
        }
        player_total_money=money;
        player_total_pm=pm;
        e_score=(money*0.5/100)+pm;
        player_total_score=e_score;
    }
    else if(money<=0)
    {
        e_score=player_total_pm;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tYou dont have money"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tEpisode "<<episode<<" is complete!"<<endl;
        textcolor(32,0);
        episode++;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\tScore : "<<e_score;
        resetcolor();
        cout<<endl;
        next_ep();
    }
}

void renamefile()
{
    remove("Player.txt");
    rename("Player2.txt", "Player.txt");
}





