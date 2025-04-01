#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    stack = new QStackedWidget(this);
    p1 = new HomePage();
    p2 = new Analyzer();

    stack->addWidget(p1);
    stack->addWidget(p2);

    connect(p1, &HomePage::GoToPage2, this, [&]() {
        stack->setCurrentIndex(1);
    });

    connect(p2, &Analyzer::GoToPage1, this, [&]() {
        stack->setCurrentIndex(0);
    });

    QVBoxLayout *main_layout = new QVBoxLayout(this);
    main_layout->addWidget(stack);
    setLayout(main_layout);
    setWindowTitle("Budget Tracker");
    resize(400,200);
}

