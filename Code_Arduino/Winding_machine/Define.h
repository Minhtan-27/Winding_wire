int step1 =5;
int dir1=6;
int ena=7;
int in1=8;
int in2=9;
int en1=13;
int up_btn= 10;
int dwn_btn=11;
int ent_btn=12;
byte limit_right=4;
byte  limit_left= A0;
int encoderA=2;
int encoderB=3;
int hold_start_time;
int lcd_state=0;
int move_state_last;
int turn=50;
int hold_duration;
int hold_duration_last;
int coil_lenght=55;
int limit_state;
double wire_size_array [16]={0.3,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,2.0};
int wire_size_col=0;
int i;
int turn_count=0;
int toltal_count=0;
int count=0;
double step1_pulse=0.04;
int count_sv=1;
 // turn of servo dc
