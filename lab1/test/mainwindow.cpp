#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,600);
    scene = new QGraphicsScene(this);
    ui->graphicsView->resize(600,600);
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0,500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rotateButton_clicked()
{
    foreach(QGraphicsItem *item, scene->selectedItems()) {
        item->setRotation(item->rotation() + ui->angleSpinBox->value());
    }
}


void MainWindow::on_scaleButton_clicked()
{
    foreach(QGraphicsItem* item, scene->selectedItems()) {
        item->setScale(ui->scaleSpinBox->value());
        if (typeid (*(item)) == typeid (Rectangle)){
            Rectangle* rect = qgraphicsitem_cast<Rectangle*>(item);
            rect->SetHeight(ui->scaleSpinBox->value()*rect->GetHeight());
            rect->SetWidth(ui->scaleSpinBox->value()*rect->GetWidth());
            ui->heightSpinBox->setValue(rect->GetHeight());
            ui->widthSpinBox->setValue(rect->GetWidth());
        } else if (typeid (*(item)) == typeid (Circle)){
            Circle* circle = qgraphicsitem_cast<Circle*>(item);
            circle->SetRadius(ui->scaleSpinBox->value()*circle->GetRadius());
            ui->radiusSpinBox->setValue(circle->GetRadius());
        } else if (typeid (*(item)) == typeid (Hexagon)){
            Hexagon* hexagon = qgraphicsitem_cast<Hexagon*>(item);
            hexagon->SetRadius(ui->scaleSpinBox->value()*hexagon->GetRadius());
            ui->radiusSpinBox->setValue(hexagon->GetRadius());
        } else if (typeid (*(item)) == typeid (Pentagon)){
            Pentagon* pentagon = qgraphicsitem_cast<Pentagon*>(item);
            pentagon->SetRadius(ui->scaleSpinBox->value()*pentagon->GetRadius());
            ui->radiusSpinBox->setValue(pentagon->GetRadius());
        } else if (typeid (*(item)) == typeid (Triangle)){
            Triangle* triangle = qgraphicsitem_cast<Triangle*>(item);
            triangle->SetRadius(ui->scaleSpinBox->value()*triangle->GetRadius());
            ui->radiusSpinBox->setValue(triangle->GetRadius());
        }
    }
}

void MainWindow::on_setPushButton_clicked()
{
    foreach(QGraphicsItem* item, scene->selectedItems()) {
        if (typeid (*(item)) == typeid (Rectangle)){
            Rectangle* rect = qgraphicsitem_cast<Rectangle*>(item);
            scene->removeItem(rect);
            Rectangle* rectNew = new Rectangle(ui->widthSpinBox->value(), ui->heightSpinBox->value(), rect->GetXCenter(), rect->GetYCenter());
            rectNew->setPos(rect->pos().x(),rect->pos().y());
            rectNew->SetXCenter(ui->XspinBox->value());
            rectNew->SetYCenter(ui->YspinBox->value());
            delete rect;
            scene->addItem(rectNew);
        } else if (typeid (*(item)) == typeid (Circle)){
            Circle* circle = qgraphicsitem_cast<Circle*>(item);
            scene->removeItem(circle);
            Circle* circleNew = new Circle(circle->GetXCenter(), circle->GetYCenter(), ui->radiusSpinBox->value());
            circleNew->setPos(circle->pos().x(),circle->pos().y());
            circleNew->SetXCenter(ui->XspinBox->value());
            circleNew->SetYCenter(ui->YspinBox->value());
            delete circle;
            scene->addItem(circleNew);
        } else if (typeid (*(item)) == typeid (Hexagon)){
            Hexagon* hexagon = qgraphicsitem_cast<Hexagon*>(item);
            scene->removeItem(hexagon);
            Hexagon* hexagonNew = new Hexagon(hexagon->GetXCenter(), hexagon->GetYCenter(), ui->radiusSpinBox->value());
            hexagonNew->setPos(hexagon->pos().x(),hexagon->pos().y());
            hexagonNew->SetXCenter(ui->XspinBox->value());
            hexagonNew->SetYCenter(ui->YspinBox->value());
            delete hexagon;
            scene->addItem(hexagonNew);
        } else if (typeid (*(item)) == typeid (Pentagon)){
            Pentagon* pentagon = qgraphicsitem_cast<Pentagon*>(item);
            scene->removeItem(pentagon);
            Pentagon* pentagonNew = new Pentagon(pentagon->GetXCenter(), pentagon->GetYCenter(), ui->radiusSpinBox->value());
            pentagonNew->setPos(pentagon->pos().x(),pentagon->pos().y());
            pentagonNew->SetXCenter(ui->XspinBox->value());
            pentagonNew->SetYCenter(ui->YspinBox->value());
            delete pentagon;
            scene->addItem(pentagonNew);
        } else if (typeid (*(item)) == typeid (Triangle)){
            Triangle* triangle = qgraphicsitem_cast<Triangle*>(item);
            scene->removeItem(triangle);
            Triangle* triangleNew = new Triangle(triangle->GetXCenter(), triangle->GetYCenter(), ui->radiusSpinBox->value());
            triangleNew->setPos(triangle->pos().x(),triangle->pos().y());
            triangleNew->SetXCenter(ui->XspinBox->value());
            triangleNew->SetYCenter(ui->YspinBox->value());
            delete triangle;
            scene->addItem(triangleNew);
        }
    }
}

