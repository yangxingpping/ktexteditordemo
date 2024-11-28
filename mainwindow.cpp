#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <KTextEditor/Document>
#include <KTextEditor/Editor>
#include <KTextEditor/View>
#include <KF5/KSyntaxHighlighting/KSyntaxHighlighting/Definition>

#include <QVBoxLayout>
#include <assert.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto editor = KTextEditor::Editor::instance();
    auto doc = editor->createDocument(this);
    doc->setText("hello\nworld");
    auto view = doc->createView(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(view);

    
    static KSyntaxHighlighting::Definition  def = repository.definitionForFileName("../gcode.xml");
    assert(def.isValid());
	mSyntax = new KSyntaxHighlighting::SyntaxHighlighter(view->document());
    mSyntax->setDefinition(def);
    ui->centralwidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
