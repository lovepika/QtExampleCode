#include "stringlistmodel.h"

StringListModel::StringListModel(const QStringList &stringList,QObject *parent)
    :QAbstractListModel (parent),m_stringlist(stringList)
{
}
/**
 * @brief StringListModel::rowCount
 * @param parent
 * @return
 */
int StringListModel::rowCount(const QModelIndex &parent) const
{
    return m_stringlist.count();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    if(index.row() >= m_stringlist.size()){
        return QVariant();
    }
// 添加编辑功能修改了这个
//    if(role == Qt::DisplayRole){
//        return m_stringlist.at(index.row()); // return index's row number
//    }else {
//        return QVariant();
//    }

    // 添加编辑功能添加 || role == Qt::EditRole
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        return m_stringlist.at(index.row());
    }else {
        return QVariant();
    }
}

//自定义header信息
//像QTreeView和QTableView等一些视图,在显示项目数据的同时还会显示标头。这里实现了在标头中显示行号和列号。
//并不是所有的视图都会显示标头，一些视图会隐藏它们。不过,还是建议通过headerData()函数来提供数据的相关信息。
QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    if(orientation == Qt::Horizontal){
        return QString("Cloume %1").arg(section);
    }else {
        return QString("Row %1").arg(section);
    }
}
/**
 * @brief StringListModel::flags
 * @param index
 * @return
 */
Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid()){
        return Qt::ItemIsEnabled;
    }
    // TODO
    return QAbstractItemModel::flags(index) |  Qt::ItemIsEditable;

}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole){
        m_stringlist.replace(index.row(),value.toString());
        // TODO
        emit dataChanged(index,index);
        return true;
    }
    return false;
}
/**
 * @brief StringListModel::insertRows
 * @param postion
 * @param rows
 * @param index
 * @return
 */
bool StringListModel::insertRows(int postion, int rows, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(),postion,postion+rows-1);
    for (int row = 0;row < rows ; ++rows) {
        m_stringlist.insert(postion,"");
    }
    endInsertRows();
    return true;
}
/**
 * @brief StringListModel::removeRows
 * @param postion
 * @param rows
 * @param index
 * @return
 */
bool StringListModel::removeRows(int postion, int rows, const QModelIndex &index)
{
   beginRemoveRows(QModelIndex(),postion,postion+rows-1);
   for (int row = 0; row <rows ; ++row) {
        m_stringlist.removeAt(postion);
   }
   endRemoveRows();
   return true;
}
