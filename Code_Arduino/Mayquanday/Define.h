#define up_btn 2
#define  dwn_btn 3
#define ent_btn 4
#define right_limit  5
#define left_limit  6
byte move_state = 0;
byte move_state_last = 0;
byte ent_state = 0;
byte ent_state_last = 0;
byte mode = 0;
byte mode_last = 5;
int  Coil_lenght = 40;
int turn = 1000; // vong
int wire_size_col = 0;
double wire_size_array [16] = {0.3, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 2.0};
int toltal_count = 0; // tong
int layer_count = 0; // dem lop
int layer_number = 0; //so lop
int direction = 1;
byte dir1 = 7;
byte step1 = 8;
byte en1 = 9;
byte dir2 = 10;
byte step2 = 11;
int en2 = 12;
byte switch_state = 0; // limit sw state
byte switch_state_last = 1 ; // last limit sw state
byte screw_dir = 0;
double screw_steps =0.1 ;
long hold_start_time = 0;
int hold_duration = 0;
int left_sw1;
int right_sw2;
byte tang;
byte giam;
byte enter;
