#ifndef ANALYZER_H_
#define ANALYZER_H_

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

class Analyzer : public QWidget {
	Q_OBJECT
	public:
		Analyzer(QWidget *parent = nullptr);
        void SetDatabaseName(QString &username);



	signals:
		void GoToPage1();
        void InsertNeeds();
        void InsertWants();
        

    private slots:
        void OnWantsClicked();
        void OnNeedsClicked();
    
    private:
        QPushButton *back_button;
        QPushButton *enter_needs;
        QPushButton *enter_wants;
        QLineEdit *neccesities;
        QLineEdit *wants;
        QString database_name;
        void InsertDataQuery(const QString &type);
        bool CheckValidInput(QLineEdit *wants_or_needs);

    

};


#endif