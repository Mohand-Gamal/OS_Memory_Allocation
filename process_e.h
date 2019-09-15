#ifndef PROCESS_E_H
#define PROCESS_E_H

#include <QWidget>
#include <QObject>
#include <QVector>
#include "segment.h"

class process_e : public QWidget
{
    Q_OBJECT
public:
    explicit process_e( QWidget *parent = nullptr);
    void set_size(unsigned int size);
    ~process_e();
private:
    static unsigned int next_id;
    unsigned int ID;
    QVector<Segment*>segments_arr;
    unsigned int segments_n;

    friend class simulate;
};

#endif // PROCESS_E_H
