#ifndef MAINWINDOWQT_H
#define MAINWINDOWQT_H

#include <QMainWindow>
#include <QString>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindowQT;
}
QT_END_NAMESPACE

class mainwindowQT : public QMainWindow {
    Q_OBJECT

public:
    mainwindowQT(QWidget *parent = nullptr);
    ~mainwindowQT();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    enum class msg {
        menu,
        game,
        victory
    };

    Ui::mainwindowQT *ui;

    QTimer *timer; //timer

    //positions Y des joueurs
    int j1_y = 250;
    int j2_y = 250;

    //position de la balle
    int balle_x = 480;
    int balle_y = 290;

    //vitesses
    int velocity = 8; //vitesse des joueurs
    int v_balle_x = 9; //vitesse de la balle X
    int v_balle_y = 9; //vitesse de la balle Y

    //deplacements
    bool j1_up = false;
    bool j1_down = false;
    bool j2_up = false;
    bool j2_down = false;

    //points
    int points_j1 = 0;
    int points_j2 = 0;

    //affichage des points
    QString text = "";
    msg game = msg::menu;
};

#endif //MAINWINDOWQT_H
