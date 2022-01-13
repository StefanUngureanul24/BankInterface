#include "banksupervision.h"
#include "ui_banksupervision.h"

BankSupervision::BankSupervision(QString loginas, QDate dd, QDate df,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BankSupervision)
{
    ui->setupUi(this);
    ui->datedebut->setDate(dd);
    ui->dateFin->setDate(df);
    ui->GB1->setTitle(loginas);
    for(int i=0;i<6;i++){ agence[i] = !loginas.compare(informations[i][0]);}
    if(agence[0]) ui->AgenceVue->setCurrentIndex(0);
    else
    {
        ui->AgenceVue->setCurrentIndex(1);
        ui->AgenceVue->removeTab(0);
        if(agence[1]) {ui->AgenceParis->setChecked(true);agence_name_axes.push_back("Paris");}
        if(agence[2]) {ui->AgenceBordeaux->setChecked(true);agence_name_axes.push_back("Bordeaux");}
        if(agence[3]) {ui->AgenceLyon->setChecked(true);agence_name_axes.push_back("Lyon");}
        if(agence[4]) {ui->AgenceStrasbourg->setChecked(true);agence_name_axes.push_back("Strasbourg");}
        if(agence[5]) {ui->AgenceToulouse->setChecked(true);agence_name_axes.push_back("Toulouse");}
    }
    initialisation();
    refraichegraphe();
}

BankSupervision::~BankSupervision()
{
    delete ui;
}

void BankSupervision::DateTime()
{
    /*
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    QString date_text = date.toString("dd / MM / yy");    
    */
}

void BankSupervision::initialisation()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(DateTime()));
    timer->start(1000);
    for(int i=1; i < informations.size(); i++)
    {
        V_Agences.push_back(Agence(informations[i][0],informations[i][1], rand()%30 +5));
    }
    getchiffresdaffaires();
    getvolume();
    getpourcentage();
    init_graph();
}

void BankSupervision::getchiffresdaffaires(){
    dd = ui->datedebut->date();
    df = ui->dateFin->date();

    for(int i=0;i<V_Agences.size();i++)
    {
            CA_AH.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getCA_AH(dd,df));
            CA_AV.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getCA_AV(dd,df));
            CA_AA.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getCA_AA(dd,df));
            CA_AO.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getCA_AO(dd,df));
            CA_CC.push_back(V_Agences[i].getCanalBancaire().getfamillecomptes().getCA_CC(dd,df));
            CA_CE.push_back(V_Agences[i].getCanalBancaire().getfamillecomptes().getCA_CE(dd,df));
            CA_PH.push_back(V_Agences[i].getCanalBancaire().getfamillepret().getCA_PH(dd,df));
            CA_PA.push_back(V_Agences[i].getCanalBancaire().getfamillepret().getCA_PA(dd,df));
            CA_DC.push_back(V_Agences[i].getCanalBancaire().getfamillechequier().getCA_DC(dd,df));
            CA_DP.push_back(V_Agences[i].getCanalBancaire().getfamillechequier().getCA_DP(dd,df));
            CA_BA.push_back(V_Agences[i].getCanalBoursier().getfamilleaction().getCA_BA(dd,df));
            CA.push_back(CA_AH[i] + CA_AV[i] + CA_AA[i] + CA_AO[i] + CA_CC[i] + CA_CE[i] + CA_PH[i] + CA_PA[i] + CA_DC[i] + CA_DP[i] + CA_BA[i]);
    }
}

