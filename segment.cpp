#include "segment.h"



QString colors[8] = {"cyan", "magenta","yellow", "red", "darkCyan", "darkMagenta",
                       "green",  "blue"};

Segment::Segment(QWidget *parent) : QWidget(parent)
{
    allocated=false;
    btn=new QPushButton;
    btn->setParent(this);
    btn->setEnabled(false);
    starting_point=new QLabel;
    starting_point->setParent(this);
    finishing_point=new QLabel;
    finishing_point->setParent(this);
}

void Segment::InputSegment(QString name, unsigned int size)
{
    this->name=name;
    this->size=size;
}

void Segment::DrawSegment(short x, short y)
{
    color=(segment_ID-1)%8;
    QString s;
    switch(type)
    {
        case normal:
        btn->setStyleSheet("color: black;"
                           "background-color:"+colors[color]+";"
                           "border: 1px solid black;"
                           );

        s="P"+QString::number(segment_ID)+" : "+name;
            break;

        case hole:
        btn->setStyleSheet("color: black;"
                           "background-color: white;"
                           "border: 1px solid black;"
                           );
        s="Hole";
            break;

        case old_process:
        btn->setStyleSheet("color: black;"
                           "background-color: lightGray;"
                           "border: 1px solid black;"
                           );
        s="Old Process"+QString::number(segment_ID);
            break;
    }
    btn->setText(s);
    btn->setGeometry(x,y,SEGMENT_WIDTH,this->size/mapping_value);
    starting_point->setText(QString::number(starting_address));
    starting_point->setStyleSheet("background-color: rgba(0,0,0,0%)");
    starting_point->setGeometry(x-30,y-10,50,20);
    finishing_point->setText(QString::number(starting_address+size));
    finishing_point->setStyleSheet("background-color: rgba(0,0,0,0%)");
    finishing_point->setGeometry(x-30,(y+this->size/mapping_value)-10,50,20);
    btn->show();
    starting_point->show();
    finishing_point->show();
}

Segment::~Segment()
{
    delete btn;
    delete starting_point;
    delete finishing_point;
}
