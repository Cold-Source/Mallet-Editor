#ifndef MALLETBASE_H
#define MALLETBASE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class malletClass; }
QT_END_NAMESPACE

class mallet : public QMainWindow
{
    Q_OBJECT

public:
    mallet(QWidget *parent = nullptr);
    ~mallet();

private slots:
    void createNewFile();
    void openFiles();
    void showInfoDialog();

private:
    Ui::malletClass *ui;
};

#endif