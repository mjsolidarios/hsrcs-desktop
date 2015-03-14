#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item){
    QSqlQuery q("SELECT studrec_id FROM studrec WHERE stud_name = '"+item->text()+"'");
    while(q.next()){
        int index = q.value(0).toInt()-1;
        //displayVal(QString::number(q.value(0).toInt()-1));
        mapper->setCurrentIndex(index);
        ui->label_current_name->setText(item->text());
        ui->statusBar->showMessage("Entry " + ui->lineEdit_itemid->text() + " on list " +QString::number(index+1)+".");
        ui->lineEdit_itemid->hide();
    }
    toggleUserButton();
}

void MainWindow::on_actionAbout_triggered(){
    QApplication::aboutQt();
}

void MainWindow::on_lineEdit_studsearch_textChanged(const QString &arg1)
{
    ui->listWidget->clear();
    QString n = QString(arg1);
    QSqlQuery studnamelist_q("SELECT stud_name FROM studrec WHERE stud_name LIKE '%"+n+"%'");
    while(studnamelist_q.next()){
        QString n = studnamelist_q.value(0).toString();
        ui->listWidget->addItem(n);
    }

}

void MainWindow::on_lineEdit_studname_editingFinished()
{
    submit();
    ui->listWidget->clear();
    QSqlQuery studnamelist_q("SELECT stud_name FROM studrec ORDER BY stud_name ASC");
    while(studnamelist_q.next()){
        QString n = studnamelist_q.value(0).toString();
        ui->listWidget->addItem(n);
        ui->label_current_name->setText(ui->lineEdit_studname->text());

    }
    setupDB();

}

void MainWindow::setupDB(){

    model = new QSqlTableModel(this,db);
    model->setTable("studrec");
    model->setSort(1,Qt::AscendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->lineEdit_itemid,0);
    mapper->addMapping(ui->lineEdit_schoolname,1);
    mapper->addMapping(ui->lineEdit_studlrn,2);
    mapper->addMapping(ui->lineEdit_studname,3);
    mapper->addMapping(ui->spinBox_age,4);
    mapper->addMapping(ui->comboBox_gender,5,"currentIndex");
    mapper->addMapping(ui->lineEdit_yrsec,6);
    mapper->addMapping(ui->lineEdit_curr,7);
    mapper->addMapping(ui->comboBox_beginSY,8,"currentIndex");
    mapper->addMapping(ui->comboBox_endSY,9,"currentIndex");
    mapper->addMapping(ui->lineEdit_advisername,10);
    mapper->addMapping(ui->lineEdit_principalname,11);
    mapper->addMapping(ui->spinBox_g_fil_gr1,12);
    mapper->addMapping(ui->spinBox_g_fil_gr2,13);
    mapper->addMapping(ui->spinBox_g_fil_gr3,14);
    mapper->addMapping(ui->spinBox_g_fil_gr4,15);
    mapper->addMapping(ui->spinBox_g_eng_gr1,16);
    mapper->addMapping(ui->spinBox_g_eng_gr2,17);
    mapper->addMapping(ui->spinBox_g_eng_gr3,18);
    mapper->addMapping(ui->spinBox_g_eng_gr4,19);
    mapper->addMapping(ui->spinBox_g_math_gr1,20);
    mapper->addMapping(ui->spinBox_g_math_gr2,21);
    mapper->addMapping(ui->spinBox_g_math_gr3,22);
    mapper->addMapping(ui->spinBox_g_math_gr4,23);
    mapper->addMapping(ui->spinBox_g_sci_gr1,24);
    mapper->addMapping(ui->spinBox_g_sci_gr2,25);
    mapper->addMapping(ui->spinBox_g_sci_gr3,26);
    mapper->addMapping(ui->spinBox_g_sci_gr4,27);
    mapper->addMapping(ui->spinBox_g_ap_gr1,28);
    mapper->addMapping(ui->spinBox_g_ap_gr2,29);
    mapper->addMapping(ui->spinBox_g_ap_gr3,30);
    mapper->addMapping(ui->spinBox_g_ap_gr4,31);
    mapper->addMapping(ui->spinBox_g_tve_gr1,32);
    mapper->addMapping(ui->spinBox_g_tve_gr2,33);
    mapper->addMapping(ui->spinBox_g_tve_gr3,34);
    mapper->addMapping(ui->spinBox_g_tve_gr4,35);
    mapper->addMapping(ui->spinBox_g_mu_gr1,36);
    mapper->addMapping(ui->spinBox_g_mu_gr2,37);
    mapper->addMapping(ui->spinBox_g_mu_gr3,38);
    mapper->addMapping(ui->spinBox_g_mu_gr4,39);
    mapper->addMapping(ui->spinBox_g_arts_gr1,40);
    mapper->addMapping(ui->spinBox_g_arts_gr2,41);
    mapper->addMapping(ui->spinBox_g_arts_gr3,42);
    mapper->addMapping(ui->spinBox_g_arts_gr4,43);
    mapper->addMapping(ui->spinBox_g_pe_gr1,44);
    mapper->addMapping(ui->spinBox_g_pe_gr2,45);
    mapper->addMapping(ui->spinBox_g_pe_gr3,46);
    mapper->addMapping(ui->spinBox_g_pe_gr4,47);
    mapper->addMapping(ui->spinBox_g_ht_gr1,48);
    mapper->addMapping(ui->spinBox_g_ht_gr2,49);
    mapper->addMapping(ui->spinBox_g_ht_gr3,50);
    mapper->addMapping(ui->spinBox_g_ht_gr4,51);
    mapper->addMapping(ui->spinBox_g_esp_gr1,52);
    mapper->addMapping(ui->spinBox_g_esp_gr2,53);
    mapper->addMapping(ui->spinBox_g_esp_gr3,54);
    mapper->addMapping(ui->spinBox_g_esp_gr4,55);
    mapper->addMapping(ui->spinBox_g_icf_gr1,56);
    mapper->addMapping(ui->spinBox_g_icf_gr2,57);
    mapper->addMapping(ui->spinBox_g_icf_gr3,58);
    mapper->addMapping(ui->spinBox_g_icf_gr4,59);
    mapper->addMapping(ui->spinBox_g_td_gr1,60);
    mapper->addMapping(ui->spinBox_g_td_gr2,61);
    mapper->addMapping(ui->spinBox_g_td_gr3,62);
    mapper->addMapping(ui->spinBox_g_td_gr4,63);
    mapper->addMapping(ui->spinBox_n_jun,64);
    mapper->addMapping(ui->spinBox_p_jun,65);
    mapper->addMapping(ui->spinBox_a_jun,66);
    mapper->addMapping(ui->spinBox_t_jun,67);
    mapper->addMapping(ui->spinBox_n_jul,68);
    mapper->addMapping(ui->spinBox_p_jul,69);
    mapper->addMapping(ui->spinBox_a_jul,70);
    mapper->addMapping(ui->spinBox_t_jul,71);
    mapper->addMapping(ui->spinBox_n_aug,72);
    mapper->addMapping(ui->spinBox_p_aug,73);
    mapper->addMapping(ui->spinBox_a_aug,74);
    mapper->addMapping(ui->spinBox_t_aug,75);
    mapper->addMapping(ui->spinBox_n_sep,76);
    mapper->addMapping(ui->spinBox_p_sep,77);
    mapper->addMapping(ui->spinBox_a_sep,78);
    mapper->addMapping(ui->spinBox_t_sep,79);
    mapper->addMapping(ui->spinBox_n_oct,80);
    mapper->addMapping(ui->spinBox_p_oct,81);
    mapper->addMapping(ui->spinBox_a_oct,82);
    mapper->addMapping(ui->spinBox_t_oct,83);
    mapper->addMapping(ui->spinBox_n_nov,84);
    mapper->addMapping(ui->spinBox_p_nov,85);
    mapper->addMapping(ui->spinBox_a_nov,86);
    mapper->addMapping(ui->spinBox_t_nov,87);
    mapper->addMapping(ui->spinBox_n_dec,88);
    mapper->addMapping(ui->spinBox_p_dec,89);
    mapper->addMapping(ui->spinBox_a_dec,90);
    mapper->addMapping(ui->spinBox_t_dec,91);
    mapper->addMapping(ui->spinBox_n_jan,92);
    mapper->addMapping(ui->spinBox_p_jan,93);
    mapper->addMapping(ui->spinBox_a_jan,94);
    mapper->addMapping(ui->spinBox_t_jan,95);
    mapper->addMapping(ui->spinBox_n_feb,96);
    mapper->addMapping(ui->spinBox_p_feb,97);
    mapper->addMapping(ui->spinBox_a_feb,98);
    mapper->addMapping(ui->spinBox_t_feb,99);
    mapper->addMapping(ui->spinBox_n_mar,100);
    mapper->addMapping(ui->spinBox_p_mar,101);
    mapper->addMapping(ui->spinBox_a_mar,102);
    mapper->addMapping(ui->spinBox_t_mar,103);
    mapper->addMapping(ui->spinBox_n_apr,104);
    mapper->addMapping(ui->spinBox_p_apr,105);
    mapper->addMapping(ui->spinBox_a_apr,106);
    mapper->addMapping(ui->spinBox_t_apr,107);
    mapper->addMapping(ui->lineEdit_elig_ad,108);
    mapper->addMapping(ui->lineEdit_adv_units,109);
    mapper->addMapping(ui->lineEdit_lack_units,110);
    mapper->addMapping(ui->lineEdit_elig_date,111);
    mapper->addMapping(ui->pb_star_pm_gr_1,112,"text");
    mapper->addMapping(ui->pb_star_pm_gr_2,113,"text");
    mapper->addMapping(ui->pb_star_pm_gr_3,114,"text");
    mapper->addMapping(ui->pb_star_pm_gr_4,115,"text");
    mapper->addMapping(ui->pb_star_as_gr_1,116,"text");
    mapper->addMapping(ui->pb_star_as_gr_2,117,"text");
    mapper->addMapping(ui->pb_star_as_gr_3,118,"text");
    mapper->addMapping(ui->pb_star_as_gr_4,119,"text");
    mapper->addMapping(ui->pb_star_to_gr_1,120,"text");
    mapper->addMapping(ui->pb_star_to_gr_2,121,"text");
    mapper->addMapping(ui->pb_star_to_gr_3,122,"text");
    mapper->addMapping(ui->pb_star_to_gr_4,123,"text");
    mapper->addMapping(ui->pb_star_li_gr_1,124,"text");
    mapper->addMapping(ui->pb_star_li_gr_2,125,"text");
    mapper->addMapping(ui->pb_star_li_gr_3,126,"text");
    mapper->addMapping(ui->pb_star_li_gr_4,127,"text");
    mapper->addMapping(ui->pb_star_sd_gr_1,128,"text");
    mapper->addMapping(ui->pb_star_sd_gr_2,129,"text");
    mapper->addMapping(ui->pb_star_sd_gr_3,130,"text");
    mapper->addMapping(ui->pb_star_sd_gr_4,131,"text");
    mapper->addMapping(ui->pb_star_rt_gr_1,132,"text");
    mapper->addMapping(ui->pb_star_rt_gr_2,133,"text");
    mapper->addMapping(ui->pb_star_rt_gr_3,134,"text");
    mapper->addMapping(ui->pb_star_rt_gr_4,135,"text");
    mapper->addMapping(ui->pb_star_rhr_gr_1,136,"text");
    mapper->addMapping(ui->pb_star_rhr_gr_2,137,"text");
    mapper->addMapping(ui->pb_star_rhr_gr_3,138,"text");
    mapper->addMapping(ui->pb_star_rhr_gr_4,139,"text");
    mapper->addMapping(ui->pb_star_pp_gr_1,140,"text");
    mapper->addMapping(ui->pb_star_pp_gr_2,141,"text");
    mapper->addMapping(ui->pb_star_pp_gr_3,142,"text");
    mapper->addMapping(ui->pb_star_pp_gr_4,143,"text");
    mapper->addMapping(ui->pb_star_re_gr_1,144,"text");
    mapper->addMapping(ui->pb_star_re_gr_2,145,"text");
    mapper->addMapping(ui->pb_star_re_gr_3,146,"text");
    mapper->addMapping(ui->pb_star_re_gr_4,147,"text");
    mapper->addMapping(ui->pb_star_pr_gr_1,148,"text");
    mapper->addMapping(ui->pb_star_pr_gr_2,149,"text");
    mapper->addMapping(ui->pb_star_pr_gr_3,150,"text");
    mapper->addMapping(ui->pb_star_pr_gr_4,151,"text");
    mapper->addMapping(ui->pb_star_ecr_gr_1,152,"text");
    mapper->addMapping(ui->pb_star_ecr_gr_2,153,"text");
    mapper->addMapping(ui->pb_star_ecr_gr_3,154,"text");
    mapper->addMapping(ui->pb_star_ecr_gr_4,155,"text");
    mapper->addMapping(ui->pb_star_fr_gr_1,156,"text");
    mapper->addMapping(ui->pb_star_fr_gr_2,157,"text");
    mapper->addMapping(ui->pb_star_fr_gr_3,158,"text");
    mapper->addMapping(ui->pb_star_fr_gr_4,159,"text");
    mapper->addMapping(ui->pb_star_rl_gr_1,160,"text");
    mapper->addMapping(ui->pb_star_rl_gr_2,161,"text");
    mapper->addMapping(ui->pb_star_rl_gr_3,162,"text");
    mapper->addMapping(ui->pb_star_rl_gr_4,163,"text");
    mapper->addMapping(ui->pb_star_nu_gr_1,164,"text");
    mapper->addMapping(ui->pb_star_nu_gr_2,165,"text");
    mapper->addMapping(ui->pb_star_nu_gr_3,166,"text");
    mapper->addMapping(ui->pb_star_nu_gr_4,167,"text");
    mapper->addMapping(ui->lineEdit_tc1_1,168);
    mapper->addMapping(ui->lineEdit_tc2_1,169);
    mapper->addMapping(ui->lineEdit_tc3_1,170);
    mapper->addMapping(ui->lineEdit_tc4_1,171);
    mapper->addMapping(ui->lineEdit_yr_trans,172);
    mapper->addMapping(ui->lineEdit_trans_adv_name,173);
    mapper->addMapping(ui->lineEdit_trans_princpl_name,174);
    mapper->addMapping(ui->lineEdit_notes,175);
    mapper->addMapping(ui->lineEdit_schooladd,176);
    mapper->addMapping(ui->lineEdit_tc1_2,177);
    mapper->addMapping(ui->lineEdit_tc2_2,178);
    mapper->addMapping(ui->lineEdit_tc3_2,179);
    mapper->addMapping(ui->lineEdit_tc4_2,180);
}

