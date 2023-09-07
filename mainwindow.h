#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <random>
#include <queue>
#include <QTimer>
//#include <QSound>

#define MINW 1024
#define MIXH 768
#define MAXROSES 28

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int width,height;
    QPixmap roses[999];
    QPoint rose_xy[999];
    int rose_speed[999];
    int rosesinthescreen = 0;
    std::queue<int> view;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event) override;
    void init();
//    void SoundShow();

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    Ui::MainWindow *ui;
    bool p = true;
    int num = 0;
    QVector<QString> salutations = {
        "难忘记，您的谆谆教诲;","难忘记，您的夸奖鼓励;","难忘记，您的执着不悔;","难忘记，您的伟大艰辛。","今天教师节，","我想说声谢谢您，祝您快乐幸福!",
        "横式竖式，算不尽老师的爱;","字里行间，装不下老师的情;","一方黑板，是您耕耘的土地;","一寸粉笔，写下真理消磨自己。","教师节，道一声：","老师辛苦了!",
        "一支粉笔，能点拨知识王国的迷津;","三尺教鞭，指点通理想的道路;","一块黑板，记下您们无限深情;","一个讲台，辉映着您的艰辛。教师节快乐!",
        "假如我能搏击蓝天，那是您给了我腾飞的翅膀;","假如我是不灭的火炬，那是您给了我青春的光亮!","在您的节日里，愿我的祝福化成一束不凋的鲜花，给您的生活带来无尽的芬芳!",
        "时九月，教师节，","有收获，心意满，","弟子心，念师恩，","无以报，师情深，","学致用，理致奉，","更努力，报恩情，","愿老师，节日好，","日日好，开心笑，没烦恼!",
        "一根粉笔教我读书识字;","一段话语令我懂得做人;","一份关切伴我健康成长;","如今虽远在天涯，师恩却在我心，请让我深深的祝福您：","老师，您辛苦了!",
        "忘不了，您在三尺讲台辛勤耕耘的身影;","忘不了，您在课堂上孜孜不倦的叮咛;","忘不了，您在教室里神采飞扬的激情。教师节到了，祝您节日快乐!",
        "心如海洋宽广，爱如骄阳辉煌，情如亲情大爱;","这就是您，我敬爱的老师!教师节到了，学生祝愿送上，愿您快乐健康，幸福永享!",
        "您在三尺讲台上放飞了一群群翱翔的鸟儿，您用辛勤的汗水扶正了学生脚下的道路，耕耘出桃李满园芬芳四溢，您用默默的奉献点燃了世界的光明，教师节来到了，学生要对老师说一句：老师您辛苦了。",
        "一支粉笔，两袖清风，","三尺讲台，四季寒暑，","五更鸡啼，六艺兼修，","七步之才，八方桃李，","九州子弟，十分可敬。","老师，教师节到了，祝您节日快乐!",
        "漫步在人生的道路，任凭时光之泉水慢慢流淌，","追溯着源头您慈祥的目光，依稀回味着过去的模样，","您的教诲永生难忘，","教师节，祝愿您快乐健康，幸福满堂。",
        "青春，是您的誓言;","讲台，是您的舞台;","黑板，是您的伙伴;","粉笔，是您的助手;","知识，是您的财富;","学生，是您的荣光。9.10教师节，对着敬爱的老师说声：您辛苦了!祝您节日快乐，福寿安康!",
        "师者，您也。在人生的道理上，您为我指引方向;","在知识的海洋里取经，您为我降妖除魔;","有了您的教导，我才能修成正果。弟子无以回报，只有奉上节日最真挚的祝福：教师节快乐!"
    };
};
#endif // MAINWINDOW_H
