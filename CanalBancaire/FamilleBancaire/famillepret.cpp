#include "famillepret.h"

FamillePret::FamillePret()
{    
    for(int j=0;j<rand()%100+50;j++)
    {
        QDate dd,df;
        int y_d = rand()%y+2000;
        int m_d = rand()%12+1;
        int d_d = rand()%30+1;

        int y_f = rand()%y+y_d+1;
        int m_f = rand()%12+1;
        int d_f = rand()%30+1;

        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VPA.push_back(PretAutomobile("AR",rand()%200+50,dd,df,rand()%20+1));
    }

    for(int j=0;j<rand()%100+50;j++)
    {
        QDate dd,df;
        int y_d = rand()%y+2000;
        int m_d = rand()%12+1;
        int d_d = rand()%30+1;

        int y_f = rand()%y+y_d+1;
        int m_f = rand()%12+1;
        int d_f = rand()%30+1;

        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VPH.push_back(PretHabitation("AR",rand()%200+50,dd,df,rand()%20+1));
    }
}

QVector<PretAutomobile> FamillePret::getpretautomobile()
{
    return this->VPA;
}

QVector<PretHabitation> FamillePret::getprethabitation()
{
    return this->VPH;
}

float FamillePret::getCA_PA(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < VPA.size(); i++)
    {
        if(VPA[i].getdatedebut()>=dd && VPA[i].getdatedebut()<=df)
        sum += VPA[i].getprix();
    }

    return sum;
}

float FamillePret::getCA_PH(QDate dd, QDate df){
    float sum = 0;
    for (int i = 0; i < VPH.size(); i++)
    {
        if(VPH[i].getdatedebut()>=dd && VPH[i].getdatedebut()<=df)
        sum += VPH[i].getprix();
    }

    return sum;
}

int FamillePret::getVolume_PA(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < VPA.size(); i++)
    {
        if(VPA[i].getdatedebut()>=dd && VPA[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}

int FamillePret::getVolume_PH(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < VPH.size(); i++)
    {
        if(VPH[i].getdatedebut()>=dd && VPH[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}
