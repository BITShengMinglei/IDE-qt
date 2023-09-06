#ifndef TREE_H
#define TREE_H

#include <QMainWindow>
#include"QTreeWidgetItem"
#include"QFileInfoList"
#include"QTranslator"


QT_BEGIN_NAMESPACE
namespace Ui { class Tree; }
QT_END_NAMESPACE

class Tree : public QMainWindow
{
    Q_OBJECT

public:
    Tree(QWidget *parent = nullptr);
    ~Tree();

    QTreeWidgetItem* root;
    QString rootPath;
    QFileInfoList allfile(QTreeWidgetItem *parent, QString path);
    QTreeWidget *treeWidget;
    QString filePath;

public slots:
    void DC(QTreeWidgetItem *item, int column);

signals:
    void DCC();
};
#endif // MAINWINDOW_H