void MainWindow::starRate(QPushButton *p){
    if(p->text().length()!=3){
       p->setText(p->text()+"★");
    }else{
        p->setText(p->text().remove(0,3));
    }
}

void MainWindow::on_pb_star_pm_gr_1_clicked()
{
    starRate(ui->pb_star_pm_gr_1);
}

void MainWindow::on_pb_star_as_gr_1_clicked()
{
    starRate(ui->pb_star_as_gr_1);
}

void MainWindow::on_pb_star_to_gr_1_clicked()
{
    starRate(ui->pb_star_to_gr_1);
}

void MainWindow::on_pb_star_li_gr_1_clicked()
{
    starRate(ui->pb_star_li_gr_1);
}

void MainWindow::on_pb_star_sd_gr_1_clicked()
{
    starRate(ui->pb_star_sd_gr_1);
}

void MainWindow::on_pb_star_rt_gr_1_clicked()
{
    starRate(ui->pb_star_rt_gr_1);
}

void MainWindow::on_pb_star_rhr_gr_1_clicked()
{
    starRate(ui->pb_star_rhr_gr_1);
}

void MainWindow::on_pb_star_pp_gr_1_clicked()
{
    starRate(ui->pb_star_pp_gr_1);
}

void MainWindow::on_pb_star_re_gr_1_clicked()
{
    starRate(ui->pb_star_re_gr_1);
}

void MainWindow::on_pb_star_pr_gr_1_clicked()
{
    starRate(ui->pb_star_pr_gr_1);
}

void MainWindow::on_pb_star_ecr_gr_1_clicked()
{
    starRate(ui->pb_star_ecr_gr_1);
}

void MainWindow::on_pb_star_fr_gr_1_clicked()
{
    starRate(ui->pb_star_fr_gr_1);
}

void MainWindow::on_pb_star_rl_gr_1_clicked()
{
    starRate(ui->pb_star_rl_gr_1);
}

void MainWindow::on_pb_star_nu_gr_1_clicked()
{
    starRate(ui->pb_star_nu_gr_1);
}

void MainWindow::on_pb_star_pm_gr_2_clicked()
{
     starRate(ui->pb_star_pm_gr_2);
}

void MainWindow::on_pb_star_as_gr_2_clicked()
{
    starRate(ui->pb_star_as_gr_2);
}

void MainWindow::on_pb_star_to_gr_2_clicked()
{
    starRate(ui->pb_star_to_gr_2);
}

void MainWindow::on_pb_star_li_gr_2_clicked()
{
    starRate(ui->pb_star_li_gr_2);
}

void MainWindow::on_pb_star_sd_gr_2_clicked()
{
    starRate(ui->pb_star_sd_gr_2);
}

void MainWindow::on_pb_star_rt_gr_2_clicked()
{
    starRate(ui->pb_star_rt_gr_2);
}

void MainWindow::on_pb_star_rhr_gr_2_clicked()
{
    starRate(ui->pb_star_rhr_gr_2);
}

void MainWindow::on_pb_star_pp_gr_2_clicked()
{
    starRate(ui->pb_star_pp_gr_2);
}

void MainWindow::on_pb_star_re_gr_2_clicked()
{
    starRate(ui->pb_star_re_gr_2);
}

void MainWindow::on_pb_star_pr_gr_2_clicked()
{
    starRate(ui->pb_star_pr_gr_2);
}

void MainWindow::on_pb_star_ecr_gr_2_clicked()
{
    starRate(ui->pb_star_ecr_gr_2);
}

void MainWindow::on_pb_star_fr_gr_2_clicked()
{
    starRate(ui->pb_star_fr_gr_2);
}

void MainWindow::on_pb_star_rl_gr_2_clicked()
{
    starRate(ui->pb_star_rl_gr_2);
}

void MainWindow::on_pb_star_nu_gr_2_clicked()
{
    starRate(ui->pb_star_nu_gr_2);
}

void MainWindow::on_pb_star_pm_gr_3_clicked()
{
    starRate(ui->pb_star_pm_gr_3);
}

void MainWindow::on_pb_star_as_gr_3_clicked()
{
    starRate(ui->pb_star_as_gr_3);
}

void MainWindow::on_pb_star_to_gr_3_clicked()
{
    starRate(ui->pb_star_to_gr_3);
}

void MainWindow::on_pb_star_li_gr_3_clicked()
{
    starRate(ui->pb_star_li_gr_3);
}

void MainWindow::on_pb_star_sd_gr_3_clicked()
{
    starRate(ui->pb_star_sd_gr_3);
}

void MainWindow::on_pb_star_rt_gr_3_clicked()
{
    starRate(ui->pb_star_rt_gr_3);
}

void MainWindow::on_pb_star_rhr_gr_3_clicked()
{
    starRate(ui->pb_star_rhr_gr_3);
}

void MainWindow::on_pb_star_pp_gr_3_clicked()
{
    starRate(ui->pb_star_pp_gr_3);
}

void MainWindow::on_pb_star_re_gr_3_clicked()
{
    starRate(ui->pb_star_re_gr_3);
}

void MainWindow::on_pb_star_pr_gr_3_clicked()
{
    starRate(ui->pb_star_pr_gr_3);
}

void MainWindow::on_pb_star_ecr_gr_3_clicked()
{
    starRate(ui->pb_star_ecr_gr_3);
}

void MainWindow::on_pb_star_fr_gr_3_clicked()
{
    starRate(ui->pb_star_fr_gr_3);
}

void MainWindow::on_pb_star_rl_gr_3_clicked()
{
    starRate(ui->pb_star_rl_gr_3);
}

void MainWindow::on_pb_star_nu_gr_3_clicked()
{
    starRate(ui->pb_star_nu_gr_3);
}

void MainWindow::on_pb_star_pm_gr_4_clicked()
{
    starRate(ui->pb_star_pm_gr_4);
}

void MainWindow::on_pb_star_as_gr_4_clicked()
{
    starRate(ui->pb_star_as_gr_4);
}

void MainWindow::on_pb_star_to_gr_4_clicked()
{
    starRate(ui->pb_star_to_gr_4);
}

void MainWindow::on_pb_star_li_gr_4_clicked()
{
    starRate(ui->pb_star_li_gr_4);
}

void MainWindow::on_pb_star_sd_gr_4_clicked()
{
    starRate(ui->pb_star_sd_gr_4);
}

void MainWindow::on_pb_star_rt_gr_4_clicked()
{
    starRate(ui->pb_star_rt_gr_4);
}

void MainWindow::on_pb_star_rhr_gr_4_clicked()
{
    starRate(ui->pb_star_rhr_gr_4);
}

void MainWindow::on_pb_star_pp_gr_4_clicked()
{
    starRate(ui->pb_star_pp_gr_4);
}

void MainWindow::on_pb_star_re_gr_4_clicked()
{
    starRate(ui->pb_star_re_gr_4);
}

void MainWindow::on_pb_star_pr_gr_4_clicked()
{
    starRate(ui->pb_star_pr_gr_4);
}

void MainWindow::on_pb_star_ecr_gr_4_clicked()
{
    starRate(ui->pb_star_ecr_gr_4);
}

void MainWindow::on_pb_star_fr_gr_4_clicked()
{
    starRate(ui->pb_star_fr_gr_4);
}

void MainWindow::on_pb_star_rl_gr_4_clicked()
{
    starRate(ui->pb_star_rl_gr_4);
}

void MainWindow::on_pb_star_nu_gr_4_clicked()
{
    starRate(ui->pb_star_nu_gr_4);
}

void MainWindow::connectDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");

    if(!db.open()){
        QMessageBox::critical(0,qApp->tr("Cannot open database"),
                              qApp->tr("Unable to establish a database connection."),QMessageBox::Cancel);
    }else{
        statusBar()->showMessage("Connected to the database.", 5000);
        QSqlQuery q;
        q.exec("CREATE TABLE `studrec` (`studrec_id` INTEGER PRIMARY KEY AUTOINCREMENT,`schl_name` text,`stud_lrn` int(11) DEFAULT NULL,`stud_name` text,`stud_age` int(11) DEFAULT NULL,`stud_gender` int(11) DEFAULT NULL,`stud_year_section` text,`curr` text,`beginSY` int(11) DEFAULT NULL,`endSY` int(11) DEFAULT NULL,`adviser_name` text,`principal_name` text,`g_fil_gr1` int(11) DEFAULT NULL,`g_fil_gr2` int(11) DEFAULT NULL,`g_fil_gr3` int(11) DEFAULT NULL,`g_fil_gr4` int(11) DEFAULT NULL,`g_eng_gr1` int(11) DEFAULT NULL,`g_eng_gr2` int(11) DEFAULT NULL,`g_eng_gr3` int(11) DEFAULT NULL,`g_eng_gr4` int(11) DEFAULT NULL,`g_math_gr1` int(11) DEFAULT NULL,`g_math_gr2` int(11) DEFAULT NULL,`g_math_gr3` int(11) DEFAULT NULL,`g_math_gr4` int(11) DEFAULT NULL,`g_sci_gr1` int(11) DEFAULT NULL,`g_sci_gr2` int(11) DEFAULT NULL,`g_sci_gr3` int(11) DEFAULT NULL,`g_sci_gr4` int(11) DEFAULT NULL,`g_ap_gr1` int(11) DEFAULT NULL,`g_ap_gr2` int(11) DEFAULT NULL,`g_ap_gr3` int(11) DEFAULT NULL,`g_ap_gr4` int(11) DEFAULT NULL,`g_tve_gr1` int(11) DEFAULT NULL,`g_tve_gr2` int(11) DEFAULT NULL,`g_tve_gr3` int(11) DEFAULT NULL,`g_tve_gr4` int(11) DEFAULT NULL,`g_mu_gr1` int(11) DEFAULT NULL,`g_mu_gr2` int(11) DEFAULT NULL,`g_mu_gr3` int(11) DEFAULT NULL,`g_mu_gr4` int(11) DEFAULT NULL,`g_arts_gr1` int(11) DEFAULT NULL,`g_arts_gr2` int(11) DEFAULT NULL,`g_arts_gr3` int(11) DEFAULT NULL,`g_arts_gr4` int(11) DEFAULT NULL,`g_pe_gr1` int(11) DEFAULT NULL,`g_pe_gr2` int(11) DEFAULT NULL,`g_pe_gr3` int(11) DEFAULT NULL,`g_pe_gr4` int(11) DEFAULT NULL,`g_ht_gr1` int(11) DEFAULT NULL,`g_ht_gr2` int(11) DEFAULT NULL,`g_ht_gr3` int(11) DEFAULT NULL,`g_ht_gr4` int(11) DEFAULT NULL,`g_esp_gr1` int(11) DEFAULT NULL,`g_esp_gr2` int(11) DEFAULT NULL,`g_esp_gr3` int(11) DEFAULT NULL,`g_esp_gr4` int(11) DEFAULT NULL,`g_icf_gr1` int(11) DEFAULT NULL,`g_icf_gr2` int(11) DEFAULT NULL,`g_icf_gr3` int(11) DEFAULT NULL,`g_icf_gr4` int(11) DEFAULT NULL,`g_td_gr1` int(11) DEFAULT NULL,`g_td_gr2` int(11) DEFAULT NULL,`g_td_gr3` int(11) DEFAULT NULL,`g_td_gr4` int(11) DEFAULT NULL,`n_jun` int(11) DEFAULT NULL,`p_jun` int(11) DEFAULT NULL,`a_jun` int(11) DEFAULT NULL,`t_jun` int(11) DEFAULT NULL,`n_jul` int(11) DEFAULT NULL,`p_jul` int(11) DEFAULT NULL,`a_jul` int(11) DEFAULT NULL,`t_jul` int(11) DEFAULT NULL,`n_aug` int(11) DEFAULT NULL,`p_aug` int(11) DEFAULT NULL,`a_aug` int(11) DEFAULT NULL,`t_aug` int(11) DEFAULT NULL,`n_sept` int(11) DEFAULT NULL,`p_sept` int(11) DEFAULT NULL,`a_sept` int(11) DEFAULT NULL,`t_sept` int(11) DEFAULT NULL,`n_oct` int(11) DEFAULT NULL,`p_oct` int(11) DEFAULT NULL,`a_oct` int(11) DEFAULT NULL,`t_oct` int(11) DEFAULT NULL,`n_nov` int(11) DEFAULT NULL,`p_nov` int(11) DEFAULT NULL,`a_nov` int(11) DEFAULT NULL,`t_nov` int(11) DEFAULT NULL,`n_dec` int(11) DEFAULT NULL,`p_dec` int(11) DEFAULT NULL,`a_dec` int(11) DEFAULT NULL,`t_dec` int(11) DEFAULT NULL,`n_jan` int(11) DEFAULT NULL,`p_jan` int(11) DEFAULT NULL,`a_jan` int(11) DEFAULT NULL,`t_jan` int(11) DEFAULT NULL,`n_feb` int(11) DEFAULT NULL,`p_feb` int(11) DEFAULT NULL,`a_feb` int(11) DEFAULT NULL,`t_feb` int(11) DEFAULT NULL,`n_mar` int(11) DEFAULT NULL,`p_mar` int(11) DEFAULT NULL,`a_mar` int(11) DEFAULT NULL,`t_mar` int(11) DEFAULT NULL,`n_ap` int(11) DEFAULT NULL,`p_ap` int(11) DEFAULT NULL,`a_ap` int(11) DEFAULT NULL,`t_ap` int(11) DEFAULT NULL,`elig_ad` text DEFAULT NULL,`adv_units` text DEFAULT NULL,`lack_units`text DEFAULT NULL,`elig_date` text DEFAULT NULL,`pm_gr1` text,`pm_gr2` text,`pm_gr3` text,`pm_gr4` text,`as_gr1` text,`as_gr2` text,`as_gr3` text,`as_gr4` text,`tol_gr1` text,`tol_gr2` text,`tol_gr3` text,`tol_gr4` text,`li_gr1` text,`li_gr2` text,`li_gr3` text,`li_gr4` text,`sd_gr1` text,`sd_gr2` text,`sd_gr3` text,`sd_gr4` text,`rt_gr1` text,`rt_gr2` text,`rt_gr3` text,`rt_gr4` text,`rhr_g1` text,`rhr_g2` text,`rhr_g3` text,`rhr_g4` text,`pp_g1` text,`pp_g2` text,`pp_g3` text,`pp_g4` text,`re_g1` text,`re_g2` text,`re_g3` text,`re_g4` text,`pr_g1` text,`pr_g2` text,`pr_g3` text,`pr_g4` text,`ecr_g1` text,`ecr_g2` text,`ecr_g3` text,`ecr_g4` text,`fr_g1` text,`fr_g2` text,`fr_g3` text,`fr_g4` text,`rl_g1` text,`rl_g2` text,`rl_g3` text,`rl_g4` text,`nu_g1` text,`nu_g2` text,`nu_g3` text,`nu_g4` text,`teacher_com_gr1_1` text,`teacher_com_gr2`_1 text,`teacher_com_gr3_1` text,`teacher_com_gr4_1` text,`year_transfered` text,`trans_advsr_name` text,`trans_prncpl_name` text, `notes` text, `schooladd` text,`teacher_com_gr1_2` text,`teacher_com_gr2_2` text,`teacher_com_gr3_2` text,`teacher_com_gr4_2` text)");

    }


}

