#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>


int main(int argc,char *argv[]){

    QApplication app(argc,argv);

    // 创建文件系统模型
    QFileSystemModel model;
    // 指定要监视的目录
    model.setRootPath(QDir::homePath());

    // QTreeView  创建树形视图
    QTreeView tree;
    // 为视图指定模型
    tree.setModel(&model);
    // 指定根索引,要展示到视图的索引
    tree.setRootIndex(model.index(QDir::homePath()));
    // [virtual slot] void QAbstractItemView::setRootIndex(const QModelIndex &index)
    // Sets the root item to the item at the given index.


    // QListView 创建列表视图
    QListView listView;
    listView.setModel(&model);
    listView.setRootIndex(model.index(QDir::currentPath()));

    // show view
    tree.show();
    listView.show();

    return app.exec();
}
