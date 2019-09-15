 #include "simulate.h"

unsigned int simulate::holes_counter=0;
unsigned int simulate::segment_counter=0;
unsigned int mapping_value;

simulate::simulate(QWidget *parent) : QWidget(parent)
{
    this->setFixedWidth(1100);
    this->setMinimumHeight(600);

    error= new QMessageBox(this);
    /********************************************************************Push Buttons***************************************************************/

    /* Declaration */
    total_memory_size_btn = new QPushButton("Submit",this);
    number_holes_btn = new QPushButton("Submit",this);
    hole_submit_btn = new QPushButton("Submit",this);
    no_segments_btn = new  QPushButton("Submit",this);
    segment_submit_btn = new QPushButton("Submit",this);
    allocation_method_btn = new QPushButton("Submit",this);
    dealloc_btn =new QPushButton("Deallocate",this);
    restart_btn=new QPushButton("Restart",this);
    /* Geometry */
    total_memory_size_btn->setGeometry(575,300,75,25);

    /* Visibility */
    total_memory_size_btn->show();
    number_holes_btn->hide();
    hole_submit_btn->hide();
    no_segments_btn->hide();
    segment_submit_btn->hide();
    allocation_method_btn->hide();
    dealloc_btn->hide();
    restart_btn->hide();
    /********************************************************************Spin Boxes*****************************************************************/

    /* Declaration */
    total_memory_size = new QSpinBox;
    number_holes = new QSpinBox;
    hole_address = new QSpinBox;
    hole_size = new QSpinBox;
    no_segments = new QSpinBox;
    segment_size = new QSpinBox;

    /* SetParent */
    total_memory_size->setParent(this);
    number_holes->setParent(this);
    hole_address->setParent(this);
    hole_size->setParent(this);
    no_segments->setParent(this);
    segment_size->setParent(this);

    /* Geometry */
    total_memory_size->setGeometry(425,300,75,25);

    /* Visibility */
    total_memory_size->show();
    number_holes->hide();
    hole_address->hide();
    hole_size->hide();
    no_segments->hide();
    segment_size->hide();

    /* Minimum */
    total_memory_size->setMinimum(1);

    /* Maximum */
    total_memory_size->setMaximum(1000000000);

    /***********************************************************************Labels******************************************************************/

    /* Declaration */
    memory_size_label = new QLabel;
    number_holes_label= new QLabel;
    hole_address_label= new QLabel;
    hole_size_label= new QLabel;
    no_segments_label= new QLabel;
    segment_name_label= new QLabel;
    segment_size_label= new QLabel;
    allocation_method_label= new QLabel;
    deallocation_label=new QLabel;

    /* SetParent */
    memory_size_label->setParent(this);
    number_holes_label->setParent(this);
    hole_address_label->setParent(this);
    hole_size_label->setParent(this);
    no_segments_label->setParent(this);
    segment_name_label->setParent(this);
    segment_size_label->setParent(this);
    allocation_method_label->setParent(this);
    deallocation_label->setParent(this);
    /* Geometry */
    memory_size_label->setGeometry(450,250,250,30);

    /* Text */
    memory_size_label->setText("Please Enter Total Memory Size in Byte: ");

    /* Font */

    /* Visibility */
    memory_size_label->show();
    number_holes_label->hide();
    hole_address_label->hide();
    hole_size_label->hide();
    no_segments_label->hide();
    segment_name_label->hide();
    segment_size_label->hide();
    allocation_method_label->hide();
    deallocation_label->hide();
    /********************************************************************Input Dialogs**************************************************************/

    /* Declaration */
    segment_name = new QLineEdit ("");

    /* SetParent */
    segment_name->setParent(this);

    /* Visibility */
    segment_name->hide();

    /********************************************************************Combo Boxes****************************************************************/

    /* Declaration */
    allocation_method =new QComboBox;
    dealloc_options= new QComboBox;

    /* SetParent */
    allocation_method->setParent(this);
    dealloc_options->setParent(this);

    /* Visibility */
    allocation_method->hide();
    dealloc_options->hide();

    /******************************************************************Signals********************************************************************/
    connect(total_memory_size_btn,SIGNAL(pressed()),this,SLOT(memory_size_chosen()));
}