void MainWindow::on_actionOpen_triggered()
{
    connectDB();

    QString filename;
    filename=QFileDialog::getOpenFileName(this,tr("Open Student Record"),QDir::currentPath(),tr("HSRCS data file (*.csv)"));

    QFile f(filename);

    if(f.open (QIODevice::ReadOnly)){
        QSqlQuery q2;
        QTextStream ts (&f);

        while(!ts.atEnd()){
            QString req = "INSERT INTO studrec VALUES (";
            QStringList l = ts.readLine().split(";");

            for(int i = 0; i<l.length(); i++){
                req.append(l.at(i));
                req.append(",");
            }
            req.chop(1);
            req.append(")");
            q2.exec(req);
        }
        f.close();
        MainWindow::setWindowTitle("High School Report Card System - "+filename);
    }

    reloadStudlist();
    setupDB();
    toggleUserButton();
}

void MainWindow::reloadStudlist(){
    ui->listWidget->clear();
    QSqlQuery studnamelist_q("SELECT stud_name FROM studrec ORDER BY stud_name ASC");
    while(studnamelist_q.next()){
        QString n = studnamelist_q.value(0).toString();
        ui->listWidget->addItem(n);
    }
}

void MainWindow::on_actionSave_triggered()
{
    submit();
    QString filename;
    QFileDialog save;
    filename=save.getSaveFileName(this,tr("Save Student Record"),QDir::currentPath(),tr("HSRCS data file *.csv (*.csv)"));
    QFile f(filename);
    save.setDefaultSuffix("csv");
    int colcount = model->columnCount();
    QSqlQuery q("SELECT * FROM studrec");

    if(f.open(QFile::WriteOnly|QFile::Truncate)){
        QTextStream ts(&f);
        while(q.next()){
            QString row = "'";
            for(int i = 0; i < colcount; i++){
            row += q.value(i).toString()+"';";
            row.append("'");
            }
         row.chop(3);
         row.append("'");
         ts << row << "\n";
        }
    }
    f.close();
}

void MainWindow::submit(){
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
        statusBar()->showMessage("Changes saved.",5000);
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
}


void MainWindow::insertStudtoDB(QString studname)
{
    QString qstr_addstud = "INSERT INTO studrec VALUES ('";
    QString qstr_rowcount = "SELECT count(*) FROM studrec";
    //QString qstr_rowcount = "SELECT studrec_id from studrec ORDER BY studrec_id DESC LIMIT 1";
    QSqlQuery q;
    int rowid;
    q.exec(qstr_rowcount);
    while(q.next()){
        rowid = q.value(0).toInt()+1;
    }
    qstr_addstud.append(QString::number(rowid));

    for(int i = 0; i < 181; i++){
    qstr_addstud.append("','");
    }
    qstr_addstud.chop(2);
    qstr_addstud.append(")");
    q.exec(qstr_addstud);
    QString qstr_updatestudname = "UPDATE studrec SET stud_name = '";
    qstr_updatestudname.append(studname);
    qstr_updatestudname.append("' WHERE studrec_id="+QString::number(rowid));
    q.exec(qstr_updatestudname);

    reloadStudlist();
    //ui->textEdit->setText(qstr_updatestudname);
}

void MainWindow::on_actionAdd_Record_triggered()
{
    bool ok;
    QString studname = QInputDialog::getText(this, tr("Add a Student"),tr("Student Name (Last Name, M.I. First Name):"), QLineEdit::Normal,"", &ok);
    if (ok && !studname.isEmpty()){
            if(!db.isOpen()){
                connectDB();
                insertStudtoDB(studname);
                setupDB();
                submit();
            }else{
                insertStudtoDB(studname);
                submit();
            }
        }
    ui->pushButton_delrec->setEnabled(true);
}

void  MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation?","Are you sure you want to exit? Unsaved changes will be lost.", QMessageBox::Yes|QMessageBox::No)){
        db.close();
        event->accept();
    }

}

void MainWindow::deleteStudfromDB(QString studname)
{
    QString qstr_deletestud = "DELETE FROM studrec WHERE stud_name='";
    qstr_deletestud.append(studname);
    //displayVal(qstr_deletestud);
    QSqlQuery q;
    q.exec(qstr_deletestud);
}

void MainWindow::on_actionDelete_Record_triggered()
{
    QString selectedstudname = ui->listWidget->item(0)->text();
    if (QMessageBox::Yes == QMessageBox::question(this,"Delete a Student", "Are you sure you want to delete "+selectedstudname+"?"))
    {
        selectedstudname.append("'");
        if(!db.isOpen()){
            connectDB();
            deleteStudfromDB(selectedstudname);
            setupDB();
            submit();
        }else{
            deleteStudfromDB(selectedstudname);
            submit();
        }
        clearFields();
        reloadStudlist();
        toggleUserButton();

    }
}

void MainWindow::toggleUserButton(){
    ui->listWidget->selectAll();
    if(ui->listWidget->count()==0){
        ui->tabWidget->setEnabled(false);
        ui->actionSave->setEnabled(false);
        ui->pushButton_delrec->setEnabled(false);
        ui->scrollArea_attenadd->setEnabled(false);
    }else{
        ui->tabWidget->setEnabled(true);
        ui->actionSave->setEnabled(true);
        ui->pushButton_delrec->setEnabled(true);
        ui->actionPrint_Preview->setEnabled(true);
        ui->actionPrint->setEnabled(true);
        ui->scrollArea_attenadd->setEnabled(true);
        ui->groupBox_transferYearLevel->setEnabled(false);
    }
    // ui->spinBox_g_tve_gr1->setEnabled("false");
    // ui->spinBox_g_tve_gr2->setEnabled("false");
    // ui->spinBox_g_tve_gr3->setEnabled("false");
    // ui->spinBox_g_tve_gr4->setEnabled("false");
}

void MainWindow::displayVal(QString v){
    QMessageBox::about(0,"Val",v);
}


