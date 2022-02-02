/***********************************************************************
*
* Copyright (c) 2021-2022 Barbara Geller and Ansel Sermersheim
*
* This example is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/
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