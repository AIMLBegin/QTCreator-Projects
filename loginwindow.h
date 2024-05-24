#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSqlDatabase>
#include <QString>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void login();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QLabel *statusLabel;
    QSqlDatabase db;
};

#endif // LOGINWINDOW_H