void MainWindow::clearFields(){
    ui->lineEdit_schoolname->clear();
    ui->lineEdit_studlrn->clear();
    ui->lineEdit_studname->clear();
    ui->spinBox_age->clear();
    ui->comboBox_gender->clear();
    ui->lineEdit_yrsec->clear();
    ui->lineEdit_curr->clear();
    ui->comboBox_beginSY->clear();
    ui->comboBox_endSY->clear();
    ui->lineEdit_advisername->clear();
    ui->lineEdit_principalname->clear();
    ui->spinBox_g_fil_gr1->clear();
    ui->spinBox_g_fil_gr2->clear();
    ui->spinBox_g_fil_gr3->clear();
    ui->spinBox_g_fil_gr4->clear();
    ui->spinBox_g_eng_gr1->clear();
    ui->spinBox_g_eng_gr2->clear();
    ui->spinBox_g_eng_gr3->clear();
    ui->spinBox_g_eng_gr4->clear();
    ui->spinBox_g_math_gr1->clear();
    ui->spinBox_g_math_gr2->clear();
    ui->spinBox_g_math_gr3->clear();
    ui->spinBox_g_math_gr4->clear();
    ui->spinBox_g_sci_gr1->clear();
    ui->spinBox_g_sci_gr2->clear();
    ui->spinBox_g_sci_gr3->clear();
    ui->spinBox_g_sci_gr4->clear();
    ui->spinBox_g_ap_gr1->clear();
    ui->spinBox_g_ap_gr2->clear();
    ui->spinBox_g_ap_gr3->clear();
    ui->spinBox_g_ap_gr4->clear();
    ui->spinBox_g_tve_gr1->clear();
    ui->spinBox_g_tve_gr2->clear();
    ui->spinBox_g_tve_gr3->clear();
    ui->spinBox_g_tve_gr4->clear();
    ui->spinBox_g_mu_gr1->clear();
    ui->spinBox_g_mu_gr2->clear();
    ui->spinBox_g_mu_gr3->clear();
    ui->spinBox_g_mu_gr4->clear();
    ui->spinBox_g_arts_gr1->clear();
    ui->spinBox_g_arts_gr2->clear();
    ui->spinBox_g_arts_gr3->clear();
    ui->spinBox_g_arts_gr4->clear();
    ui->spinBox_g_pe_gr1->clear();
    ui->spinBox_g_pe_gr2->clear();
    ui->spinBox_g_pe_gr3->clear();
    ui->spinBox_g_pe_gr4->clear();
    ui->spinBox_g_ht_gr1->clear();
    ui->spinBox_g_ht_gr2->clear();
    ui->spinBox_g_ht_gr3->clear();
    ui->spinBox_g_ht_gr4->clear();
    ui->spinBox_g_esp_gr1->clear();
    ui->spinBox_g_esp_gr2->clear();
    ui->spinBox_g_esp_gr3->clear();
    ui->spinBox_g_esp_gr4->clear();
    ui->spinBox_g_icf_gr1->clear();
    ui->spinBox_g_icf_gr2->clear();
    ui->spinBox_g_icf_gr3->clear();
    ui->spinBox_g_icf_gr4->clear();
    ui->spinBox_g_td_gr1->clear();
    ui->spinBox_g_td_gr2->clear();
    ui->spinBox_g_td_gr3->clear();
    ui->spinBox_g_td_gr4->clear();
    ui->spinBox_n_jun->clear();
    ui->spinBox_p_jun->clear();
    ui->spinBox_a_jun->clear();
    ui->spinBox_t_jun->clear();
    ui->spinBox_n_jul->clear();
    ui->spinBox_p_jul->clear();
    ui->spinBox_a_jul->clear();
    ui->spinBox_t_jul->clear();
    ui->spinBox_n_aug->clear();
    ui->spinBox_p_aug->clear();
    ui->spinBox_a_aug->clear();
    ui->spinBox_t_aug->clear();
    ui->spinBox_n_sep->clear();
    ui->spinBox_p_sep->clear();
    ui->spinBox_a_sep->clear();
    ui->spinBox_t_sep->clear();
    ui->spinBox_n_oct->clear();
    ui->spinBox_p_oct->clear();
    ui->spinBox_a_oct->clear();
    ui->spinBox_t_oct->clear();
    ui->spinBox_n_nov->clear();
    ui->spinBox_p_nov->clear();
    ui->spinBox_a_nov->clear();
    ui->spinBox_t_nov->clear();
    ui->spinBox_n_dec->clear();
    ui->spinBox_p_dec->clear();
    ui->spinBox_a_dec->clear();
    ui->spinBox_t_dec->clear();
    ui->spinBox_n_jan->clear();
    ui->spinBox_p_jan->clear();
    ui->spinBox_a_jan->clear();
    ui->spinBox_t_jan->clear();
    ui->spinBox_n_feb->clear();
    ui->spinBox_p_feb->clear();
    ui->spinBox_a_feb->clear();
    ui->spinBox_t_feb->clear();
    ui->spinBox_n_mar->clear();
    ui->spinBox_p_mar->clear();
    ui->spinBox_a_mar->clear();
    ui->spinBox_t_mar->clear();
    ui->spinBox_n_apr->clear();
    ui->spinBox_p_apr->clear();
    ui->spinBox_a_apr->clear();
    ui->spinBox_t_apr->clear();
    ui->lineEdit_elig_ad->clear();
    ui->lineEdit_adv_units->clear();
    ui->lineEdit_lack_units->clear();
    ui->lineEdit_lack_units->clear();
    ui->lineEdit_elig_date->clear();
    ui->pb_star_pm_gr_1->setText("");
    ui->pb_star_pm_gr_2->setText("");
    ui->pb_star_pm_gr_3->setText("");
    ui->pb_star_pm_gr_4->setText("");
    ui->pb_star_as_gr_1->setText("");
    ui->pb_star_as_gr_2->setText("");
    ui->pb_star_as_gr_3->setText("");
    ui->pb_star_as_gr_4->setText("");
    ui->pb_star_to_gr_1->setText("");
    ui->pb_star_to_gr_2->setText("");
    ui->pb_star_to_gr_3->setText("");
    ui->pb_star_to_gr_4->setText("");
    ui->pb_star_li_gr_1->setText("");
    ui->pb_star_li_gr_2->setText("");
    ui->pb_star_li_gr_3->setText("");
    ui->pb_star_li_gr_4->setText("");
    ui->pb_star_sd_gr_1->setText("");
    ui->pb_star_sd_gr_2->setText("");
    ui->pb_star_sd_gr_3->setText("");
    ui->pb_star_sd_gr_4->setText("");
    ui->pb_star_rt_gr_1->setText("");
    ui->pb_star_rt_gr_2->setText("");
    ui->pb_star_rt_gr_3->setText("");
    ui->pb_star_rt_gr_4->setText("");
    ui->pb_star_rhr_gr_1->setText("");
    ui->pb_star_rhr_gr_2->setText("");
    ui->pb_star_rhr_gr_3->setText("");
    ui->pb_star_rhr_gr_4->setText("");
    ui->pb_star_pp_gr_1->setText("");
    ui->pb_star_pp_gr_2->setText("");
    ui->pb_star_pp_gr_3->setText("");
    ui->pb_star_pp_gr_4->setText("");
    ui->pb_star_re_gr_1->setText("");
    ui->pb_star_re_gr_2->setText("");
    ui->pb_star_re_gr_3->setText("");
    ui->pb_star_re_gr_4->setText("");
    ui->pb_star_pr_gr_1->setText("");
    ui->pb_star_pr_gr_2->setText("");
    ui->pb_star_pr_gr_3->setText("");
    ui->pb_star_pr_gr_4->setText("");
    ui->pb_star_ecr_gr_1->setText("");
    ui->pb_star_ecr_gr_2->setText("");
    ui->pb_star_ecr_gr_3->setText("");
    ui->pb_star_ecr_gr_4->setText("");
    ui->pb_star_fr_gr_1->setText("");
    ui->pb_star_fr_gr_2->setText("");
    ui->pb_star_fr_gr_3->setText("");
    ui->pb_star_fr_gr_4->setText("");
    ui->pb_star_rl_gr_1->setText("");
    ui->pb_star_rl_gr_2->setText("");
    ui->pb_star_rl_gr_3->setText("");
    ui->pb_star_rl_gr_4->setText("");
    ui->pb_star_nu_gr_1->setText("");
    ui->pb_star_nu_gr_2->setText("");
    ui->pb_star_nu_gr_3->setText("");
    ui->pb_star_nu_gr_4->setText("");
    ui->lineEdit_yr_trans->clear();
    ui->lineEdit_trans_adv_name->clear();
    ui->lineEdit_trans_princpl_name->clear();
    ui->lineEdit_notes->clear();
    ui->lineEdit_schooladd->clear();
    ui->lineEdit_tc1_1->clear();
    ui->lineEdit_tc2_1->clear();
    ui->lineEdit_tc3_1->clear();
    ui->lineEdit_tc4_1->clear();
    ui->lineEdit_tc1_2->clear();
    ui->lineEdit_tc2_2->clear();
    ui->lineEdit_tc3_2->clear();
    ui->lineEdit_tc4_2->clear();
}

void MainWindow::on_pushButton_addrec_clicked()
{

    bool ok;
    QString studname = QInputDialog::getText(this, tr("Add a Student"),tr("Student Name (Last Name, M.I. First Name):"), QLineEdit::Normal,"", &ok);
    if (ok && !studname.isEmpty()){
            if(!db.isOpen()){
                connectDB();
                insertStudtoDB(studname);
                setupDB();
                submit();
            }else{
                insertStudtoDB(studname);
                submit();
            }
        }
    toggleUserButton();
}

void MainWindow::on_pushButton_delrec_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this, "Delete Confirmation.","This feature currently have bugs and may result to unwanted data loss. Are you sure you want to continue?", QMessageBox::Yes|QMessageBox::No)){
        QString selectedstudname = ui->listWidget->item(0)->text();
        if (QMessageBox::Yes == QMessageBox::question(this,"Delete a Student", "Are you sure you want to delete "+selectedstudname+"?"))
        {
            selectedstudname.append("'");
            if(!db.isOpen()){
                connectDB();
                deleteStudfromDB(selectedstudname);
                setupDB();
                submit();
            }else{
                deleteStudfromDB(selectedstudname);
                submit();
            }
            clearFields();
            reloadStudlist();
            ui->listWidget->selectAll();
            if(ui->listWidget->item(0)==NULL){
                ui->tabWidget->setEnabled(false);
            }
        }
    }


}

//printing

void MainWindow::filePrintPreview(){

    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
    preview.exec();

}

//check grade field if empty. If true return Null
QString checkGradeInput(int val){
    return (!val==0 ? QString::number(val):NULL);
}

//solve for grade average
float gradeAverage(int val1, int val2, int val3, int val4){
    float res = (val1+val2+val3+val4)/4;
    return res;
}

//calc descriptive rating
int determineDR(float gradeAverage){

    int val = qRound(gradeAverage);
    int option;

    if(val>=90){
        option = 0;
    }
    if(val>=85 && val<=89){
        option = 1;
    }

    if(val>=80 && val<=84){
        option = 2;
    }

    if(val>=75 && val<=79){
        option = 3;
    }

    if(val<=74){
        option = 4;
    }

    return option;
}

QString printDR(int caseVal){
    switch (caseVal) {
    case 0:
        return "A";
        break;
    case 1:
        return "P";
        break;
    case 2:
        return "AP";
        break;
    case 3:
        return "D";
        break;
    default:
        return "B";
        break;
    }
}

int addsubpix(int stringLength){
    switch (stringLength) {
    case 1:
        return -30;
        break;
    case 2:
        return 10;
        break;
    case 3:
        return 20;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 80;
        break;
    default:
        return 120;
        break;
    }
}