void simulate::memory_size_chosen(){

    memory_size=total_memory_size->value();
    mapping_value=MAPPING_VALUE*memory_size/1000;
    /********************************************************************Push Buttons***************************************************************/
    /* Geometry */
    allocation_method_btn->setGeometry(575,300,75,25);
    restart_btn->setGeometry(60,550,200,30);
    /* Visibility */
    total_memory_size_btn->hide();
    number_holes_btn->hide();
    hole_submit_btn->hide();
    no_segments_btn->hide();
    segment_submit_btn->hide();
    allocation_method_btn->show();
    restart_btn->show();
    /********************************************************************ComboBox*****************************************************************/

    /* Geometry */
    allocation_method->setGeometry(425,300,75,25);

    /* Visibility */
    allocation_method->show();

    /* Options */
    allocation_method->addItem("First Fit");
    allocation_method->addItem("Best Fit");
    allocation_method->addItem("Worst Fit");
    /********************************************************************labels*****************************************************************/

    /* Geometry */
    allocation_method_label->setGeometry(430,250,250,30);

    /* Text */
    allocation_method_label->setText("Please Choose Method of Memory Allocation: ");

    /* Visibility */
    memory_size_label->hide();
    number_holes_label->hide();
    hole_address_label->hide();
    hole_size_label->hide();
    no_segments_label->hide();
    segment_name_label->hide();
    segment_size_label->hide();
    allocation_method_label->show();

    /******************************************************************Signals********************************************************************/
    connect(allocation_method_btn,SIGNAL(pressed()),this,SLOT(alloc_method_chosen()));
    connect(restart_btn,SIGNAL(pressed()),this,SLOT(restart()));

}
void simulate::alloc_method_chosen()
{
    allocation_type=allocation_method->currentText();

    allocation_method->hide();
   /********************************************************************Push Buttons***************************************************************/

   /* Geometry */
   number_holes_btn->setGeometry(575,300,75,25);

   /* Visibility */
   total_memory_size_btn->hide();
   number_holes_btn->show();
   hole_submit_btn->hide();
   no_segments_btn->hide();
   segment_submit_btn->hide();
   allocation_method_btn->hide();

   /********************************************************************Spin Boxes*****************************************************************/

   /* Geometry */
   number_holes->setGeometry(425,300,75,25);

   /* Visibility */
   total_memory_size->hide();
   number_holes->show();
   hole_address->hide();
   hole_size->hide();
   no_segments->hide();
   segment_size->hide();

   /* Minimum */
   number_holes->setMinimum(0);

   /* Maximum */
   number_holes->setMaximum(1000000000);

   /********************************************************************labels*****************************************************************/

   /* Geometry */
   number_holes_label->setGeometry(450,250,250,30);

   /* Text */
   number_holes_label->setText("Please Enter Initial Number of Holes: ");

   /* Font */

   /* Visibility */
   memory_size_label->hide();
   number_holes_label->show();
   hole_address_label->hide();
   hole_size_label->hide();
   no_segments_label->hide();
   segment_name_label->hide();
   segment_size_label->hide();
   allocation_method_label->hide();

   /******************************************************************Signals********************************************************************/
   connect(number_holes_btn,SIGNAL(pressed()),this,SLOT(no_holes_chosen()));
}

