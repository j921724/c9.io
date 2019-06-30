#include "h_crane.h"
#include <iostream>

class Crain : public CraneCrane
{
private:
    ev3dev::touch_sensor touch_q;
    ev3dev::motor a;
    ev3dev::motor b; 
    ev3dev::motor c;
    
public:
    // Hardware Configuration
    Crain():m_speed(0), touch_q(ev3dev::INPUT_2),a(ev3dev::OUTPUT_B), b(ev3dev::OUTPUT_C), c(ev3dev::OUTPUT_A)
    { // 여기에 touch_p(ev3dev::INPUT_3) 추가해서 센서로 인식함
        
    }
    
    int m_speed;
    
    bool get_touch_pressed()
    {
        return touch_q.is_pressed();  //button은 is_pressed/ color는 아마도 int color 관련해서 찾아봐야할 듯
    }
    
    virtual bool get_down()
    {
        return m_down;
    }

    virtual bool get_up()
    {
        return m_up;
    }

    virtual bool get_right()
    {
        return m_right;
    }

    virtual bool get_left()
    {
        return m_left;
    }

    virtual bool get_enter()
    {
        return m_enter;
    }

    virtual bool get_escape()
    {
        return m_escape;
    }

    virtual int  get_speed()
    {
        return 100;
    }

    virtual void set_down(bool val)
    {
        m_down = val;
    }
    
    virtual void set_up(bool val)
    {
        m_up = val;    
    }
    
    virtual void set_right(bool val)
    {
        m_right = val;   
    }
    virtual void set_left(bool val)
    {
        m_left = val; 
    } 
    
    virtual void set_enter(bool val)
    {
        m_enter = val;    
    }
    
    virtual void set_escape(bool val)
    {
        m_escape = val;    
    }
    
    virtual void set_speed(int val)
    {
        m_speed = val;    
    }
public:
    void example_code();
    void my_code();
};

void Crain::example_code()
{ //This function is for example, you should develop your own logics
    while(get_escape() == false)
    {
        set_down(ev3dev::button::down.pressed());
        set_up(ev3dev::button::up.pressed());
        set_right(ev3dev::button::right.pressed());
        set_left(ev3dev::button::left.pressed());
        set_escape(ev3dev::button::back.pressed());
        set_enter(ev3dev::button::enter.pressed());
        
    if(get_up())
    {for (int i = 0; i<500; i++){
        c.set_speed_sp(-1*get_speed());
        c.run_forever();
    }
    sleep(10);
    for(int i=0; i<100; i++){
        a.set_speed_sp(get_speed());
        a.run_forever();
        b.set_speed_sp(get_speed());
        b.run_forever();
    }
    sleep(10);
    for(int i=0; i<100; i++){
        a.set_speed_sp(-1*get_speed());
        a.run_forever();
    }
    sleep(10);
    for(int i = 0; i<400; i++){
        b.set_speed_sp(-1* get_speed());
        b.run_forever();
    }
            
                // a.set_speed_sp(-1*get_speed());
                // a.run_forever();
    }   
        if(get_down())
        {
                a.set_speed_sp(get_speed());
                a.run_forever();
        }
        if(get_left())
        {
              b.set_speed_sp(get_speed());
              b.run_forever(); 
              c.set_speed_sp(-1*get_speed());
              c.run_forever();
        }
        if(get_right())
        {
              b.set_speed_sp(-1* get_speed());
              b.run_forever();
               
                c.set_speed_sp(get_speed());
                c.run_forever();
        }
       
       
        if(!(get_up() | get_down() | get_right() | get_left() | get_enter())) //동작없을 때, 생뚱맞은 걸 누르면?
        {
            a.set_speed_sp(0);
            a.run_forever();
            b.set_speed_sp(0);
            b.run_forever();
        }}


    a.stop();
    b.stop();
}

void Crain::my_code(){
    while(get_escape() == false)
    {
        set_down(ev3dev::button::down.pressed());
        set_up(ev3dev::button::up.pressed());
        set_right(ev3dev::button::right.pressed());
        set_left(ev3dev::button::left.pressed());
        set_escape(ev3dev::button::back.pressed());
        set_enter(ev3dev::button::enter.pressed());
    if(get_right()){
    for (int i = 0; i<400; i++){
        c.set_speed_sp(get_speed());
        c.run_forever();
    }
    for(int i=0; i<100; i++){
        a.set_speed_sp(get_speed());
        c.run_forever();
    }
    for(int i=0; i<100; i++){
        a.set_speed_sp(-1*get_speed());
        c.run_forever();
    }
    for(int i = 0; i<400; i++){
        b.set_speed_sp(-1* get_speed());
        b.run_forever();
    }
    }   
    }
    
    {
    // abs 관련 실행
    // b.run_to_abs_pos();
    // b.set_speed_sp(-1* get_speed());
    // b.set_position_sp(get_speed());
    // b.run_to_abs_pos();
    // b.stop();
    // sleep(100);
    // c.set_speed_sp(get_speed());
    // c.set_position_sp(get_speed());
    // c.stop();
    // c.run_to_abs_pos();
    }
    
}

int main(){     
    Crain crain;
    // if (crain.get_touch_pressed()==true){
    //     crain.my_code();

    // }
    // if (crain.get_touch_pressed()==true){
    //     crain.my_code();
    // }
    while(true){
        if(crain.get_touch_pressed()==true){ 
            
        
        crain.example_code(); //This line is for example, you should erase this ex_code in your 'real code' 
  
        }
    }
}

//run_abs pos 해서 값을 일일이 찾아야함. 
//ultra sonic value값 받는 거 찾아야함. 거리 알려주는 기계