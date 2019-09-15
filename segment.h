#ifndef SEGMENT_H
#define SEGMENT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <stdlib.h>
#include <QString>
#include <QLabel>

#define SEGMENT_WIDTH 200
#define MAPPING_VALUE 2

extern unsigned int mapping_value;

typedef enum
{
    normal,hole,old_process
}SegmentType;

class Segment : public QWidget
{
    Q_OBJECT
public:
    explicit Segment(QWidget *parent = nullptr);
    void InputSegment(QString name, unsigned int size);
    void DrawSegment(short x, short y);
    ~Segment();
private:
    unsigned int segment_ID; //process no
    unsigned int starting_address;
    unsigned int size;
    bool allocated;
    SegmentType type;
    QString name;
    QPushButton *btn;
    QLabel *starting_point;
    QLabel *finishing_point;
    unsigned short color;
    friend class process_e;
    friend class simulate;
};

#endif // SEGMENT_H