void simulate::no_holes_chosen(){

    holes=number_holes->value();
    if(holes==0)
    {
        cal_old();
    }else
    {
    /********************************************************************Push Buttons***************************************************************/

    /* Geometry */
    hole_submit_btn->setGeometry(775,300,100,25);

    /* Visibility */
    total_memory_size_btn->hide();
    number_holes_btn->hide();
    hole_submit_btn->show();
    no_segments_btn->hide();
    segment_submit_btn->hide();
    allocation_method_btn->hide();

    /********************************************************************Spin Boxes*****************************************************************/

    /* Geometry */
    hole_address->setGeometry(350,300,75,25);
    hole_size->setGeometry(600,300,75,25);

    /* Visibility */
    total_memory_size->hide();
    number_holes->hide();
    hole_address->show();
    hole_size->show();
    no_segments->hide();
    segment_size->hide();

    /* Minimum */
    hole_address->setMinimum(0);
    hole_size->setMinimum(1);

    /* Maximum */
    hole_address->setMaximum(1000000000);
    hole_size->setMaximum(1000000000);
    /********************************************************************labels*****************************************************************/

    /* Geometry */
    hole_address_label->setGeometry(220,300,130,25);
    hole_size_label->setGeometry(500,300,130,25);

    /* Font */


    /* Visibility */
    memory_size_label->hide();
    number_holes_label->hide();
    hole_address_label->show();
    hole_size_label->show();
    no_segments_label->hide();
    segment_name_label->hide();
    segment_size_label->hide();
    allocation_method_label->hide();

    /* Text */
    hole_submit_btn->setText("Submit Hole "+QString::number(holes_counter+1));
    hole_address_label->setText("Address of Hole "+QString::number(holes_counter+1));
    hole_size_label->setText("Size of Hole "+QString::number(holes_counter+1));
    }
    /******************************************************************Signals********************************************************************/
    connect(hole_submit_btn,SIGNAL(pressed()),this,SLOT(Input_holes()));
}

void simulate::Input_holes()
{
    if(!(hole_address->value()==0 && hole_size->value()==1))
    {
        /******************************************************************Inputs*********************************************************************/
        bool overlap=false;
        unsigned int address=hole_address->value();
        unsigned int size =hole_size->value();

        if(address+size>memory_size)
        {
            overlap=true;
        }
        else
        {
            for(int i=0;i<memory.size();i++)
            {
                if(( address >= memory[i]->starting_address )&&( address < ((memory[i]->starting_address)+(memory[i]->size))))
                {
                    overlap=true;
                    break;
                }
                else if(( (address+size) > memory[i]->starting_address )&& ( (address+size) <= ((memory[i]->starting_address)+(memory[i]->size))))
                {
                    overlap=true;
                    break;
                }
                else if((address < memory[i]->starting_address)&&( (address+size) > ((memory[i]->starting_address)+(memory[i]->size))))
                {
                    overlap=true;
                    break;
                }
            }
        }

        if(!overlap)
        {
            Segment* newsegment=new Segment;
            newsegment->starting_address=hole_address->value();
            newsegment->size=hole_size->value();
            newsegment->type =hole;
            memory.push_back(newsegment);
            holes_counter++;
            hole_address->setValue(hole_address->minimum());
            hole_size->setValue(hole_size->minimum());
            hole_submit_btn->setText("Submit Hole "+QString::number(holes_counter+1));
            hole_address_label->setText("Address of Hole "+QString::number(holes_counter+1));
            hole_size_label->setText("Size of Hole "+QString::number(holes_counter+1));
        }
        else {
            error->setText("Error Allocating Please Try Again");
            error->exec();
        }

        if(holes_counter==holes)
        {
            cal_old();
        }
    }
}