//print preview
void MainWindow::printPreview(QPrinter *printer){
    //ui->textEdit->print(printer);
    printer->setPaperSize(QSize(8,10),QPrinter::Inch);
    printer->setOrientation(QPrinter::Landscape);
    QPainter p(printer);

    int w = printer->pageRect().width();
    int h = printer->pageRect().height();
    QRect page( 0, 0, w, h );

    // create a font appropriate to page size
    QFont defaultFont = p.font();
    defaultFont.setPixelSize( (w+h) / 150 );
    p.setFont( defaultFont );

    //draw card canvas
    QPixmap p1(":/graphics/data/images/p1.png");
    p.drawPixmap(page,p1);

    //draw text

    QString lrn = ui->lineEdit_studlrn->text();
    int ybalancer = 2950;
    int xbalancer = 250;
    if(lrn.length()==12){
        QStringList s = lrn.split(QRegExp("(?!^)"));
        p.drawText(8530-xbalancer,ybalancer,s[0]);//lrn
        p.drawText(8740-xbalancer,ybalancer,s[1]);//lrn
        p.drawText(8930-xbalancer,ybalancer,s[2]);//lrn
        p.drawText(9140-xbalancer,ybalancer,s[3]);//lrn
        p.drawText(9340-xbalancer,ybalancer,s[4]);//lrn
        p.drawText(9540-xbalancer,ybalancer,s[5]);//lrn
        p.drawText(9745-xbalancer,ybalancer,s[6]);//lrn
        p.drawText(9930-xbalancer,ybalancer,s[7]);//lrn
        p.drawText(10110-xbalancer,ybalancer,s[8]);//lrn
        p.drawText(10300-xbalancer,ybalancer,s[9]);//lrn
        p.drawText(10510-xbalancer,ybalancer,s[10]);//lrn
        p.drawText(10710-xbalancer,ybalancer,s[11]);//lrn
    }else{
        p.drawText(8530-xbalancer,ybalancer,0);//lrn
        p.drawText(8740-xbalancer,ybalancer,0);//lrn
        p.drawText(8930-xbalancer,ybalancer,0);//lrn
        p.drawText(9140-xbalancer,ybalancer,0);//lrn
        p.drawText(9340-xbalancer,ybalancer,0);//lrn
        p.drawText(9540-xbalancer,ybalancer,0);//lrn
        p.drawText(9745-xbalancer,ybalancer,0);//lrn
        p.drawText(9950-xbalancer,ybalancer,0);//lrn
        p.drawText(10160-xbalancer,ybalancer,0);//lrn
        p.drawText(10350-xbalancer,ybalancer,0);//lrn
        p.drawText(10560-xbalancer,ybalancer,0);//lrn
        p.drawText(10760-xbalancer,ybalancer,0);//lrn
    }

    p.drawText(6700,3350,ui->lineEdit_studname->text());//name
    if(!ui->spinBox_age->value()==0){
    p.drawText(6600,3650,QString::number(ui->spinBox_age->value()));//age
    }

    p.drawText(9100,3650,ui->comboBox_gender->currentText());//gender
    p.drawText(7250,4100-163,ui->lineEdit_yrsec->text());//year and section
    p.drawText(7000,4410-165,ui->lineEdit_curr->text());//curr
    p.drawText(7050,4710-160,ui->comboBox_beginSY->currentText() + " - " + ui->comboBox_endSY->currentText());//sy

    QFont titleFont = p.font();
    titleFont.setBold(true);
    titleFont.setPixelSize(200);
    p.setFont(titleFont);

    QString schoolName = ui->lineEdit_schoolname->text();
    //start trimming
    schoolName.remove(QRegExp("(high school)|(High School)"));

    //guide for centering the title
    QRect boxHSName(6200,1975,4750,500);
    p.drawText(boxHSName,Qt::AlignTop | Qt::AlignCenter,schoolName);
    QRect boxHS(6200,2180,4750,500);
    p.drawText(boxHS,Qt::AlignCenter,"High School");

    p.setFont(defaultFont);
    p.drawText(boxHS,Qt::AlignCenter | Qt::AlignTop,"\n\n"+ui->lineEdit_schooladd->text());
    QRect advisernameBox(8200,7340,1980,300);
    p.drawText(advisernameBox,Qt::AlignCenter,ui->lineEdit_advisername->text());

    QRect principalBox(5800,7950,2560,300);
    p.drawText(principalBox,Qt::AlignCenter,ui->lineEdit_principalname->text());

    //teacher's comments
    int tcXCor = 2030;
    int tcYbase = 1100;
    p.drawText(tcXCor,tcYbase,ui->lineEdit_tc1_1->text());
    p.drawText(tcXCor,tcYbase+240,ui->lineEdit_tc1_2->text());
    p.drawText(tcXCor,tcYbase+(240*2),ui->lineEdit_tc2_1->text());
    p.drawText(tcXCor,tcYbase+(240*3),ui->lineEdit_tc2_2->text());
    p.drawText(tcXCor,tcYbase+(240*4),ui->lineEdit_tc3_1->text());
    p.drawText(tcXCor,tcYbase+(240*5),ui->lineEdit_tc3_2->text());
    p.drawText(tcXCor,tcYbase+(240*6),ui->lineEdit_tc4_1->text());
    p.drawText(tcXCor,tcYbase+(240*7),ui->lineEdit_tc4_2->text());

    //transferee -soon
    /*
    p.drawText(1980,6140,"sdfsdfsdf");
    p.drawText(1980,6340,"sdfsdfsdf");
    */

    //next page
    printer->newPage();
    //draw card canvas
    QPixmap p2(":/graphics/data/images/p2.png");
    p.drawPixmap(page,p2);

    //pen color

    /*
    QColor r("red");
    p.setPen(r);
    */

    //drawguide

    /*
    for(int i=0; i<24; i++){
        p.drawRect(0,0,1000*i,1000*i);
        p.drawText(1000*i,1000*i,QString::number(1000*i));
    }
    */

    //grades
    int ycor = 1820-80;
    int xcor = 3070-170;

    //grade values
    //first grading
    int fil_gr1 = ui->spinBox_g_fil_gr1->value();
    int eng_gr1 = ui->spinBox_g_eng_gr1->value();
    int math_gr1= ui->spinBox_g_math_gr1->value();
    int sci_gr1 =ui->spinBox_g_sci_gr1->value();
    int ap_gr1 = ui->spinBox_g_ap_gr1->value();
//    int tve_gr1 = ui->spinBox_g_tve_gr1->value();
    int mu_gr1 = ui->spinBox_g_mu_gr1->value();
    int arts_gr1 = ui->spinBox_g_arts_gr1->value();
    int pe_gr1 = ui->spinBox_g_pe_gr1->value();
    int ht_gr1 = ui->spinBox_g_ht_gr1->value();
    int esp_gr1 = ui->spinBox_g_esp_gr1->value();
//    int icf_gr1 = ui->spinBox_g_icf_gr1->value();
//    int td_gr1 = ui->spinBox_g_td_gr1->value();
    //second grading
    int fil_gr2 = ui->spinBox_g_fil_gr2->value();
    int eng_gr2 = ui->spinBox_g_eng_gr2->value();
    int math_gr2= ui->spinBox_g_math_gr2->value();
    int sci_gr2 =ui->spinBox_g_sci_gr2->value();
    int ap_gr2 = ui->spinBox_g_ap_gr2->value();
//    int tve_gr2 = ui->spinBox_g_tve_gr2->value();
    int mu_gr2 = ui->spinBox_g_mu_gr2->value();
    int arts_gr2 = ui->spinBox_g_arts_gr2->value();
    int pe_gr2 = ui->spinBox_g_pe_gr2->value();
    int ht_gr2 = ui->spinBox_g_ht_gr2->value();
    int esp_gr2 = ui->spinBox_g_esp_gr2->value();
//    int icf_gr2 = ui->spinBox_g_icf_gr2->value();
//    int td_gr2 = ui->spinBox_g_td_gr2->value();
    //third grading
    int fil_gr3 = ui->spinBox_g_fil_gr3->value();
    int eng_gr3 = ui->spinBox_g_eng_gr3->value();
    int math_gr3= ui->spinBox_g_math_gr3->value();
    int sci_gr3 =ui->spinBox_g_sci_gr3->value();
    int ap_gr3 = ui->spinBox_g_ap_gr3->value();
//    int tve_gr3 = ui->spinBox_g_tve_gr3->value();
    int mu_gr3 = ui->spinBox_g_mu_gr3->value();
    int arts_gr3 = ui->spinBox_g_arts_gr3->value();
    int pe_gr3 = ui->spinBox_g_pe_gr3->value();
    int ht_gr3 = ui->spinBox_g_ht_gr3->value();
    int esp_gr3 = ui->spinBox_g_esp_gr3->value();
//    int icf_gr3 = ui->spinBox_g_icf_gr3->value();
//    int td_gr3 = ui->spinBox_g_td_gr3->value();
    //fourth grading
    int fil_gr4 = ui->spinBox_g_fil_gr4->value();
    int eng_gr4 = ui->spinBox_g_eng_gr4->value();
    int math_gr4= ui->spinBox_g_math_gr4->value();
    int sci_gr4 =ui->spinBox_g_sci_gr4->value();
    int ap_gr4 = ui->spinBox_g_ap_gr4->value();
//    int tve_gr4 = ui->spinBox_g_tve_gr4->value();
    int mu_gr4 = ui->spinBox_g_mu_gr4->value();
    int arts_gr4 = ui->spinBox_g_arts_gr4->value();
    int pe_gr4 = ui->spinBox_g_pe_gr4->value();
    int ht_gr4 = ui->spinBox_g_ht_gr4->value();
    int esp_gr4 = ui->spinBox_g_esp_gr4->value();
//    int icf_gr4 = ui->spinBox_g_icf_gr4->value();
//    int td_gr4 = ui->spinBox_g_td_gr4->value();

    //first grading
    p.drawText(xcor,ycor,checkGradeInput(fil_gr1));
    p.drawText(xcor,ycor+200,checkGradeInput(eng_gr1));
    p.drawText(xcor,ycor+400,checkGradeInput(math_gr1));
    p.drawText(xcor,ycor+600,checkGradeInput(sci_gr1));
    p.drawText(xcor,ycor+800-20,checkGradeInput(ap_gr1));
    //skip tve
    // p.drawText(xcor,ycor+1000-20,checkGradeInput(tve_gr1));
    //skip mapeh
    //p.drawText(xcor,ycor+1400-60,checkGradeInput(mu_gr1));
    p.drawText(xcor,ycor+1200-60,checkGradeInput(mu_gr1));
    p.drawText(xcor,ycor+1400-60,checkGradeInput(arts_gr1));
    p.drawText(xcor,ycor+1600-80,checkGradeInput(pe_gr1));
    p.drawText(xcor,ycor+1800-80,checkGradeInput(ht_gr1));
    p.drawText(xcor,ycor+2000-80,checkGradeInput(esp_gr1));
    // p.drawText(xcor,ycor+2200-80,checkGradeInput(icf_gr1));
    // p.drawText(xcor,ycor+2400-80,checkGradeInput(td_gr1));

    //2ndgrading
    p.drawText(xcor+270,ycor,checkGradeInput(fil_gr2));
    p.drawText(xcor+270,ycor+200,checkGradeInput(eng_gr2));
    p.drawText(xcor+270,ycor+400,checkGradeInput(math_gr2));
    p.drawText(xcor+270,ycor+600,checkGradeInput(sci_gr2));
    p.drawText(xcor+270,ycor+800-20,checkGradeInput(ap_gr2));
    //skip tve
    // p.drawText(xcor+270,ycor+1000-20,checkGradeInput(tve_gr2));
    //skip mapeh
    p.drawText(xcor+270,ycor+1200-60,checkGradeInput(mu_gr2));
    p.drawText(xcor+270,ycor+1400-60,checkGradeInput(arts_gr2));
    p.drawText(xcor+270,ycor+1600-80,checkGradeInput(pe_gr2));
    p.drawText(xcor+270,ycor+1800-80,checkGradeInput(ht_gr2));
    p.drawText(xcor+270,ycor+2000-80,checkGradeInput(esp_gr2));
    // p.drawText(xcor+270,ycor+2200-80,checkGradeInput(icf_gr2));
    // p.drawText(xcor+270,ycor+2400-80,checkGradeInput(td_gr2));

    //third grading
    p.drawText(xcor+540,ycor,checkGradeInput(fil_gr3));
    p.drawText(xcor+540,ycor+200,checkGradeInput(eng_gr3));
    p.drawText(xcor+540,ycor+400,checkGradeInput(math_gr3));
    p.drawText(xcor+540,ycor+600,checkGradeInput(sci_gr3));
    p.drawText(xcor+540,ycor+800-20,checkGradeInput(ap_gr3));
    //skip tve
    // p.drawText(xcor+540,ycor+1000-20,checkGradeInput(tve_gr3));
    //skip mapeh
    p.drawText(xcor+540,ycor+1200-60,checkGradeInput(mu_gr3));
    p.drawText(xcor+540,ycor+1400-60,checkGradeInput(arts_gr3));
    p.drawText(xcor+540,ycor+1600-80,checkGradeInput(pe_gr3));
    p.drawText(xcor+540,ycor+1800-80,checkGradeInput(ht_gr3));
    p.drawText(xcor+540,ycor+2000-80,checkGradeInput(esp_gr3));
    // p.drawText(xcor+540,ycor+2200-80,checkGradeInput(icf_gr3));
    // p.drawText(xcor+540,ycor+2400-80,checkGradeInput(td_gr3));

    //fourth grading
    p.drawText(xcor+810,ycor,checkGradeInput(fil_gr4));
    p.drawText(xcor+810,ycor+200,checkGradeInput(eng_gr4));
    p.drawText(xcor+810,ycor+400,checkGradeInput(math_gr4));
    p.drawText(xcor+810,ycor+600,checkGradeInput(sci_gr4));
    p.drawText(xcor+810,ycor+800-20,checkGradeInput(ap_gr4));
    //skip tve
    // p.drawText(xcor+810,ycor+1000-20,checkGradeInput(tve_gr4));
    //skip mapeh
    p.drawText(xcor+810,ycor+1200-60,checkGradeInput(mu_gr4));
    p.drawText(xcor+810,ycor+1400-60,checkGradeInput(arts_gr4));
    p.drawText(xcor+810,ycor+1600-80,checkGradeInput(pe_gr4));
    p.drawText(xcor+810,ycor+1800-80,checkGradeInput(ht_gr4));
    p.drawText(xcor+810,ycor+2000-80,checkGradeInput(esp_gr4));
    // p.drawText(xcor+810,ycor+2200-80,checkGradeInput(icf_gr4));
    // p.drawText(xcor+810,ycor+2400-80,checkGradeInput(td_gr4));

    //NR&DR
    float filAVE = gradeAverage(fil_gr1,fil_gr2,fil_gr3,fil_gr4);
    float engAVE = gradeAverage(eng_gr1,eng_gr2,eng_gr3,eng_gr4);
    float mathAVE =gradeAverage(math_gr1,math_gr2,math_gr3,math_gr4);
    float sciAVE = gradeAverage(sci_gr1,sci_gr2,sci_gr3,sci_gr4);
    float apAVE = gradeAverage(ap_gr1,ap_gr2,ap_gr3,ap_gr4);
    // float tveAVE = gradeAverage(tve_gr1,tve_gr2,tve_gr3,tve_gr4);
    float muAVE = gradeAverage(mu_gr1,mu_gr2,mu_gr3,mu_gr4);
    float artsAVE = gradeAverage(arts_gr1,arts_gr2,arts_gr3,arts_gr4);
    float peAVE = gradeAverage(pe_gr1,pe_gr2,pe_gr3,pe_gr4);
    float htAVE = gradeAverage(ht_gr1,ht_gr2,ht_gr3,ht_gr4);
    float espAVE = gradeAverage(esp_gr1,esp_gr2,esp_gr3,esp_gr4);
    // float icfAVE = gradeAverage(icf_gr1,icf_gr2,icf_gr3,icf_gr4);
    // float tdAVE = gradeAverage(td_gr1,td_gr2,td_gr3,td_gr4);

    //DR
    if(ui->checkBox_calcDescRat->checkState()){
        QString filDR = printDR(determineDR(filAVE));
        QString engDR = printDR(determineDR(engAVE));
        QString mathDR = printDR(determineDR(mathAVE));
        QString sciDR = printDR(determineDR(sciAVE));
        QString apDR = printDR(determineDR(apAVE));
//        QString tveDR = printDR(determineDR(tveAVE));
        QString muDR = printDR(determineDR(muAVE));
        QString artsDR = printDR(determineDR(artsAVE));
        QString peDR = printDR(determineDR(peAVE));
        QString htDR = printDR(determineDR(htAVE));
        QString espDR = printDR(determineDR(espAVE));
//        QString icfDR = printDR(determineDR(icfAVE));
//        QString tdDR = printDR(determineDR(tdAVE));

        p.drawText(xcor+1120-addsubpix(filDR.length()),ycor,filDR);
        p.drawText(xcor+1120-addsubpix(engDR.length()),ycor+200,engDR);
        p.drawText(xcor+1120-addsubpix(mathDR.length()),ycor+400,mathDR);
        p.drawText(xcor+1120-addsubpix(sciDR.length()),ycor+600,sciDR);
        p.drawText(xcor+1120-addsubpix(apDR.length()),ycor+800-20,apDR);
//      disabled tve
//      p.drawText(xcor+1120-addsubpix(tveDR.length()),ycor+1000-20,tveDR);
        p.drawText(xcor+1120-addsubpix(muDR.length()),ycor+1200-60,muDR);
        p.drawText(xcor+1120-addsubpix(artsDR.length()),ycor+1400-60,artsDR);
        p.drawText(xcor+1120-addsubpix(peDR.length()),ycor+1600-80,peDR);
        p.drawText(xcor+1120-addsubpix(htDR.length()),ycor+1800-80,htDR);
        p.drawText(xcor+1120-addsubpix(espDR.length()),ycor+2000-80,espDR);
//      disabled icf & td
//      p.drawText(xcor+1120-addsubpix(icfDR.length()),ycor+2200-80,icfDR);
//      p.drawText(xcor+1120-addsubpix(tdDR.length()),ycor+2400-80,tdDR);
    }

    //NR
    if(ui->checkBox_CalcNumRat->checkState()){
        int dlimit = ui->spinBox_NRAveDecLimit->value();
        p.drawText(xcor+1547-addsubpix(QString::number(filAVE,'f',dlimit).length()),ycor,QString::number(filAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(engAVE,'f',dlimit).length()),ycor+200,QString::number(engAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(mathAVE,'f',dlimit).length()),ycor+400,QString::number(mathAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(sciAVE,'f',dlimit).length()),ycor+600,QString::number(sciAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(apAVE,'f',dlimit).length()),ycor+800-20,QString::number(apAVE,'f',dlimit));
        //disabled tve
//        p.drawText(xcor+1498-addsubpix(QString::number(tveAVE,'f',dlimit).length()),ycor+1000-20,QString::number(tveAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(muAVE,'f',dlimit).length()),ycor+1200-60,QString::number(muAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(artsAVE,'f',dlimit).length()),ycor+1400-60,QString::number(artsAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(peAVE,'f',dlimit).length()),ycor+1800-60,QString::number(peAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(htAVE,'f',dlimit).length()),ycor+1600-60,QString::number(htAVE,'f',dlimit));
        p.drawText(xcor+1547-addsubpix(QString::number(espAVE,'f',dlimit).length()),ycor+2000-80,QString::number(espAVE,'f',dlimit));
        //disabled icf & td
//        p.drawText(xcor+1498-addsubpix(QString::number(icfAVE,'f',dlimit).length()),ycor+2200-80,QString::number(icfAVE,'f',dlimit));
//        p.drawText(xcor+1498-addsubpix(QString::number(tdAVE,'f',dlimit).length()),ycor+2400-80,QString::number(tdAVE,'f',dlimit));
    }

    //gen ave
    if(ui->checkBox_calcGenAve->checkState()){
      //removed tveAVE, icfAVE and tdAVE
        float genAVE = (filAVE+engAVE+mathAVE+sciAVE+apAVE+muAVE+artsAVE+peAVE+htAVE+espAVE)/10;
        int genAVEDecLimit = ui->spinBox_genAveDecLimit->value();
        QRect genAVEBox(3900,4480,1300,300);
        p.drawText(genAVEBox,Qt::AlignCenter,QString::number(genAVE,'f',genAVEDecLimit));
    }



    //attendance
    if(ui->checkBox_attenShow->checkState()){
        int attenYCor = 6598+158;
        int addY = 210;
        int attenXCor = 2290-78;

        int njun = ui->spinBox_n_jun->value();
        int njul = ui->spinBox_n_jul->value();
        int naug = ui->spinBox_n_aug->value();
        int nsep = ui->spinBox_n_sep->value();
        int noct = ui->spinBox_n_oct->value();
        int nnov = ui->spinBox_n_nov->value();
        int ndec = ui->spinBox_n_dec->value();
        int njan = ui->spinBox_n_jan->value();
        int nfeb = ui->spinBox_n_feb->value();
        int nmar = ui->spinBox_n_mar->value();
        int napr = ui->spinBox_n_apr->value();

        int pjun = ui->spinBox_p_jun->value();
        int pjul = ui->spinBox_p_jul->value();
        int paug = ui->spinBox_p_aug->value();
        int psep = ui->spinBox_p_sep->value();
        int poct = ui->spinBox_p_oct->value();
        int pnov = ui->spinBox_p_nov->value();
        int pdec = ui->spinBox_p_dec->value();
        int pjan = ui->spinBox_p_jan->value();
        int pfeb = ui->spinBox_p_feb->value();
        int pmar = ui->spinBox_p_mar->value();
        int papr = ui->spinBox_p_apr->value();

        int ajun = ui->spinBox_a_jun->value();
        int ajul = ui->spinBox_a_jul->value();
        int aaug = ui->spinBox_a_aug->value();
        int asep = ui->spinBox_a_sep->value();
        int aoct = ui->spinBox_a_oct->value();
        int anov = ui->spinBox_a_nov->value();
        int adec = ui->spinBox_a_dec->value();
        int ajan = ui->spinBox_a_jan->value();
        int afeb = ui->spinBox_a_feb->value();
        int amar = ui->spinBox_a_mar->value();
        int aapr = ui->spinBox_a_apr->value();

        int tjun = ui->spinBox_t_jun->value();
        int tjul = ui->spinBox_t_jul->value();
        int taug = ui->spinBox_t_aug->value();
        int tsep = ui->spinBox_t_sep->value();
        int toct = ui->spinBox_t_oct->value();
        int tnov = ui->spinBox_t_nov->value();
        int tdec = ui->spinBox_t_dec->value();
        int tjan = ui->spinBox_t_jan->value();
        int tfeb = ui->spinBox_t_feb->value();
        int tmar = ui->spinBox_t_mar->value();
        int tapr = ui->spinBox_t_apr->value();

        QList<int> ndays,pdays,adays,tdays;

        ndays << njun << njul << naug << nsep << noct << nnov << ndec << njan << nfeb << nmar << napr;
        pdays << pjun << pjul << paug << psep << poct << pnov << pdec << pjan << pfeb << pmar << papr;
        adays << ajun << ajul << aaug << asep << aoct << anov << adec << ajan << afeb << amar << aapr;
        tdays << tjun << tjul << taug << tsep << toct << tnov << tdec << tjan << tfeb << tmar << tapr;

        p.drawText(attenXCor+50,attenYCor,QString::number(ndays[0]));
        p.drawText(attenXCor+50,attenYCor+addY,QString::number(pdays[0]));
        p.drawText(attenXCor+50,attenYCor+(addY*2),QString::number(adays[0]));
        p.drawText(attenXCor+50,attenYCor+(addY*3),QString::number(tdays[0]));

        p.drawText(attenXCor+300+50,attenYCor,QString::number(ndays[1]));
        p.drawText(attenXCor+300+50,attenYCor+addY,QString::number(pdays[1]));
        p.drawText(attenXCor+300+50,attenYCor+(addY*2),QString::number(adays[1]));
        p.drawText(attenXCor+300+50,attenYCor+(addY*3),QString::number(tdays[1]));

        p.drawText(attenXCor+(300*2)+50,attenYCor,QString::number(ndays[2]));
        p.drawText(attenXCor+(300*2)+50,attenYCor+addY,QString::number(pdays[2]));
        p.drawText(attenXCor+(300*2)+50,attenYCor+(addY*2),QString::number(adays[2]));
        p.drawText(attenXCor+(300*2)+50,attenYCor+(addY*3),QString::number(tdays[2]));

        p.drawText(attenXCor+(300*3)+50,attenYCor,QString::number(ndays[3]));
        p.drawText(attenXCor+(300*3)+50,attenYCor+addY,QString::number(pdays[3]));
        p.drawText(attenXCor+(300*3)+50,attenYCor+(addY*2),QString::number(adays[3]));
        p.drawText(attenXCor+(300*3)+50,attenYCor+(addY*3),QString::number(tdays[3]));

        p.drawText(attenXCor+(300*4)+10,attenYCor,QString::number(ndays[4]));
        p.drawText(attenXCor+(300*4)+10,attenYCor+addY,QString::number(pdays[4]));
        p.drawText(attenXCor+(300*4)+10,attenYCor+(addY*2),QString::number(adays[4]));
        p.drawText(attenXCor+(300*4)+10,attenYCor+(addY*3),QString::number(tdays[4]));

        p.drawText(attenXCor+(280*5)+70,attenYCor,QString::number(ndays[5]));
        p.drawText(attenXCor+(280*5)+70,attenYCor+addY,QString::number(pdays[5]));
        p.drawText(attenXCor+(280*5)+70,attenYCor+(addY*2),QString::number(adays[5]));
        p.drawText(attenXCor+(280*5)+70,attenYCor+(addY*3),QString::number(tdays[5]));

        p.drawText(attenXCor+(280*6)+60,attenYCor,QString::number(ndays[6]));
        p.drawText(attenXCor+(280*6)+60,attenYCor+addY,QString::number(pdays[6]));
        p.drawText(attenXCor+(280*6)+60,attenYCor+(addY*2),QString::number(adays[6]));
        p.drawText(attenXCor+(280*6)+60,attenYCor+(addY*3),QString::number(tdays[6]));

        p.drawText(attenXCor+(280*7)+90,attenYCor,QString::number(ndays[7]));
        p.drawText(attenXCor+(280*7)+90,attenYCor+addY,QString::number(pdays[7]));
        p.drawText(attenXCor+(280*7)+90,attenYCor+(addY*2),QString::number(adays[7]));
        p.drawText(attenXCor+(280*7)+90,attenYCor+(addY*3),QString::number(tdays[7]));

        p.drawText(attenXCor+(280*8)+100,attenYCor,QString::number(ndays[8]));
        p.drawText(attenXCor+(280*8)+100,attenYCor+addY,QString::number(pdays[8]));
        p.drawText(attenXCor+(280*8)+100,attenYCor+(addY*2),QString::number(adays[8]));
        p.drawText(attenXCor+(280*8)+100,attenYCor+(addY*3),QString::number(tdays[8]));

        p.drawText(attenXCor+(280*9)+60,attenYCor,QString::number(ndays[9]));
        p.drawText(attenXCor+(280*9)+60,attenYCor+addY,QString::number(pdays[9]));
        p.drawText(attenXCor+(280*9)+60,attenYCor+(addY*2),QString::number(adays[9]));
        p.drawText(attenXCor+(280*9)+60,attenYCor+(addY*3),QString::number(tdays[9]));

        p.drawText(attenXCor+(280*10)+70,attenYCor,QString::number(ndays[10]));
        p.drawText(attenXCor+(280*10)+70,attenYCor+addY,QString::number(pdays[10]));
        p.drawText(attenXCor+(280*10)+70,attenYCor+(addY*2),QString::number(adays[10]));
        p.drawText(attenXCor+(280*10)+70,attenYCor+(addY*3),QString::number(tdays[10]));

        //for total days
        if(ui->checkBox_calcTDays->checkState()){
            int ndays_sum = 0;
            int pdays_sum = 0;;
            int adays_sum = 0;;
            int tdays_sum = 0;;

            for(int i = 0;  i<ndays.length();i++){
                ndays_sum += ndays[i];
            }
            for(int i = 0;  i<pdays.length();i++){
                pdays_sum += pdays[i];
            }
            for(int i = 0;  i<adays.length();i++){
                adays_sum += adays[i];
            }
            for(int i = 0;  i<tdays.length();i++){
                tdays_sum += tdays[i];
            }

            p.drawText(attenXCor+(280*11),attenYCor,QString::number(ndays_sum));
            p.drawText(attenXCor+(280*11),attenYCor+addY,QString::number(pdays_sum));
            p.drawText(attenXCor+(280*11),attenYCor+(addY*2),QString::number(adays_sum));
            p.drawText(attenXCor+(280*11),attenYCor+(addY*3),QString::number(tdays_sum));
        }

    }

    //admission
    int adminAdjustY = 170;
    QRect admissionBox(2300,7500-adminAdjustY, 3460,300);
    p.drawText(admissionBox,Qt::AlignVCenter,ui->lineEdit_elig_ad->text());

    QRect advUnitsBox(2150,7660-adminAdjustY, 3760,300);
    p.drawText(advUnitsBox,Qt::AlignVCenter,ui->lineEdit_adv_units->text());

    QRect lackUnitsBox(1650,7820-adminAdjustY, 4500,300);
    p.drawText(lackUnitsBox,Qt::AlignVCenter,ui->lineEdit_lack_units->text());

    QRect advsrBox(780,8210-adminAdjustY,1900,300);
    p.drawText(advsrBox,Qt::AlignCenter,ui->lineEdit_advisername->text());

    //stars
    QPixmap s1(":/graphics/data/images/onestar.png");
    QPixmap s2(":/graphics/data/images/twostars.png");
    QPixmap s3(":/graphics/data/images/threestars.png");

    int sxbase = 9100;
    int starybalancer = 90;

    //1st
    QRect s1box_1(sxbase,2530-starybalancer,300,240);
    QRect s2box_1(sxbase,2900-starybalancer,300,240);
    QRect s3box_1(sxbase,3260-starybalancer-40,300,240);
    QRect s4box_1(sxbase,3580-starybalancer-40,300,240);
    QRect s5box_1(sxbase,4000-starybalancer-40,300,240);
    QRect s6box_1(sxbase,4500-starybalancer-40,300,240);
    QRect s7box_1(sxbase,5140-starybalancer-40,300,240);
    QRect s8box_1(sxbase,5700-starybalancer-90,300,240);
    QRect s9box_1(sxbase,6060-starybalancer-100,300,240);
    QRect s10box_1(sxbase,6400-starybalancer-110,300,240);
    QRect s11box_1(sxbase,6840-starybalancer-130,300,240);
    QRect s12box_1(sxbase,7340-starybalancer-150,300,240);
    QRect s13box_1(sxbase,7740-starybalancer-150,300,240);
    QRect s14box_1(sxbase,8220-starybalancer-170,300,240);
    //2nd
    QRect s1box_2(sxbase+380,2530-starybalancer,300,240);
    QRect s2box_2(sxbase+380,2900-starybalancer,300,240);
    QRect s3box_2(sxbase+380,3260-starybalancer-40,300,240);
    QRect s4box_2(sxbase+380,3580-starybalancer-40,300,240);
    QRect s5box_2(sxbase+380,4000-starybalancer-40,300,240);
    QRect s6box_2(sxbase+380,4500-starybalancer-40,300,240);
    QRect s7box_2(sxbase+380,5140-starybalancer-40,300,240);
    QRect s8box_2(sxbase+380,5700-starybalancer-90,300,240);
    QRect s9box_2(sxbase+380,6060-starybalancer-100,300,240);
    QRect s10box_2(sxbase+380,6400-starybalancer-110,300,240);
    QRect s11box_2(sxbase+380,6840-starybalancer-130,300,240);
    QRect s12box_2(sxbase+380,7340-starybalancer-150,300,240);
    QRect s13box_2(sxbase+380,7740-starybalancer-150,300,240);
    QRect s14box_2(sxbase+380,8220-starybalancer-170,300,240);
    //3rd
    QRect s1box_3(sxbase+(380*2),2530-starybalancer,300,240);
    QRect s2box_3(sxbase+(380*2),2900-starybalancer,300,240);
    QRect s3box_3(sxbase+(380*2),3260-starybalancer-40,300,240);
    QRect s4box_3(sxbase+(380*2),3580-starybalancer-40,300,240);
    QRect s5box_3(sxbase+(380*2),4000-starybalancer-40,300,240);
    QRect s6box_3(sxbase+(380*2),4500-starybalancer-40,300,240);
    QRect s7box_3(sxbase+(380*2),5140-starybalancer-40,300,240);
    QRect s8box_3(sxbase+(380*2),5700-starybalancer-90,300,240);
    QRect s9box_3(sxbase+(380*2),6060-starybalancer-100,300,240);
    QRect s10box_3(sxbase+(380*2),6400-starybalancer-110,300,240);
    QRect s11box_3(sxbase+(380*2),6840-starybalancer-130,300,240);
    QRect s12box_3(sxbase+(380*2),7340-starybalancer-150,300,240);
    QRect s13box_3(sxbase+(380*2),7740-starybalancer-150,300,240);
    QRect s14box_3(sxbase+(380*2),8220-starybalancer-170,300,240);
    //4th
    QRect s1box_4(sxbase+(380*3),2530-starybalancer,300,240);
    QRect s2box_4(sxbase+(380*3),2900-starybalancer,300,240);
    QRect s3box_4(sxbase+(380*3),3260-starybalancer-40,300,240);
    QRect s4box_4(sxbase+(380*3),3580-starybalancer-40,300,240);
    QRect s5box_4(sxbase+(380*3),4000-starybalancer-40,300,240);
    QRect s6box_4(sxbase+(380*3),4500-starybalancer-40,300,240);
    QRect s7box_4(sxbase+(380*3),5140-starybalancer-40,300,240);
    QRect s8box_4(sxbase+(380*3),5700-starybalancer-90,300,240);
    QRect s9box_4(sxbase+(380*3),6060-starybalancer-100,300,240);
    QRect s10box_4(sxbase+(380*3),6400-starybalancer-110,300,240);
    QRect s11box_4(sxbase+(380*3),6840-starybalancer-130,300,240);
    QRect s12box_4(sxbase+(380*3),7340-starybalancer-150,300,240);
    QRect s13box_4(sxbase+(380*3),7740-starybalancer-150,300,240);
    QRect s14box_4(sxbase+(380*3),8220-starybalancer-170,300,240);
    //1st
    QRect s1box_1_2s(sxbase,2530+50-starybalancer,320,130);
    QRect s2box_1_2s(sxbase,2900+50-starybalancer,320,130);
    QRect s3box_1_2s(sxbase,3260+50-starybalancer-40,320,130);
    QRect s4box_1_2s(sxbase,3580+50-starybalancer-40,320,130);
    QRect s5box_1_2s(sxbase,4000+50-starybalancer-40,320,130);
    QRect s6box_1_2s(sxbase,4500+50-starybalancer-40,320,130);
    QRect s7box_1_2s(sxbase,5140+50-starybalancer-50,320,130);
    QRect s8box_1_2s(sxbase,5700+50-starybalancer-90,320,130);
    QRect s9box_1_2s(sxbase,6060+50-starybalancer-100,320,130);
    QRect s10box_1_2s(sxbase,6400+50-starybalancer-110,320,130);
    QRect s11box_1_2s(sxbase,6840+50-starybalancer-130,320,130);
    QRect s12box_1_2s(sxbase,7340+50-starybalancer-150,320,130);
    QRect s13box_1_2s(sxbase,7740+50-starybalancer-150,320,130);
    QRect s14box_1_2s(sxbase,8220+50-starybalancer-170,320,130);
    //2nd
    QRect s1box_2_2s(sxbase+380,2530+50-starybalancer,320,130);
    QRect s2box_2_2s(sxbase+380,2900+50-starybalancer,320,130);
    QRect s3box_2_2s(sxbase+380,3260+50-starybalancer-40,320,130);
    QRect s4box_2_2s(sxbase+380,3580+50-starybalancer-40,320,130);
    QRect s5box_2_2s(sxbase+380,4000+50-starybalancer-40,320,130);
    QRect s6box_2_2s(sxbase+380,4500+50-starybalancer-40,320,130);
    QRect s7box_2_2s(sxbase+380,5140+50-starybalancer-50,320,130);
    QRect s8box_2_2s(sxbase+380,5700+50-starybalancer-90,320,130);
    QRect s9box_2_2s(sxbase+380,6060+50-starybalancer-100,320,130);
    QRect s10box_2_2s(sxbase+380,6400+50-starybalancer-110,320,130);
    QRect s11box_2_2s(sxbase+380,6840+50-starybalancer-130,320,130);
    QRect s12box_2_2s(sxbase+380,7340+50-starybalancer-150,320,130);
    QRect s13box_2_2s(sxbase+380,7740+50-starybalancer-150,320,130);
    QRect s14box_2_2s(sxbase+380,8220+50-starybalancer-170,320,130);
    //3rd
    QRect s1box_3_2s(sxbase+(380*2),2530+50-starybalancer,320,130);
    QRect s2box_3_2s(sxbase+(380*2),2900+50-starybalancer,320,130);
    QRect s3box_3_2s(sxbase+(380*2),3260+50-starybalancer-40,320,130);
    QRect s4box_3_2s(sxbase+(380*2),3580+50-starybalancer-40,320,130);
    QRect s5box_3_2s(sxbase+(380*2),4000+50-starybalancer-40,320,130);
    QRect s6box_3_2s(sxbase+(380*2),4500+50-starybalancer-40,320,130);
    QRect s7box_3_2s(sxbase+(380*2),5140+50-starybalancer-50,320,130);
    QRect s8box_3_2s(sxbase+(380*2),5700+50-starybalancer-100,320,130);
    QRect s9box_3_2s(sxbase+(380*2),6060+50-starybalancer-90,320,130);
    QRect s10box_3_2s(sxbase+(380*2),6400+50-starybalancer-110,320,130);
    QRect s11box_3_2s(sxbase+(380*2),6840+50-starybalancer-130,320,130);
    QRect s12box_3_2s(sxbase+(380*2),7340+50-starybalancer-150,320,130);
    QRect s13box_3_2s(sxbase+(380*2),7740+50-starybalancer-150,320,130);
    QRect s14box_3_2s(sxbase+(380*2),8220+50-starybalancer-170,320,130);
    //4th
    QRect s1box_4_2s(sxbase+(380*3),2530+50-starybalancer,320,130);
    QRect s2box_4_2s(sxbase+(380*3),2900+50-starybalancer,320,130);
    QRect s3box_4_2s(sxbase+(380*3),3260+50-starybalancer-40,320,130);
    QRect s4box_4_2s(sxbase+(380*3),3580+50-starybalancer-40,320,130);
    QRect s5box_4_2s(sxbase+(380*3),4000+50-starybalancer-40,320,130);
    QRect s6box_4_2s(sxbase+(380*3),4500+50-starybalancer-40,320,130);
    QRect s7box_4_2s(sxbase+(380*3),5140+50-starybalancer-50,320,130);
    QRect s8box_4_2s(sxbase+(380*3),5700+50-starybalancer-90,320,130);
    QRect s9box_4_2s(sxbase+(380*3),6060+50-starybalancer-100,320,130);
    QRect s10box_4_2s(sxbase+(380*3),6400+50-starybalancer-110,320,130);
    QRect s11box_4_2s(sxbase+(380*3),6840+50-starybalancer-130,320,130);
    QRect s12box_4_2s(sxbase+(380*3),7340+50-starybalancer-150,320,130);
    QRect s13box_4_2s(sxbase+(380*3),7740+50-starybalancer-150,320,130);
    QRect s14box_4_2s(sxbase+(380*3),8220+50-starybalancer-170,320,130);
    //1st
    QRect s1box_1_3s(sxbase,2530-20-starybalancer,320,240);
    QRect s2box_1_3s(sxbase,2900-20-starybalancer,320,240);
    QRect s3box_1_3s(sxbase,3260-20-starybalancer-40,320,240);
    QRect s4box_1_3s(sxbase,3580-20-starybalancer-40,320,240);
    QRect s5box_1_3s(sxbase,4000-20-starybalancer-40,320,240);
    QRect s6box_1_3s(sxbase,4500-20-starybalancer-40,320,240);
    QRect s7box_1_3s(sxbase,5140-20-starybalancer-50,320,240);
    QRect s8box_1_3s(sxbase,5700-20-starybalancer-90,320,240);
    QRect s9box_1_3s(sxbase,6060-20-starybalancer-100,320,240);
    QRect s10box_1_3s(sxbase,6400-20-starybalancer-110,320,240);
    QRect s11box_1_3s(sxbase,6840-20-starybalancer-130,320,240);
    QRect s12box_1_3s(sxbase,7340-20-starybalancer-150,320,240);
    QRect s13box_1_3s(sxbase,7740-20-starybalancer-150,320,240);
    QRect s14box_1_3s(sxbase,8220-20-starybalancer-170,320,240);
    //2nd
    QRect s1box_2_3s(sxbase+380,2530-20-starybalancer,320,240);
    QRect s2box_2_3s(sxbase+380,2900-20-starybalancer,320,240);
    QRect s3box_2_3s(sxbase+380,3260-20-starybalancer-40,320,240);
    QRect s4box_2_3s(sxbase+380,3580-20-starybalancer-40,320,240);
    QRect s5box_2_3s(sxbase+380,4000-20-starybalancer-40,320,240);
    QRect s6box_2_3s(sxbase+380,4500-20-starybalancer-40,320,240);
    QRect s7box_2_3s(sxbase+380,5140-20-starybalancer-50,320,240);
    QRect s8box_2_3s(sxbase+380,5700-20-starybalancer-90,320,240);
    QRect s9box_2_3s(sxbase+380,6060-20-starybalancer-100,320,240);
    QRect s10box_2_3s(sxbase+380,6400-20-starybalancer-110,320,240);
    QRect s11box_2_3s(sxbase+380,6840-20-starybalancer-130,320,240);
    QRect s12box_2_3s(sxbase+380,7340-20-starybalancer-150,320,240);
    QRect s13box_2_3s(sxbase+380,7740-20-starybalancer-150,320,240);
    QRect s14box_2_3s(sxbase+380,8220-20-starybalancer-170,320,240);
    //3rd
    QRect s1box_3_3s(sxbase+(380*2),2530-20-starybalancer,320,240);
    QRect s2box_3_3s(sxbase+(380*2),2900-20-starybalancer,320,240);
    QRect s3box_3_3s(sxbase+(380*2),3260-20-starybalancer-40,320,240);
    QRect s4box_3_3s(sxbase+(380*2),3580-20-starybalancer-40,320,240);
    QRect s5box_3_3s(sxbase+(380*2),4000-20-starybalancer-40,320,240);
    QRect s6box_3_3s(sxbase+(380*2),4500-20-starybalancer-40,320,240);
    QRect s7box_3_3s(sxbase+(380*2),5140-20-starybalancer-50,320,240);
    QRect s8box_3_3s(sxbase+(380*2),5700-20-starybalancer-90,320,240);
    QRect s9box_3_3s(sxbase+(380*2),6060-20-starybalancer-100,320,240);
    QRect s10box_3_3s(sxbase+(380*2),6400-20-starybalancer-110,320,240);
    QRect s11box_3_3s(sxbase+(380*2),6840-20-starybalancer-130,320,240);
    QRect s12box_3_3s(sxbase+(380*2),7340-20-starybalancer-150,320,240);
    QRect s13box_3_3s(sxbase+(380*2),7740-20-starybalancer-150,320,240);
    QRect s14box_3_3s(sxbase+(380*2),8220-20-starybalancer-170,320,240);
    //4th
    QRect s1box_4_3s(sxbase+(380*3)-40,2530-20-starybalancer,320,240);
    QRect s2box_4_3s(sxbase+(380*3)-40,2900-20-starybalancer,320,240);
    QRect s3box_4_3s(sxbase+(380*3)-40,3260-20-starybalancer-40,320,240);
    QRect s4box_4_3s(sxbase+(380*3)-40,3580-20-starybalancer-40,320,240);
    QRect s5box_4_3s(sxbase+(380*3)-40,4000-20-starybalancer-40,320,240);
    QRect s6box_4_3s(sxbase+(380*3)-40,4500-20-starybalancer-40,320,240);
    QRect s7box_4_3s(sxbase+(380*3)-40,5140-20-starybalancer-50,320,240);
    QRect s8box_4_3s(sxbase+(380*3)-40,5700-20-starybalancer-90,320,240);
    QRect s9box_4_3s(sxbase+(380*3)-40,6060-20-starybalancer-100,320,240);
    QRect s10box_4_3s(sxbase+(380*3)-40,6400-20-starybalancer-110,320,240);
    QRect s11box_4_3s(sxbase+(380*3)-40,6840-20-starybalancer-130,320,240);
    QRect s12box_4_3s(sxbase+(380*3)-40,7340-20-starybalancer-150,320,240);
    QRect s13box_4_3s(sxbase+(380*3)-40,7740-20-starybalancer-150,320,240);
    QRect s14box_4_3s(sxbase+(380*3)-40,8220-20-starybalancer-170,320,240);

    //start drawing stars

    //first grading
    switch (ui->pb_star_pm_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s1box_1,s1);
        break;
    case 2:
        p.drawPixmap(s1box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s1box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_as_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s2box_1,s1);
        break;
    case 2:
        p.drawPixmap(s2box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s2box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_to_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s3box_1,s1);
        break;
    case 2:
        p.drawPixmap(s3box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s3box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_li_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s4box_1,s1);
        break;
    case 2:
        p.drawPixmap(s4box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s4box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_sd_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s5box_1,s1);
        break;
    case 2:
        p.drawPixmap(s5box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s5box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rt_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s6box_1,s1);
        break;
    case 2:
        p.drawPixmap(s6box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s6box_1_3s,s3);
        break;
    default:
        break;
    }

    switch (ui->pb_star_rhr_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s7box_1,s1);
        break;
    case 2:
        p.drawPixmap(s7box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s7box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pp_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s8box_1,s1);
        break;
    case 2:
        p.drawPixmap(s8box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s8box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_re_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s9box_1,s1);
        break;
    case 2:
        p.drawPixmap(s9box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s9box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pr_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s10box_1,s1);
        break;
    case 2:
        p.drawPixmap(s10box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s10box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_ecr_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s11box_1,s1);
        break;
    case 2:
        p.drawPixmap(s11box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s11box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_fr_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s12box_1,s1);
        break;
    case 2:
        p.drawPixmap(s12box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s12box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rl_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s13box_1,s1);
        break;
    case 2:
        p.drawPixmap(s13box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s13box_1_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_nu_gr_1->text().length()) {
    case 1:
        p.drawPixmap(s14box_1,s1);
        break;
    case 2:
        p.drawPixmap(s14box_1_2s,s2);
        break;
    case 3:
        p.drawPixmap(s14box_1_3s,s3);
        break;
    default:
        break;
    }
    //second grading
    switch (ui->pb_star_pm_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s1box_2,s1);
        break;
    case 2:
        p.drawPixmap(s1box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s1box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_as_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s2box_2,s1);
        break;
    case 2:
        p.drawPixmap(s2box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s2box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_to_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s3box_2,s1);
        break;
    case 2:
        p.drawPixmap(s3box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s3box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_li_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s4box_2,s1);
        break;
    case 2:
        p.drawPixmap(s4box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s4box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_sd_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s5box_2,s1);
        break;
    case 2:
        p.drawPixmap(s5box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s5box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rt_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s6box_2,s1);
        break;
    case 2:
        p.drawPixmap(s6box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s6box_2_3s,s3);
        break;
    default:
        break;
    }

    switch (ui->pb_star_rhr_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s7box_2,s1);
        break;
    case 2:
        p.drawPixmap(s7box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s7box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pp_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s8box_2,s1);
        break;
    case 2:
        p.drawPixmap(s8box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s8box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_re_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s9box_2,s1);
        break;
    case 2:
        p.drawPixmap(s9box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s9box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pr_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s10box_2,s1);
        break;
    case 2:
        p.drawPixmap(s10box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s10box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_ecr_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s11box_2,s1);
        break;
    case 2:
        p.drawPixmap(s11box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s11box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_fr_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s12box_2,s1);
        break;
    case 2:
        p.drawPixmap(s12box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s12box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rl_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s13box_2,s1);
        break;
    case 2:
        p.drawPixmap(s13box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s13box_2_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_nu_gr_2->text().length()) {
    case 1:
        p.drawPixmap(s14box_2,s1);
        break;
    case 2:
        p.drawPixmap(s14box_2_2s,s2);
        break;
    case 3:
        p.drawPixmap(s14box_2_3s,s3);
        break;
    default:
        break;
    }
    //third grading
    switch (ui->pb_star_pm_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s1box_3,s1);
        break;
    case 2:
        p.drawPixmap(s1box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s1box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_as_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s2box_3,s1);
        break;
    case 2:
        p.drawPixmap(s2box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s2box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_to_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s3box_3,s1);
        break;
    case 2:
        p.drawPixmap(s3box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s3box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_li_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s4box_3,s1);
        break;
    case 2:
        p.drawPixmap(s4box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s4box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_sd_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s5box_3,s1);
        break;
    case 2:
        p.drawPixmap(s5box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s5box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rt_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s6box_3,s1);
        break;
    case 2:
        p.drawPixmap(s6box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s6box_3_3s,s3);
        break;
    default:
        break;
    }

    switch (ui->pb_star_rhr_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s7box_3,s1);
        break;
    case 2:
        p.drawPixmap(s7box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s7box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pp_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s8box_3,s1);
        break;
    case 2:
        p.drawPixmap(s8box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s8box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_re_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s9box_3,s1);
        break;
    case 2:
        p.drawPixmap(s9box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s9box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pr_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s10box_3,s1);
        break;
    case 2:
        p.drawPixmap(s10box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s10box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_ecr_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s11box_3,s1);
        break;
    case 2:
        p.drawPixmap(s11box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s11box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_fr_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s12box_3,s1);
        break;
    case 2:
        p.drawPixmap(s12box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s12box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rl_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s13box_3,s1);
        break;
    case 2:
        p.drawPixmap(s13box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s13box_3_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_nu_gr_3->text().length()) {
    case 1:
        p.drawPixmap(s14box_3,s1);
        break;
    case 2:
        p.drawPixmap(s14box_3_2s,s2);
        break;
    case 3:
        p.drawPixmap(s14box_3_3s,s3);
        break;
    default:
        break;
    }

    //fourth grading
    switch (ui->pb_star_pm_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s1box_4,s1);
        break;
    case 2:
        p.drawPixmap(s1box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s1box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_as_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s2box_4,s1);
        break;
    case 2:
        p.drawPixmap(s2box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s2box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_to_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s3box_4,s1);
        break;
    case 2:
        p.drawPixmap(s3box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s3box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_li_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s4box_4,s1);
        break;
    case 2:
        p.drawPixmap(s4box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s4box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_sd_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s5box_4,s1);
        break;
    case 2:
        p.drawPixmap(s5box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s5box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rt_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s6box_4,s1);
        break;
    case 2:
        p.drawPixmap(s6box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s6box_4_3s,s3);
        break;
    default:
        break;
    }

    switch (ui->pb_star_rhr_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s7box_4,s1);
        break;
    case 2:
        p.drawPixmap(s7box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s7box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pp_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s8box_4,s1);
        break;
    case 2:
        p.drawPixmap(s8box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s8box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_re_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s9box_4,s1);
        break;
    case 2:
        p.drawPixmap(s9box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s9box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_pr_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s10box_4,s1);
        break;
    case 2:
        p.drawPixmap(s10box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s10box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_ecr_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s11box_4,s1);
        break;
    case 2:
        p.drawPixmap(s11box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s11box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_fr_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s12box_4,s1);
        break;
    case 2:
        p.drawPixmap(s12box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s12box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_rl_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s13box_4,s1);
        break;
    case 2:
        p.drawPixmap(s13box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s13box_4_3s,s3);
        break;
    default:
        break;
    }
    switch (ui->pb_star_nu_gr_4->text().length()) {
    case 1:
        p.drawPixmap(s14box_4,s1);
        break;
    case 2:
        p.drawPixmap(s14box_4_2s,s2);
        break;
    case 3:
        p.drawPixmap(s14box_4_3s,s3);
        break;
    default:
        break;
    }


}

