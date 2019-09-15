#ifndef SIMULATE_H
#define SIMULATE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include<QPushButton>
#include <stdlib.h>
#include <QString>
#include<QSpinBox>
#include<QComboBox>
#include <QDebug>
#include <QVector>
#include "process_e.h"
#include "segment.h"
#include <QLineEdit>
#include <QFont>
#include <QtAlgorithms>
#include<QMessageBox>
#include<iterator>
#include <QApplication>
#include <QProcess>

class simulate : public QWidget
{
    Q_OBJECT
public:
    explicit simulate(QWidget *parent = nullptr);
    void First_Fit();
    void Best_Fit();
    void De_Allocate(unsigned int index);
    void DrawOutput();
    ~simulate();
private:
    process_e *entry_process;
    QVector<Segment*>memory;
    unsigned int memory_size;
    unsigned int holes;
    static unsigned int holes_counter;
    unsigned int segments;
    static unsigned int segment_counter;
    QString allocation_type;
    QMessageBox *error;
    QPushButton *total_memory_size_btn;
    QPushButton *number_holes_btn;
    QPushButton *hole_submit_btn;
    QPushButton *no_segments_btn;
    QPushButton *segment_submit_btn;
    QPushButton *allocation_method_btn;
    QPushButton *dealloc_btn;
    QPushButton *restart_btn;
    QLabel *memory_size_label;
    QLabel *number_holes_label;
    QLabel *hole_address_label;
    QLabel *hole_size_label;
    QLabel *no_segments_label;
    QLabel *segment_name_label;
    QLabel *segment_size_label;
    QLabel *allocation_method_label;
    QLabel *deallocation_label;
    QSpinBox *total_memory_size;
    QSpinBox *number_holes;
    QSpinBox *hole_address;
    QSpinBox *hole_size;
    QSpinBox *no_segments;
    QLineEdit *segment_name;
    QSpinBox *segment_size;
    QComboBox *dealloc_options;
    QComboBox *allocation_method;
    void cal_old();
    void process_done();
    void first_fit();
    void allocate_segment_ff(QVector<Segment*> &memory,Segment* target);
    bool check_allocacation_ff();
    void best_fit();
    void allocate_segment_bf(QVector<Segment*> &memory,Segment* target);
    bool check_allocacation_bf();
    void worst_fit();
    void allocate_segment_wf(QVector<Segment*> &memory,Segment* target);
    bool check_allocacation_wf();
    void compact_holes();
public slots:
    void memory_size_chosen();
    void no_holes_chosen();
    void Input_holes();
    void no_segments_chosen();
    void Input_segments();
    void alloc_method_chosen();
    void deallocate_process();
    void restart();
signals:

};

#endif // SIMULATE_H