void simulate::cal_old()
{ 
    if(holes!=0)
    {
      for(unsigned int i=0; i<holes-1;i++)
      {
          for(unsigned int j=0; j<holes-i-1;j++)
          {
              if(memory[j]->starting_address>memory[j+1]->starting_address)
              {
                  Segment *temp=memory[j];
                  memory[j]=memory[j+1];
                  memory[j+1]=temp;
              }
          }
       }
    }
   unsigned int previous_ending_address=0;
   unsigned int counter=0;
   for (int j=0;j<memory.size();j++)
   {
       if(previous_ending_address != memory[j]->starting_address && memory[j]->type==hole)
       {
           Segment* newsegment=new Segment;
           newsegment->starting_address=previous_ending_address;
           newsegment->size=(memory[j]->starting_address)- previous_ending_address;
           newsegment->type =old_process;
           counter++;
           newsegment->segment_ID=counter;
           memory.insert(j,newsegment);
           dealloc_options->addItem("Old Process"+QString::number(newsegment->segment_ID));
           j++;
       }
       previous_ending_address=(memory[j]->starting_address)+(memory[j]->size);
   }
   if(previous_ending_address<memory_size)
   {
       Segment* newsegment=new Segment();
       newsegment->starting_address=previous_ending_address;
       newsegment->size=memory_size-previous_ending_address;
       newsegment->type =old_process;
       counter++;
       newsegment->segment_ID=counter;
       dealloc_options->addItem("Old Process"+QString::number(newsegment->segment_ID));
       memory.push_back(newsegment);
   }

   for(int i=0;i<memory.size();i++)
   {
       qDebug()<<memory[i]->starting_address<<" "<<memory[i]->size<<" "<<memory[i]->type<<endl;
   }
    compact_holes();
    DrawOutput();

   /********************************************************************Push Buttons***************************************************************/

   /* Geometry */
   no_segments_btn->setGeometry(400,350,75,25);
   dealloc_btn->setGeometry(400,150,75,25);
   no_segments_btn->raise();
   dealloc_btn->raise();
   restart_btn->raise();
   /* Visibility */
   total_memory_size_btn->hide();
   number_holes_btn->hide();
   hole_submit_btn->hide();
   no_segments_btn->show();
   segment_submit_btn->hide();
   allocation_method_btn->hide();
   dealloc_btn->show();

   /********************************************************************Spin Boxes*****************************************************************/

   /* Geometry */
   no_segments->setGeometry(150,350,75,25);

   /* Visibility */
   total_memory_size->hide();
   number_holes->hide();
   hole_address->hide();
   hole_size->hide();
   no_segments->show();
   segment_size->hide();

   no_segments->raise();
   /* Minimum */
   no_segments->setMinimum(1);

   /* Maximum */
   no_segments->setMaximum(1000000000);

   /********************************************************************labels*****************************************************************/

   /* Geometry */
   no_segments_label->setGeometry(180,300,400,30);

   /* Text */
   no_segments_label->setText("Please Enter Number of Segments for allocating Process ");

   /* Visibility */
   memory_size_label->hide();
   number_holes_label->hide();
   hole_address_label->hide();
   hole_size_label->hide();
   no_segments_label->show();
   segment_name_label->hide();
   segment_size_label->hide();
   allocation_method_label->hide();

   /********************************************************************labels*****************************************************************/
    deallocation_label->setGeometry(200,100,400,30);
    deallocation_label->setText("Please Choose a Process to deallocate");
    deallocation_label->show();
   /* Geometry */
   dealloc_options->setGeometry(150,150,100,25);
   /* Visibility */
   dealloc_options->show();
   dealloc_options->raise();

   /******************************************************************Signals********************************************************************/
   connect(no_segments_btn,SIGNAL(pressed()),this,SLOT(no_segments_chosen()));
   connect(dealloc_btn,SIGNAL(pressed()),this,SLOT(deallocate_process()));
 }

void simulate::no_segments_chosen(){

    segments=no_segments->value();
    entry_process=new process_e;
    entry_process->set_size(segments);

    /********************************************************************Push Buttons***************************************************************/

    /* Geometry */
    segment_submit_btn->setGeometry(575,300,100,25);

    /* Text */
    segment_submit_btn->setText("Submit Seg"+QString::number(segment_counter+1));
    segment_submit_btn->raise();
    restart_btn->raise();
    /* Visibility */
    total_memory_size_btn->hide();
    number_holes_btn->hide();
    hole_submit_btn->hide();
    no_segments_btn->hide();
    segment_submit_btn->show();
    allocation_method_btn->hide();

    /********************************************************************Spin Boxes*****************************************************************/

    /* Geometry */
    segment_size->setGeometry(475,300,75,25);
    segment_size->raise();
    /* Visibility */
    total_memory_size->hide();
    number_holes->hide();
    hole_address->hide();
    hole_size->hide();
    no_segments->hide();
    segment_size->show();

    /* Minimum */
    segment_size->setMinimum(1);

    /* Maximum */
    segment_size->setMaximum(1000000000);

    /********************************************************************Input Dialogs**************************************************************/

    /* Geometry */
    segment_name->setGeometry(225,300,75,25);

    /* Visibility */
    segment_name->show();
    segment_name->raise();
    /* Text */
    segment_name->setText("");

    /********************************************************************labels*****************************************************************/

    /* Geometry */
    segment_name_label->setGeometry(100,300,150,25);
    segment_size_label->setGeometry(350,300,150,25);

    /* Visibility */
    memory_size_label->hide();
    number_holes_label->hide();
    hole_address_label->hide();
    hole_size_label->hide();
    no_segments_label->hide();
    segment_name_label->show();
    segment_size_label->show();
    allocation_method_label->hide();

    /* Text */

    segment_name_label->setText("Name of Seg"+QString::number(segment_counter+1));
    segment_size_label->setText("Size of Seg"+QString::number(segment_counter+1));

    /******************************************************************Signals********************************************************************/
    connect(segment_submit_btn,SIGNAL(pressed()),this,SLOT(Input_segments()));
}

