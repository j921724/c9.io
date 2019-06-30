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
    
    // 인식 거리
    virtual float mode_us_dist_cm()
    {
        return 10;
    }
    bool get_touch_pressed()
    {
        return touch_q.is_pressed();
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
    void left();
    void left1();
    void right();
    void right1(int j);
    void up();
    void down();
    void pick();
    void drop();
    void sleep();
};


void Crain::right(){
    b.set_speed_sp(get_speed());
    for (int i = 0; i<1400; i++){
        if (ultra.distance_centimeters() < mode_us_dist_cm())
                break;
                cout << i << endl;
                b.run_forever();
        
    }
    
        sleep();
}

// 남은 거리 이동
void Crain::right1(int j){
    b.set_speed_sp(get_speed());
    for (int i= 0; i < 1550-j; i++){
        // if (ultra.distance_centimeters() < mode_us_dist_cm())
        //         break;
                cout << i << endl;
                b.run_forever();
        
    }
    
        sleep();
}

void Crain::left(){
            b.set_speed_sp(-1*get_speed());
            for (int i = 0; i<1700; i++){
                //if (ultra.distance_centimeters() < mode_us_dist_cm())
                //break;
                cout << i << endl;
                b.run_forever();
            }
            
        sleep();
}
            
// 짚기 위해 옆으로 살작 이동하는 것
void Crain::left1(){
            b.set_speed_sp(-1*get_speed());
            for (int i = 0; i<100; i++){
                //if (ultra.distance_centimeters() < mode_us_dist_cm())
                //break;
                cout << i << endl;
                b.run_forever();
            }  
            
        sleep();
}

void Crain::up(){
            a.set_speed_sp(-1*get_speed());
            for (int i = 0; i <600; i++){
                cout << i << endl;
                a.run_forever();
            }    
            
        sleep();
}

void Crain::down(){
            a.set_speed_sp(get_speed());
            for (int i = 0; i<300; i++){
                cout << i << endl;
                a.run_forever();
            }
            
        sleep();
}

void Crain::pick(){
    down();
    a.set_speed_sp(get_speed());
    for (int i=0; i<300; i++){
        while(100<i<200){
            c.set_speed_sp(0.4*get_speed());
            c.run_timed();
        }
        a.run_forever();
    }
    sleep();
}
    
//     down();
//     a.set_speed_sp(get_speed());
//     for (int i=0; i<300; i++){
//         while(100<i<200){
//             c.set_speed_sp(0.4*get_speed());
//             c.run_forever();
//         }
//         a.run_forever();
//     }
//     sleep();
// }
 
    
/*        
        a.set_speed_sp(get_speed());
        c.set_speed_sp(-1*get_speed());
        for (int i = 0; i<350; i++){
            cout << i << endl;
            a.run_forever();
            if(i>50){
            c.run_forever();
            }
        }
        sleep();
        up();
        sleep();
}
*/


void Crain::drop(){
        a.set_speed_sp(-1*get_speed());
        c.set_speed_sp(-0.5*get_speed());
        down();
        for (int i = 0; i<400; i++){
            cout << i << endl;
            c.run_forever();
            if(i>100){
            a.run_forever();
            }
        }
        sleep();
        //up();
        sleep();
}

void Crain::sleep(){
        a.set_speed_sp(0);
        b.set_speed_sp(0);
        for (int i = 0; i<130; i++){
                cout << "wow" << endl;
            }
            
            a.run_forever();
            b.run_forever();
    
}


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
        int j;
        cout<<"hi2"<<endl;//여기서 멈춤
        if(get_up()){
            
        cout<<"hi3"<<endl;
            up();
        }
        
        if(get_down()){
            down();
        }
        
        if(get_left()){
            left();
            
        }
        
        if(get_right()){
            right();
            }
        
        if(get_enter()){
            pick();
            up();
            //drop();
            //up();
            /*
            up();
            right();
            left1();
            pick();
            right1(700);
            drop();
            left();
            down();
            down();
            */
        }
       
        cout<<"hi4"<<endl;
        if(!(get_up() | get_down() | get_right() | get_left() | get_enter()))
        {
        cout<<"hi5"<<endl;
            a.set_speed_sp(0);
            cout<<"hi5-1"<<endl;
            a.run_forever();
            cout<<"hi5-2"<<endl;
            b.set_speed_sp(0);
            cout<<"hi5-3"<<endl;
            b.run_forever();
            cout<<"hi5-4"<<endl;
            // c.set_speed_sp(0);
            // cout<<"hi5-5"<<endl;
            // c.run_forever;
            
            
        }
    }
        cout<<"hi6"<<endl;

    a.stop();
    b.stop();
}

int main()
{     
    Crain crain;
    while(true){
        if(crain.get_touch_pressed()==true){ 
            
        cout<<"hi"<<endl;
        crain.example_code(); //This line is for example, you should erase this ex_code in your 'real code' 
  
        }
    }
}