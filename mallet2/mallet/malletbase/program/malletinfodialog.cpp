#include "malletinfodialog.h"
#include "ui_mallethelp.h"

MalletInfoDialog::MalletInfoDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Malletinfo)
{
}

MalletInfoDialog::~MalletInfoDialog()
{
    delete ui;
}