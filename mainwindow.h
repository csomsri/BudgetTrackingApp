#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

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
#include "analyzer.h"
#include "homepage.h"

/*
    Making the homepage by an inherited class from
    the QWidget
*/

class MainWindow : public QWidget {
	Q_OBJECT // Incase I use QT thingy, otherwise signals
    	private:
        	//const std::string title_str;
        	QStackedWidget *stack; // for each page
        	// Make a HomePage
        	HomePage *p1;
       		// Make a Analyze Page
        	Analyzer *p2;
        	// Make a Data Entry Page? (Maybe in homepage)
        

        
        
    	public:
            MainWindow(QWidget *parent);


};

#endif // MAINWINDOW_H_