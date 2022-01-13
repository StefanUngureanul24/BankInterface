#ifndef BANKSUPERVISION_H
#define BANKSUPERVISION_H
#include <agence.h>
#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QTimer>
#include <QtCharts>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class BankSupervision; }
QT_END_NAMESPACE

class BankSupervision : public QMainWindow
{
    Q_OBJECT

public:
    BankSupervision(QString , QDate , QDate,QWidget *parent = nullptr);
    ~BankSupervision();
    void initialisation();
    void getchiffresdaffaires();
    void getvolume();
    void getpourcentage();
    void setCA();
    void setVolume();
    void setPourcentage();
    void setfamille();
    void setcanal();
    void setreset();
    void careset();
    void volumereset();
    void pourcentagereset();
    void refraichegraphe();
    void refraichedata();
    int getmax(QVector<QBarSet*>);

private slots:
    void init_graph();
    void cleargraph();
    void DateTime();
    void on_datedebut_dateChanged(const QDate &date);
    void on_dateFin_dateChanged(const QDate &date);
    void on_CA_clicked();
    void on_Volume_clicked();
    void on_Pourcentage_clicked();
    void on_AgenceParis_clicked();
    void on_AgenceBordeaux_clicked();
    void on_AgenceLyon_clicked();
    void on_AgenceStrasbourg_clicked();
    void on_AgenceToulouse_clicked();

private:
    Ui::BankSupervision *ui;
    QVector<Agence> V_Agences;
    QTimer *timer;
    QDate dd;
    QDate df;
    QVector<bool> agence = {false,false,false,false,false,false};
    QVector<QString> agence_name_axes;
    QVector<QVector<QString>> informations = {
                                             {"Directeur" , "M Jean-Pierre Dupont"},
                                             {"Agence de Paris" , "29 Rue de Bièvre"},
                                             {"Agence de Bordeaux", "19 Rue des Augustins"},
                                             {"Agence de Lyon" , "55 Rue de la Bourse"},
                                             {"Agence de Strasbourg" , "2 Rue de Zurich"},
                                             {"Agence de Toulouse", "Rue du Doyen Gabriel Marty"}
                                              };
    QVector<float> CA;
    QVector<float> CA_AH;
    QVector<float> CA_AV;
    QVector<float> CA_AA;
    QVector<float> CA_AO;
    QVector<float> CA_CC;
    QVector<float> CA_CE;
    QVector<float> CA_PA;
    QVector<float> CA_PH;
    QVector<float> CA_DC;
    QVector<float> CA_DP;
    QVector<float> CA_BA;

    QVector<int> VT;
    QVector<int> V_AH;
    QVector<int> V_AV;
    QVector<int> V_AA;
    QVector<int> V_AO;
    QVector<int> V_CC;
    QVector<int> V_CE;
    QVector<int> V_PA;
    QVector<int> V_PH;
    QVector<int> V_DC;
    QVector<int> V_DP;
    QVector<int> V_BA;

    QVector<float> PT;
    QVector<float> P_AH;
    QVector<float> P_AV;
    QVector<float> P_AA;
    QVector<float> P_AO;
    QVector<float> P_CC;
    QVector<float> P_CE;
    QVector<float> P_PA;
    QVector<float> P_PH;
    QVector<float> P_DC;
    QVector<float> P_DP;
    QVector<float> P_BA;

    QBarSet *set = new QBarSet("Bank Supervision");
    QBarSet *set_cc = new QBarSet("Compte Courant");
    QBarSet *set_ce = new QBarSet("Compte Epargne");
    QBarSet *set_pa = new QBarSet("Pret Automobile");
    QBarSet *set_ph = new QBarSet("Pret Habitation");
    QBarSet *set_dc = new QBarSet("demande courant");
    QBarSet *set_dp = new QBarSet("demande passée");
    QBarSet *set_ah = new QBarSet("Assurance Habitation");
    QBarSet *set_av = new QBarSet("Assurance velo");
    QBarSet *set_aa = new QBarSet("Assurance automobile");
    QBarSet *set_ao = new QBarSet("Assurance ordianteur");
    QBarSet *set_ba = new QBarSet("Bank Action");
    QBarSet *set_canalBancaire = new QBarSet("Canal Bancaire");
    QBarSet *set_canalAssurance = new QBarSet("Canal Assurance");
    QBarSet *set_canalAction = new QBarSet("Canal Actions");

    QBarSeries *FamilleCompte = new QBarSeries();
    QBarSeries *FamillePret = new QBarSeries();
    QBarSeries *FamilleChequier = new QBarSeries();
    QBarSeries *FamilleAssurance = new QBarSeries();
    QBarSeries *FamilleActions = new QBarSeries();
    QBarSeries *CanalBancaire = new QBarSeries();
    QBarSeries *CanalAssurance = new QBarSeries();
    QBarSeries *CanalAction = new QBarSeries();

    QChart *chartCB = new QChart();
    QStringList categoriesCB;
    QBarCategoryAxis *axisXCB = new QBarCategoryAxis();
    QValueAxis *axisYCB = new QValueAxis();
    QChartView *chartViewCB = new QChartView(chartCB);

    QChart *chartCA = new QChart();
    QStringList categoriesCA;
    QBarCategoryAxis *axisXCA = new QBarCategoryAxis();
    QValueAxis *axisYCA = new QValueAxis();
    QChartView *chartViewCA = new QChartView(chartCA);

    QChart *chartCS = new QChart();
    QStringList categoriesCS;
    QBarCategoryAxis *axisXCS = new QBarCategoryAxis();
    QValueAxis *axisYCS = new QValueAxis();
    QChartView *chartViewCS = new QChartView(chartCS);

    QChart *chartFC = new QChart();
    QStringList categoriesFC;
    QBarCategoryAxis *axisXFC = new QBarCategoryAxis();
    QValueAxis *axisYFC = new QValueAxis();
    QChartView *chartViewFC = new QChartView(chartFC);

    QChart *chartFP = new QChart();
    QStringList categoriesFP;
    QBarCategoryAxis *axisXFP = new QBarCategoryAxis();
    QValueAxis *axisYFP = new QValueAxis();
    QChartView *chartViewFP = new QChartView(chartFP);

    QChart *chartFH = new QChart(); //famille chequier
    QStringList categoriesFH;
    QBarCategoryAxis *axisXFH = new QBarCategoryAxis();
    QValueAxis *axisYFH = new QValueAxis();
    QChartView *chartViewFH = new QChartView(chartFH);

    QChart *chartFA = new QChart();
    QStringList categoriesFA;
    QBarCategoryAxis *axisXFA = new QBarCategoryAxis();
    QValueAxis *axisYFA = new QValueAxis();
    QChartView *chartViewFA = new QChartView(chartFA);

    QChart *chartFB = new QChart();
    QStringList categoriesFB;
    QBarCategoryAxis *axisXFB = new QBarCategoryAxis();
    QValueAxis *axisYFB = new QValueAxis();
    QChartView *chartViewFB = new QChartView(chartFB);

};
#endif
