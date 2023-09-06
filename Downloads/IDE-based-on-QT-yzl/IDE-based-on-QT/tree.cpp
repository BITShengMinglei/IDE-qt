#include "tree.h"
#include "ui_tree.h"
#include"QTreeWidgetItem"
#include"QFileInfoList"
#include"QDir"
#include"QDebug"
#include <QHBoxLayout>
#include <QFileInfo>
#include <QtGui/QGuiApplication>
#include <QUrl>
#include <QDesktopServices>
#include <Qsci/qsciscintilla.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include <QMenuBar>
#include"QTreeWidgetItem"
#include <QToolBar>
#include "QFileInfoList"
#include <QIcon>
#include <QLabel>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QPushButton>
#include <QTextCursor>
#include <QClipboard>
#include <QLineEdit>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QFontDialog>
#include <QTextCodec>   // 字符编码转换头文件
#include <QDebug>
#include <string.h>
#include<QSplitter>
#include <QFileInfo>
#include <QtGui/QGuiApplication>
#include <QUrl>
#include <QDesktopServices>

Tree::Tree(QWidget *parent)
    : QMainWindow(parent)
{
    treeWidget = new QTreeWidget(this);

    QStringList headers;
    headers << "Name";
    treeWidget->setHeaderLabels(headers);
    treeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // 设置最小最大宽度
    treeWidget->setMinimumWidth(350);
    treeWidget->setMaximumWidth(550);

    treeWidget->setMinimumHeight(950);
    root = new QTreeWidgetItem(treeWidget);
    root->setIcon(0, QIcon(":/icon/icon/openfile.png"));
    root->setText(0, "欢迎您使用Editor");
    rootPath = "欢迎您使用Editor";
    QFileInfoList fileLists = allfile(root, rootPath);
    connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &Tree::DC);
    filePath = "null";
}


Tree::~Tree()
{

}

QFileInfoList Tree::allfile(QTreeWidgetItem *root,QString path)         //参数为主函数中添加的item和路径名
{
    qDebug()<<'hello';
    QDir dir(path);          //遍历各级子目录 "D:/first"
    QDir dir_file(path);    //遍历子目录中所有文件
    //先遍历文件夹 添加进widget
    QFileInfoList file_list=dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);   //获取当前所有目录 QDir::Dirs 0x001 列出目录；


    for(int i = 0; i != folder_list.size(); i++)         //自动递归添加各目录到上一级目录
    {

             QString namepath = folder_list.at(i).absoluteFilePath();    //获取路径
             QFileInfo folderinfo= folder_list.at(i);
             QString name=folderinfo.fileName();      //获取目录名
             QTreeWidgetItem* childroot = new QTreeWidgetItem(QStringList()<<name);
             childroot->setIcon(0, QIcon(":/icon/icon/openfile.png"));
             root->addChild(childroot);
             childroot->setText(0,name);
             root->addChild(childroot);              //将当前目录添加成path的子项
             QFileInfoList child_file_list = allfile(childroot,namepath);          //进行递归 递归这个文件夹
             file_list.append(child_file_list);
             file_list.append(name);

     }
    /*添加path路径文件*/

    dir_file.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);        //获取当前所有文件
    dir_file.setSorting(QDir::Name);//
    QFileInfoList list_file = dir_file.entryInfoList();
    for (int i = 0; i < list_file.size(); ++i) {       //将当前目录中所有文件添加到treewidget中
        QFileInfo fileInfo = list_file.at(i);
        QString name2=fileInfo.fileName();
        QTreeWidgetItem* child = new QTreeWidgetItem(QStringList()<<name2);
        child->setIcon(0, QIcon(":/icon/icon/newfile.png"));	//这里只是用了D盘下一张图片 可以随意更改
        child->setText(0,name2);
        root->addChild(child);  //allfile传入的root下面加入

    }
//    root->setText(0, "D:/niumo");
    return file_list;
}

void Tree::DC(QTreeWidgetItem *item, int column)
{

    QString path1 = item->text(column);
    QTreeWidgetItem *parent = item->parent();
    while (parent != nullptr)
    {
        path1.prepend(parent->text(column) + "/");
        parent = parent->parent();
    }
    filePath = path1;
//    qDebug()<<filePath;
    emit DCC();
    qDebug()<<filePath;
    return;
}