void simulate::Input_segments()
{
    if(!(segment_size->value()==1 && segment_name->text()==""))
    {
        entry_process->segments_arr[segment_counter]->size=segment_size->value();
        entry_process->segments_arr[segment_counter]->name=segment_name->text();
        segment_counter++;
        if(segment_counter==segments)
        {
            process_done();
        }
        segment_name->setText("");
        segment_size->setValue(hole_size->minimum());
        segment_name_label->setText("Name of Seg"+QString::number(segment_counter+1));
        segment_size_label->setText("Size of Seg"+QString::number(segment_counter+1));
        segment_submit_btn->setText("Submit Seg"+QString::number(segment_counter+1));
    }
}

void simulate::process_done(){
    segment_counter=0;

    if(allocation_type=="First Fit")
    {
        first_fit();
    }
    else if(allocation_type=="Best Fit")
    {
        best_fit();
    }
    else
    {
        worst_fit();
    }
    for(int i=0;i<memory.size();i++)
    {
        qDebug()<<memory[i]->starting_address<<" "<<memory[i]->size<<" "<<memory[i]->type<<endl;
    }
    DrawOutput();
    no_segments_btn->raise();
    dealloc_btn->raise();
    no_segments->raise();
    dealloc_options->raise();
    segment_submit_btn->raise();
    segment_size->raise();
    segment_name->raise();
    restart_btn->raise();
    no_segments->show();
    no_segments_btn->show();
    no_segments_label->show();
    segment_submit_btn->hide();
    segment_name_label->hide();
    segment_name->hide();
    segment_size_label->hide();
    segment_size->hide();
    no_segments->setValue(no_segments->minimum());
}

void simulate::first_fit()
{
   if(check_allocacation_ff())
   {
       dealloc_options->addItem("P"+QString::number(entry_process->ID));
       for(unsigned int j=0;j<entry_process->segments_n;j++)
       {
              allocate_segment_ff(memory,entry_process->segments_arr[j]);
       }
   }
   else
   {
       error->setText("The Process can not be allocated");
       error->exec();
   }
}

void simulate::best_fit()
{
    if(check_allocacation_bf())
    {
        dealloc_options->addItem("P"+QString::number(entry_process->ID));
        for(unsigned int j=0;j<entry_process->segments_n;j++)
        {
               allocate_segment_bf(memory,entry_process->segments_arr[j]);

        }
    }
    else
    {
        error->setText("The Process can not be allocated");
        error->exec();
    }
}

void simulate::worst_fit(){
    if(check_allocacation_wf())
    {
        dealloc_options->addItem("P"+QString::number(entry_process->ID));
        for(unsigned int j=0;j<entry_process->segments_n;j++)
        {
               allocate_segment_wf(memory,entry_process->segments_arr[j]);
        }
    }
    else
    {
        error->setText("The Process can not be allocated");
        error->exec();
    }
}

void simulate::allocate_segment_ff(QVector<Segment*> &memory,Segment* target)
{
   unsigned int target_size =target->size;
     for(int i=0;i<memory.size();i++)
     {
       if(memory[i]->type==hole&&memory[i]->size>=target_size)
       {
           target->starting_address=memory[i]->starting_address;
           memory[i]->size-=target_size;
           memory[i]->starting_address+=target_size;
           target->allocated=true;
           memory.insert(i,target);
           break;
       }
   }
}

