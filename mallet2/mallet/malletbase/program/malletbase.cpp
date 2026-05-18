#include "malletbase.h"
#include "ui_mallet.h"
#include <QFileDialog>
#include "ui_mallethelp.h"
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

mallet::mallet(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::malletClass)
{
    ui->setupUi(this);

    connect(ui->actionNew_File, &QAction::triggered, this, &mallet::createNewFile);
    connect(ui->actionOpen_Files, &QAction::triggered, this, &mallet::openFiles);
    connect(ui->actionInfo_Mallet_editor, &QAction::triggered, this, &mallet::showInfoDialog);
}

mallet::~mallet()
{
    delete ui;
}

void mallet::createNewFile()
{

    QString filePath = QFileDialog::getSaveFileName(this,
        "Create New File",
        QDir::homePath(),
        "Text files (*.txt);;All files (*.*)");

    if (filePath.isEmpty())
        return;

    QFileInfo fileInfo(filePath);
    QString directoryPath = fileInfo.absolutePath();

    QDir dir;
    if (!dir.mkpath(directoryPath)) {
        QMessageBox::critical(this, "Error", "Cannot create folder: " + directoryPath);
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot create file: " + file.errorString());
        return;
    }

    file.write("Hello from Mallet Editor");
    file.close();

    QMessageBox::information(this, "Success", "File created:\n" + filePath);
}

void mallet::openFiles()
{
    QStringList files = QFileDialog::getOpenFileNames(this, "Open Files", QDir::homePath(), "Text files (*.txt)");
    if (files.isEmpty())
        return;
    QMessageBox::information(this, "Opened", files.join("\n"));
}


void mallet::showInfoDialog()
{
    QDialog dialog(this);
    Ui::Malletinfo ui_help;
    ui_help.setupUi(&dialog);

    dialog.exec();
}

