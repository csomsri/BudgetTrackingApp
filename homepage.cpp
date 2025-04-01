#include "homepage.h"
HomePage::HomePage(QWidget *parent) : QWidget(parent) {
    QGroupBox *group = new QGroupBox("Welcome to the Homepage");  // This shows the title
    QVBoxLayout *group_layout = new QVBoxLayout(group);
    
    QLabel *label = new QLabel("Enter your Username");
    QLabel *instruction = new QLabel("*Please make it have at least 1 number and at least 12 characters long");
    QPushButton *forward_button = new QPushButton("Analyze your Budget");
    
    user_input = EnterUser();
    


    group_layout->addWidget(label);
    group_layout->addWidget(instruction);
    group_layout->addWidget(user_input);
    group_layout->addWidget(forward_button);
    
    // Now set this as the layout of your widget
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    main_layout->addWidget(group);    
    // Connect your button
    connect(forward_button, &QPushButton::clicked, this, &HomePage::OnButtonClicked);

    
} 


QLineEdit* HomePage::EnterUser() {
    QLineEdit *user_input = new QLineEdit();
    user_input->setPlaceholderText("EX: USERNAME123");
    return user_input;
}

bool HomePage::InputIsValid(QLineEdit* user_input) {
    QString input = user_input->text();
    if (input.isEmpty()) {
        QMessageBox::warning(this, "Error", "please enter a username");    
        return false;
    }

    // NOTE TO SELF
    // We can make another page just for this make it cleaner instead of a pop up

    return true;
}

void HomePage::OnButtonClicked() {
    if (InputIsValid(user_input)) {
        emit GoToPage2();
    }
}