void BankSupervision::getvolume()
{
    for(int i=0;i<V_Agences.size();i++)
    {
        dd = ui->datedebut->date();
        df = ui->dateFin->date();
        V_AH.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getVolume_AH(dd,df));
        V_AV.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getVolume_AV(dd,df));
        V_AA.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getVolume_AA(dd,df));
        V_AO.push_back(V_Agences[i].getCanalAssurance().getfamilleassurance().getVolume_AO(dd,df));
        V_CC.push_back(V_Agences[i].getCanalBancaire().getfamillecomptes().getVolume_CC(dd,df));
        V_CE.push_back(V_Agences[i].getCanalBancaire().getfamillecomptes().getVolume_CE(dd,df));
        V_PH.push_back(V_Agences[i].getCanalBancaire().getfamillepret().getVolume_PH(dd,df));
        V_PA.push_back(V_Agences[i].getCanalBancaire().getfamillepret().getVolume_PA(dd,df));
        V_DC.push_back(V_Agences[i].getCanalBancaire().getfamillechequier().getVolume_DC(dd,df));
        V_DP.push_back(V_Agences[i].getCanalBancaire().getfamillechequier().getVolume_DP(dd,df));
        V_BA.push_back(V_Agences[i].getCanalBoursier().getfamilleaction().getVolume_BA(dd,df));
        VT.push_back(V_AH[i] + V_AV[i] + V_AA[i] + V_AO[i] + V_CC[i] + V_CE[i] + V_PH[i] + V_PA[i] + V_DC[i] + V_DP[i] + V_BA[i]);
    }
}

void BankSupervision::getpourcentage()
{
    for (int i=0; i < V_Agences.size(); i++)
    {
        dd = ui->datedebut->date();
        df = ui->dateFin->date();

        P_AH.push_back((CA_AH[i]/CA[i])*100);
        P_AV.push_back((CA_AV[i]/CA[i])*100);
        P_AA.push_back((CA_AA[i]/CA[i])*100);
        P_AO.push_back((CA_AO[i]/CA[i])*100);
        P_CC.push_back((CA_CC[i]/CA[i])*100);
        P_CE.push_back((CA_CE[i]/CA[i])*100);
        P_PH.push_back((CA_PH[i]/CA[i])*100);
        P_PA.push_back((CA_PA[i]/CA[i])*100);
        P_DC.push_back((CA_DC[i]/CA[i])*100);
        P_DP.push_back((CA_DP[i]/CA[i])*100);
        P_BA.push_back((CA_BA[i]/CA[i])*100);
    }
}

void BankSupervision::setCA()
{
    setreset();
    for (int i = 0; i < V_Agences.size(); i++)
    {
        if (agence[i+1] || agence[0])
        {
            *set << CA[i];
            *set_cc << CA_CC[i];
            *set_ce << CA_CE[i];
            *set_ph << CA_PH[i];
            *set_pa << CA_PA[i];
            *set_dp << CA_DP[i];
            *set_dc << CA_DC[i];
            *set_ah << CA_AH[i];
            *set_av << CA_AV[i];
            *set_aa << CA_AA[i];
            *set_ao << CA_AO[i];
            *set_ba << CA_BA[i];
            *set_canalBancaire << CA_CC[i]+CA_CE[i]+CA_PA[i]+CA_PH[i];
            *set_canalAssurance << CA_AH[i]+CA_AV[i];
            *set_canalAction << CA_BA[i];
        }
    }
    refraichegraphe();
}

void BankSupervision::setVolume()
{
    setreset();
    for (int i=0; i < V_Agences.size(); i++)
    {
        if (agence[i+1] || agence[0])
        {
            *set << VT[i];
            *set_cc << V_CC[i];
            *set_ce << V_CE[i];
            *set_ph << V_PH[i];
            *set_pa << V_PA[i];
            *set_dp << V_DP[i];
            *set_dc << V_DC[i];
            *set_ah << V_AH[i];
            *set_av << V_AV[i];
            *set_aa << V_AA[i];
            *set_ao << V_AO[i];
            *set_ba << V_BA[i];
            *set_canalBancaire << V_CC[i]+V_CE[i]+V_PA[i]+V_PH[i]+V_DC[i]+V_DP[i];
            *set_canalAssurance << V_AH[i]+V_AV[i]+V_AA[i]+V_AO[i];
            *set_canalAction << V_BA[i];
        }
    }
    refraichegraphe();
}

