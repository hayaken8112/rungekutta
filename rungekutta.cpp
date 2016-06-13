#include<iostream>
#include<math.h>
#include<vector>
#define IMAX 100001

class Func 
{
public:
    std::vector<double> operator()(double x, std::vector<double> y)
        {
            std::vector<double> ans(1);
            ans[0] = sin(x) * cos(x) - y[0] * cos(x);
            return ans;
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
                m_params[i] = 0.0;
            }
            m_steps = 10000;
            
            
        }
    template<class F>
    void calc(F func)
        {
            std::vector<double> temp(m_num_of_params);
            
            double h = (m_target - m_axis[0]) / m_steps;
            

                
            for (int j = 0; j < m_steps; j++){
                // k1
                std::vector<double> k1 = func(m_axis[j], m_params);
                // k2
                for (int i = 0; i < m_num_of_params; i++){
                    temp[i] = m_params[i] + (h / 2.0) * k1[i];
                }
                std::vector<double> k2 = func(m_axis[j] + h / 2.0, temp);
                // k3
                for (int i = 0; i < m_num_of_params; i++){
                    temp[i] = m_params[i] + (h / 2.0) * k2[i];
                }
                std::vector<double> k3 = func(m_axis[j] + h / 2.0, temp);

                // k4
                for (int i = 0; i < m_num_of_params; i++){
                    temp[i] = m_params[i] + h * k3[i];
                }
                
                std::vector<double> k4 = func(m_axis[j] + h, temp);

            
                for (int i = 0; i < m_num_of_params; i++){
                    m_params[i] = m_params[i] + (h / 6.0) * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]);
                }
                
                m_axis[j+1] = m_axis[j] + h;

            }
            for (int i = 0; i < m_num_of_params; i++){
                std::cout << m_params[i] << std::endl;
            }
            
        }
private:
    int m_num_of_params;
    double m_axis[IMAX];
    std::vector<double> m_params;
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



    
