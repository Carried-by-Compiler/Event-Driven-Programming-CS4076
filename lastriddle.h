#ifndef LASTRIDDLE_H
#define LASTRIDDLE_H

#include <QDialog>

namespace Ui {
class LastRiddle;
}

class LastRiddle : public QDialog
{
    Q_OBJECT

public:
    explicit LastRiddle(QWidget *parent = 0);
    LastRiddle(QWidget *parent, QString *);
    ~LastRiddle();

private slots:
    void on_riddleSubmit_clicked();

    void on_riddleAnswer_returnPressed();

private:
    Ui::LastRiddle *ui;
    QString *a;
};

#endif // LASTRIDDLE_H
