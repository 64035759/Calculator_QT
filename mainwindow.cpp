#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_First;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2_3,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3_2,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_razdelit,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_x,SIGNAL(clicked()), this, SLOT(math_operations()));



    ui ->pushButton_razdelit -> setCheckable(true);
    ui ->pushButton_plus -> setCheckable(true);
    ui ->pushButton_x -> setCheckable(true);
    ui ->pushButton_minus -> setCheckable(true);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: digits_numbers()
{

   QPushButton *button = (QPushButton *)sender();

   double all_numbers;
   QString new_label;

   all_numbers = (ui ->label -> text() + button ->text()).toDouble();
   new_label = QString :: number(all_numbers,'g', 15 );

    ui-> label->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui -> label -> text().contains('.')))
    ui-> label->setText(ui->label->text() +".");

}
void MainWindow :: operations()
{

   QPushButton *button = (QPushButton *)sender();

   double all_numbers;
   QString new_label;
if (button ->text() == "+/-")
    {
   all_numbers = (ui ->label ->text()).toDouble();
   all_numbers = all_numbers * -1;
   new_label = QString :: number(all_numbers,'g', 15 );

    ui-> label->setText(new_label);
    }
 else if(button ->text() == "%")
    {
all_numbers = (ui ->label ->text()).toDouble();
all_numbers = all_numbers * 0.01;
new_label = QString :: number(all_numbers,'g', 15 );

ui-> label->setText(new_label);
    }
}



void MainWindow::math_operations()
{
   QPushButton *button = (QPushButton *)sender();


   num_First = ui-> label -> text().toDouble();

   ui-> label -> setText("");
   button -> setChecked(true);

}




void MainWindow::on_pushButton_clicked()
{


}

void MainWindow::on_pushButton_ravno_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->label ->text().toDouble();


    if(ui->pushButton_plus-> isChecked())
    {
        labelNumber = num_First + num_second;
        new_label = QString :: number(labelNumber,'g', 15 );

         ui-> label->setText(new_label);
         ui-> pushButton_plus ->setChecked(false);
    }
     else if(ui->pushButton_minus ->isChecked())
    {
        labelNumber = num_First - num_second;
        new_label = QString :: number(labelNumber,'g', 15 );

         ui-> label->setText(new_label);
         ui-> pushButton_minus ->setChecked(false);
    }
    else if(ui->pushButton_razdelit -> isChecked())
    {
        if(num_second == 0)
        {
            ui-> label->setText("0");

        }
        else
        {


        labelNumber = num_First / num_second;
        new_label = QString :: number(labelNumber,'g', 15 );

         ui-> label->setText(new_label);
         }
         ui-> pushButton_razdelit ->setChecked(false);


    } else if(ui -> pushButton_x ->isChecked())
    {
        labelNumber = num_First * num_second;
        new_label = QString :: number(labelNumber,'g', 15 );

         ui-> label->setText(new_label);
         ui-> pushButton_x ->setChecked(false);

    }
}