void MainWindow::on_rectanglePushButton_clicked()
{
    Rectangle *item = new Rectangle(60,60,0,0);
    ui->heightSpinBox->setValue(item->GetHeight());
    ui->widthSpinBox->setValue(item->GetWidth());
    item->setPos(50,50);
    scene->addItem(item);
}

void MainWindow::on_trianglePushButton_clicked()
{
    Triangle *item = new Triangle(0,0,20);
    ui->radiusSpinBox->setValue(item->GetRadius());
    item->setPos(50,50);
    scene->addItem(item);
    qDebug() << "hello";
}



void MainWindow::on_pentagonPushButton_clicked()
{
    Pentagon *item = new Pentagon(0,0,20);
    ui->radiusSpinBox->setValue(item->GetRadius());
    item->setPos(50,50);
    scene->addItem(item);

}

void MainWindow::on_hexagonPushButton_clicked()
{
    Hexagon *item = new Hexagon(0,0,20);
    ui->radiusSpinBox->setValue(item->GetRadius());
    item->setPos(50,50);
    scene->addItem(item);
}

void MainWindow::on_circlePushButton_clicked()
{
    Circle *item = new Circle(0,0,20);
    ui->radiusSpinBox->setValue(item->GetRadius());
    item->setPos(50,50);
    scene->addItem(item);

}

void MainWindow::on_areaPushButton_clicked()
{
    foreach(QGraphicsItem* item, scene->selectedItems()) {
         if (typeid (*(item)) == typeid (Rectangle)){
            Rectangle* rect = qgraphicsitem_cast<Rectangle*>(item);
            ui->AreaAndPerimetrLabel->setText("Area: " + rect->GetArea() + "\nPerimetr: " + rect->GetPerimeter());
         } else if (typeid (*(item)) == typeid (Hexagon)){
            Hexagon* hexagon = qgraphicsitem_cast<Hexagon*>(item);
            ui->AreaAndPerimetrLabel->setText("Area: " + hexagon->GetArea() + "\nPerimetr: " + hexagon->GetPerimeter());
         } else if (typeid (*(item)) == typeid (Pentagon)){
            Pentagon* pentagon = qgraphicsitem_cast<Pentagon*>(item);
            ui->AreaAndPerimetrLabel->setText("Area: " + pentagon->GetArea() + "\nPerimetr: " + pentagon->GetPerimeter());
         } else if (typeid (*(item)) == typeid (Triangle)){
            Triangle* triangle = qgraphicsitem_cast<Triangle*>(item);
            ui->AreaAndPerimetrLabel->setText("Area: " + triangle->GetArea() + "\nPerimetr: " + triangle->GetPerimeter());
         } else if (typeid (*(item)) == typeid (Circle)){
            Circle* circle = qgraphicsitem_cast<Circle*>(item);
            ui->AreaAndPerimetrLabel->setText("Area: " + circle->GetArea() + "\nPerimetr: " + circle->GetPerimeter());
         }
    }
}
