#ifndef BANQUIER_H
#define BANQUIER_H
#include <QString>

class Banquier
{
private:
    QString nom;
    QString prenom;
    int age;

public:
    Banquier(QString, QString, int);
    QString getnom();
    QString getprenom();
    int getage();
};

#endif