void BankSupervision::setPourcentage()
{
    setreset();
    for (int i=0; i < V_Agences.size(); i++)
    {
        if(agence[i+1] || agence[0])
        {
            *set_cc << P_CC[i];
            *set_ce << P_CE[i];
            *set_ph << P_PH[i];
            *set_pa << P_PA[i];
            *set_dp << P_DP[i];
            *set_dc << P_DC[i];
            *set_ah << P_AH[i];
            *set_av << P_AV[i];
            *set_aa << P_AA[i];
            *set_ao << P_AO[i];
            *set_ba << P_BA[i];
        }
    }
    refraichegraphe();
}

void BankSupervision::setreset()
{
    set->remove(0,5);
    set_cc->remove(0,5);
    set_ce->remove(0,5);
    set_ph->remove(0,5);
    set_pa->remove(0,5);
    set_dp->remove(0,5);
    set_dc->remove(0,5);
    set_aa->remove(0,5);
    set_ao->remove(0,5);
    set_av->remove(0,5);
    set_ah->remove(0,5);
    set_ba->remove(0,5);
    set_canalBancaire->remove(0,5);
    set_canalAssurance->remove(0,5);
    set_canalAction->remove(0,5);
}

int BankSupervision::getmax(QVector<QBarSet*> B)
{
    int max = 0;
    for (int i = 0; i < B.size();i++)
    {
        for(int j=0; j < B[i]->count(); j++)
        {
            if (max<B[i]->at(j))
            {
                max = B[i]->at(j);
            }
        }
    }
    return max;
}

void BankSupervision::careset()
{
    CA_AH.clear();
    CA_AV.clear();
    CA_AA.clear();
    CA_AO.clear();
    CA_CC.clear();
    CA_CE.clear();
    CA_PH.clear();
    CA_PA.clear();
    CA_DC.clear();
    CA_DP.clear();
    CA_BA.clear();
    CA.clear();
}

void BankSupervision::volumereset()
{
    V_AH.clear();
    V_AV.clear();
    V_AA.clear();
    V_AO.clear();
    V_CC.clear();
    V_CE.clear();
    V_PH.clear();
    V_PA.clear();
    V_DC.clear();
    V_DP.clear();
    V_BA.clear();
    VT.clear();
}

void BankSupervision::pourcentagereset()
{
    P_AH.clear();
    P_AV.clear();
    P_AA.clear();
    P_AO.clear();
    P_CC.clear();
    P_CE.clear();
    P_PH.clear();
    P_PA.clear();
    P_DC.clear();
    P_DP.clear();
    P_BA.clear();
    PT.clear();
}