void MainWindow::filePrint(){
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    dlg->setWindowTitle(tr("Print Document"));
    if (dlg->exec() == QDialog::Accepted) {

    }
    delete dlg;
}


void MainWindow::on_actionPrint_Preview_triggered()
{
    filePrintPreview();
}

void MainWindow::on_actionPrint_triggered()
{
    filePrint();
}

void MainWindow::on_lineEdit_studlrn_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toLong(&ok);
    if(!ok && arg1!=NULL){
        ui->label_studlrn->setText("Student LRN - can only contain numbers");
        ui->label_studlrn->setStyleSheet("QLabel{color: red}");
        ui->lineEdit_studlrn->selectAll();
    }else{
        ui->label_studlrn->setStyleSheet(this->styleSheet());
        ui->label_studlrn->setText("Student LRN");
    }

    int tleft = 12 - arg1.length();
    if(tleft<=9){
       ui->label_lrnLimit->setText("0"+QString::number(tleft));
    }else{
       ui->label_lrnLimit->setText(QString::number(tleft));
    }
}

void MainWindow::on_actionAbout_HSRCS_triggered()
{
    //initiate splash
    QString msg = "(HSRCS) High School Report Card System version 0.01 ";
    msg += "is a free and open-source software (FOSS) for automated report card generation and archiving.\n\n";
    msg += "Copyright © 2015 Mark Joseph J. Solidarios. \n\n";
    msg += "The developer would like to thank his teacher, Mrs. Salvacion P. Jade for ";
    msg += "the initiative and inspiration in pursuing this project.";
    msg += "\n\nFor comments and suggestions please email the developer, ";
    msg += "mjsolidarios@wvsu.edu.ph.\n\n";
    msg += "This program comes with ABSOLUTELY NO WARRANTY.";
    QMessageBox::about(this,"About HSRCS v0.01",msg);

}