bool simulate::check_allocacation_ff()
{
    QVector<Segment*>temp_process(entry_process->segments_n);
    for(unsigned int i=0;i<entry_process->segments_n;i++)
    {
        temp_process[i]=new Segment;
        temp_process[i]->size=entry_process->segments_arr[i]->size;
        temp_process[i]->type=entry_process->segments_arr[i]->type;
    }
    QVector<Segment*> temp_memory;
    temp_memory.resize(memory.size());
    for(int i=0;i<memory.size();i++)
    {
        temp_memory[i]=new Segment;
        temp_memory[i]->starting_address=memory[i]->starting_address;
        temp_memory[i]->size=memory[i]->size;
        temp_memory[i]->type=memory[i]->type;
    }
    for(unsigned int j=0;j<entry_process->segments_n;j++)
    {
        allocate_segment_ff(temp_memory,temp_process[j]);
    }
    for(unsigned int i=0;i<entry_process->segments_n;i++)
    {
        if(!(temp_process[i]->allocated))
        {
           return false;
        }
    }
    return true;
}

void simulate::allocate_segment_bf(QVector<Segment*> &memory,Segment* target)
{
   unsigned int best_size(0),best_index(0);
   unsigned int target_size =target->size;
   // this loop is just to initilize the best size with any availabe value and break if there is no available hole
    for(int i=0;i<memory.size();i++)
    {
         if(memory[i]->type==hole&&memory[i]->size>=target_size)
         {
             best_size=memory[i]->size;
             best_index=i;
             break; // it's just for right initialization
         }
    }

    for(int i=0;i<memory.size();i++)
    {
         if(memory[i]->type==hole&&memory[i]->size>=target_size&&memory[i]->size<best_size)
         {
             best_size=memory[i]->size;
             best_index=i;
         }
    }
    if(best_size!=0)
    {
        target->starting_address=memory[best_index]->starting_address;
        memory[best_index]->size-=target_size;
        memory[best_index]->starting_address+=target_size;
        target->allocated=true;
        memory.insert(best_index,target);
    }
}

bool simulate::check_allocacation_bf()
{
    QVector<Segment*>temp_process(entry_process->segments_n);
    for(unsigned int i=0;i<entry_process->segments_n;i++)
    {
        temp_process[i]=new Segment;
        temp_process[i]->size=entry_process->segments_arr[i]->size;
        temp_process[i]->type=entry_process->segments_arr[i]->type;
    }
    QVector<Segment*> temp_memory;
    temp_memory.resize(memory.size());
    for(int i=0;i<memory.size();i++)
    {
        temp_memory[i]=new Segment;
        temp_memory[i]->starting_address=memory[i]->starting_address;
        temp_memory[i]->size=memory[i]->size;
        temp_memory[i]->type=memory[i]->type;
    }
    for(unsigned int j=0;j<entry_process->segments_n;j++)
    {
        allocate_segment_bf(temp_memory,temp_process[j]);
    }
    for(unsigned int i=0;i<entry_process->segments_n;i++)
    {
        if(!(temp_process[i]->allocated))
        {
           return false;
        }
    }
    return true;
}

void simulate::allocate_segment_wf(QVector<Segment*> &memory,Segment* target)
{
    unsigned int worst_size(0),worst_index(0);
    unsigned int target_size =target->size;
    // this loop is just to initilize the best size with any availabe value and break if there is no available hole
     for(int i=0;i<memory.size();i++)
     {
          if(memory[i]->type==hole&&memory[i]->size>=target_size)
          {
              worst_size=memory[i]->size;
              worst_index=i;
              break; // it's just for right initialization
          }
     }

     for(int i=0;i<memory.size();i++)
     {
          if(memory[i]->type==hole&&memory[i]->size>=target_size&&memory[i]->size>worst_size)
          {
              worst_size=memory[i]->size;
              worst_index=i;
          }
     }
     if(worst_size!=0)
     {
         target->starting_address=memory[worst_index]->starting_address;
         memory[worst_index]->size-=target_size;
         memory[worst_index]->starting_address+=target_size;
         target->allocated=true;
         memory.insert(worst_index,target);
     }
}

