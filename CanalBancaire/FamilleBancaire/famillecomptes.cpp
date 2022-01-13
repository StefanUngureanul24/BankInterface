#include "famillecomptes.h"

FamilleComptes::FamilleComptes()
{
    /*
        Calcul pour le compte actuel
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
        VCC.push_back(CompteCourant("AR",rand()%200+50,dd,df,rand()%20+1));
    }

    /*
        Calcul pour le compte d'epargne
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
        VCE.push_back(CompteEpargne("AR",rand()%200+50,dd,df,rand()%20+1));
    }
}

QVector<CompteCourant> FamilleComptes::getcompteCourant()
{
    return this->VCC;
}

QVector<CompteEpargne> FamilleComptes::getcompteEpargne()
{
    return this->VCE;
}

float FamilleComptes::getCA_CC(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < FamilleComptes::VCC.size(); i++)
    {
        if (VCC[i].getdatedebut()>=dd && VCC[i].getdatedebut()<=df)
        sum += VCC[i].getprix();
    }

    return sum;
}

float FamilleComptes::getCA_CE(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < FamilleComptes::VCE.size(); i++)
    {
        if(VCE[i].getdatedebut()>=dd && VCE[i].getdatedebut()<=df)
        sum += VCE[i].getprix();
    }

    return sum;
}

int FamilleComptes::getVolume_CC(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < FamilleComptes::VCC.size(); i++)
    {
        if(VCC[i].getdatedebut()>=dd && VCC[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}

int FamilleComptes::getVolume_CE(QDate dd, QDate df)
{
    int sum = 0;
    for(int i=0;i<FamilleComptes::VCE.size();i++)
    {
        if(VCE[i].getdatedebut()>=dd && VCE[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}
