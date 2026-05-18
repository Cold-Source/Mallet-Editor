#ifndef MALLETINFODIALOG_H
#define MALLETINFODIALOG_H

#include <QDialog>

namespace Ui {
    class Malletinfo;
}

class MalletInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MalletInfoDialog(QWidget* parent = nullptr);
    ~MalletInfoDialog();

private:
    Ui::Malletinfo* ui;
};

#endif