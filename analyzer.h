#ifndef ANALYZER_H_
#define ANALYZER_H_

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <string>
#include <QResizeEvent>

// #include <QTSql>

class Analyzer : public QWidget {
	Q_OBJECT
	public:
		Analyzer(QWidget *parent = nullptr);
	signals:
		void GoToPage1();
    
    private:
        QPushButton *back_button;
    

};


#endif