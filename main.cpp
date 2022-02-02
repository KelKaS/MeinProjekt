#include <QtCore>
#include <QtGui>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   auto *mainWindow = new QWidget();
   mainWindow->setMinimumSize(700, 350);

   auto *slider = new QSlider(Qt::Horizontal);
   slider-> setMinimum(0);
   slider-> setMaximum(100);

   auto *pb = new QPushButton();
   pb->setText("Close");

   auto *progress = new QProgressBar();
   progress->setMinimum(0);
   progress->setMaximum(100);

   auto *Ausgabe = new QLabel();

   auto *Eingabe = new QLineEdit();    


   auto *layout = new QHBoxLayout();
   layout->addWidget(pb);
   layout->addWidget(slider);
   layout->addWidget(progress);

   
   auto *layout1 = new QVBoxLayout(mainWindow);
   layout1->addStretch();
   layout1->addLayout(layout);
   layout1->addWidget(Eingabe);
   layout1->addWidget(Ausgabe);
   layout1->addStretch();


   QObject::connect(pb, &QPushButton::clicked, mainWindow, &QWidget::close);
   QObject::connect(slider, &QSlider::valueChanged, progress, &QProgressBar::setValue);
   QObject::connect(Eingabe, &QLineEdit::textChanged, Ausgabe, &QLabel::setText);
   
   mainWindow->show();

   return app.exec();
}
