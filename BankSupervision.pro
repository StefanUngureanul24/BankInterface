QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CanalAssurance/FamilleAssurance/ProduitAssurance/assuranceauto.cpp \
    CanalAssurance/FamilleAssurance/ProduitAssurance/assuranceordi.cpp \
    CanalBancaire/FamilleBancaire/ProduitChequier/demandeencours.cpp \
    CanalBancaire/FamilleBancaire/ProduitChequier/demandepassee.cpp \
    agence.cpp \
    banquier.cpp \
    canalassurance/familleassurance/produitassurance/assurancehabitation.cpp \
    canalassurance/familleassurance/produitassurance/assurancevelo.cpp \
    canalboursier/familleactions/produitactions/bankaction.cpp \
    canalassurance/canalassurance.cpp \
    canalbancaire/canalbancaire.cpp \
    canalboursier/canalboursier.cpp \
    canalbancaire/famillebancaire/produitcompte/comptecourant.cpp \
    canalbancaire/famillebancaire/produitcompte/compteepargne.cpp \
    canalboursier/familleactions/familleactions.cpp \
    canalassurance/familleassurance/familleassurance.cpp \
    canalbancaire/famillebancaire/famillecartes.cpp \
    canalbancaire/famillebancaire/famillechequiers.cpp \
    canalbancaire/famillebancaire/famillecomptes.cpp \
    canalbancaire/famillebancaire/famillepret.cpp \
    login.cpp \
    main.cpp \
    banksupervision.cpp \
    canalbancaire/famillebancaire/produitpret/pretautomobile.cpp \
    canalbancaire/famillebancaire/produitpret/prethabitation.cpp

HEADERS += \
    CanalAssurance/FamilleAssurance/ProduitAssurance/assuranceauto.h \
    CanalAssurance/FamilleAssurance/ProduitAssurance/assuranceordi.h \
    CanalBancaire/FamilleBancaire/ProduitChequier/demandeencours.h \
    CanalBancaire/FamilleBancaire/ProduitChequier/demandepassee.h \
    agence.h \
    banquier.h \
    canalassurance/familleassurance/produitassurance/assurancehabitation.h \
    canalassurance/familleassurance/produitassurance/assurancevelo.h \
    canalboursier/familleactions/produitactions/bankaction.h \
    banksupervision.h \
    canalassurance/canalassurance.h \
    canalbancaire/canalbancaire.h \
    canalboursier/canalboursier.h \
    canalbancaire/famillebancaire/produitcompte/comptecourant.h \
    canalbancaire/famillebancaire/produitcompte/compteepargne.h \
    canalboursier/familleactions/familleactions.h \
    canalassurance/familleassurance/familleassurance.h \
    canalbancaire/famillebancaire/famillecartes.h \
    canalbancaire/famillebancaire/famillechequiers.h \
    canalbancaire/famillebancaire/famillecomptes.h \
    canalbancaire/famillebancaire/famillepret.h \
    canalbancaire/famillebancaire/produitpret/pretautomobile.h \
    canalbancaire/famillebancaire/produitpret/prethabitation.h \
    login.h

FORMS += \
    banksupervision.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Banksupervision.qrc

DISTFILES += \
    login1.png \
    reload.png