void MainWindow::on_checkBox_calcGenAve_toggled(bool checked)
{
    ui->spinBox_genAveDecLimit->setEnabled(checked);
    ui->label_decp1->setEnabled(checked);
}

void MainWindow::on_checkBox_CalcNumRat_toggled(bool checked)
{
    ui->spinBox_NRAveDecLimit->setEnabled(checked);
    ui->label_decp2->setEnabled(checked);
}

void MainWindow::on_lineEdit_tc1_1_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_1->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_1->setText(QString::number(tleft));
    }
}

void MainWindow::on_lineEdit_tc1_2_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_2->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_2->setText(QString::number(tleft));
    }
}

void MainWindow::on_lineEdit_tc2_1_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_3->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_3->setText(QString::number(tleft));
    }
}

void MainWindow::on_lineEdit_tc2_2_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_4->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_4->setText(QString::number(tleft));
    }
}

void MainWindow::on_lineEdit_tc3_1_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_5->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_5->setText(QString::number(tleft));
    }
}

void MainWindow::on_lineEdit_tc3_2_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_6->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_6->setText(QString::number(tleft));
    }
}

void MainWindow::on_lineEdit_tc4_1_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_7->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_7->setText(QString::number(tleft));
    }
}

void MainWindow::on_lineEdit_tc4_2_textChanged(const QString &arg1)
{
    int tleft = 48 - arg1.length();
    if(tleft<=9){
       ui->label_tclimit_8->setText("0"+QString::number(tleft));
    }else{
       ui->label_tclimit_8->setText(QString::number(tleft));
    }
}

void MainWindow::on_actionExit_triggered()
{

    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation?","Are you sure you want to exit? Unsaved changes will be lost.", QMessageBox::Yes|QMessageBox::No)){
        db.close();
        qApp->exit();
    }
}
