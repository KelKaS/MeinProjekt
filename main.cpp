













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
   
   
   
   auto *layout = new QHBoxLayout(mainWindow);
   layout->addWidget(pb);
   layout->addWidget(slider);
   layout->addWidget(progress);
   QObject::connect(pb, &QPushButton::clicked, mainWindow, &QWidget::close);
   QObject::connect(slider, &QSlider::valueChanged, progress, &QProgressBar::setValue);
   mainWindow->show();

   return app.exec();
}
