#ifndef MYQFILESYSTEMMODEL_H
#define MYQFILESYSTEMMODEL_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>

class MyQFileSystemModel : public QWidget
{
    Q_OBJECT
public:
    explicit MyQFileSystemModel(QWidget *parent = nullptr);

signals:

public slots:

private:
    QFileSystemModel *fileSystemModel;
    QTreeView *treeView;

private slots:
    void mkdir();
    void rm();
};

#endif // MYQFILESYSTEMMODEL_H
