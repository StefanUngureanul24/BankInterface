#include "familleactions.h"
int y = 21;
FamilleActions::FamilleActions()
{
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
        VBA.push_back(BankAction("AR",rand()%200+50,dd,df,rand()%20+1));
    }
}

QVector<BankAction> FamilleActions::getbankaction()
{
    return this->VBA;
}

float FamilleActions::getCA_BA(QDate dd, QDate df)
{
    float sum = 0;

    for (int i = 0; i < FamilleActions::VBA.size(); i++)
    {
        if(VBA[i].getdatedebut()>=dd && VBA[i].getdatedebut()<=df)
        sum += VBA[i].getprix();
    }

    return sum;
}

int FamilleActions::getVolume_BA(QDate dd, QDate df)
{
    int sum = 0;

    for (int i = 0; i < VBA.size(); i++)
    {
        if(VBA[i].getdatedebut()>=dd && VBA[i].getdatedebut()<=df)
        sum++;
    }

    return sum;
}