void BankSupervision::init_graph()
{
    chartCB->addSeries(CanalBancaire);
    chartCB->setTitle("Canal Bancaire Supervision");
    chartCB->setAnimationOptions(QChart::SeriesAnimations);
    categoriesCB << "Paris" << "Bordeaux" << "Lyon" << "Strasbourg" << "Toulouse";
    axisXCB->append(categoriesCB);
    chartCB->addAxis(axisXCB, Qt::AlignBottom);
    CanalBancaire->attachAxis(axisXCB);
    chartCB->addAxis(axisYCB, Qt::AlignLeft);
    CanalBancaire->attachAxis(axisYCB);
    chartViewCB->setRenderHint(QPainter::Antialiasing);
    ui->CGeneralLayout->addWidget(chartViewCB);

    chartCA->addSeries(CanalAssurance);
    chartCA->setTitle("Canal Assurance Supervision");
    chartCA->setAnimationOptions(QChart::SeriesAnimations);
    categoriesCA << "Paris" << "Bordeaux" << "Lyon" << "Strasbourg" << "Toulouse";
    axisXCA->append(categoriesCA);
    chartCA->addAxis(axisXCA, Qt::AlignBottom);
    CanalAssurance->attachAxis(axisXCA);
    chartCA->addAxis(axisYCA, Qt::AlignLeft);
    CanalAssurance->attachAxis(axisYCA);
    chartViewCA->setRenderHint(QPainter::Antialiasing);
    ui->CGeneralLayout->addWidget(chartViewCA);

    chartCS->addSeries(CanalAction);
    chartCS->setTitle("Famille Comptes Supervision");
    chartCS->setAnimationOptions(QChart::SeriesAnimations);
    categoriesCS << "Paris" << "Bordeaux" << "Lyon" << "Strasbourg" << "Toulouse";
    axisXCS->append(categoriesCS);
    chartCS->addAxis(axisXCS, Qt::AlignBottom);
    CanalAction->attachAxis(axisXCS);
    chartCS->addAxis(axisYCS, Qt::AlignLeft);
    CanalAction->attachAxis(axisYCS);
    chartViewCS->setRenderHint(QPainter::Antialiasing);
    ui->CGeneralLayout->addWidget(chartViewCS);

    chartFC->addSeries(FamilleCompte);
    chartFC->setTitle("Famille Comptes Supervision");
    chartFC->setAnimationOptions(QChart::SeriesAnimations);
    chartFC->addAxis(axisXFC, Qt::AlignBottom);
    FamilleCompte->attachAxis(axisXFC);
    chartFC->addAxis(axisYFC, Qt::AlignLeft);
    FamilleCompte->attachAxis(axisYFC);
    chartFC->legend()->setVisible(true);
    chartFC->legend()->setAlignment(Qt::AlignBottom);
    chartViewFC->setRenderHint(QPainter::Antialiasing);
    ui->CBancaireLayout->addWidget(chartViewFC);

    chartFP->addSeries(FamillePret);
    chartFP->setTitle("Famille Pret Supervision");
    chartFP->setAnimationOptions(QChart::SeriesAnimations);
    chartFP->addAxis(axisXFP, Qt::AlignBottom);
    FamillePret->attachAxis(axisXFP);
    chartFP->addAxis(axisYFP, Qt::AlignLeft);
    FamillePret->attachAxis(axisYFP);
    chartFP->legend()->setVisible(true);
    chartFP->legend()->setAlignment(Qt::AlignBottom);
    chartViewFP->setRenderHint(QPainter::Antialiasing);
    ui->CBancaireLayout->addWidget(chartViewFP);

    chartFA->addSeries(FamilleAssurance);
    chartFA->setTitle("Famille Assurance Supervision");
    chartFA->setAnimationOptions(QChart::SeriesAnimations);
    chartFA->addAxis(axisXFA, Qt::AlignBottom);
    FamilleAssurance->attachAxis(axisXFA);
    chartFA->addAxis(axisYFA, Qt::AlignLeft);
    FamilleAssurance->attachAxis(axisYFA);
    chartFA->legend()->setVisible(true);
    chartFA->legend()->setAlignment(Qt::AlignBottom);
    chartViewFA->setRenderHint(QPainter::Antialiasing);
    ui->CAssuranceLayout->addWidget(chartViewFA);

    chartFB->addSeries(FamilleActions);
    chartFB->setTitle("Famille Actions Supervision");
    chartFB->setAnimationOptions(QChart::SeriesAnimations);
    chartFB->addAxis(axisXFB, Qt::AlignBottom);
    FamilleActions->attachAxis(axisXFB);
    chartFB->addAxis(axisYFB, Qt::AlignLeft);
    FamilleActions->attachAxis(axisYFB);
    chartFB->legend()->setVisible(true);
    chartFB->legend()->setAlignment(Qt::AlignBottom);
    chartViewFB->setRenderHint(QPainter::Antialiasing);
    ui->CBoursierLayout->addWidget(chartViewFB);

}

