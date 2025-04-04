#ifndef HOMEPAGE_H_
#define HOMEPAGE_H_

#include <QChar>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <string>
#include <QResizeEvent>
#include <QGroupBox>
#include <QMessageBox>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


class HomePage : public QWidget {
	Q_OBJECT
	public:
        	HomePage(QWidget *parent = nullptr); 
                QString ShowUsername();
            
        signals:
                void GoToPage2();

        private slots:
                void OnButtonClicked();

        private:
                QLineEdit* user_input;
                QLineEdit* EnterUser();
                bool InputIsValid(QLineEdit* user_input);
};


#endif // HOMEPAGE_H_