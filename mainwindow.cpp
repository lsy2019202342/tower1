#include "mainwindow.h"
#include <QDebug>
#include "globalstruct.h"       //选择框按钮全局结构
#include <cmath>               //数学
#include "greenturret.h"        //绿色防御塔类
#include "fireturret.h"         //火防御塔类
#include "lightturret.h"        //光炮防御塔类
#include "bigturret.h"          //大炮防御塔类
#include <QPushButton>



MainWindow::MainWindow(int LevelNumber) : LevelNumber(LevelNumber)
{
    //设置固定窗口大小
    setFixedSize(1280, 1040);

    //设置标题
    setWindowTitle("游戏界面");

    //提示胜利标签
    QLabel *victorylable = new QLabel(this);
    victorylable->move(176, 180);
    victorylable->setFont(QFont("楷体", 110));
    victorylable->setText(QString("游戏胜利"));
    victorylable->hide();

    QTimer* timer2 = new QTimer(this);      //用于插入怪物定时器
    timer2->start(2000);

    connect(timer2,&QTimer::timeout,[=]()
    {
        switch (LevelNumber) {
        case 0:
        {
            //设置路径点
            CoorStr* Waypointarr1[] = {new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)), new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)), new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(20), X40(5)), new CoorStr(X40(14), X40(5)), new CoorStr(X40(14), X40(9)), new CoorStr(X40(8), X40(9)), new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)),
                                             new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)), new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)}; //最后的路径点设为家
            //怪物的四个起始点
            CoorStr staco[] = {CoorStr(8, 0), CoorStr(20, 0), CoorStr(8, -1), CoorStr(20, -1)};

            //每条路径的结点个数
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);   //使用预设的两条路产生怪物方案

            break;
        }
        case 1:
        {
            //设置路径点
            CoorStr* Waypointarr1[] = {new CoorStr(X40(4), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(11), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};

                                      //怪物的四个起始点
            CoorStr staco[] = {CoorStr(4, 0), CoorStr(11, 0), CoorStr(4, -1), CoorStr(11, -1)};

            //每条路径的结点个数
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);   //使用预设的两条路产生怪物方案
            break;
        }

        case 2:
        {
            //设置路径点
            CoorStr* Waypointarr1[] = {new CoorStr(X40(12), X40(9)), new CoorStr(X40(8), X40(9)), new CoorStr(X40(8), X40(0)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(12), X40(9)), new CoorStr(X40(16), X40(9)), new CoorStr(X40(16), X40(0)), new CoorStr(homecoor->x, homecoor->y)};

            //怪物的四个起始点
            CoorStr staco[] = {CoorStr(12, 16), CoorStr(12, 16), CoorStr(12, 17), CoorStr(12, 18)};

            //每条路径的结点个数
            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);   //使用预设的两条路的产生怪物方案
            break;
        }
        }
    });
