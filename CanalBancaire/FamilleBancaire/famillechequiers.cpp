#include "famillechequiers.h"

FamilleChequiers::FamilleChequiers()
{
    /*
        Pour une demande en cours d'etre calculee
    */
    for (int j = 0; j < rand()%100+50; j++)
    {
        QDate dd,df;
        int y_d = rand()%y+2000;
        int m_d = rand()%12+1;
        int d_d = rand()%30+1;

        int y_f = rand()%y+y_d+1;
        int m_f = rand()%12+1;
        int d_f = rand()%30+1;

        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VDC.push_back(demandeEnCours("AR",rand()%200+50,dd,df,rand()%20+1));
    }

    /*
        Pour une demande qui a ete deja calculee
    */
    for (int j = 0; j < rand()%100+50; j++)
    {
        QDate dd,df;
        int y_d = rand()%y+2000;
        int m_d = rand()%12+1;
        int d_d = rand()%30+1;

        int y_f = rand()%y+y_d+1;
        int m_f = rand()%12+1;
        int d_f = rand()%30+1;

        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VDP.push_back(demandePassee("AR",rand()%200+50,dd,df,rand()%20+1));
    }
}

QVector<demandeEnCours> FamilleChequiers::getdemandeencours()
{
    return this->VDC;
}

QVector<demandePassee> FamilleChequiers::getdemandepasse()
{
    return this->VDP;
}

float FamilleChequiers::getCA_DC(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < VDC.size(); i++)
    {
        if (VDC[i].getdatedebut()>=dd && VDC[i].getdatedebut()<=df)
        sum += VDC[i].getprix();
    }

    return sum;
}

float FamilleChequiers::getCA_DP(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < VDP.size(); i++)
    {
        if(VDP[i].getdatedebut()>=dd && VDP[i].getdatedebut()<=df)
        sum += VDP[i].getprix();
    }

    return sum;
}

int FamilleChequiers::getVolume_DC(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < VDC.size(); i++)
    {
        if(VDC[i].getdatedebut()>=dd && VDC[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}

int FamilleChequiers::getVolume_DP(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < VDP.size(); i++)
    {
        if(VDP[i].getdatedebut()>=dd && VDP[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}