bool simulate::check_allocacation_wf()
{
    QVector<Segment*>temp_process(entry_process->segments_n);
    for(unsigned int i=0;i<entry_process->segments_n;i++)
    {
        temp_process[i]=new Segment;
        temp_process[i]->size=entry_process->segments_arr[i]->size;
        temp_process[i]->type=entry_process->segments_arr[i]->type;
    }
    QVector<Segment*> temp_memory;
    temp_memory.resize(memory.size());
    for(int i=0;i<memory.size();i++)
    {
        temp_memory[i]=new Segment;
        temp_memory[i]->starting_address=memory[i]->starting_address;
        temp_memory[i]->size=memory[i]->size;
        temp_memory[i]->type=memory[i]->type;
    }
    for(unsigned int j=0;j<entry_process->segments_n;j++)
    {
        allocate_segment_wf(temp_memory,temp_process[j]);
    }
    for(unsigned int i=0;i<entry_process->segments_n;i++)
    {
        if(!(temp_process[i]->allocated))
        {
           return false;
        }
    }
    return true;
}

void simulate::deallocate_process()
{
    QString name=dealloc_options->currentText();
    int index=dealloc_options->currentIndex();
    dealloc_options->removeItem(index);
    if(name[0]=='O')
    {
       for(int i=0;i<memory.size();i++)
       {
           if(memory[i]->type==old_process &&QString::number(memory[i]->segment_ID)==name.right(name.size()-11))
           {
               memory[i]->type=hole;
               break;
           }
       }
    }
    else
    {
        for(int i=0;i<memory.size();i++)
        {
            if(memory[i]->type==normal &&QString::number(memory[i]->segment_ID)==name.right(name.size()-1))
            {
                memory[i]->type=hole;
            }
        }
    }
    compact_holes();
    qDebug()<<"compact";
    for(int i=0;i<memory.size();i++)
    {
        qDebug()<<memory[i]->starting_address<<" "<<memory[i]->size<<" "<<memory[i]->type<<endl;
    }
    DrawOutput();
    no_segments_btn->raise();
    dealloc_btn->raise();
    no_segments->raise();
    dealloc_options->raise();
    segment_submit_btn->raise();
    segment_size->raise();
    segment_name->raise();
    restart_btn->raise();
}

void simulate::compact_holes()
{
    for(int i=0;i<memory.size()-1;i++)
    {
        if(memory[i]->type==hole&&memory[i+1]->type==hole)
        {
            Segment* newsegment=new Segment;
            newsegment->starting_address=memory[i]->starting_address;
            newsegment->size=memory[i]->size+memory[i+1]->size;
            newsegment->type =hole;
            delete memory[i+1];
            memory.removeAt(i+1);
            delete memory[i];
            memory.removeAt(i);
            memory.insert(i,newsegment);
            i--;
        }
    }
}

void simulate::DrawOutput()
{
    for(int i=0;i<memory.size();i++)
        {
            memory[i]->DrawSegment(750,memory[i]->starting_address/mapping_value + 50);
            memory[i]->setParent(this);
            memory[i]->show();
        }
}

void simulate::restart()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
//    total_memory_size_btn->show();
//    number_holes_btn->hide();
//    hole_submit_btn->hide();
//    no_segments_btn->hide();
//    segment_submit_btn->hide();
//    allocation_method_btn->hide();
//    dealloc_btn->hide();
//    restart_btn->hide();
//    total_memory_size->show();
//    number_holes->hide();
//    hole_address->hide();
//    hole_size->hide();
//    no_segments->hide();
//    segment_size->hide();
//    memory_size_label->show();
//    number_holes_label->hide();
//    hole_address_label->hide();
//    hole_size_label->hide();
//    no_segments_label->hide();
//    segment_name_label->hide();
//    segment_size_label->hide();
//    allocation_method_label->hide();
//    deallocation_label->hide();
//    segment_name->hide();
//    allocation_method->hide();
//    dealloc_options->hide();
//    for(int i=0;i<memory.size();i++)
//    {
//        delete memory[i];
//        memory.removeAt(i);
//        i--;
//    }
//    memory_size=0;
//    holes=0;
//    holes_counter=0;
//    segments=0;
//    segment_counter=0;
//    total_memory_size->setValue(total_memory_size->minimum());
//    number_holes->setValue(number_holes->minimum());
//    hole_address->setValue(hole_address->minimum());
//    hole_size->setValue(hole_size->minimum());
//    no_segments->setValue(no_segments->minimum());
//    segment_name->setText("");
//    segment_size->setValue(segment_size->minimum());
//    dealloc_options->clear();
//    allocation_method->clear();
}

simulate::~simulate()
{


}
