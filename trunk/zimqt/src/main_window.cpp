
#include <QtGui>

#include "main_window.h"

MainWindow::MainWindow()
{

}


void MainWindow::createActions()
 {
     newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
     newAct->setShortcut(tr("Ctrl+N"));
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

     openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
     openAct->setShortcut(tr("Ctrl+O"));
     openAct->setStatusTip(tr("Open an existing file"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
     saveAct->setShortcut(tr("Ctrl+S"));
     saveAct->setStatusTip(tr("Save the document to disk"));
     connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

     saveAsAct = new QAction(tr("Save &As..."), this);
     saveAsAct->setStatusTip(tr("Save the document under a new name"));
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     closeAct = new QAction(tr("&Close"), this);
     closeAct->setShortcut(tr("Ctrl+W"));
     closeAct->setStatusTip(tr("Close this window"));
     connect(closeAct, SIGNAL(triggered()), this, SLOT(close()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcut(tr("Ctrl+Q"));
     exitAct->setStatusTip(tr("Exit the application"));
     connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

     cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
     cutAct->setShortcut(tr("Ctrl+X"));
     cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                             "clipboard"));
     connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

     copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
     copyAct->setShortcut(tr("Ctrl+C"));
     copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                              "clipboard"));
     connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

     pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
     pasteAct->setShortcut(tr("Ctrl+V"));
     pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                               "selection"));
     connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

     aboutAct = new QAction(tr("&About"), this);
     aboutAct->setStatusTip(tr("Show the application's About box"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("About &Qt"), this);
     aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

     cutAct->setEnabled(false);
     copyAct->setEnabled(false);
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             cutAct, SLOT(setEnabled(bool)));
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             copyAct, SLOT(setEnabled(bool)));
 }