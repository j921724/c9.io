#include "h_crane.h"
#include <iostream>
using namespace std;

class Crain : public CraneCrane
{
private:
    ev3dev::touch_sensor touch_q;
    ev3dev::motor a;
    ev3dev::motor b; 
    ev3dev::motor c;
    ev3dev::ultrasonic_sensor ultra;
    
public:
    // Hardware Configuration
    Crain():m_speed(0), ultra(ev3dev::INPUT_1), touch_q(ev3dev::INPUT_2), a(ev3dev::OUTPUT_B), b(ev3dev::OUTPUT_C), c(ev3dev::OUTPUT_A)
    {
        
    }
    
    int m_speed;
    
    bool get_touch_pressed()
    {
        return touch_q.is_pressed();
    }
    
    // 인식 거리
    virtual float mode_us_dist_cm()
    {
        return 7.;
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
        
        int i;
        
        
        
        //sensor 측정, 거리가 10보다 멀면, 내려감 else break.
        if (ultra.distance_centimeters() < mode_us_dist_cm()){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
          
        cout<<ultra.distance_centimeters()<<endl;
        
        if(get_up()){
        
            // for (int i = 0; i<300; i++){
            //     cout << i << endl;
                a.set_speed_sp(-1*get_speed());
                a.run_forever();
            }
        
        if(get_down()){
            // for (int i = 0; i<300; i++){
            //     cout << i << endl;
                a.set_speed_sp(get_speed());
                a.run_forever();
        
        }
        
        if(get_left()){
            //for (int i = 0; i<1500; i++){
                // if (ultra.distance_centimeters() < mode_us_dist_cm())
                // break;
                // cout << i << endl;
                b.set_speed_sp(-1*get_speed());
                b.run_forever();
        }
        
        if(get_right()){
            //for (int i = 0; i<1500; i++){
                // if (ultra.distance_centimeters() < mode_us_dist_cm())
                // break;
                // cout << i << endl;
                b.set_speed_sp(get_speed());
                b.run_forever();
            }
       
        if(!(get_up() | get_down() | get_right() | get_left() | get_enter()))
        {
            a.set_speed_sp(0);
            a.run_forever();
            b.set_speed_sp(0);
            b.run_forever();
        }
    }
    a.stop();
    b.stop();
}

int main()
{     
    Crain crain;
    while(true){
        if(crain.get_touch_pressed()==true){ 
            
        
        crain.example_code(); //This line is for example, you should erase this ex_code in your 'real code' 
  
        }
    }
}