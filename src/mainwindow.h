#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtSql>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include <QFileDialog>
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QInputDialog>
#include <QPainter>
#include <QDateTime>
#include <QCloseEvent>


//Printer
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QPrintDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_actionAbout_triggered();

    void on_lineEdit_studsearch_textChanged(const QString &arg1);

    void on_lineEdit_studname_editingFinished();

    void on_actionSave_triggered();

    void setupDB();

    void starRate(QPushButton *p);

    void on_pb_star_pm_gr_1_clicked();

    void on_pb_star_as_gr_1_clicked();

    void on_pb_star_to_gr_1_clicked();

    void on_pb_star_li_gr_1_clicked();

    void on_pb_star_sd_gr_1_clicked();

    void on_pb_star_rt_gr_1_clicked();

    void on_pb_star_rhr_gr_1_clicked();

    void on_pb_star_pp_gr_1_clicked();

    void on_pb_star_re_gr_1_clicked();

    void on_pb_star_pr_gr_1_clicked();

    void on_pb_star_ecr_gr_1_clicked();

    void on_pb_star_fr_gr_1_clicked();

    void on_pb_star_rl_gr_1_clicked();

    void on_pb_star_nu_gr_1_clicked();

    void on_pb_star_pm_gr_2_clicked();

    void on_pb_star_as_gr_2_clicked();

    void on_pb_star_to_gr_2_clicked();

    void on_pb_star_li_gr_2_clicked();

    void on_pb_star_sd_gr_2_clicked();

    void on_pb_star_rt_gr_2_clicked();

    void on_pb_star_rhr_gr_2_clicked();

    void on_pb_star_pp_gr_2_clicked();

    void on_pb_star_re_gr_2_clicked();

    void on_pb_star_pr_gr_2_clicked();

    void on_pb_star_ecr_gr_2_clicked();

    void on_pb_star_fr_gr_2_clicked();

    void on_pb_star_rl_gr_2_clicked();

    void on_pb_star_nu_gr_2_clicked();

    void on_pb_star_pm_gr_3_clicked();

    void on_pb_star_as_gr_3_clicked();

    void on_pb_star_to_gr_3_clicked();

    void on_pb_star_li_gr_3_clicked();

    void on_pb_star_sd_gr_3_clicked();

    void on_pb_star_rt_gr_3_clicked();

    void on_pb_star_rhr_gr_3_clicked();

    void on_pb_star_pp_gr_3_clicked();

    void on_pb_star_re_gr_3_clicked();

    void on_pb_star_pr_gr_3_clicked();

    void on_pb_star_ecr_gr_3_clicked();

    void on_pb_star_fr_gr_3_clicked();

    void on_pb_star_rl_gr_3_clicked();

    void on_pb_star_nu_gr_3_clicked();

    void on_pb_star_pm_gr_4_clicked();

    void on_pb_star_as_gr_4_clicked();

    void on_pb_star_to_gr_4_clicked();

    void on_pb_star_li_gr_4_clicked();

    void on_pb_star_sd_gr_4_clicked();

    void on_pb_star_rt_gr_4_clicked();

    void on_pb_star_rhr_gr_4_clicked();

    void on_pb_star_pp_gr_4_clicked();

    void on_pb_star_re_gr_4_clicked();

    void on_pb_star_pr_gr_4_clicked();

    void on_pb_star_ecr_gr_4_clicked();

    void on_pb_star_fr_gr_4_clicked();

    void on_pb_star_rl_gr_4_clicked();

    void on_pb_star_nu_gr_4_clicked();

    void on_actionOpen_triggered();

    void connectDB();

    void submit();

    void on_actionAdd_Record_triggered();

    void reloadStudlist();

    void insertStudtoDB(QString studname);

    void deleteStudfromDB(QString studname);

    void on_actionDelete_Record_triggered();

    void displayVal(QString v);

    void clearFields();

    void on_pushButton_addrec_clicked();

    void on_pushButton_delrec_clicked();

    void toggleUserButton();

    //printing

    void filePrintPreview();
    void filePrint();
    void printPreview(QPrinter *printer);

    void on_actionPrint_Preview_triggered();

    void on_actionPrint_triggered();

    void on_lineEdit_studlrn_textChanged(const QString &arg1);

    void on_actionAbout_HSRCS_triggered();

    //void on_checkBox_3_toggled(bool checked);

    void on_checkBox_calcGenAve_toggled(bool checked);

    void on_checkBox_CalcNumRat_toggled(bool checked);

    void on_lineEdit_tc1_1_textChanged(const QString &arg1);

    void on_lineEdit_tc1_2_textChanged(const QString &arg1);

    void on_lineEdit_tc2_1_textChanged(const QString &arg1);

    void on_lineEdit_tc2_2_textChanged(const QString &arg1);

    void on_lineEdit_tc3_1_textChanged(const QString &arg1);

    ///void on_lineEdit_tc3_2_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_tc3_2_textChanged(const QString &arg1);

    void on_lineEdit_tc4_1_textChanged(const QString &arg1);

    void on_lineEdit_tc4_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;
};


#endif // MAINWINDOW_H
