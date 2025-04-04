#include "analyzer.h"

Analyzer::Analyzer(QWidget *parent) : QWidget(parent) {
    
    // Lets make a grid

    QGroupBox *group = new QGroupBox("Welcome to the insertion page");
    QVBoxLayout *group_layout = new QVBoxLayout(group);
    QPushButton *back_button = new QPushButton("Go Back");

    QGridLayout *grid = new QGridLayout();

    QLabel *wants_label = new QLabel("Wants");
    QLabel *needs_label = new QLabel("Needs");
    neccesities = new QLineEdit();
    wants = new QLineEdit();
    enter_needs = new QPushButton("Enter");
    enter_wants = new QPushButton("Enter");
    neccesities->setPlaceholderText("EX: 1.00");
    wants->setPlaceholderText("EX: 1.00");

    grid->addWidget(needs_label, 0, 0 );
    grid->addWidget(neccesities, 1, 0);
    grid->addWidget(wants_label, 2, 0);
    grid->addWidget(wants,3,0);
    grid->addWidget(enter_wants,3,1);
    grid->addWidget(enter_needs, 1,1);

    QWidget *grid_layout = new QWidget();
    grid_layout->setLayout(grid);
   
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    group_layout->addWidget(grid_layout);
    main_layout->addWidget(group);
    main_layout->addWidget(back_button);


    connect(enter_wants, &QPushButton::clicked, this, &Analyzer::InsertWants);
    connect(enter_needs, &QPushButton::clicked, this, &Analyzer::InsertNeeds);
    
    connect(this, &Analyzer::InsertWants, this, [&]() { InsertDataQuery("Wants"); });
    connect(this, &Analyzer::InsertNeeds, this, [&]() { InsertDataQuery("Needs"); });

    connect(back_button, &QPushButton::clicked, this, &Analyzer::GoToPage1);
}

void Analyzer::SetDatabaseName(QString &username) {database_name = username;}

bool Analyzer::CheckValidInput(QLineEdit *wants_or_needs) {
    QString user_input = wants_or_needs->text();
    QString final_num;
    int num_count;
    bool decimal_already_exists = false;
    
    // Maybe make a long &number to enter
    
    for (auto i = 0; i < user_input.size(); i++) {
        if (!user_input[i].isDigit()) {
            // INVALID 
            // DO SOMETHING
            return false;
        }

        if (user_input[i].isSpace()) {
            // INVALID 
            // DO SOMETHING
            return false;
        }

        if (user_input[i] == '.') {
            if (decimal_already_exists) {
                // INVALID 
                // DO SOMETHING
                return false;
            } else {
                decimal_already_exists = true;
            } 
        }

        if (user_input[i] == ',') {
            // Just make it skip
            continue;
        }

        final_num += user_input[i];
        wants_or_needs->setText(final_num);
    }

    return true;
}


void Analyzer::OnWantsClicked() {
    if (CheckValidInput(wants)) {
        emit InsertWants();
        wants->setPlaceholderText("EX: 1.00");
        wants->clear();
    }
}


void Analyzer::OnNeedsClicked() {
    if (CheckValidInput(neccesities)) {
        emit InsertNeeds();
        neccesities->setPlaceholderText("EX: 1.00");
        neccesities->clear();
    }
}

void Analyzer::InsertDataQuery(const QString &type) {

    QString number_str;
    if (type == "Wants") {
        number_str = wants->text();
    } else {
        number_str = neccesities->text();
    }

    double amount = number_str.toDouble();


}

