#include "homepage.h"
HomePage::HomePage(QWidget *parent) : QWidget(parent) {
    QGroupBox *group = new QGroupBox("Welcome to the Homepage");  // This shows the title
    QVBoxLayout *group_layout = new QVBoxLayout(group);
    
    QLabel *label = new QLabel("Enter your Username");
    QLabel *instruction = new QLabel("*Must have 1 digit\n*Must have 10 or less characters\n*Must contain one letter\n*No empty space");
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
    user_input->setPlaceholderText("EX: USERNAME12");
    return user_input;
}

bool HomePage::InputIsValid(QLineEdit* user_input) {
    QString input = user_input->text();
    if (input.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a username");    
        return false;
    }

    if (input.size() > 10) {
        QMessageBox::warning(this, "Error", "Please enter a username with 10 characters");
        return false;
    }
    
    int number_count = 0;
    int char_count = 0;
    int space_count;
    for (auto i = 0; i < input.size(); i++) {
        if (input[i].isDigit()) {
            number_count++;
        }

        if (input[i].isLetter()) {
            char_count++;
        }

        if (input[i].isSpace()) {
            QMessageBox::warning(this, "Error", "Please enter a username with no empty space");
            return false;
        }
    }

    if (number_count < 1) {
        QMessageBox::warning(this, "Error", "Please enter a username with atleast 1 digit");
        return false;
    }

    if (char_count < 1) {
        QMessageBox::warning(this, "Error", "Please enter a username with atleast 1 letter");
        return false;
    }

    // NOTE TO SELF
    // We can make another page just for this make it cleaner instead of a pop up
    
    // If user name already exist perhaps put password? or make a second thing where its like enter password
    // but for now lets do a system where there is no passwords at all

    return true;
}

void HomePage::OnButtonClicked() {
    if (InputIsValid(user_input)) {
        emit GoToPage2();
    }
}

QString HomePage::ShowUsername() {
    QString username = user_input->text();
    return username;
}

