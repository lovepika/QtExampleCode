
#include <QApplication>
#include <QTableView>
#include <QListView>
#include "stringlistmodel.h"

int main(int argc,char *argv[]){

    QApplication app(argc,argv);
    // 准备数据
    QStringList list;
    list << "a"<< "b"<<"c" << "d"<< "e";

    // 使用自定义的模型，并把数据源给模型
    StringListModel model(list);

    // QListView作为显示
    QListView listView;
    listView.setModel(&model);
    listView.show();

    // QTreeView作为显示
    QTableView tableVeiw;
    tableVeiw.setModel(&model);
    tableVeiw.show();

    model.insertRows(1,2); // TODO BUG
    model.removeRows(0,1);
    
    return app.exec();
}
