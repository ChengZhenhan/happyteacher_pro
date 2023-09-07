#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTime>
#include <qrandom.h>
#include <unistd.h>
//#include <QMovie>
#include <QSound>
//#include <QSoundEffect>
//#include <QtMultimedia>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTimer(1000);
    init();
    QSound::play(":/music/output.wav");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing, true);
    if( p ) {
        num++;
        p = false;
    }
    if(num < salutations.size()) {
        QFont font("宋体",48,QFont::Bold,true);
        font.setUnderline(true);
        font.setOverline(true);
        font.setLetterSpacing(QFont::AbsoluteSpacing,20);
        paint.setPen(Qt::red);
        paint.setFont(font);
        QRect textRect = paint.boundingRect(QRect(), Qt::AlignCenter, salutations[num].toStdString().c_str());
//        if(textRect.width() >= width) {
////            QFontMetrics fontMetrics(font());
////            int fontWidth = fontMetrics.width(" "); // 获取字体的平均宽度（以空格字符为例）
////            // 计算字体应该缩小的比例
////            int fontSize = font().pointSize();
////            double scaleFactor = (double)windowWidth / fontWidth;
////            fontSize = qRound(fontSize * scaleFactor);
//            font.setPointSize(font.pointSize() - 12);
//        }
//        while(textRect.width() >= width && font.pointSize() >= 0) {
//            font.setPointSize(font.pointSize() - 2);
//            textRect = paint.boundingRect(QRect(), Qt::AlignCenter, salutations[num].toStdString().c_str());
//        }
        paint.drawText(width/2-textRect.width() / 2,height/2 - textRect.height() / 2,tr(salutations[num].toStdString().c_str()));
    }
    if(rosesinthescreen <= 520) {
        for (int i = 0;i < MAXROSES; i++) {
    //        if(rosesinthescreen==MAXROSES) {
    //            break;
    //        }
    //        rose_xy[view.front()].setX(qrand()%MINW);
    //        rose_xy[view.front()].setY(0-qrand()%MIXH);
            QRect famerect = rect();
            paint.drawPixmap(rose_xy[i],roses[i],famerect);
    //        view.push(view.front());
    //        view.pop();
    //        rosesinthescreen++;
        }
        for (int i = 0;i<MAXROSES;i++) {
            if(rose_xy[i].ry() > MIXH) {
                rosesinthescreen++;
                rose_xy[i].setX(rand()%width);
                rose_xy[i].setY(0-rand()%height);
    //            rosesinthescreen--;
                continue;
            }
            rose_xy[i].setY(rose_xy[i].ry()+rose_speed[i]);
        }
        usleep(400);
    }
    else {
        QFont font("宋体",48,QFont::Bold,true);
        font.setUnderline(true);
        font.setOverline(true);
        font.setLetterSpacing(QFont::AbsoluteSpacing,20);
        paint.setPen(Qt::red);
        paint.setFont(font);
        QRect textRect = paint.boundingRect(QRect(), Qt::AlignCenter, "老师，您辛苦了！");
        paint.drawText(width/2-textRect.width() / 2,height/2 - textRect.height() / 2,tr("老师，您辛苦了！"));
    }
    update();
}

void MainWindow::init() {
    setWindowTitle("祝老师教师节快乐");
    setMinimumSize(MINW,MIXH);
    width = window()->width();
    height = window()->height();
    QTime time=QTime::currentTime();
    srand(time.msec()+time.second());
    for (int i = 0;i < MAXROSES;i++) {
        QString rn=QString(":/image/rose_%1.png").arg(rand()%4+1);
        roses[i]=QPixmap(rn).scaled(72,72);
//        rose_xy[i].setX(qrand()%MINW);
//        rose_xy[i].setY(0-qrand()%MIXH);
        rose_speed[i] = 1;
//        view.push(i);
    }
}

void MainWindow::timerEvent(QTimerEvent *event) {
    width = window()->width();
    height = window()->height();
    p = true;
    return;
}


//void MainWindow::SoundShow() {
//    QSound *music=new QSound(filepath.c_str(),this);
//    music->play();
//    if(loop)
//        music->setLoops(400);
//}
