#include "mainwindowqt.h"
#include "./ui_mainwindowqt.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <cmath>

//logique du jeu
mainwindowQT::mainwindowQT(QWidget *parent) : QMainWindow(parent), ui(new Ui::mainwindowQT) {
    ui->setupUi(this);
    setFixedSize(1000, 600); //taille de la fenetre

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        if (game == msg::game) {

            //mouvements des joueurs
            if (j1_up && j1_y > 0) j1_y -= velocity;
            if (j1_down && j1_y + 100 < height()) j1_y += velocity;
            if (j2_up && j2_y > 0) j2_y -= velocity;
            if (j2_down && j2_y + 100 < height()) j2_y += velocity;

            //deplacement de la balle
            balle_x += v_balle_x;
            balle_y += v_balle_y;

            //collision avec les bords
            if (balle_y <= 0 || balle_y + 20 >= height()) v_balle_y = -v_balle_y;

            //collision avec joueur 1
            if (balle_x <= 50 && balle_y + 20 >= j1_y && balle_y <= j1_y + 100) {
                v_balle_x = -v_balle_x;

                float center_paddle = j1_y + 50;
                float center_ball = balle_y + 10;
                float offset = (center_ball - center_paddle) / 50.0f;
                v_balle_y = offset * 8.0f;
            }

            //collision avec joueur 2
            if (balle_x + 20 >= 950 && balle_y + 20 >= j2_y && balle_y <= j2_y + 100) {
                v_balle_x = -v_balle_x;

                float center_paddle = j2_y + 50;
                float center_ball = balle_y + 10;
                float offset = (center_ball - center_paddle) / 50.0f;
                v_balle_y = offset * 8.0f;
            }

            //buts
            if (balle_x + 20 >= width()) {
                points_j1++;
                balle_x = 490;
                balle_y = 290;
                v_balle_x = -v_balle_x;
            } else if (balle_x <= 0) {
                points_j2++;
                balle_x = 490;
                balle_y = 290;
                v_balle_x = -v_balle_x;
            }

            //victoire
            if (points_j1 >= 10) {
                text = "joueur 1 a gagne!";
                points_j1 = 0; points_j2 = 0;
                j1_y = j2_y = 250;
                game = msg::victory;
                timer->stop();
            } else if (points_j2 >= 10) {
                text = "joueur 2 a gagne!";
                points_j1 = 0; points_j2 = 0;
                j1_y = j2_y = 250;
                game = msg::victory;
                timer->stop();
            }
        }

        update();
    });
    timer->start(16);
}

//fermeture de la fenetre
mainwindowQT::~mainwindowQT() {
    delete ui;
}

//affichage des joueurs et de la balle
void mainwindowQT::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    if (game == msg::menu) {
        painter.setPen(Qt::white);  //texte blanc
        painter.setFont(QFont("Arial", 50));
        painter.drawText(370, 100, "PONG 3");
        painter.setFont(QFont("Arial", 30));
        painter.drawText(250, 250, "Joueur 1: Z/S | Joueur 2: P/L");
        painter.drawText(330, 400, "Press SPACE to start");

    } else if (game == msg::game) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::white);

        painter.drawRect(50, j1_y, 10, 100); //joueur 1
        painter.drawRect(940, j2_y, 10, 100); //joueur 2
        painter.drawEllipse(balle_x, balle_y, 20, 20); //balle

        //affichage des scores
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 40));
        painter.drawText(width()/2 - 50, 50, QString::number(points_j1));
        painter.drawText(width()/2 + 20, 50, QString::number(points_j2));

    } else if (game == msg::victory) {
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 40));
        painter.drawText(width() / 2 - 200, height() / 2, text);
    }
}

//=====deplacements des joueurs=====

void mainwindowQT::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    if (game == msg::menu && key == Qt::Key_Space) {
        game = msg::game;
        timer->start(16);

    } else if (game == msg::game) {
        if (key == Qt::Key_Z) j1_up = true;
        if (key == Qt::Key_S) j1_down = true;
        if (key == Qt::Key_P) j2_up = true;
        if (key == Qt::Key_L) j2_down = true;

    } else if (game == msg::victory && key == Qt::Key_Space) {
        game = msg::menu;
        timer->stop();
        update();
    }
}

void mainwindowQT::keyReleaseEvent(QKeyEvent *event) {
    int key = event->key();
    if (key == Qt::Key_Z) j1_up = false;
    if (key == Qt::Key_S) j1_down = false;
    if (key == Qt::Key_P) j2_up = false;
    if (key == Qt::Key_L) j2_down = false;
}

//===================================

//magnus carlsen 2024-06
//v0.9
