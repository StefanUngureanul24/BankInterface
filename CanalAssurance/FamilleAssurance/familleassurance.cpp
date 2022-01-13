#include "familleassurance.h"

FamilleAssurance::FamilleAssurance()
{
    /*
        Ajout assurance habitation
    */
    for (int j = 0; j < rand()%100+4; j++)
    {
        QDate dd,df;
        int y_d = (rand()%y)+2000;int m_d = rand()%12+1; int d_d = rand()%30+1;
        int y_f = (rand()%y)+y_d+1;int m_f = rand()%12+1;int d_f = rand()%30+1;
        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VAH.push_back(AssuranceHabitation("AR",rand()%200+50,dd,df,rand()%20+1));
    }

    /*
        Ajout assurance auto
    */
    for (int j = 0; j < rand()%100+4; j++)
    {
        QDate dd,df;
        int y_d = rand()%y+2000;int m_d = rand()%12+1; int d_d = rand()%30+1;
        int y_f = rand()%y+y_d+1;int m_f = rand()%12+1;int d_f = rand()%30+1;
        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VAA.push_back(AssuranceAuto("AR",rand()%200+50,dd,df,rand()%20+1));
    }

    /*
        Ajout assurance velo
    */
    for (int j = 0; j < rand()%100+4; j++)
    {
        QDate dd,df;
        int y_d = rand()%y+2000;int m_d = rand()%12+1; int d_d = rand()%30+1;
        int y_f = rand()%y+y_d+1;int m_f = rand()%12+1;int d_f = rand()%30+1;
        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VAV.push_back(AssuranceVelo("AR",rand()%200+50,dd,df,rand()%20+1));
    }

    /*
        Ajout assurance ordi
    */
    for (int j = 0; j < rand()%100+4; j++)
    {
        QDate dd,df;
        int y_d = rand()%y+2000;int m_d = rand()%12+1; int d_d = rand()%30+1;
        int y_f = rand()%y+y_d+1;int m_f = rand()%12+1;int d_f = rand()%30+1;
        dd.setDate(y_d,m_d,d_d);df.setDate(y_f,m_f,d_f);
        VAO.push_back(AssuranceOrdi("AR",rand()%200+50,dd,df,rand()%20+1));
    }
}

QVector<AssuranceHabitation> FamilleAssurance::getassurancehabitation()
{
    return this->VAH;
}

QVector<AssuranceVelo> FamilleAssurance::getassurancevelo()
{
    return this->VAV;
}

QVector<AssuranceOrdi> FamilleAssurance::getassuranceordi()
{
    return this->VAO;
}

QVector<AssuranceAuto> FamilleAssurance::getassuranceauto()
{
    return this->VAA;
}

float FamilleAssurance::getCA_AH(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < FamilleAssurance::VAH.size(); i++)
    {
        if (VAH[i].getdatedebut()>=dd && VAH[i].getdatedebut()<=df)
        sum += VAH[i].getprix();
    }
    return sum;
}

float FamilleAssurance::getCA_AV(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < FamilleAssurance::VAV.size(); i++)
    {
        if(VAV[i].getdatedebut()>=dd && VAV[i].getdatedebut()<=df)
        sum += VAV[i].getprix();
    }

    return sum;
}

float FamilleAssurance::getCA_AA(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < FamilleAssurance::VAA.size(); i++)
    {
        if(VAA[i].getdatedebut()>=dd && VAA[i].getdatedebut()<=df)
        sum += VAA[i].getprix();
    }

    return sum;
}

float FamilleAssurance::getCA_AO(QDate dd, QDate df)
{
    float sum = 0;
    for (int i = 0; i < FamilleAssurance::VAO.size(); i++)
    {
        if(VAO[i].getdatedebut()>=dd && VAO[i].getdatedebut()<=df)
        sum += VAO[i].getprix();
    }

    return sum;
}

int FamilleAssurance::getVolume_AV(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < FamilleAssurance::VAV.size(); i++)
    {
        if(VAV[i].getdatedebut()>=dd && VAV[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}

int FamilleAssurance::getVolume_AH(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < FamilleAssurance::VAV.size(); i++)
    {
        if(VAV[i].getdatedebut()>=dd && VAV[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}

int FamilleAssurance::getVolume_AA(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < FamilleAssurance::VAA.size(); i++)
    {
        if(VAA[i].getdatedebut()>=dd && VAA[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}

int FamilleAssurance::getVolume_AO(QDate dd, QDate df)
{
    int sum = 0;
    for (int i = 0; i < FamilleAssurance::VAO.size(); i++)
    {
        if(VAO[i].getdatedebut()>=dd && VAO[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}
