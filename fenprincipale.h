#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QMainWindow>
#include <QtWidgets>
#include <QList>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
    public:
    //explicit FenPrincipale(QWidget *parent = nullptr);
    FenPrincipale(int x, int y);

    private:
    QString *fileName;
    QTextEdit *textEdit;
    QString mot;
    QString texte;
    QString curFile;
    QLabel* imageLabel;

    public slots:
    bool sauvegarder();
    bool saveFile(const QString &fileName);
    void charger();
    void saisie();
    void affichageNC();
    void affichageNPI();


    signals:

};

#endif // FENPRINCIPALE_H
