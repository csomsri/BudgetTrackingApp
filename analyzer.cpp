#include "analyzer.h"

Analyzer::Analyzer(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Welcome to the analye page");
    QPushButton *back_button = new QPushButton("Go Back");

    layout->addWidget(label);
    layout->addWidget(back_button);
    connect(back_button, &QPushButton::clicked, this, &Analyzer::GoToPage1);

}
