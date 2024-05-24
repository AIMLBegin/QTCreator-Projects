#include "loginwindow.h"
#include <QVBoxLayout>    // Include QVBoxLayout for layout
#include <QSqlQuery>      // Include QSqlQuery for database queries
#include <QSqlError>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    usernameEdit(new QLineEdit(this)),
    passwordEdit(new QLineEdit(this)),
    loginButton(new QPushButton("Login", this)),
    statusLabel(new QLabel(this)),
    db(QSqlDatabase::addDatabase("QSQLITE"))
{
    // Set up UI elements
    usernameEdit->setPlaceholderText("Username");
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setEchoMode(QLineEdit::Password);  // Hide password input

    // Create a layout and add widgets
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);
    layout->addWidget(statusLabel);

    // Set the layout for the main widget
    setLayout(layout);

    // Connect the login button's clicked signal to the login slot
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::login);

    // Open the database connection (assuming it's an SQLite database)
    db.setDatabaseName("/home/vision/ex1.db");  // Path to your database file

    if (!db.open()) {
        statusLabel->setText("Failed to connect to the database.");
        qDebug() << "Database error: " << db.lastError().text();
    }
}

void LoginWindow::login() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        statusLabel->setText("Please enter both username and password.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) {
            statusLabel->setText("Login successful.");
            // Handle successful login (e.g., open a new window or change the view)
        } else {
            statusLabel->setText("Invalid username or password.");
        }
    } else {
        statusLabel->setText("Query execution failed.");
        qDebug() << "Query error: " << query.lastError().text();
    }
}
