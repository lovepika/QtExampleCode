#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>

// custom model
// 这是一个，简单的,非层次的,只读的模型
// 值得注意的是，我们重写的函数原本在基类中是public 还是protected

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    StringListModel(const QStringList &stringList,QObject *parent = nullptr);

    // rowcount()
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    // 获取数据项
    QVariant data(const QModelIndex &index,int role) const override;
    // header信息
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // 添加编辑功能实现data setData flags
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index,const QVariant &value,int role = Qt::EditRole) override;

    // 插入行和删除行功能需要重写这俩函数
    bool insertRows(int postion, int rows,const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int postion,int rows,const QModelIndex &index = QModelIndex()) override;

private:
    QStringList m_stringlist;

};


#endif // STRINGLISTMODEL_H