void BankSupervision::refraichegraphe()
{
    FamilleCompte->append(set_cc);
    FamilleCompte->append(set_ce);
    FamillePret->append(set_ph);
    FamillePret->append(set_pa);
    FamilleChequier->append(set_dc);
    FamilleChequier->append(set_dp);
    FamilleAssurance->append(set_aa);
    FamilleAssurance->append(set_ao);
    FamilleAssurance->append(set_av);
    FamilleAssurance->append(set_ah);
    FamilleActions->append(set_ba);
    CanalBancaire->append({set_cc,set_ce,set_ph,set_pa,set_dc,set_dp});
    CanalAssurance->append({set_aa,set_ao,set_av,set_ah});
    CanalAction->append(set_ba);

    cleargraph();

    axisYCB->setRange(0,getmax({set_cc,set_ce,set_ph,set_pa,set_dc,set_dp}));
    axisYCA->setRange(0,getmax({set_aa,set_ao,set_av,set_ah}));
    axisYCS->setRange(0,getmax({set_ba}));

    for (int i=1; i<6; i++)
    {
        if (agence[i])
            categoriesFC << informations[i][0];
    }
    axisXFC->append(categoriesFC);
    axisYFC->setRange(0,getmax({set_cc,set_ce}));

    for(int i=1; i<6; i++)
    {
        if(agence[i])
        {categoriesFP << informations[i][0];}
    }
    axisXFP->append(categoriesFP);
    axisYFP->setRange(0,getmax({set_pa,set_ph}));

    for(int i=1; i<6; i++)
    {if(agence[i])
        {categoriesFA << informations[i][0];}
    }
    axisXFA->append(categoriesFA);
    axisYFA->setRange(0,getmax({set_aa,set_ah,set_ao,set_av}));

    for(int i=1; i<6; i++)
    {if(agence[i])
        {categoriesFB << informations[i][0];}
    }
    axisXFB->append(categoriesFB);
    axisYFB->setRange(0,getmax({set_ba}));

}

void BankSupervision::cleargraph()
{
    categoriesFC.clear();
    axisXFC->clear();

    categoriesFP.clear();
    axisXFP->clear();

    categoriesFA.clear();
    axisXFA->clear();

    categoriesFB.clear();
    axisXFB->clear();
}

void BankSupervision::on_datedebut_dateChanged(const QDate &date)
{
    dd=date;
    refraichedata();
}

void BankSupervision::on_dateFin_dateChanged(const QDate &date)
{
    df=date;
    refraichedata();
}

void BankSupervision::refraichedata()
{
    careset();
    volumereset();
    pourcentagereset();
    getchiffresdaffaires();
    getvolume();
    getpourcentage();
    setCA();
}

void BankSupervision::on_CA_clicked()
{
    setCA();
}

void BankSupervision::on_Volume_clicked()
{
    setVolume();
}

void BankSupervision::on_Pourcentage_clicked()
{
    setPourcentage();
}

void BankSupervision::on_AgenceParis_clicked()
{
    agence[1] = ui->AgenceParis->isChecked();
    if (agence[1] && !agence_name_axes.contains("Paris") ){
        agence_name_axes.push_back("Paris");
    }

    else
        if (!agence[1])
        {
            agence_name_axes.remove(agence_name_axes.indexOf("Paris"));
        }
    setCA();
}

void BankSupervision::on_AgenceBordeaux_clicked()
{
    agence[2] = ui->AgenceBordeaux->isChecked();
    if (agence[2] && !agence_name_axes.contains("Bordeaux") ){
        agence_name_axes.push_back("Bordeaux");
    }

    else
        if (!agence[2])
        {
            agence_name_axes.remove(agence_name_axes.indexOf("Bordeaux"));
        }
    setCA();
}

void BankSupervision::on_AgenceLyon_clicked()
{
    agence[3] = ui->AgenceLyon->isChecked();
    if (agence[3] && !agence_name_axes.contains("Lyon") ){
        agence_name_axes.push_back("Lyon");
    }

    else
        if (!agence[3])
        {
            agence_name_axes.remove(agence_name_axes.indexOf("Lyon"));
        }
    setCA();
}

void BankSupervision::on_AgenceStrasbourg_clicked()
{
    agence[4] = ui->AgenceStrasbourg->isChecked();
    if (agence[4] && !agence_name_axes.contains("Strasbourg") ){
        agence_name_axes.push_back("Strasbourg");
    }

    else
        if(!agence[4])
        {
        agence_name_axes.remove(agence_name_axes.indexOf("Strasbourg"));
        }
    setCA();
}


void BankSupervision::on_AgenceToulouse_clicked()
{
    agence[5] = ui->AgenceToulouse->isChecked();
    if(agence[5] && !agence_name_axes.contains("Toulouse") ){
        agence_name_axes.push_back("Toulouse");
    }

    else
        if(!agence[5])
        {
        agence_name_axes.remove(agence_name_axes.indexOf("Toulouse"));
        }
    setCA();
}
