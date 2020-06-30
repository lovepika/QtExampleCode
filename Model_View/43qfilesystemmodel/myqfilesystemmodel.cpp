#include "myqfilesystemmodel.h"

#include <QInputDialog>
#include <QPushButton>
#include <qboxlayout.h>
#include <QMessageBox>
#include <QHeaderView>

MyQFileSystemModel::MyQFileSystemModel(QWidget *parent) : QWidget(parent)
{

    fileSystemModel = new QFileSystemModel;
    fileSystemModel->setRootPath(QDir::currentPath());

    treeView = new QTreeView(this);
    treeView->setModel(fileSystemModel);

    treeView->setRootIndex(fileSystemModel->index(QDir::currentPath()));

    treeView->header()->setStretchLastSection(true);
    treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
    treeView->header()->setSortIndicatorShown(true);
#if QT_VERSION >= 0x050000
    treeView->header()->setSectionsClickable(true);
#else
    treeView->header()->setClickable(true);
#endif

    QPushButton *mkdirButton = new QPushButton(tr("Make Directory..."), this);
    QPushButton *rmButton = new QPushButton(tr("Remove"), this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mkdirButton);
    buttonLayout->addWidget(rmButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(treeView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setWindowTitle("File System Model");

    connect(mkdirButton, SIGNAL(clicked()),
            this, SLOT(mkdir()));
    connect(rmButton, SIGNAL(clicked()),
            this, SLOT(rm()));
}

void MyQFileSystemModel::mkdir()
{
    QModelIndex index =  treeView->currentIndex();
    if (!index.isValid()){
        return;
    }
    bool isOk;
    QString dirName = QInputDialog::getText(this,
                                            tr("创建"),
                                            tr("新建文件夹"),
                                            QLineEdit::Normal,
                                            tr("未命名文件夹"),
                                            &isOk);

    if(!dirName.isEmpty() && isOk){
        if(fileSystemModel->mkdir(index,dirName).isValid()){
            QMessageBox::information(this,tr("提示"),"创建成功");
        }else {
            QMessageBox::information(this,tr("提示"),"创建文件夹失败");
        }
    }else {
        QMessageBox::information(this,tr("提示"),"创建文件夹失败");
    }
}

void MyQFileSystemModel::rm()
{
    QModelIndex index = treeView->currentIndex();
    if(!index.isValid()){
        return;
    }
    bool isOk;
    if(fileSystemModel->fileInfo(index).isDir()){
        isOk = fileSystemModel->rmdir(index);
    }else {
        isOk = fileSystemModel->remove(index);
    }
    if(!isOk){
        QMessageBox::information(this,tr("提示"),tr("%1 删除失败").arg(fileSystemModel->fileName(index)));
    }else{
        QMessageBox::information(this,tr("提示"),tr("%1 删除成功").arg(fileSystemModel->fileName(index)));
    }
}
