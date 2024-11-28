#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <KF5/KSyntaxHighlighting/KSyntaxHighlighting/SyntaxHighlighter>
#include <KSyntaxHighlighting/Repository>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    KSyntaxHighlighting::SyntaxHighlighter* mSyntax{nullptr};
    KSyntaxHighlighting::Repository repository;
};
#endif // MAINWINDOW_H
