#include<iostream>
#include<math.h>
#include<vector>
#define IMAX 100001

class Func 
{
public:
    double operator()(double x, double y)
        {
            double dydx;
            dydx = sin(x) * cos(x) - y * cos(x);
            return dydx;
        }
};


class RungeKutta 
{
public:
    RungeKutta(int num_of_params, double target):m_num_of_params(num_of_params), m_target(target)
        {
            m_axis[0] = 0.0;
            m_params.resize(m_num_of_params);
            for(int i = 0; i < m_num_of_params; i++){
                m_params[i].resize(IMAX);
                m_params[i][0] = 0.0;
            }
            m_steps = 10000;
            
            
            
        }
    template<class F>
    void calc(F func)
        {
            double k1, k2, k3, k4;
            double h = (m_target - m_axis[0]) / m_steps;
            

            for (int i = 0; i < m_steps; i++){
                k1 = h * func(m_axis[i], m_params[0][i]);
                k2 = h * func(m_axis[i] + h / 2.0, m_params[0][i] + k1 / 2.0);
                k3 = h * func(m_axis[i] + h / 2.0, m_params[0][i] + k2 / 2.0);
                k4 = h * func(m_axis[i] + h, m_params[0][i] + k3);

                m_axis[i+1] = m_axis[i] + h;
                m_params[0][i+1] = m_params[0][i] + 1.0 / 6.0 * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
                std::cout << m_axis[i] << " " << m_params[0][i] << std::endl;
            }
        }
private:
    int m_num_of_params;
    double m_axis[IMAX];
    std::vector<std::vector<double>> m_params;
    double m_target;
    int m_steps;
    
    
};

    
int main()
{

    Func func;
    RungeKutta rungekutta(1, 10.0);
    
    rungekutta.calc(func);

    return 0;
    
}



    
