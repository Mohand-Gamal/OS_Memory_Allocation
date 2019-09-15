#include "process_e.h"
unsigned int process_e::next_id=0;

process_e::process_e(QWidget *parent) : QWidget(parent)
{
    ID=++next_id;
}

void process_e::set_size(unsigned int size)
{
    segments_n=size;
    for(unsigned int i=0;i<segments_n;i++)
    {
        Segment *newsegment=new Segment(this);
        newsegment->segment_ID=ID;
        newsegment->type=normal;
        segments_arr.push_back(newsegment);
    }
}


process_e::~process_e()
{
    for(unsigned int i=0;i<segments_n;i++)
    {
        delete segments_arr[i];
    }
}
